
#include <stdio.h>
#include <stdint.h>

#include "../libusb_test/usb.h"
#include "../libusb_test/FirefaceUSB.h"


int hwSetSampleRate ( libusb_device_handle *dev, /*uint32_t productId,*/ uint32_t rateValue )
{

	uint32_t productId = 0x3fc6;

	// uint8_t bmRequestType = 0;
	// uint8_t bRequest = 0;
	// uint16_t wValue = 0;
	// uint16_t wIndex = 0;
	// uint16_t wLength = 0;

/*

	called by :
		de_RME_driver_USBAudioEngine::Timer()
		de_RME_driver_USBAudioEngine::performFormatChange()
		de_RME_driver_USBAudioEngine::initHardware()
		de_RME_driver_USBAudioEngine::performAudioEngineStart()


	hwSetSampleRate (
						IOUSBDevice*,		rdi	IOUSBDevice*
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
*/

/*
	0x00001b3d	mov	ebx, edx		; ebx = productId
	0x00001b3f	mov	r14d, esi		; r14 = rateValue
	0x00001b42	mov	r15, rdi
	0x00001b45	mov	edi, r14d		; argument #1 (rateValue) for method
	0x00001b48	call	xRate()		; eax = perfect Rate Value
	0x00001b4d	cmp	eax, 0x2b10f
	0x00001b52	jg	0x1b9a
*/
	uint32_t rate = xRate( rateValue );

	uint32_t flag = 0;			// si, esi
	uint32_t p2_wValue = 0;		// r12d
	uint16_t p2_wIndex = 0;		// r13w

	if ( rate > 0x2b10f ) {	/* 176399 */
/*
		0x00001b9a	cmp	eax, 0x2b110
		0x00001b9f	je	0x1b8e
*/
		if ( rate == 0x2b110 ) { /* 176400 */
/*
			0x00001b8e	mov	si, 0x1
			0x00001b92	mov	r12d, 0x10
			0x00001b98	jmp	0x1bab		; end of else / if
*/
			flag = 0x1;
			p2_wValue = 0x10;

		} else {
/*
			0x00001ba1	mov	si, 0x2
			0x00001ba5	mov	r12d, 0x20
										; end of else / if
*/
			flag = 0x2;
			p2_wValue = 0x20;
		}
/*
	0x00001b54	cmp	eax, 0x1f3ff
	0x00001b59	jg	0x1b79
*/
	} else if ( rate > 0x1f3ff ) { /* 127999 */
/*
		0x00001b79	cmp	eax, 0x1f400
		0x00001b7e	jne	0x1ba1
*/
		if ( rate == 128000 ) {
/*
			0x00001b80	xor	esi, esi
			0x00001b82	xor	r12d, r12d
			0x00001b85	jmp	0x1bab		; end of else / if
*/
			flag = 0;
			p2_wValue = 0;

		} else {
/*
			0x00001ba1	mov	si, 0x2
			0x00001ba5	mov	r12d, 0x20
										; end of else / if
*/
			flag = 0x2;
			p2_wValue = 0x20;
		}
/*
	0x00001b5b	cmp	eax, 0x15887
	0x00001b60	jg	0x1b87
*/
	} else if ( rate > 0x15887 ) { /* 88199 */
/*
		0x00001b87	cmp	eax, 0x15888
		0x00001b8c	jne	0x1ba1
*/
		if ( rate == 0x15888 ) { /* 88200 */
/*
			0x00001b8e	mov	si, 0x1
			0x00001b92	mov	r12d, 0x10
			0x00001b98	jmp	0x1bab		; end of else / if
*/
			flag = 0x1;
			p2_wValue = 0x10;

		} else {
/*
			0x00001ba1	mov	si, 0x2
			0x00001ba5	mov	r12d, 0x20
										; end of else / if
*/
			flag = 0x2;
			p2_wValue = 0x20;
		}
/*
	0x00001b62	cmp	eax, 0x7d00
	0x00001b67	je	0x1b80
*/
	} else if ( rate == 0x7d00 ) { /* 32000 */
/*
		0x00001b80	xor	esi, esi
		0x00001b82	xor	r12d, r12d
		0x00001b85	jmp	0x1bab			; end of else / if
*/
//		uint32_t esi = 0;

//		esi = 0;
		flag = 0;
		p2_wValue = 0;
/*
	0x00001b69	cmp	eax, 0xac44
	0x00001b6e	je	0x1b8e
*/
	} else if ( rate == 0xac44 ) { /* 44100 */
/*
		0x00001b8e	mov	si, 0x1
		0x00001b92	mov	r12d, 0x10
		0x00001b98	jmp	0x1bab			; end of else / if
*/
		flag = 0x1;
		p2_wValue = 0x10;
/*
	0x00001b70	cmp	eax, 0xfa00
	0x00001b75	je	0x1b80
*/
	} else if ( rate == 0xfa00 ) { /* 64000 */
/*
		0x00001b80	xor	esi, esi
		0x00001b82	xor	r12d, r12d
		0x00001b85	jmp	0x1bab			; end of else / if
*/
//		uint32_t esi = 0;

//		esi = 0;
		flag = 0;
		p2_wValue = 0;
/*
	0x00001b77	jmp	0x1ba1
*/
	} else {
/*
		0x00001ba1	mov	si, 0x2
		0x00001ba5	mov	r12d, 0x20
										; end of else / if
*/
		flag = 0x2;
		p2_wValue = 0x20;
	}




/*
	0x00001bab	mov	eax, ebx			; eax = productId
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
			0x00001be9	cmp	r14d, 0x1bd50		; r14d = rateValue
			0x00001bf0	jb	0x1bf8
*/
			p2_wValue >>= 0x1;

			if ( rateValue >= 0x1bd50 ) { /* 114000 */
/*
				0x00001bf2	or	r12d, 0x40
				0x00001bf6	jmp	0x1c09

				0x00001c09	mov	r13w, 0x78
											; end of else / if
*/
				p2_wValue |= 0x40;
				p2_wIndex  = 0x78;

			} else {
/*
				0x00001bf8	mov	eax, r12d
				0x00001bfb	or	eax, 0x20
				0x00001bfe	cmp	r14d, 0xdea7
				0x00001c05	cmova	r12d, eax

				0x00001c09	mov	r13w, 0x78
											; end of else / if
*/
				if ( rateValue > 0xdea7 ) { /* 56999 */
					p2_wValue |= 0x20;
				}

				p2_wIndex = 0x78;
			}
/*
		0x00001bbf	mov	eax, ebx		; eax = productId
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
			/* TODO: That part was not tested yet (false for Fireface UC 0x3fc6) */

			if ( ((0x1a00000001 >> (uint16_t)((productId + 0xffffc060) & 0xffff)) & 0x1) == 0x0 ) {
/*
				0x00001bdf	mov	r13w, 0x30
				0x00001be4	jmp	0x1c0e			; end of else / if
*/
				p2_wIndex = 0x30;

			} else {
/*
				0x00001be6	shr	r12d, 0x1
				0x00001be9	cmp	r14d, 0x1bd50
				0x00001bf0	jb	0x1bf8
*/
				p2_wValue >>= 0x1;

				if ( rateValue >= 0x1bd50 ) { /* 114000 */
/*
					0x00001bf2	or	r12d, 0x40
					0x00001bf6	jmp	0x1c09

					0x00001c09	mov	r13w, 0x78
												; end of else / if
*/
					p2_wValue |= 0x40;
					p2_wIndex  = 0x78;

				} else {
/*
					0x00001bf8	mov	eax, r12d
					0x00001bfb	or	eax, 0x20
					0x00001bfe	cmp	r14d, 0xdea7
					0x00001c05	cmova	r12d, eax

					0x00001c09	mov	r13w, 0x78
												; end of else / if
*/
					if ( rateValue > 0xdea7 ) { /* 56999 */
						p2_wValue |= 0x20;
					}

					p2_wIndex = 0x78;
				}

			}

		} else {					/* 0x3fc6 TRUE */
/*
			0x00001bdf	mov	r13w, 0x30
			0x00001be4	jmp	0x1c0e			; end of else / if
*/
			p2_wIndex = 0x30;
		}

	} else {
/*
		0x00001be6	shr	r12d, 0x1
		0x00001be9	cmp	r14d, 0x1bd50
		0x00001bf0	jb	0x1bf8
*/
		p2_wValue >>= 0x1;

		if ( rateValue >= 0x1bd50 ) { /* 114000 */
/*
			0x00001bf2	or	r12d, 0x40
			0x00001bf6	jmp	0x1c09

			0x00001c09	mov	r13w, 0x78
											; end of else / if
*/
			p2_wValue |= 0x40;
			p2_wIndex  = 0x78;

		} else {
/*
			0x00001bf8	mov	eax, r12d
			0x00001bfb	or	eax, 0x20
			0x00001bfe	cmp	r14d, 0xdea7
			0x00001c05	cmova	r12d, eax

			0x00001c09	mov	r13w, 0x78
											; end of else / if
*/
			if ( rateValue > 0xdea7 ) { /* 56999 */
				p2_wValue |= 0x20;
			}

			p2_wIndex = 0x78;
		}
	}

