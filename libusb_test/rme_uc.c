
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <libusb-1.0/libusb.h>

#include "rme_uc.h"

int send_ctrl_setup( libusb_device_handle *dev, ctrl_setup *ctrl, unsigned char *data ) {

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

int send_ctrl_setup_alt( libusb_device_handle *dev, uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, uint16_t wLength, unsigned char *data ) {

	ctrl_setup ctrl;

	ctrl.bmRequestType = bmRequestType;
	ctrl.bRequest = bRequest;
	ctrl.wValue = wValue;
	ctrl.wIndex = wIndex;
	ctrl.wLength = wLength;

	return send_ctrl_setup( dev, &ctrl, data );
}

unsigned int xRate( unsigned int rate ) {

	/*
		This function ensures we send a valid sample rate.

		called by :
			hwSetSampleRate()
			de_RME_driver_USBAudioEngine::Timer()

		0x00001aaa	xRate( unsigned int );

		TODO: re-re-check values
	*/

	if ( rate < 0x94a1 )
		return 0x7d00;	//  32 000 Hz

	if ( rate < 0xb3b7 )
		return 0xac44;	//  44 100 Hz

	if ( rate < 0xdea7 )
		return 0xbb80;	//  48 000 Hz

	if ( rate < 0x12943 )
		return 0xfa00;	//  64 000 Hz

	if ( rate < 0x167c3 )
		return 0x15888;	//  88 200 Hz

	if ( rate < 0x1bd4f )
		return 0x17700;	//  96 000 Hz

	if ( rate < 0x25287 )
		return 0x1f400;	// 128 000 Hz

	if ( rate < 0x2cf88 )
		return 0x2b110;	// 176 400 Hz

	return 0x2ee00;		// 192 000 Hz
}

int hwSetSampleRate( libusb_device_handle *dev, unsigned int rval ) {

	uint32_t productId = 0x3fc6;

	/*
		This function set interface sample rate

		called by :
			de_RME_driver_USBAudioEngine::Timer()
			de_RME_driver_USBAudioEngine::performFormatChange()
			de_RME_driver_USBAudioEngine::initHardware()
			de_RME_driver_USBAudioEngine::performAudioEngineStart()

		hwSetSampleRate( IOUSBDevice*,		rdi	IOUSBDevice*
				 unsigned int,		rsi	rateValue
				 unsigned short		rdx	productId
			       );

		0x00001b2c	push	rbp
		0x00001b2d	mov	rbp, rsp
		0x00001b30	push	r15
		0x00001b32	push	r14
		0x00001b34	push	r13
		0x00001b36	push	r12
		0x00001b38	push	rbx
		0x00001b39	sub	rsp, 0x38
		0x00001b3d	mov	ebx, edx		; ebx = edx = 0x3fc6
		0x00001b3f	mov	r14d, esi		; r14 = esi = rate_value
		0x00001b42	mov	r15, rdi
		0x00001b45	mov	edi, r14d		; argument #1 for method
		0x00001b48	call	xRate()
		0x00001b4d	cmp	eax, 0x2b10f		; if ( eax > 176399 )
		0x00001b52	jg	0x1b9a			;	then jump
*/
		unsigned int rate = xRate( rval );

		uint16_t   si = 0;
		uint32_t r12d = 0;
		uint16_t r13w = 0;

		if ( rate > 176399 ) {
/*
			0x00001b9a	cmp	eax, 0x2b110
			0x00001b9f	je	0x1b8e
*/
			if ( rate == 176400 ) {
/*
				0x00001b8e	mov	si, 0x1
				0x00001b92	mov	r12d, 0x10
				0x00001b98	jmp	0x1bab
*/
				si = 0x1;
				r12d = 0x10;
			} else {
/*
				0x00001ba1	mov	si, 0x2
				0x00001ba5	mov	r12d, 0x20
*/
				si = 0x2;
				r12d = 0x20;
			}
/*
		0x00001b54	cmp	eax, 0x1f3ff
		0x00001b59	jg	0x1b79
*/
		} else if ( rate > 127999 ) {
/*
			0x00001b79	cmp	eax, 0x1f400
			0x00001b7e	jne	0x1ba1
*/
			if ( rate == 128000 ) {
/*
				0x00001b80	xor	esi, esi
				0x00001b82	xor	r12d, r12d
				0x00001b85	jmp	0x1bab
*/
				si = 0;
				r12d = 0;

			} else {
/*
				0x00001ba1	mov	si, 0x2
				0x00001ba5	mov	r12d, 0x20
*/
				si = 0x2;
				r12d = 0x20;
			}
/*
		0x00001b5b	cmp	eax, 0x15887
		0x00001b60	jg	0x1b87
*/
		} else if ( rate > 88199 ) {
/*
			0x00001b87	cmp	eax, 0x15888
			0x00001b8c	jne	0x1ba1
*/
			if ( rate == 88200 ) {
/*
				0x00001b8e	mov	si, 0x1
				0x00001b92	mov	r12d, 0x10
				0x00001b98	jmp	0x1bab
*/
				si = 0x1;
				r12d = 0x10;

			} else {
/*
				0x00001ba1	mov	si, 0x2
				0x00001ba5	mov	r12d, 0x20
*/
				si = 0x2;
				r12d = 0x20;
			}
/*
		0x00001b62	cmp	eax, 0x7d00
		0x00001b67	je	0x1b80
*/
		} else if ( rate == 32000 ) {
/*
			0x00001b80	xor	esi, esi
			0x00001b82	xor	r12d, r12d
			0x00001b85	jmp	0x1bab
*/
			uint32_t esi = 0;

			esi = 0;
			r12d = 0;
/*
		0x00001b69	cmp	eax, 0xac44
		0x00001b6e	je	0x1b8e
*/
		} else if ( rate == 44100 ) {
/*
			0x00001b8e	mov	si, 0x1
			0x00001b92	mov	r12d, 0x10
			0x00001b98	jmp	0x1bab
*/
			si = 0x1;
			r12d = 0x10;
/*
		0x00001b70	cmp	eax, 0xfa00
		0x00001b75	je	0x1b80
*/
		} else if ( rate == 64000 ) {
/*
			0x00001b80	xor	esi, esi
			0x00001b82	xor	r12d, r12d
			0x00001b85	jmp	0x1bab
*/
			uint32_t esi = 0;
			esi = 0;
			r12d = 0;
/*
		0x00001b77	jmp	0x1ba1
*/
		} else {
/*
			0x00001ba1	mov	si, 0x2
			0x00001ba5	mov	r12d, 0x20
*/
			si = 0x2;
			r12d = 0x20;
		}
/*
		0x00001bab	mov	eax, ebx
		0x00001bad	add	eax, 0xffffc036
		0x00001bb2	cmp	ax, 0x3
		0x00001bb6	jb	0x1be6
*/
		if ( (uint16_t)((productId + 0xffffc036) & 0xffff) >= 0x3 ) {	/* 0x3fc6 TRUE */
/*
			0x00001bb8	cmp	bx, 0x3fc2
			0x00001bbd	je	0x1be6
*/
			if ( productId == 0x3fc2 ) {
/*
				0x00001be6	shr	r12d, 0x1
				0x00001be9	cmp	r14d, 0x1bd50
				0x00001bf0	jb	0x1bf8
*/
				r12d >>= 0x1;

				if ( rval >= 114000 ) {
/*
					0x00001bf2	or	r12d, 0x40
					0x00001bf6	jmp	0x1c09

					0x00001c09	mov	r13w, 0x78
*/
					r12d |= 0x40;
					r13w  = 0x78;

				} else {
/*
					0x00001bf8	mov	eax, r12d
					0x00001bfb	or	eax, 0x20
					0x00001bfe	cmp	r14d, 0xdea7
					0x00001c05	cmova	r12d, eax
*/
					if ( rval > 56999 ) {
						r12d |= 0x20;
					}
				}
/*
			0x00001bbf	mov	eax, ebx
			0x00001bc1	add	eax, 0xffffc060
			0x00001bc6	cmp	ax, 0x24
			0x00001bca	ja	0x1bdf
*/
			} else if ( (uint16_t)((productId + 0xffffc060) & 0xffff) <= 0x24 ) {
/*
				0x00001bcc	movzx	eax, ax
				0x00001bcf	mov	rcx, 0x1a00000001
				0x00001bd9	bt	rcx, rax
				0x00001bdd	jb	0x1be6
*/
				/* TODO ( not for UC ) */

			} else {					/* 0x3fc6 TRUE */
/*
				0x00001bdf	mov	r13w, 0x30
				0x00001be4	jmp	0x1c0e
*/
				r13w = 0x30;
			}

		} else {
/*
			0x00001be6	shr	r12d, 0x1
			0x00001be9	cmp	r14d, 0x1bd50
			0x00001bf0	jb	0x1bf8
*/
			r12d >>= 0x1;

			if ( rval >= 114000 ) {
/*
				0x00001bf2	or	r12d, 0x40
				0x00001bf6	jmp	0x1c09

				0x00001c09	mov	r13w, 0x78
*/
				r12d |= 0x40;
				r13w  = 0x78;

			} else {
/*
				0x00001bf8	mov	eax, r12d
				0x00001bfb	or	eax, 0x20
				0x00001bfe	cmp	r14d, 0xdea7
				0x00001c05	cmova	r12d, eax
*/
				if ( rval > 56999 ) {
					r12d |= 0x20;
				}
			}
		}

/*
		0x00001c0e	mov	eax, ebx		; eax = ebx = productId
		0x00001c10	add	eax, 0xffffc03f
		0x00001c15	cmp	ax, 0x1
		0x00001c19	seta	al
*/

		uint8_t al = 0;
		uint8_t cl = 0;

		if ( (uint16_t)((productId + 0xffffc03f) & 0xffff) > 0x1 )	/* 0x3fc6 TRUE */
			al = 0x01;
		else
			al = 0x00;
/*
		0x00001c1c	cmp	bx, 0x3fc4
		0x00001c21	setne	cl
*/
		if ( productId != 0x3fc4 )			/* 0x3fc6 TRUE */
			cl = 0x01;
		else
			cl = 0x00;
/*
		0x00001c24	test	cl, al
		0x00001c26	mov	rcx, 0x5f5e10000000
		0x00001c30	mov	rax, 0x773594000000
		0x00001c3a	cmovne	rax, rcx
*/
		uint64_t rax = 0;

		if ( (cl & al) != 0 ) {
//			rcx = 0x5f5e10000000;
			rax = 0x5f5e10000000;
		} else {					/* 0x3fc6 TRUE */
//			rcx = 0x5f5e10000000;
			rax = 0x773594000000;
		}
/*
		0x00001c3e	mov	ecx, r14d
		0x00001c41	xor	edx, edx		; edx = 0
		0x00001c43	div	rcx			; eax = 0x5f5e10000000 / rate
								; ex_32000 : 0xc3500000
								; ex_44100 : 0x8db92ddc
								; ex_64000 : 0x61a80000
*/
		rax = rax / rval;
/*
		0x00001c46	cmp	r14d, 0x1bd51		; 0x1bd51 = 114001
		0x00001c4d	jb	0x1c55
*/
		if ( rval >= 114001 ) {
/*
			0x00001c4f	shl	rax, 0x2
			0x00001c53	jmp	0x1c62
*/
			rax <<= 0x02;

		} else {
/*
			0x00001c55	cmp	r14d, 0xdea8
			0x00001c5c	seta	cl
			0x00001c5f	shl	rax, cl
*/
			if ( rval > 57000 )
				cl = 0x01;
			else
				cl = 0x00;

			rax <<= cl;
		}
/*
		0x00001c62	mov	byte [ss:rbp+var_58], 0x40
		0x00001c66	mov	byte [ss:rbp+var_57], 0x1b
		0x00001c6a	mov	ecx, eax
		0x00001c6c	shr	ecx, 0x10
		0x00001c6f	mov	word [ss:rbp+var_56], cx
		0x00001c73	and	eax, 0xff00
		0x00001c78	or	eax, esi
		0x00001c7a	mov	word [ss:rbp+var_54], ax
		0x00001c7e	mov	word [ss:rbp+var_52], 0x0
		0x00001c84	mov	qword [ss:rbp+var_50], 0x0
		0x00001c8c	mov	rax, qword [ds:r15]		; ???
		0x00001c8f	lea	rsi, qword [ss:rbp+var_58]	; arg 2 -> ptr to ctrl_setup
		0x00001c93	mov	rdi, r15			; arg_1 -> IOUSBDevice*
		0x00001c96	xor	edx, edx			; arg_3 -> 0 / NULL
		0x00001c98	call	qword [ds:rax+0x938]		; send
*/
		ctrl_setup ctrl;

		ctrl.bmRequestType = 0x40;
		ctrl.bRequest = 0x1b;
		ctrl.wValue = (rax & 0xffffffff) >> 0x10;
		ctrl.wIndex = ((rax & 0xffffffff) & 0xff00) | si;
		ctrl.wLength = 0;

		send_ctrl_setup( dev, &ctrl, NULL );
/*
		0x00001c9e	mov	byte [ss:rbp+var_40], 0x40
		0x00001ca2	mov	byte [ss:rbp+var_3F], 0x10
		0x00001ca6	mov	word [ss:rbp+var_3E], r12w
		0x00001cab	mov	word [ss:rbp+var_3C], r13w
		0x00001cb0	mov	word [ss:rbp+var_3A], 0x0
		0x00001cb6	mov	qword [ss:rbp+var_38], 0x0
		0x00001cbe	mov	rax, qword [ds:r15]		; ???
		0x00001cc1	lea	rsi, qword [ss:rbp+var_40]	; arg_2 -> ptr to ctrl_setup
		0x00001cc5	mov	rdi, r15			; arg_1 -> IOUSBDevice*
		0x00001cc8	xor	edx, edx			; arg_3 -> 0 / NULL
		0x00001cca	call	qword [ds:rax+0x938]		; send
*/
		ctrl.bmRequestType = 0x40;
		ctrl.bRequest = 0x10;
		ctrl.wValue = (r12d & 0xffff);
		ctrl.wIndex = r13w;
		ctrl.wLength = 0;

		send_ctrl_setup( dev, &ctrl, NULL );

		return 0;
/*
		0x00001cd0	add	rsp, 0x38
		0x00001cd4	pop	rbx
		0x00001cd5	pop	r12
		0x00001cd7	pop	r13
		0x00001cd9	pop	r14
		0x00001cdb	pop	r15
		0x00001cdd	pop	rbp
		0x00001cde	ret
				; endp
*/








//	short int bAlternateSetting = 0;

/*
	ctrl_setup ctrl;

	ctrl.bmRequestType = 0x40;
	ctrl.wLength = 0x0000;

	unsigned int rate = xRate( rval );
	unsigned int si = 0;

	if ( rate ==  32000 ||
	     rate ==  64000 ||
	     rate == 128000 ) {

		si = 0;
	}
	else if ( rate ==  44100 ||
		  rate ==  88200 ||
		  rate == 176400 ) {

		si = 0x01;
	}
	else if ( rate ==  48000 ||
		  rate ==  96000 ||
		  rate == 192000 ) {

		si = 0x02;
	}

	uint32_t wValue32 = 0x5f5e10000000 / rval;

	if ( rval > 114001 )
		wValue32 = (wValue32 << 0x02) & 0xffffffff;
	else if ( rval > 57000 )
		wValue32 = (wValue32 << 0x01) & 0xffffffff;


	fprintf( stdout, ":: Set sample rate\n" );

	ctrl.bRequest = 0x1b;
	ctrl.wValue = (wValue32 >>  0x10) & 0xffff;
	ctrl.wIndex = (wValue32 & 0xff00) | si;
	print_ctrl_setup( &ctrl );

	ctrl.bRequest = 0x10;
	ctrl.wValue = (si << 4) & 0xffff;
	ctrl.wIndex = 0x0030;			// TODO : False ! (see 64000Hz)
	print_ctrl_setup( &ctrl );

	fprintf( stdout, "\n" );

	return 0;
*/
}

hwGetRevision( libusb_device_handle *dev, unsigned int *rev ) {

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
	uint32_t len  = 0;
	uint32_t data = 0;

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
//	usb_vendor_device_request( IOUSBDevice, 0x1c, 0, 0, data, 0x04, 0x01, len_p );
	len = send_ctrl_setup_alt( dev, 0xc0, 0x1c, 0x0000, 0x0000, 0x0004, (unsigned char *)&data );

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


int hwMuteChannels( libusb_device_handle *dev, short int mute ) {

	/*
		This function presumably mute / unmute all harware outputs.
		Called only when start/stop playing sound or recording.

		called by :
			de_RME_driver_USBAudioEngine::performAudioEngineStop()
			de_RME_driver_USBAudioEngine::performAudioEngineStart()

		0x00001923	hwMuteChannels( IOUSBDevice*, unsigned int, bool, unsigned short );
					rdi = IOUSBDevice*
					rsi = constant ( 0x3ffff )
					rdx = mute ( 0x00 ) / unmute ( 0x01 )
					rcx = Fireface UC ( 0x3fc6 )
		...
		0x00001954	ja	0x1969
		...
		0x00001969	jne	0x1989
		...
		0x00001989	mov	eax, esi			; eax = esi = 0x3ffff
		0x0000198b	shl	eax, 0xe			; eax = 0xffffc000
		0x0000198e	shr	esi, 0x2			; esi = 0xffff

		0x00001991	movzx	eax, ax				; eax = 0xc000
		0x00001994	mov	byte [ss:rbp+var_18], 0x40	; USB_CONTROL bmRequestType

		0x00001998	test	dl, dl				; if ( rdx != 0 )
		0x0000199a	setne	cl				;	cl = 1;
		0x0000199d	add	cl, 0x13			; cl += 0x13

		0x000019a0	mov	byte [ss:rbp+var_17], cl	; USB_CONTROL bRequest
		0x000019a3	mov	word [ss:rbp+var_16], si	; USB_CONTROL wValue
		0x000019a7	mov	word [ss:rbp+var_14], ax	; USB_CONTROL wIndex
		0x000019ab	mov	word [ss:rbp+var_12], 0x0	; USB_CONTROL wLength
		0x000019b1	mov	qword [ss:rbp+var_10], 0x0	; 16 null bytes

		; send data
		...

		The result match usb sniffing observations :
			start_stop_playinit_PB12-OUT12.pcapng
			start_stop_playinit_PB12-OUT34.pcapng
			start_stop_recinit_IN1.pcapng
	*/

	ctrl_setup ctrl;

	if ( mute == 0 )
		fprintf( stdout, ":: Mute channels\n" );
	else
		fprintf( stdout, ":: Unmute channels\n" );

	ctrl.bmRequestType = 0x40;

	if ( mute == 0 ) // do mute
		ctrl.bRequest = 0x13;
	else		 //  unmute
		ctrl.bRequest = 0x14;

	ctrl.wValue  = 0xffff;
	ctrl.wIndex  = 0xc000;
	ctrl.wLength = 0x0000;

	send_ctrl_setup( dev, &ctrl, NULL );

	fprintf( stdout, "\n" );

	return 0;
}

int setVolume( uint32_t channelID, int8_t channelType, uint32_t outputID, int32_t level ) {

/*
	CCardIOUC::SetGain( int,	rdi	this pointer ?
			    int, 	rsi	channelID
			    int, 	rdx	channelType
							0 = input
							1 = playback
							2 = output
			    int		rcx	outputID (0 - 17)
					r8	value
			  )

	0x100061ccc	push	rbp
	0x100061ccd	mov	rbp, rsp
	0x100061cd0	push	rbx
	0x100061cd1	sub	rsp, 0x28
*/

/*
	0x100061cd5	mov	rbx, qword [ds:_got__stack_chk_guard]
	0x100061cdc	mov	rbx, qword [ds:rbx]
	0x100061cdf	mov	qword [ss:rbp+var_10], rbx
*/
	// Stack Smashing Protector stuff ?

/*
	0x100061ce3	cmp	edx, 0x2
	0x100061ce6	jne	0x100061cf0
*/
	if ( channelType == 0x2 ) {	// OUTPUT
/*
		0x100061ce8	add	ecx, 0x3e0
		0x100061cee	jmp	0x100061cfc
*/
		outputID += 0x3e0;	// 992

	} else {			// INPUT & PLAYBACK
/*
		0x100061cf0	lea	eax, qword [ds:rdx+rdx*8]
		0x100061cf3	lea	eax, qword [ds:rsi+rax*2]
		0x100061cf6	lea	ecx, qword [ds:rcx+rcx*8]
		0x100061cf9	lea	ecx, qword [ds:rax+rcx*4]
*/
//		int eax;
//		eax = (channelType * 9);
//		eax = (channelID + eax * 2);

//		eax = channelType * 11;
//		eax += channelID;



//		int ecx;
//		ecx = (outputID * 9);
//		ecx = (eax + ecx * 4);

		outputID *= 13;
		outputID += (channelType * 11) + channelID;
//		outputID += eax;

	}

/*
	0x100061cfc	mov	byte [ds:rdi+0x2a0], 0x1   	; class stuff
	0x100061d03	mov	eax, r8d
	0x100061d06	sar	eax, 0x2
	0x100061d09	cdqe
	0x100061d0b	mov	qword [ss:rbp-0x20], rax	; wValue
*/
	// that part is here because of the type of the input value.
	// we should implement directly the right value so that part
	// can be avoided.

	// gcc implements arithmetic shift so that's fine
	// level >>= 0x2;

/*
	0x100061d0f	and	ecx, 0x3fff
	0x100061d15	and	r8d, 0x3
	0x100061d19	shl	r8d, 0xe
	0x100061d1d	or	r8d, ecx
*/
	outputID &= 0x3fff;
	channelID = ((level & 0x3) << 0xe) | outputID;

/*
	0x100061d20	mov	qword [ss:rbp-0x18], r8		; wIndex
	0x100061d24	mov	dword [ss:rbp-0x24], 0x0
	0x100061d2b	mov	edi, dword [ds:rdi+0x2a4]	; argument "connection" for method
	0x100061d31	lea	rdx, qword [ss:rbp-0x20]	; argument "input"      for method
	0x100061d35	lea	r9, qword [ss:rbp-0x24]		; argument "outputCnt"  for method
	0x100061d39	mov	esi, 0x3			; argument "selector"   for method
	0x100061d3e	mov	ecx, 0x2			; argument "inputCnt"   for method
	0x100061d43	xor	r8d, r8d			; argument "output"     for method
	0x100061d46	call	imp___stubs__IOConnectCallScalarMethod
	0x100061d4b	test	eax, eax
	0x100061d4d	sete	al
	0x100061d50	cmp	rbx, qword [ss:rbp-0x10]
	0x100061d54	jne	0x100061d60

	0x100061d56	movzx	eax, al
	0x100061d59	add	rsp, 0x28
	0x100061d5d	pop	rbx
	0x100061d5e	pop	rbp
	0x100061d5f	ret

	0x100061d60	call	imp___stubs____stack_chk_fail
			; endp
	0x100061d65	nop
*/

	ctrl_setup ctrl;

	ctrl.bmRequestType = 0x40;
	ctrl.bRequest = 0x12;
	ctrl.wValue = level;
	ctrl.wIndex = channelID;
	ctrl.wLength = 0x0000;

}




















#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

//#include <libusb.h>
#include <libusb-1.0/libusb.h>

#define EP_DATA_IN	0x82
#define EP_ISO_IN	0x86

#define EP_ISO_OUT	0x01	/* mod */

static int do_exit = 0;
static struct libusb_device_handle *devh = NULL;

static unsigned long num_bytes = 0, num_xfer = 0;
static struct timeval tv_start;

static void cb_xfr(struct libusb_transfer *xfr)
{

	if (xfr->status == LIBUSB_TRANSFER_TIMED_OUT) {
		fprintf(stderr, "TX %d : TIMED_OUT\n", num_xfer);
	}

	num_xfer++;
/*	unsigned int i;

	if (xfr->status != LIBUSB_TRANSFER_COMPLETED) {
		fprintf(stderr, "transfer status %d\n", xfr->status);
//		libusb_free_transfer(xfr);
//		exit(3);
	}

	if (xfr->type == LIBUSB_TRANSFER_TYPE_ISOCHRONOUS) {
		for (i = 0; i < xfr->num_iso_packets; i++) {
			struct libusb_iso_packet_descriptor *pack = &xfr->iso_packet_desc[i];

			if (pack->status != LIBUSB_TRANSFER_COMPLETED) {
				fprintf(stderr, "Error: pack %u status %d\n", i, pack->status);
				exit(5);
			}

//			printf("pack%u length:%u, actual_length:%u\n", i, pack->length, pack->actual_length);
		}
	}

//	printf("length:%u, actual_length:%u\n", xfr->length, xfr->actual_length);
	for (i = 0; i < xfr->actual_length; i++) {
		printf("%02x", xfr->buffer[i]);
		if (i % 16)
			printf("\n");
		else if (i % 8)
			printf("  ");
		else
			printf(" ");
	}
	num_bytes += xfr->actual_length;
	num_xfer++;

	if (libusb_submit_transfer(xfr) < 0) {
		fprintf(stderr, "error re-submitting URB\n");
		exit(1);
	}
*/
}

static int benchmark_in(uint8_t ep)
{
	static uint8_t buf[2048];
	static struct libusb_transfer *xfr;
	int num_iso_pack = 0;

	if (ep == EP_ISO_IN)
		num_iso_pack = 16;

	xfr = libusb_alloc_transfer(num_iso_pack);
	if (!xfr)
		return -ENOMEM;

	if (ep == EP_ISO_IN) {
		libusb_fill_iso_transfer(xfr, devh, ep, buf,
				sizeof(buf), num_iso_pack, cb_xfr, NULL, 0);
		libusb_set_iso_packet_lengths(xfr, sizeof(buf)/num_iso_pack);
	} else
		libusb_fill_bulk_transfer(xfr, devh, ep, buf,
				sizeof(buf), cb_xfr, NULL, 0);

	gettimeofday(&tv_start, NULL);

	/* NOTE: To reach maximum possible performance the program must
	 * submit *multiple* transfers here, not just one.
	 *
	 * When only one transfer is submitted there is a gap in the bus
	 * schedule from when the transfer completes until a new transfer
	 * is submitted by the callback. This causes some jitter for
	 * isochronous transfers and loss of throughput for bulk transfers.
	 *
	 * This is avoided by queueing multiple transfers in advance, so
	 * that the host controller is always kept busy, and will schedule
	 * more transfers on the bus while the callback is running for
	 * transfers which have completed on the bus.
	 */

	return libusb_submit_transfer(xfr);
}

int tx_rate = 1000;	// per sec rate
int tx_lt_cnt = 0;	// last ten count
uint32_t unkId = 0x16;


proc_sample( uint32_t *buf, uint32_t *pcm ) {
//	*buf = le2be( *pcm );
	*buf = *pcm;
}

void fill_audio_data( uint32_t *buf, size_t buf_sz, uint32_t *pcm, struct libusb_transfer *xfr ) {

	int i = 0, y = 0, x = 0, z = 0, ckCnt = 0, offset = 0;

	while ( i < (buf_sz/4) ) {

		buf[i+0] = unkId;


		if ( buf_sz == 3420 && ckCnt == 1 ) {

			for ( x=1; x < (6 * 19); x+=19 ) {
				proc_sample( &buf[i+x], &pcm[z] );
				proc_sample( &buf[i+x+1], &pcm[z]);
				z++;
//				buf[i+x] = pcm[z++];// << 0x16;
//				buf[i+x+1] = pcm[z++];// << 0x16;
			}

			i += x-1;

			xfr->iso_packet_desc[ckCnt].length = 0x01c8;
			unkId += 6;

			ckCnt++;

		} else if ( ckCnt % 2 ) {

			for ( x=1; x < (5 * 19); x+=19 ) {
//				proc_sample();
//				proc_sample( &buf[i+x], &pcm[z++] );
				proc_sample( &buf[i+x], &pcm[z] );
				proc_sample( &buf[i+x+1], &pcm[z]);
				z++;

//				buf[i+x] = pcm[z++];// << 0x16;
//				buf[i+x+1] = pcm[z++];// << 0x16;
			}

			i += x-1;

			xfr->iso_packet_desc[ckCnt].length = 0x017c;
			unkId += 5;

			ckCnt++;

		} else {

			for ( x=1; x < (6 * 19 ); x+=19 ) {
//				proc_sample( &buf[i+x], &pcm[z++] );
				proc_sample( &buf[i+x], &pcm[z] );
				proc_sample( &buf[i+x+1], &pcm[z]);
				z++;

//				buf[i+x] = pcm[z++];// << 0x16;
//				buf[i+x+1] = pcm[z++];// << 0x16;
			}

			i += x-1;

			xfr->iso_packet_desc[ckCnt].length = 0x01c8;
			unkId += 6;

			ckCnt++;
		}
//		printf("new iso %d\n", ckCnt);
	}
}


size_t get_audio_data_from_file( const char *filename, uint32_t **buf )
{
	size_t size = 0;

	FILE *f = fopen(filename, "rb");

	if (f == NULL)
	{
		*buf = NULL;
		return -1; // -1 means file opening fail
	}

	fseek(f, 0, SEEK_END);

	size = ftell(f);

	fseek(f, 0, SEEK_SET);

	*buf = malloc(size+1);

	if (size/sizeof(uint32_t) != fread(*buf, sizeof(uint32_t), size/sizeof(uint32_t), f))
	{
		free(*buf);
		*buf = NULL;
		return -2; // -2 means file reading fail
	}

	fclose(f);
	// (*buf)[size] = 0;
	return size;
}



static int send_iso_out(uint8_t ep)
{

	uint32_t buf[855];
	uint32_t pcm[45];				/* TODO: when back to read() */

	static struct libusb_transfer *xfr;
	int num_iso_pack = 0;

	int buf_len = 0;
	int pcm_len = 0;

	if ( tx_lt_cnt == 9 ) {
		buf_len = 3420;
		pcm_len = 180;
		tx_lt_cnt  = 0;
	} else {
		buf_len = 3344;
		pcm_len = 176;
		tx_lt_cnt++;
	}

	if ( unkId > 0xffff )
		unkId = 0x16;

//	int chunkCount = 0;
//	int i = 0;
//	int y = 0;

	num_iso_pack = 8;

	xfr = libusb_alloc_transfer(num_iso_pack);
	if (!xfr)
		return -ENOMEM;

	libusb_fill_iso_transfer(xfr, devh, ep, (unsigned char *)buf,
		buf_len, num_iso_pack, cb_xfr, NULL, 0);

	xfr->flags = LIBUSB_TRANSFER_FREE_TRANSFER;

	memset((unsigned char *)pcm, 0, pcm_len);
	memset((unsigned char *)buf, 0, buf_len);


	// uint32_t *audioData = NULL;

	// size_t audioDataSize = get_audio_data_from_file( "../1CH_44100_f32le_RIFF.raw", &audioData );

	// printf("coucou\n");


    //
	if ( read( 0, pcm, pcm_len ) == 0 ) {
		printf("*** EOF ***\n");
		do_exit = 1;
	}

/*
	int i = 0;
	while ( i < buf_len/4 ) {
		printf("0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x\n",
			buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++]);
//		i++;
	}

//	return -1;
	exit(1);
*/
//	printf("buf_len : %d\n", buf_len);


	fill_audio_data( buf, buf_len, pcm, xfr );

	gettimeofday(&tv_start, NULL);

	/* NOTE: To reach maximum possible performance the program must
	 * submit *multiple* transfers here, not just one.
	 *
	 * When only one transfer is submitted there is a gap in the bus
	 * schedule from when the transfer completes until a new transfer
	 * is submitted by the callback. This causes some jitter for
	 * isochronous transfers and loss of throughput for bulk transfers.
	 *
	 * This is avoided by queueing multiple transfers in advance, so
	 * that the host controller is always kept busy, and will schedule
	 * more transfers on the bus while the callback is running for
	 * transfers which have completed on the bus.
	 */

	libusb_submit_transfer(xfr);

	printf("coucou2\n");

	return 0;
}

static int send_iso_in(uint8_t ep)
{
	int buf_len = 4064;
	uint8_t buf[4064];
	memset((unsigned char *)buf, 0, buf_len);

	uint32_t pcm[45];				/* TODO: when back to read() */
	int pcm_len = 45;

	static struct libusb_transfer *xfr;
	int num_iso_pack = 8;


	xfr = libusb_alloc_transfer(num_iso_pack);
	if (!xfr)
		return -ENOMEM;


	libusb_fill_iso_transfer(xfr, devh, ep, buf,
		buf_len, num_iso_pack, cb_xfr, NULL, 0);

/*
	xfr->iso_packet_desc[0].length = 0x01b4;
	xfr->iso_packet_desc[1].length = 0x016c;
	xfr->iso_packet_desc[2].length = 0x01b4;
	xfr->iso_packet_desc[3].length = 0x016c;
	xfr->iso_packet_desc[4].length = 0x01b4;
	xfr->iso_packet_desc[5].length = 0x016c;
	xfr->iso_packet_desc[6].length = 0x01b4;
	xfr->iso_packet_desc[7].length = 0x016c;
*/

	xfr->iso_packet_desc[0].length = 0x01fc;
	xfr->iso_packet_desc[1].length = 0x01fc;
	xfr->iso_packet_desc[2].length = 0x01fc;
	xfr->iso_packet_desc[3].length = 0x01fc;
	xfr->iso_packet_desc[4].length = 0x01fc;
	xfr->iso_packet_desc[5].length = 0x01fc;
	xfr->iso_packet_desc[6].length = 0x01fc;
	xfr->iso_packet_desc[7].length = 0x01fc;

	xfr->flags = LIBUSB_TRANSFER_FREE_TRANSFER;

	memset((unsigned char *)pcm, 0, pcm_len);
	memset((unsigned char *)buf, 0, buf_len);


	if ( read( 0, pcm, pcm_len ) == 0 ) {
		printf("*** EOF ***\n");
		do_exit = 1;
	}
/*
	int i = 0;
	while ( i < buf_len/4 ) {
		printf("0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x  0x%04x\n",
			buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++], buf[i++]);
//		i++;
	}

//	return -1;
	exit(1);
*/
//	printf("buf_len : %d\n", buf_len);

	fill_audio_data( buf, buf_len, pcm, xfr );

	gettimeofday(&tv_start, NULL);

	/* NOTE: To reach maximum possible performance the program must
	 * submit *multiple* transfers here, not just one.
	 *
	 * When only one transfer is submitted there is a gap in the bus
	 * schedule from when the transfer completes until a new transfer
	 * is submitted by the callback. This causes some jitter for
	 * isochronous transfers and loss of throughput for bulk transfers.
	 *
	 * This is avoided by queueing multiple transfers in advance, so
	 * that the host controller is always kept busy, and will schedule
	 * more transfers on the bus while the callback is running for
	 * transfers which have completed on the bus.
	 */
	printf("before libusb_submit_transfer()\n");
	libusb_submit_transfer(xfr);
	printf("after  libusb_submit_transfer()\n");

	return 0;
}



static void measure(void)
{
	struct timeval tv_stop;
	unsigned int diff_msec;

	gettimeofday(&tv_stop, NULL);

	diff_msec = (tv_stop.tv_sec - tv_start.tv_sec)*1000;
	diff_msec += (tv_stop.tv_usec - tv_start.tv_usec)/1000;

	printf("\n%lu transfers (total %lu bytes) in %u miliseconds => %lu bytes/sec\n",
		num_xfer, num_bytes, diff_msec, (num_bytes*1000)/diff_msec);
}

static void sig_hdlr(int signum)
{
	switch (signum) {
	case SIGINT:
//		measure();
		do_exit = 1;
		break;
	}
}


int main(int argc, char **argv)
{
/*
	int rc;

	struct sigaction sigact;

	sigact.sa_handler = sig_hdlr;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigaction(SIGINT, &sigact, NULL);

	rc = libusb_init(NULL);
	if (rc < 0) {
		fprintf(stderr, "Error initializing libusb: %s\n", libusb_error_name(rc));
		exit(1);
	}

	devh = libusb_open_device_with_vid_pid(NULL, 0x0424, 0x3fc6);
	if (!devh) {
		fprintf(stderr, "Error finding USB device\n");
		goto out;
	}

	rc = libusb_claim_interface(devh, 0);
	if (rc < 0) {
		fprintf(stderr, "Error claiming interface: %s\n", libusb_error_name(rc));
		goto out;
	}

	libusb_set_interface_alt_setting( devh, rc, 1 );

//	benchmark_out(EP_ISO_OUT);

	while (!do_exit) {
		benchmark_out(EP_ISO_OUT);
		usleep(1000);	// wait 1 ms
//		rc = libusb_handle_events(NULL);
//		if (rc != LIBUSB_SUCCESS)
//			break;
	}

	// Measurement has already been done by the signal handler.

	libusb_release_interface(devh, 0);
out:
	if (devh)
		libusb_close(devh);
	libusb_exit(NULL);
	return rc;
}
*/





















int loop_cnt = 0;
uint16_t val = 0x200;
int rc = 0;

// int rme_init_iface( libusb_device_handle *dev ) {

	// devh = dev;

	printf("%s\n", "before" );

	ctrl_setup ctrl;

	rc = libusb_init(NULL);

	if (rc < 0) {
		fprintf(stderr, "Error initializing libusb: %s\n", libusb_error_name(rc));
		exit(1);
	}

	// libusb_set_debug(NULL, LIBUSB_LOG_LEVEL_WARNING);


	devh = libusb_open_device_with_vid_pid(NULL, 0x0424, 0x3fc6);

	printf("%s\n", "after");

	if (!devh) {
		fprintf(stderr, "Error finding USB device\n");
		goto out;
	}




	// int rc = 0;


//	goto SEND_AUDIO;

	/*
		First we set the usb interface to 1 (from wireshark)
	*/

//	rc = libusb_init(NULL);
//	if (rc < 0) {
//		fprintf(stderr, "Error initializing libusb: %s\n", libusb_error_name(rc));
//		exit(1);
//	}

//	devh = libusb_open_device_with_vid_pid(NULL, 0x0424, 0x3fc6);
//	if (!devh) {
//		fprintf(stderr, "Error finding USB device\n");
//		goto out;
//	}
	printf("claiming\n");

	rc = libusb_claim_interface(devh, 0);

	if (rc < 0) {
		fprintf(stderr, "Error claiming interface: %s\n", libusb_error_name(rc));
		goto out;
	}

	libusb_set_interface_alt_setting( devh, rc, 1 );

	goto SEND_AUDIO;

//	printf("Setting interface to 1\n");

//	ctrl.bmRequestType = 0x01;
//	ctrl.bRequest  = 0x0b;
//	ctrl.wValue  = 0x0001;
//	ctrl.wIndex  = 0x0000;
//	ctrl.wLength = 0x0000;

//	send_ctrl_setup( devh, &ctrl, NULL );


	/*
		Get Hardware Revision (Firmware Version)
	*/

	uint32_t rev = 0;

	hwGetRevision( devh, &rev );
	printf("Firmware Version : %d (0x%02x)\n", rev, rev);


	/*
		call hwInitHarware()
	*/

	printf("hwInitHardware()\n");

	ctrl.bmRequestType = 0x40;
	ctrl.bRequest  = 0x16;
	ctrl.wValue  = 0x0001;
	ctrl.wIndex  = 0x0000;
	ctrl.wLength = 0x0000;

	uint16_t i = 0;

	while ( i < 18 ) {

		ctrl.wIndex = i;
		send_ctrl_setup( devh, &ctrl, NULL );

		ctrl.wIndex = i + 0x20;
		send_ctrl_setup( devh, &ctrl, NULL );

		i++;
	}

	ctrl.bRequest = 0x10;
	ctrl.wValue = 0x0800;
	ctrl.wIndex = 0xb800;
	send_ctrl_setup( devh, &ctrl, NULL );

	ctrl.bRequest = 0x20;
	ctrl.wValue = 0x0001;
	ctrl.wIndex = 0x0000;
	send_ctrl_setup( devh, &ctrl, NULL );



	/*
		call hwSetSampleRate()
		seems to always init with 44100 Hz :

		0x00007ec3	mov	rdi, qword [ds:r15+0x120]		; argument #1 for method
		0x00007eca	movzx	edx, word [ds:r15+0x128]		; argument #3 for method
		0x00007ed2	mov	esi, 0xac44				; argument #2 for method
		0x00007ed7	call	__Z15hwSetSampleRateP11IOUSBDevicejt
	*/

	hwSetSampleRate( devh, 44100 );


	/*
		do some stuff seen in wireshark.
		This was not found in original drivers yet..
	*/

	printf("\n");

	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x000a, 0x0000, 0, NULL );	// set MIC_1 GAIN to 10
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x000a, 0x0001, 0, NULL );	// set MIC_2 GAIN to 10
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0002, 0, NULL );	// set LIN_3 GAIN to  0
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0003, 0, NULL );	// set LIN_4 GAIN to  0

	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0004, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0005, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0006, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0007, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0008, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0009, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000a, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000b, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000c, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000d, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000e, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x000f, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0010, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0011, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0012, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0013, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0014, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x002e, 0x0015, 0, NULL );

