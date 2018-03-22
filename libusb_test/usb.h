#ifndef __usb_h__
#define __usb_h__

#include <libusb-1.0/libusb.h>
#include <stdint.h>


#define TRACE_USB



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



#ifdef TRACE_USB
#define send_ctrl_setup( dev, ctrl, data ) do_send_ctrl_setup_trace( dev, ctrl, data, __func__ )
#else
#define send_ctrl_setup( dev, ctrl, data ) do_send_ctrl_setup( dev, ctrl, data )
#endif

int do_send_ctrl_setup_trace( libusb_device_handle *dev, ctrl_setup *ctrl, unsigned char *data, const char *caller_name );
int do_send_ctrl_setup( libusb_device_handle *dev, ctrl_setup *ctrl, unsigned char *data );

int send_ctrl_setup_alt( libusb_device_handle *dev, uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, uint16_t wLength, unsigned char *data );

// #define send_ctrl_setup( de, ct, da ) send_ctrl_setup_trace( de, ct, da, __FUNCTION__ )

#endif
