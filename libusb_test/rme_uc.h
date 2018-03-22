#ifndef __rme_uc_h__
#define __rme_uc_h__

#include <libusb-1.0/libusb.h>

#define RME_UC_VENDOR		0x0424  /*  1060 */
#define RME_UC_PRODUCT		0x3fc6  /* 16326 */


int rme_init_iface( libusb_device_handle *dev );

#endif
