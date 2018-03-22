
CC = gcc
CFLAGS = -W -Wall -lusb-1.0 -g
SRC = ./rme_uc.c\
      ./usb.c\
	  ../asm/FirefaceUSB-xRate.c\
	  ../asm/FirefaceUSB-hwSetSampleRate.c\
	  ../asm/FirefaceUSB-hwGetRevision.c\
	  ../asm/FirefaceUSB-hwMuteChannels.c\
	  ../asm/FirefaceUSB-hwInitHardware.c\
	  ../asm/TotalmixFX-CCardIOUC\:\:SetGain.c

all: $(SRC)
	$(CC) $(SRC) -o rme_uc $(CFLAGS)
