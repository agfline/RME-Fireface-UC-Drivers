
// SAME AS DEV

/*
		This function is used by several others for different purposes.
 		It simply gets data to build CONTROL_SETUP frame and sends it.
 		However it does some processing on the bmRequestType byte.

 		Also, the function called to send the packet seems to return something (answer ?) that
 		then go arg_8* is not null.

 		// called by :
 			hwGetStatusReg()
 				bmRequestType = 0x1 => 0xc0
 				bRequest = 0x11
 				wValue = 0x0000
 				wIndex = 0x0000
 				wLength = 0x0002
 				payload = ??????

 			hwGetRevision()
 				bmRequestType = 0x1 => 0xc0
 				bRequest = 0x1c
 				wValue = 0x0000
 				wIndex = 0x0000
 				wLength = 0x0004
 				payload = 0

 			hwGetRate()
 				bmRequestType = 0x1 => 0xc0
 				bRequest = 0x11
 				wValue = 0x0000
 				wIndex = 0x0000
 				wLength = 0x0004
 				payload = ?

 				bmRequestType = 0x1 => 0xc0
 				bRequest = 0x10
 				wValue = 0x0000
 				wIndex = 0x0000
 				wLength = 0x0004
 				payload = 0x00000000


 			de_RME_driver_USBAudioUserClient::sUserClientWriteVolume()
 				bmRequestType = 0x0 => 0x40
 				bRequest = 0x12
 				wValue = 0xXXXX
 				wIndex = 0xXXXX
 				wLength = 0x0000
 				payload = 0x0000 (NULL)
 */

usb_vendor_device_request(
							char bmRequestType,
							char bRequest,
							uint16_t wValue,
							uint16_t wIndex,
							uint16_t wLength,
							unsigned char *data,
							uint32_t *len
						 )
{


	/*

		Usb_vendor_device_request( IOUSBDevice*, 	rdi		arg_1	IOUSBDevice *
					   unsigned char,	rsi		arg_2	bRequest
					   unsigned short, 	rdx		arg_3	wValue
					   unsigned short, 	rcx		arg_4	wIndex
					   void*, 		r8		arg_5	pData * (send/recv)
					   unsigned short, 	r9		arg_6	wLength
					   unsigned char, 	rbp+0x10	arg_7	bmRequestType
					   unsigned int*	rbp+0x18	arg_8	wLenDone ?
					 )

*/

/* From https://github.com/opensource-apple/IOUSBFamily/blob/master/IOUSBFamily/Headers/USB.h
    @struct IOUSBDevRequest from Apple implementation

    @field wLength Length of data part of request, 16 bits, host endianess
    @field pData Pointer to data for request - data returned in bus endianess
    @field wLenDone Set by standard completion routine to number of data bytes
	actually transferred

typedef struct {
    UInt8       bmRequestType;
    UInt8       bRequest;
    UInt16      wValue;
    UInt16      wIndex;
    UInt16      wLength;
    void *      pData;
    UInt32      wLenDone;
} IOUSBDevRequest;
*/


/*
	================ B E G I N N I N G   O F   P R O C E D U R E ================

	0x00000f9c	push	rbp
	0x00000f9d	mov	rbp, rsp
	0x00000fa0	sub	rsp, 0x20
*/
	ctrl_setup ctrl;

/*
	0x00000fa4	mov	al, byte [ss:rbp+arg_0]
	0x00000fa7	shl	al, 0x7
	0x00000faa	or	al, 0x40
	0x00000fac	mov	byte [ss:rbp-0x18], al		; bmRequestType
	0x00000faf	mov	byte [ss:rbp-0x17], sil		; bRequest
	0x00000fb3	mov	word [ss:rbp-0x16], dx		; wValue
	0x00000fb7	mov	word [ss:rbp-0x14], cx		; wIndex
	0x00000fbb	mov	word [ss:rbp-0x12], r9w		; wLength
	0x00000fc0	mov	qword [ss:rbp-0x10], r8
*/
	ctrl.bmRequestType = (bmRequestType << 0x7) | 0x40;
	ctrl.bRequest = bRequest;
	ctrl.wValue = wValue;
	ctrl.wIndex = wIndex;
	ctrl.wLength = wLength;
//	ctrl.pData = data;

/*
	0x00000fc4	mov	rax, qword [ds:rdi]
	0x00000fc7	lea	rsi, qword [ss:rbp-0x18]
	0x00000fcb	xor	edx, edx
	0x00000fcd	call	qword [ds:rax+0x938]   ; setup_request( IOUSBDevice *, ctrl_struct *, int )
	0x00000fd3	mov	rcx, qword [ss:rbp+0x18]
	0x00000fd7	test	rcx, rcx
	0x00000fda	je	0xfe1
*/
	print_ctrl_setup( &ctrl );
//	send_setup_request( IOUSBDevice, &ctrl, 0 );

	if ( len == NULL )
		return;

/*
	0x00000fdc	mov	edx, dword [ss:rbp-0x08]
	0x00000fdf	mov	dword [ds:rcx], edx
*/
	else
		*len = ctrl.wLenDone;

/*
	0x00000fe1	add	rsp, 0x20
	0x00000fe5	pop	rbp
	0x00000fe6	ret
			; endp
*/

	return;	// TODO: returns setup_request( IOUSBDevice *, ctrl_struct *, int ) ???
			// TODO: is this an answer ? is this a return code ?
}