/*
	0x00001c0e	mov	eax, ebx		; eax = ebx = productId
	0x00001c10	add	eax, 0xffffc03f
	0x00001c15	cmp	ax, 0x1
	0x00001c19	seta	al
*/

//	uint8_t al = 0;
//	uint8_t cl = 0;

//	if ( (uint16_t)((productId + 0xffffc03f) & 0xffff) > 0x1 )	/* 0x3fc6 TRUE */
//		al = 0x01;
//	else
//		al = 0x00;
/*
	0x00001c1c	cmp	bx, 0x3fc4
	0x00001c21	setne	cl
*/
//	if ( productId != 0x3fc4 )			/* 0x3fc6 TRUE */
//		cl = 0x01;
//	else
//		cl = 0x00;
/*
	0x00001c24	test	cl, al
	0x00001c26	mov	rcx, 0x5f5e10000000
	0x00001c30	mov	rax, 0x773594000000
	0x00001c3a	cmovne	rax, rcx
*/
//	uint64_t rax = 0;
	uint64_t p1_wIwV = 0;	// rax

//	if ( (cl & al) != 0 )
//		rax = 0x5f5e10000000;
//	else					/* 0x3fc6 TRUE */
//		rax = 0x773594000000;

	if ( ((uint16_t)((productId + 0xffffc03f) & 0xffff) > 0x1) && ( productId != 0x3fc4 ) )
		p1_wIwV = 0x5f5e10000000;
	else
		p1_wIwV = 0x773594000000;


