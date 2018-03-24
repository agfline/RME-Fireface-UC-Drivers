#ifndef __FirefaceUSB__
#define __FirefaceUSB__

/*
 *  Declarations for the reverse engineered functions in ../asm/
 */

uint32_t xRate( uint32_t edi );
int hwSetSampleRate ( libusb_device_handle *dev, /*uint32_t productId,*/ uint32_t rateValue );
void hwGetRevision( libusb_device_handle *dev, unsigned int *rev );
int hwMuteChannels ( libusb_device_handle *dev, /*uint32_t value, uint16_t productId,*/ uint8_t unmute );
int setVolume( libusb_device_handle *dev, uint32_t channelID, int8_t channelType, uint32_t outputID, int32_t level );
void hwInitHardware ( libusb_device_handle *dev/*, uint16_t productId*/ );
uint32_t hwGetRate ( libusb_device_handle *devh, /*uint16_t productId,*/ uint8_t /*dx*/ unknownArg );

// Not for 0x3fc6
// uint8_t hwGetIsoModeFlag( libusb_device_handle *dev /*, uint16_t *productId*/ );

#endif // __FirefaceUSB__
