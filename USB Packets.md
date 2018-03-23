
## Init sequence (on plug usb)

* We have one set of 22 packets starting @ 123, incrementing wIndex in ascending order
with fix values : 0x0a, 0x00, 0x2e
* Then, another set of 20 packets starting @ 186, with no particular incrementing order,
but are paired by two (stereo ? while loop ? probably stereo groups.). Missing indexes are 2 and 3.

```
0x40 : 26 (0x1a)  |  SetGain() / hwWriteLedAndPga()
```

**Note**: Those could be some initialization first, followed by user-saved gain value if different.
This should be tested and verified with TotalmixFX and wireshark.

**TODO**: Find the function sending those guys !

**Conclusion**: The first set always send the same values. This must be some init.
                The second is the application of the user values from TotalMix. These are sent only if they are different from the "init".
                Nice guess, dude.

## Once iface's up

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
                   Found in hwGetStatusReg() from FirefaceUSB.kext
                   0x3fc6/FALSE Found in hwGetIsoModeFlag() from FirefaceUSB.kext
                   Found in hwGetRate() from FirefaceUSB.kext
0xc0 : 16 (0x10) Found in hwGetRate() from FirefaceUSB.kext
```


## Notes

```
0x40 : 16 (0x10)  |  Set Sample Rate (pkt 2/2)
                  |  Set Clk src, single speed, coax AES/SPDIF
                  |  UNKNOWN - sent by hwInitHardware() from FirefaceUSB.kext
0x40 : 18 (0x12)  |  Set in / pb / output volume
0x40 : 19 (0x13)  |  Hardware Mute
0x40 : 20 (0x14)  |  Hardware unMute
0x40 : 21 (0x15)  |  Set Loopback on output
0x40 : 22 (0x16)  |  UNKNOWN - sent by hwInitHardware() from FirefaceUSB.kext
0x40 : 23 (0x17)  |  Set +48v / PAD / Hi-Z
0x40 : 26 (0x1a)  |  Always from hwWriteLedAndPga() function (Gain, output vol)
0x40 : 27 (0x1b)  |  Set Sample Rate (pkt 1/2)
0xc0 : 28 (0x1c)  |  Get firmware version
0x40 : 32 (0x20)  |  UNKNOWN - sent by hwInitHardware() from FirefaceUSB.kext
```
