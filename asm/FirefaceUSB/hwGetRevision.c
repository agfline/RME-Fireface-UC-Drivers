
#include <stdio.h>
#include <stdint.h>

#include "../libusb_test/usb.h"


void hwGetRevision( libusb_device_handle *dev, unsigned int *rev )
{

/*
	hwGetRevision( IOUSBDevice*, 	rdi	IOUSBDevice
		       unsigned int*	rsi	rev*
		     )



	================ B E G I N N I N G   O F   P R O C E D U R E ================

	0x0000101e	push	rbp
	0x0000101f	mov	rbp, rsp
	0x00001022	push	rbx
	0x00001023	sub	rsp, 0x18
*/

/*
	0x00001027	mov	rbx, rsi
	0x0000102a	mov	dword [ss:rbp-0x0C], 0x0
	0x00001031	mov	dword [ss:rbp-0x10], 0x0
*/
	// uint32_t len  = 0;
	uint32_t data = 0;
	ctrl_setup ctrl;

/*
	0x00001038	lea	rax, qword [ss:rbp-0x0C]
*/
//	uint32_t *len_p = &len;

/*
	0x0000103c	mov	qword [ss:rsp+0x8], rax			; argument "var_18" for method
	0x00001041	mov	dword [ss:rsp], 0x1			; argument "var_10" for method
	0x00001048	mov	esi, 0x1c				; argument #2 for method
	0x0000104d	xor	edx, edx				; argument #3 for method
	0x0000104f	lea	r8, qword [ss:rbp-0x10]			; argument #5 for method
	0x00001053	mov	r9d, 0x4				; argument #6 for method
	0x00001059	xor	ecx, ecx				; argument #4 for method
	0x0000105b	call	Usb_vendor_device_request( IOUSBDevice*,
							   unsigned char, 	; bRequest	0x1c
							   unsigned short,	; wValue	0
							   unsigned short,	; wIndex	0
							   void*, 		; data
							   unsigned short,	; wLength	0x4
							   unsigned char,	; bmRequestType	0x1 (0xc0)
							   unsigned int*	; &len
							 )
*/
	// usb_vendor_device_request( IOUSBDevice, 0x1c, 0, 0, data, 0x04, 0x01, len_p );
	// len = send_ctrl_setup_alt( dev, 0xc0, 0x1c, 0x0000, 0x0000, 0x0004, (unsigned char *)&data );

	ctrl.bmRequestType = 0xc0;
	ctrl.bRequest = 0x1c;
	ctrl.wValue = 0x0000;
	ctrl.wIndex = 0x0000;
	ctrl.wLength = 0x0004;

	send_ctrl_setup( dev, &ctrl, (unsigned char *)&data );

/*

	0x00001060	mov	ecx, dword [ss:rbp-0x10]
	0x00001063	shr	ecx, 0x10
	0x00001066	mov	dword [ds:rbx], ecx
*/
	data >>= 0x10;
	*rev = data;

/*
	0x00001068	add	rsp, 0x18
	0x0000106c	pop	rbx
	0x0000106d	pop	rbp
	0x0000106e	ret
			; endp
*/
	return;		// TODO: depends on Usb_vendor_device_request() return (eax ?)
}
