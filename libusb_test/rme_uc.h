#ifndef _RME_UC_H_
#define _RME_UC_H_

#include <libusb-1.0/libusb.h>

#define RME_UC_VENDOR		0x0424  /*  1060 */
#define RME_UC_PRODUCT		0x3fc6  /* 16326 */

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


int rme_init_iface( libusb_device_handle *dev );

#endif