/*
	0x00001c3e	mov	ecx, r14d
	0x00001c41	xor	edx, edx		; edx = 0
	0x00001c43	div	rcx			; eax = 0x5f5e10000000 / rate
							; ex_32000 : 0xc3500000
							; ex_44100 : 0x8db92ddc
							; ex_64000 : 0x61a80000
*/
	p1_wIwV = p1_wIwV / rateValue;
/*
	0x00001c46	cmp	r14d, 0x1bd51
	0x00001c4d	jb	0x1c55
*/
	if ( rateValue >= 0x1bd51 ) { /* 114001 */
/*
		0x00001c4f	shl	rax, 0x2
		0x00001c53	jmp	0x1c62
*/
		p1_wIwV <<= 0x02;

/*
	0x00001c55	cmp	r14d, 0xdea8
	0x00001c5c	seta	cl
	0x00001c5f	shl	rax, cl
*/

	} else if ( rateValue > 0xdea8 ) { /* 57000 */

		p1_wIwV <<= 0x1;

//		if ( rval > 0xdea8 )
//			cl = 0x01;
//		else
//			cl = 0x00;

//		rax <<= cl;
	}

/*
	0x00001c62	mov	byte [ss:rbp+var_58], 0x40	; bmRequestType
	0x00001c66	mov	byte [ss:rbp+var_57], 0x1b	; bRequest
	0x00001c6a	mov	ecx, eax
	0x00001c6c	shr	ecx, 0x10
	0x00001c6f	mov	word [ss:rbp+var_56], cx	; wValue
	0x00001c73	and	eax, 0xff00
	0x00001c78	or	eax, esi
	0x00001c7a	mov	word [ss:rbp+var_54], ax	; wIndex
	0x00001c7e	mov	word [ss:rbp+var_52], 0x0	; wLength
	0x00001c84	mov	qword [ss:rbp+var_50], 0x0	; wLenDone
	0x00001c8c	mov	rax, qword [ds:r15]		; ???
	0x00001c8f	lea	rsi, qword [ss:rbp+var_58]	; arg 2 -> ptr to ctrl_setup
	0x00001c93	mov	rdi, r15			; arg_1 -> IOUSBDevice*
	0x00001c96	xor	edx, edx			; arg_3 -> 0 / NULL
	0x00001c98	call	qword [ds:rax+0x938]		; send
*/

	// bmRequestType = 0x40;
	// bRequest = 0x1b;
	// wValue = (uint16_t)((p1_wIwV & 0xffffffff) >> 0x10);
	// wIndex = (uint16_t)(((p1_wIwV & 0xffffffff) & 0xff00) | flag);
	// wLength = 0;

	// printf("TX1 : 0x%02x 0x%02x (%d) 0x%04x 0x%04x 0x%x\n",
	// 	bmRequestType, bRequest, bRequest, wValue, wIndex, wLength);

	ctrl_setup ctrl;

	ctrl.bmRequestType = 0x40;
	ctrl.bRequest = 0x1b;
	ctrl.wValue = (uint16_t)(( p1_wIwV & 0xffffffff) >> 0x10);
	ctrl.wIndex = (uint16_t)(((p1_wIwV & 0xffffffff) & 0xff00) | flag);
	ctrl.wLength = 0;

	send_ctrl_setup( dev, &ctrl, NULL );