//	usleep(100000);

	// send bulk_in	> 11 EP 0x8b
	// GET_DESCRIPTORS

	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0014, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0015, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0012, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0013, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0010, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0011, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x000e, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x000f, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x000c, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x000d, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0008, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0009, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0006, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0007, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0004, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0006, 0x0005, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0027, 0x000a, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0027, 0x000b, 0, NULL );

	/* set true gain values for inputs 1,2,3,4 */
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0000, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0001, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0002, 0, NULL );
	send_ctrl_setup_alt( devh, 0x40, 0x1a, 0x0000, 0x0003, 0, NULL );

	// BULK_IN > 6 EP 0x8§
	// MIDI Stuff > 7 EP 0x07

	// set mixer (routes)

//		printf(" %d ms\n", clock());
/***********************************************************************************************************
					    P L A Y    A U D I O
***********************************************************************************************************/

SEND_AUDIO:


	hwSetSampleRate( devh, 44100 );
	hwMuteChannels( devh, 1 );	// unmute channels



	struct sigaction sigact;

	sigact.sa_handler = sig_hdlr;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigaction(SIGINT, &sigact, NULL);


	while (!do_exit) {

		struct timeval timeout;
		timeout.tv_sec = 0;
		timeout.tv_usec = 0;

		// rc = send_iso_in(0x82);
		rc = send_iso_out(0x01);

		// libusb_handle_events_locked( NULL, NULL );

		// rc = send_iso_out(0x82);

		struct timeval tv_mes;
		gettimeofday(&tv_mes, NULL);

		timeout.tv_usec = 1000 - (tv_mes.tv_usec - tv_start.tv_usec);

//		printf("SET TIME_OUT : %d\n", timeout.tv_usec);

		rc = libusb_handle_events_timeout_completed(NULL, &timeout, NULL);

		if (rc != LIBUSB_SUCCESS) {
			printf("LIBUSB ERROR (%d) : %s\n", rc, libusb_error_name( rc ));
			break;
		}

		loop_cnt++;

		if ( loop_cnt == 3000 ) {
//			printf("set level to (0x%04x) %d\n", val, val);
//			send_ctrl_setup_alt( devh, 0x40, 0x1a, val, 0x000a, 0, NULL );
//			send_ctrl_setup_alt( devh, 0x40, 0x1a, val, 0x000b, 0, NULL );
//			send_ctrl_setup_alt( devh, 0x40, 0x12, val, 0x03e6, 0, NULL );
//			send_ctrl_setup_alt( devh, 0x40, 0x12, val, 0x03e7, 0, NULL );

//			val += 5;
//			val -= 50;
//			loop_cnt = 0;
//			hwMuteChannels( devh, 0 );
		} else if ( loop_cnt > 6000 ) {
//			hwMuteChannels( devh, 1 );
			loop_cnt = 0;
		}
	}

	rc = libusb_handle_events( NULL );

	if (rc != LIBUSB_SUCCESS) {
		printf("LIBUSB ERROR (%d) : %s\n", rc, libusb_error_name( rc ));
	}

	hwMuteChannels( devh, 0 );

//	libusb_release_interface(devh, 0);

out:
//	libusb_release_interface(devh, 0);

	if (devh)
		libusb_close(devh);

	libusb_exit(NULL);
	return rc;




	//printf("xxx\n");
	return 0;
}
