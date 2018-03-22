
## Init sequence (on plug usb)


* 36 x UNKNOWN CTRL SETUP Packets @ pckn° 43
```
0x40 : 22 (0x16)
Highly probably coming from hwInitHardware() from FirefaceUSB.kext
```

* 18 x UNKNOWN CTRL SETUP Packets @ pckn° 1566
```
0x40 : 21 (0x15)
```

* 6 x UNKNOWN CTRL SETUP Packets @ pckn° 1602
```
0x40 : 23 (0x17)
```




* 54, 196, 198 x UNKNOWN CTRL SETUP Packets @ pckn° 1650, answered 0x04000000
```
0xc0 : 25 (0x19) Found in CHardware::LoadSettings() from Fireface USB Settings
```
* alternate with
```
0xc0 : 17 (0x11) Found in CHardware::GetStatus() from Fireface USB Settings
                 Found in hwGetIsoModeFlag() from FirefaceUSB.kext
0xc0 : 16 (0x10)
```


## Notes

```
0x40 : 16 (0x10)  |  Set Sample Rate (pkt 2/2), Clk src, single speed, coax AES/SPDIF
0x40 : 18 (0x12)  |  Set in / pb / output volume
0x40 : 19 (0x13)  |  Hardware Mute
0x40 : 20 (0x14)  |  Hardware unMute
0x40 : 23 (0x17)  |  Set +48v / PAD / Hi-Z
0x40 : 26 (0x1a)  |  Always from hwWriteLedAndPga() function (Gain, output vol)
0x40 : 27 (0x1b)  |  Set Sample Rate (pkt 1/2)
0xc0 : 28 (0x1c)  |  Get firmware version
```