/*
	0x00001c9e	mov	byte [ss:rbp+var_40], 0x40	; bmRequestType
	0x00001ca2	mov	byte [ss:rbp+var_3F], 0x10	; bRequest
	0x00001ca6	mov	word [ss:rbp+var_3E], r12w	; wValue
	0x00001cab	mov	word [ss:rbp+var_3C], r13w	; wIndex
	0x00001cb0	mov	word [ss:rbp+var_3A], 0x0	; wLength
	0x00001cb6	mov	qword [ss:rbp+var_38], 0x0	; wLenDone
	0x00001cbe	mov	rax, qword [ds:r15]		; ???
	0x00001cc1	lea	rsi, qword [ss:rbp+var_40]	; arg_2 -> ptr to ctrl_setup
	0x00001cc5	mov	rdi, r15			; arg_1 -> IOUSBDevice*
	0x00001cc8	xor	edx, edx			; arg_3 -> 0 / NULL
	0x00001cca	call	qword [ds:rax+0x938]		; send
*/

	// bmRequestType = 0x40;
	// bRequest = 0x10;
	// wValue = (uint16_t)(p2_wValue);
	// wIndex = p2_wIndex;
	// wLength = 0;
    //
	// printf("TX2 : 0x%02x 0x%02x (%d) 0x%04x 0x%04x 0x%x\n",
	// 	bmRequestType, bRequest, bRequest, wValue, wIndex, wLength);


	ctrl.bmRequestType = 0x40;
	ctrl.bRequest = 0x10;
	ctrl.wValue = (uint16_t)(p2_wValue);
	ctrl.wIndex = p2_wIndex;
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

}
