#ifndef __usb_h__
#define __usb_h__

#include <libusb-1.0/libusb.h>
#include <stdint.h>

#ifdef LIBUSB_H
	typedef struct libusb_control_setup ctrl_setup;
#else
	typedef struct control_setup {
		uint8_t  bmRequestType;
		uint8_t  bRequest;
		uint16_t wValue;
		uint16_t wIndex;
		uint16_t wLength;
	} ctrl_setup;
#endif

int send_ctrl_setup( libusb_device_handle *dev, ctrl_setup *ctrl, unsigned char *data );

int send_ctrl_setup_alt( libusb_device_handle *dev, uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, uint16_t wLength, unsigned char *data );

#endif
