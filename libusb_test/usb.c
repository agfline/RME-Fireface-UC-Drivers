#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <libusb-1.0/libusb.h>

#include "usb.h"



int send_ctrl_setup( libusb_device_handle *dev, ctrl_setup *ctrl, unsigned char *data )
{

	if ( dev == NULL ) {
		fprintf( stdout, "SENDING > %02x %02x %04x %04x %04x\n",
			 ctrl->bmRequestType,
			 ctrl->bRequest,
			 ctrl->wValue,
			 ctrl->wIndex,
			 ctrl->wLength );

		return 0;
	}

	int r = libusb_control_transfer(
			dev,
			ctrl->bmRequestType,
			ctrl->bRequest,
			ctrl->wValue,
			ctrl->wIndex,
			data,
			ctrl->wLength,
			0
		);

	if ( r < 0 ) {

		fprintf( stderr, "%s:%d in %s() : %s\n",
			 __FILE__,
			 __LINE__,
			 __func__,
			 libusb_error_name( r ) );

		exit( r );
	}

	return r;
}



int send_ctrl_setup_alt( libusb_device_handle *dev, uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, uint16_t wLength, unsigned char *data )
{
	ctrl_setup ctrl;

	ctrl.bmRequestType = bmRequestType;
	ctrl.bRequest = bRequest;
	ctrl.wValue = wValue;
	ctrl.wIndex = wIndex;
	ctrl.wLength = wLength;

	return send_ctrl_setup( dev, &ctrl, data );
}
