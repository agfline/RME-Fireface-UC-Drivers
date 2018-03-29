
CC = gcc
CFLAGS = -W -Wall -lusb-1.0 -g -I ./
SRC = ./rme_uc.c\
      ./usb.c\
	  ../asm/FirefaceUSB/xRate.c\
	  ../asm/FirefaceUSB/hwSetSampleRate.c\
	  ../asm/FirefaceUSB/hwGetRevision.c\
	  ../asm/FirefaceUSB/hwMuteChannels.c\
	  ../asm/FirefaceUSB/hwInitHardware.c\
	  ../asm/FirefaceUSB/hwGetRate.c\
	  ../asm/FirefaceUSB/de_RME_driver_USBAudioUserClient\:\:sUserClientReadStatus.c\
	  ../asm/TotalmixFX/CCardIOUC\:\:SetGain.c\
	  ../asm/FirefaceUSBSettings/CHardware\:\:GetStatus.c\
	  ../asm/FirefaceUSBSettings/getDeviceNameByTypeId.c

	  # Not for 0x3fc6
	  #../asm/FirefaceUSB/hwGetIsoModeFlag.c


all: $(SRC)
	$(CC) $(SRC) -o rme_uc $(CFLAGS)
