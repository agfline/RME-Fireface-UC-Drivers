# RME Fireface UC Linux drivers

>This repos is currently for development purposes only and does not contain any working driver yet.

<br/>

Le but est dans un premier temps de disposer de drivers fonctionnels pour Linux avec le support de toutes les entrées / sorties, et dans un second temps envisager le développemment d'une interface de control générique des DSP, similaire à TotalMix.

Bien que ce projet repose sur le portage de la Fireface UC, les drivers officiels sont communs aux interfaces **UFX / UFX+**, **802**, **UCX**, **Babyface**, **Babyface Pro**, **MADIface XT / USB / Pro**. Le travail effectué ici peut donc servir de base aux futurs portages de celles-ci.

<br>


## Reverse Engineering

* Fireface UC (**firmware v118**)
* VM Mac OSX 10.8.5 (**[drivers v2.20](http://www.rme-audio.de/en/downloads/driver/uc.php)**)

L'ensemble du travail présenté ici repose sur l'analyse des trames USB (**usbmon & Wireshark**) ainsi que sur le désassemblage du driver officiel [FirefaceUSB.kext](./asm/FirefaceUSB.asm) et des logiciels [Fireface USB Settings](./asm/FirefaceUSBSettings.asm) et [TotalMix-FX](./asm/TotalmixFX.asm).

* Les captures Wireshark sont disponibles dans le dossier [cap/](./cap)
* Les fonctions réimplémentées sont disponibles dans le dossier [asm/](./asm)

## Description

L'appareil peut fonctionner selon deux modes : Windows (**PC**, `productId 0x3fc5`) ou Mac (**AP**, `productId 0x3fc6`).

On choisit le mode en « double-clickant » rapidement sur le bouton de controle en face avant lorsque le cable usb est débranché.

Le choix du mode va déterminer l'architecture des Interfaces et Endpoints (device descriptor), avec notamment pour les transferts audio  des Endpoints BULK en mode PC et ISOCHRONOUS en mode AP.

**Ce projet vise à porter les drivers en mode AP uniquement.**

* Voir le [device descriptor](./device_descriptor).


## Audio

Les transmissions audio se font via des transferts asynchrones ISOCHRONOUS. Le format audio transmis en lecture est toujours en **32 bits flottant Little Endian**.

Les transmissions audio (entrantes et sortantes) se font sur l'interface 0, alternate settings 1, 2, ou 3.

Le choix de l'alternate setting se fait en fonction de la capacité de transmission des Endpoints (wMaxPacketSize), et donc de la fréquence d'échantillonnage :

* bAlternateSetting **1** : `[32000Hz; 64000Hz[`
* bAlternateSetting **2** : `[64000Hz; 128000Hz[`
* bAlternateSetting **3** : `[128000Hz; 192000Hz]`


### Observations en lecture à 44100 Hz

Une trame ISO est transmise toutes les millisecondes pour un débit de 1000 trames par seconde.

Chaque trame ISO contient 8 subframes de tailles alternant entre 456 bytes (`0x01c8`) et 380 bytes (`0x017c`).

```wireshark
Isodescriptor from wireshark :

0000   ee ff ff ff 00 00 00 00   c8 01 00 00 00 00 00 00  ................
0010   ee ff ff ff c8 01 00 00   7c 01 00 00 00 00 00 00  ........|.......
0020   ee ff ff ff 44 03 00 00   c8 01 00 00 00 00 00 00  ....D...........
0030   ee ff ff ff 0c 05 00 00   7c 01 00 00 00 00 00 00  ........|.......
0040   ee ff ff ff 88 06 00 00   c8 01 00 00 00 00 00 00  ................
0050   ee ff ff ff 50 08 00 00   7c 01 00 00 00 00 00 00  ....P...|.......
0060   ee ff ff ff cc 09 00 00   c8 01 00 00 00 00 00 00  ................
0070   ee ff ff ff 94 0b 00 00   7c 01 00 00 00 00 00 00  ........|.......
```

Chaque subframe se découpe alternativement en 5 ou 6 blocs de 19 * 4 bytes :
&nbsp;&nbsp;&nbsp;`5 * (19 * 4) = 380 Bytes`
&nbsp;&nbsp;&nbsp;`6 * (19 * 4) = 456 Bytes`

9 trames ISO sur 10 transmettent 3344 bytes, soit `3344 / (19 * 4) =` 44 blocs.
1 trame ISO sur 10 transmet 3420 bytes, soit `3420 / (19 * 4) = ` 45 blocs.

On obtient donc sur 10ms (10 trames) `(9 * 44) + 45 =` 441 blocs, soit **44100** blocs sur une seconde.

Un bloc contient donc 1 sample audio (sur 32 bits flotant) pour chaque cannal, soit 18 samples + 4 bytes.

```wireshark
0080   fe 05 00 00 00 fe 7f 3f   00 00 00 00 00 00 00 00  .......?........
      |__????_____|__ch_1_____| |__ch_2_____|__ch_3_____|

0090   00 00 00 00 00 00 00 00   00 00 00 00 00 00 00 00  ................
      |__ch_4_____|__ch_5_____| |__ch_6_____|__ch_7_____|

00a0   00 00 00 00 00 00 00 00   00 00 00 00 00 00 00 00  ................
      |__ch_8_____|__ch_9_____| |__ch_10____|__ch_11____|

00b0   00 00 00 00 00 00 00 00   00 00 00 00 00 00 00 00  ................
      |__ch_12____|__ch_13____| |__ch_14____|__ch_15____|

00c0   00 00 00 00 00 00 00 00   00 00 00 00              ............
      |__ch_16____|__ch_17____| |__ch_18____|

```


### Observations en capture à 44100 Hz

**TODO**


## Synchronisation

La synchro entre l'hôte et l'interface est très probablement basé sur un implicit feedback (voir [5.12.4.3 Implicit Feedback](sdphca.ucsd.edu/lab_equip_manuals/usb_20.pdf) des specs de l'USB 2.0), avec comme référence le flux en provenance de l'interface (audio inputs).

Voir :
* de_RME_driver_USBAudioEngine::Timer()
* de_RME_driver_USBAudioEngine::inIsochCallback()
* de_RME_driver_USBAudioEngine::outIsochCallback()
* de_RME_driver_USBAudioEngine::inBulkCallback()
* de_RME_driver_USBAudioEngine::CalcTimestamp()




## Routage et Mixeur

Le DSP se comporte comme une matrice. Chaque entrée et sortie virtuelle (*playback*) est identifiée indépendamment avec un index, par rapport à une sortie physique.

Il suffit alors d'associer une valeur à un index pour monter ou diminuer un volume vers une sortie, établir ou fermer une route.

A noter que les fonctions de **routage**, **panoramique**, **mute**, **solo**, et d'**association stéréo** sont entièrement gérées par le logiciel TotalMix en jouant sur les volumes, et sont donc indépendantes du DSP.

```
             out_1  out_2  out_3  out_4  out_5  out_6  out_7  out_8 ...

in MIC__1       0     36     72    108    144    180    216    252  ...
in MIC__2       1     37     73    109    145    182    217    253  ...
...            ..     ..     ..    ...    ...    ...    ...    ...  ...
in ADAT_7      16     52     88    124    160    196    232    268  ...
in ADAT_8      17     53     89    125    161    197    233    269  ...


pb AN___1      18     54     90    126    162    198    234    270  ...
pb AN___2      19     55     91    127    163    199    235    271  ...
...            ..     ..     ..    ...    ...    ...    ...    ...  ...
pb ADAT_7      34     70    106    142    178    214    250    286  ...
pb ADAT_8      35     71    107    143    179    215    251    287  ... up to 647
```

Cependant, les index qui apparaissent dans les trames USB ont parfois des valeurs beaucoup plus élevées. Cela est du à la fonction **CCardIOUC::SetGain()** dans TotalMix qui procède à un traitement de l'index en fonction du volume à appliquer. Cette fonction est réimplémentée dans **setVolume()**.

```
out AN___1      992
out AN___2      993
out AN___3      994
out AN___4      995
out AN___5      996
out AN___6      997
out AN___7      998
out AN___8      999
out SPDF_L     1000
out SPDF_R     1001
out AS___1     1002
out AS___2     1003
out AD___3     1004
out AD___4     1005
out AD___5     1006
out AD___6     1007
out AD___7     1008
out AD___8     1009
```


## Controles

### Set Loopback

**TODO** : find function in TotalmixFX
**TODO** : Init -> default values ? user values ? must be user values.

* CCardIOUC::SetLoopbackChannel()

La fonction Loopback permet de router le signal présent sur une sortie vers l'entrée correspondante.

Le Loopback de chaque sortie est définit lors de l'initialisation de l'interface, juste après l'initialisation des "faders".


```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x15 (21)
wValue           : 0x0001 on / 0x0000 off
wIndex           : channelID
wLength          : 0x0000
```

### Set in & pb Volume

**TODO** : ok

* **[CCardIOUC::SetGain()](./asm/TotalmixFX/CCardIOUC::SetGain.c)**
* **[de_RME_driver_USBAudioUserClient::sUserClientWriteVolume()](./asm/FirefaceUSB/de_RME_driver_USBAudioUserClient::sUserClientWriteVolume.c)**
* **[Usb_vendor_device_request()](./asm/FirefaceUSB/Usb_vendor_device_request.c)**

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x12 (18)
wValue           : volume
wIndex           : channelID
wLength          : 0x0000
```


### Set output Volume

**TODO** : Trouver qui appelle qui, quand et comment.

* **[CCardIOUC::SetGain()](./asm/TotalmixFX/CCardIOUC::SetGain.c)**
* **[de_RME_driver_USBAudioUserClient::sUserClientWriteVolume()](./asm/FirefaceUSB/de_RME_driver_USBAudioUserClient::sUserClientWriteVolume.c)**
* **[Usb_vendor_device_request()](./asm/FirefaceUSB/Usb_vendor_device_request.c)**

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x12 (18)
wValue           : volume
wIndex           : channelID (992 - 1009)
wLength          : 0x0000
```

* **[hwWriteLedAndPga()](./asm/FirefaceUSB/hwWriteLedAndPga.c)**

Ce transfert accepte comme valeurs de volume `[0x3f (-inf); 0x00 (+6)]` pour un total de 64 valeurs.

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x1a (26)
wValue           : volume
wIndex           : channelID (4 - 21)
wLength          : 0x0000
```

Les deux transferts sont employés en alternance par TotalMix. TODO: en alternance ???

Les deux transferts ont un effet sur le niveau de sorti, seul le second modifie la valeur de l'afficheur LCD.


### Set Gain

**TODO** : Trouver l'appellant dans TotalMix

* **[hwWriteLedAndPga()](./asm/FirefaceUSB/hwWriteLedAndPga.c)**

Les entrées 1 à 4 disposent d'un réglage de gain.

Les entrées 1 et 2 prennent les valeurs [0,10; 65] par pas de 1 ([0x0,0xa; 0x41]).
Les entrées 3 et 4 prennent les valeurs [0; 18] par pas de 0.5 ([0x0; 0x24]).

Ces valeurs sont gérées par **hwWriteLedAndPga()** qui assrure la conversion, sans assurer de limite haute.

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x1a (26)
wValue           : gain
wIndex           : channelID (0 - 3)
wLength          : 0x0000
```


### Set +48v

**TODO** : ok

* **[CCardIOUC::WriteDWORD()](./asm/TotalmixFX/CCardIOUC::WriteDWORD.c)**
* **[de_RME_driver_USBAudioUserClient::sUserClientWriteSettings()](./asm/FirefaceUSB/de_RME_driver_USBAudioUserClient::sUserClientWriteSettings.c)**
* **[Usb_vendor_device_request()](./asm/FirefaceUSB/Usb_vendor_device_request.c)**

S'applique uniquement aux entrées 1 et 2.

**Channel 1** :

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x17 (23)
wValue           : 0x0001 on / 0x0000 off
wIndex           : 0x0001
wLength          : 0x0000
```

**Channel 2** :

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x17 (23)
wValue           : 0x0002 on / 0x0000 off
wIndex           : 0x0002
wLength          : 0x0000
```


### Set PAD

**TODO** : en fonction d'un élément inconnu, *wValue* peut prendre 0x8008 ou 0x4004. Cependant jamais observé avec Wireshark.

* **[CCardIOUC::WriteDWORD()](./asm/TotalmixFX/CCardIOUC::WriteDWORD.c)**
* **[de_RME_driver_USBAudioUserClient::sUserClientWriteSettings()](./asm/FirefaceUSB/de_RME_driver_USBAudioUserClient::sUserClientWriteSettings.c)**
* **[Usb_vendor_device_request()](./asm/FirefaceUSB/Usb_vendor_device_request.c)**

S'applique uniquement aux entrées 3 et 4.

**Channel 3** :

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x17 (23)
wValue           : 0x0008 on / 0x0000 off
wIndex           : 0x0008
wLength          : 0x0000
```

**Channel 4** :

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x17 (23)
wValue           : 0x0004 on / 0x0000 off
wIndex           : 0x0004
wLength          : 0x0000
```


### Set Inst (Hi-Z)

**TODO** : ok

* **[CCardIOUC::WriteDWORD()](./asm/TotalmixFX/CCardIOUC::WriteDWORD.c)**
* **[de_RME_driver_USBAudioUserClient::sUserClientWriteSettings()](./asm/FirefaceUSB/de_RME_driver_USBAudioUserClient::sUserClientWriteSettings.c)**
* **[Usb_vendor_device_request()](./asm/FirefaceUSB/Usb_vendor_device_request.c)**

S'applique uniquement aux entrées 3 et 4.

**Channel 3** :

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x17 (23)
wValue           : 0x0020 on / 0x0000 off
wIndex           : 0x0020
wLength          : 0x0000
```

**Channel 4** :

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x17 (23)
wValue           : 0x0010 on / 0x0000 off
wIndex           : 0x0010
wLength          : 0x0000
```


### Set output Mute

**TODO** : ok

* **[hwMuteChannels()](./asm/FirefaceUSB/hwMuteChannels.c)**

Cette fonction permet un **mute hardware de l'ensemble des sorties**.

Cette fonction est employée uniquement lors des operations de lecture audio (unmute) et d'arret (mute).

Note: Les fonctions mute présentes dans Totalmix se comportent comme celles des cannaux d'entrées et de playback, c'est à dire en jouant avec les volumes.

Le champ *bRequest* détermine l'action : `0x13 : mute` et `0x14 : unmute`.

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x13 (19) / 0x14 (20)
wValue           : 0xffff
wIndex           : 0xc000
wLength          : 0x0000
```


### Get Sample Rate

**TODO** : ok

* **[hwGetRate()](./asm/FirefaceUSB/hwGetRate.c)**

```
Control Transfer : 0x00
============================
bmRequestType    : 0xc0
bRequest         : 0x11 (17)
wValue           : 0x0000
wIndex           : 0x0000
wLength          : 0x0004
```

```
Control Transfer : 0x00
============================
bmRequestType    : 0xc0
bRequest         : 0x10 (16)
wValue           : 0x0000
wIndex           : 0x0000
wLength          : 0x0004
```


### Set Sample Rate

**TODO** : ok

* **[hwSetSampleRate()](./asm/FirefaceUSB/hwSetSampleRate.c)**

Les deux transferts sont envoyés dans cet ordre. Ils peuvent être si besoin être précédé d'un changement de configuration sur l'interface USB 0 (*bAlternateSetting*), voir la section **Audio**.

**Ce changement de l'alternate setting est indispensable dans le cas d'un changement de groupe de fréquences**, autrement la fréquence tombera au multiple du groupe en cours. Par exemple, si l'on est sur l'*alternate setting* **1** à 44100 Hz et que l'on change la fréquence à 96000 Hz sans passer sur l'*alternate setting* **2**, la fréquence tombera à 48000 Hz.

* bAlternateSetting **1** : `[32000Hz; 64000Hz[`
* bAlternateSetting **2** : `[64000Hz; 128000Hz[`
* bAlternateSetting **3** : `[128000Hz; 192000Hz]`

Les valeurs de *wValue* et *wIndex* sont déterminées par la fonction **hwSetSampleRate()**.

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x1b (27)
wValue           : var1
wIndex           : var2
wLength          : 0x0000
```

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x10 (16)
wValue           : var3
wIndex           : var4
wLength          : 0x0000
```


## Settings

**TODO** : ok

Les settings font l'objet d'une catégorie à part pour plusieurs raisons.

D'abord, il s'agit de l'ensemble des paramètres que l'on trouve dans le programme **Fireface USB Settings**, et ils ont ceci en commun que lorsqu'on modifie un paramètre, l'ensemble des paramètres est transmis par deux transferts, dans les champs *wValue* sous forme de bit flags.

Ces transferts proviennent de la fonction **[hwWriteSettings_uc()](./asm/FirefaceUSBSettings/hwWriteSettings_uc.c)**.

*Le premier transfert concerne les **niveaux d'entrées** et de **sorties**.*

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x17 (23)
wValue           : FLAGS_1
wIndex           : 0x0fc0
wLength          : 0x0000
```


### Set input Levels

```
bit num  | 10  9
---------+-------
+4dBu    |  0  1
-10dBV   |  1  1
Low Gain |  0  0
```


### Set output Levels

```
bit num  |  8  7
---------+-------
+4dBu    |  1  1
-10dBV   |  0  1
Hi Gain  |  1  0
```


### Set phones Levels

```
bit num  | 12 11
---------+-------
+4dBu    |  1  1
-10dBV   |  1  0
Hi Gain  |  0  1
```

<br/><br/><br/>
*Le second transfert concerne les paramètres des **sorties numériques** et de **synchro**,*

```
Control Transfer : 0x00
============================
bmRequestType    : 0x40
bRequest         : 0x10 (16)
wValue           : FLAGS_2
wIndex           : 0x46cf
wLength          : 0x0000
```


### Set Clock Source

```
bit num      |  3  2  1
-------------+----------
Internal     |  0  0  1
SPDIF in     |  0  1  0
ADAT in      |  1  0  0
WordClock in |  1  1  0
```


### Set Single Speed

La fréquence du signal sur la sortie WordClock est normalement égale à la fréquence d'échantionnage.

L'option *single speed* force la sortie WordClock à une fréquence basse. Par exemple, si la fréquence d'échantillonnage est à 96 kHz ou 192 kHz, la sortie WC sera fixée à 48 kHz (multiple inférieur).

```
bit num  |  7
---------+----
on       |  1
off      |  0
```


### Set Coax to AES

Définit la sortie coaxiale comme étant au format **SPDIF** (consumer) ou **AES** (professionnel).

```
bit num  |  8
---------+----
AES      |  1
SPDIF    |  0
```


### Set Optical SPDIF

Définit le format des entrée / sortie optiques comme étant **ADAT** ou **SPDIF**.

```
bit num  | 11
---------+----
SPDIF    |  1
ADAT     |  0
```


### Status

#### Get Firmware Version

**TODO** : ok

* **[hwGetRevision()](./asm/FirefaceUSB/hwGetRevision.c)**
* **[Usb_vendor_device_request()](./asm/FirefaceUSB/Usb_vendor_device_request.c)**

```
Control Transfer : 0x00
============================
bmRequestType    : 0xc0
bRequest         : 0x1c (28)
wValue           : 0x0000
wIndex           : 0x0000
wLength          : 0x0004
```

```
version = (uint32_t)answer >> 0x10
```

#### Get Current Clock

**TODO**


#### Get VU Meters

**TODO**
