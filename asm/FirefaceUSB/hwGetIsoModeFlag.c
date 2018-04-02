
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "../libusb_test/usb.h"

// Always return 0 for 0x3fc6..


uint8_t hwGetIsoModeFlag( libusb_device_handle *dev /*, uint16_t *productId*/ )
{
	uint16_t productId = 0x3fc6;

/*
================ B E G I N N I N G   O F   P R O C E D U R E ================



	hwGetIsoModeFlag ( IOUSBDevice*,
	                   unsigned short
	                 )


	0x000018ce   push   rbp					; XREF=__ZN28de_RME_driver_USBAudioEngine5TimerEv+230
	0x000018cf   mov    rbp, rsp
	0x000018d2   sub    rsp, 0x30
*/

/*
	0x000018d6   cmp  si, 0x3fc1
	0x000018db   je   0x18e4

	0x000018dd   cmp  si, 0x3fca
	0x000018e2   jne  0x191b
*/
	if ( productId != 0x3fc1 && productId != 0x3fca )
	{
		return 0;
	}

/*
	0x000018e4   lea    rax, qword [ss:rbp+var_4]  ; XREF=__Z16hwGetIsoModeFlagP11IOUSBDevicet+13
	0x000018e8   mov    qword [ss:rsp+0x8], rax    ; argument "var_18" for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
	0x000018ed   mov    dword [ss:rsp], 0x1        ; argument "var_10" for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
	0x000018f4   mov    esi, 0x11                  ; argument #2 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
	0x000018f9   xor    edx, edx                   ; argument #3 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
	0x000018fb   lea    r8, qword [ss:rbp+var_14]  ; argument #5 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
	0x000018ff   mov    r9d, 0x10                  ; argument #6 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
	0x00001905   xor    ecx, ecx                   ; argument #4 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
	0x00001907   call   __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj; Usb_vendor_device_request(IOUSBDevice*, unsigned char, unsigned short, unsigned short, void*, unsigned short, unsigned char, unsigned int*)
*/

	unsigned char data[0x10];
	unsigned char *data_p = data;

	memset( &data, 0x00, 0x10 );

	ctrl_setup ctrl;

	ctrl.bmRequestType = 0xc0;
	ctrl.bRequest  = 0x11;
	ctrl.wValue  = 0x0000;
	ctrl.wIndex  = 0x0000;
	ctrl.wLength = 0x0010;

	int rc = send_ctrl_setup( dev, &ctrl, data_p);

/*
	0x0000190c   test   eax, eax
	0x0000190e   jne    0x191b
*/
	if ( rc == 0 )
	{
/*
		0x00001910   mov    eax, dword [ss:rbp+var_8]
		0x00001913   shr    eax, 0x1a
		0x00001916   and    eax, 0x1
		0x00001919   jmp    0x191d
*/
		uint8_t isoModeFlag = ((uint32_t)*(data_p + 8) >> 0x1a) & 0x1;

		return isoModeFlag;
	}

/*
	0x0000191b   xor    eax, eax				; XREF=__Z16hwGetIsoModeFlagP11IOUSBDevicet+20, __Z16hwGetIsoModeFlagP11IOUSBDevicet+64

	0x0000191d   add    rsp, 0x30				; XREF=__Z16hwGetIsoModeFlagP11IOUSBDevicet+75
	0x00001921   pop    rbp
	0x00001922   ret
				; endp
*/

	return 0;
}
