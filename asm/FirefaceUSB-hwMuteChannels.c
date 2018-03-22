
#include <stdint.h>
#include <stdio.h>

#include "../libusb_test/usb.h"

int hwMuteChannels ( libusb_device_handle *dev, /*uint32_t value, uint16_t productId,*/ uint8_t unmute ) {

	uint32_t value = 0x3ffff;	// for 0x3fcd : value = 0x3fffffff
	// uint8_t  do_mute = 0;
	uint16_t productId = 0x3fc6;

	ctrl_setup ctrl;

	// uint8_t  bmRequestType = 0;
	// uint8_t  bRequest = 0;
	// uint16_t wValue   = 0;
	// uint16_t wIndex   = 0;
	// uint16_t wLength  = 0;

/*
================ B E G I N N I N G   O F   P R O C E D U R E ================



	hwMuteChannels (
						IOUSBDevice*, 		rdi
						unsigned int, 		rsi		value
						bool, 				rdx		do_mute (0x00) / unmute (0x01)
						unsigned short		rcx		productId
				   );

	0x00001923	push	rbp
	0x00001924	mov	rbp, rsp
	0x00001927	sub	rsp, 0x20
*/

/*
	0x0000192b	mov	ax, cx		; eax = productId
	0x0000192e	cmp	ax, 0x3fc2
	0x00001932	je	0x19ca
*/
	if ( productId == 0x3fc2 )
		return 0;
/*
	0x00001938	add	ecx, 0xffffc036
	0x0000193e	cmp	cx, 0x3
	0x00001942	jb	0x19ca
*/
	if ( (uint16_t)((productId + 0xffffc036) & 0xffff) < 0x03 )
		return 0;
/*
	0x00001948	mov	ecx, eax
	0x0000194a	add	ecx, 0xffffc060
	0x00001950	cmp	cx, 0x24
	0x00001954	ja	0x1969
*/
	if ( (uint16_t)((productId + 0xffffc060) & 0xffff) <= 0x24 ) {

/*
		0x00001956	movzx	ecx, cx
		0x00001959	mov	r8, 0x1a00000001
		0x00001963	bt	r8, rcx
		0x00001967	jb	0x19ca
*/
		if ( (0x1a00000001 >> (uint16_t)((productId + 0xffffc060) & 0xffff)) & 0x01 )
			return 0;

	}
/*
	0x00001969	mov	ecx, eax
	0x0000196b	add	ecx, 0xffffc038
	0x00001971	cmp	cx, 0x2
	0x00001975	jb	0x197d
	0x00001977	cmp	ax, 0x3fcd
	0x0000197b	jne	0x1989
*/
	if ( (uint16_t)((productId + 0xffffc038) & 0xffff) < 0x02 ) {
/*
		0x0000197d	lea	eax, qword [ds:0x0+rsi*4]
		0x00001984	shr	esi, 0xe
		0x00001987	jmp	0x1991
*/
		ctrl.wIndex = value * 4;
		value >>= 0xe;

	} else if ( productId != 0x3fcd ) {
/*
		0x00001989	mov	eax, esi
		0x0000198b	shl	eax, 0xe
		0x0000198e	shr	esi, 0x2
*/
		ctrl.wIndex = value;
		ctrl.wIndex <<= 0xe;
		value >>= 0x2;

	} else {
/*
		0x0000197d	lea	eax, qword [ds:0x0+rsi*4]
		0x00001984	shr	esi, 0xe
		0x00001987	jmp	0x1991
*/
		ctrl.wIndex = value * 4;
		value >>= 0xe;
	}
/*
	0x00001991	movzx	eax, ax
	0x00001994	mov	byte [ss:rbp+var_18], 0x40
	0x00001998	test	dl, dl
	0x0000199a	setne	cl
	0x0000199d	add	cl, 0x13
	0x000019a0	mov	byte [ss:rbp+var_17], cl
	0x000019a3	mov	word [ss:rbp+var_16], si
	0x000019a7	mov	word [ss:rbp+var_14], ax
	0x000019ab	mov	word [ss:rbp+var_12], 0x0
	0x000019b1	mov	qword [ss:rbp+var_10], 0x0
	0x000019b9	mov	rax, qword [ds:rdi]
	0x000019bc	lea	rsi, qword [ss:rbp+var_18]
	0x000019c0	xor	edx, edx
	0x000019c2	call	qword [ds:rax+0x938]
	0x000019c8	jmp	0x19cc
*/

	ctrl.bmRequestType = 0x40;

	/*
		in the 0x3fc6 case :

			wValue is always 0xffff
	*/

/*
	if ( unmute == 0 )	bRequest = 0x13;	// do_mute
	else				bRequest = 0x14;	// do_unmute
*/

	ctrl.bRequest = ( unmute ) ? 0x14 : 0x13; /* 0x13 : mute  |  0x14 : unmute */
	ctrl.wValue = value;
	ctrl.wLength = 0;

	// printf("0x%02x 0x%02x 0x%04x 0x%04x\n",
	// 	bmRequestType,
	// 	bRequest,
	// 	wValue,
	// 	wIndex);

	send_ctrl_setup( dev, &ctrl, NULL );

/*
	0x000019ca	xor	eax, eax

	0x000019cc	add	rsp, 0x20;
	0x000019d0	pop	rbp
	0x000019d1	ret
			; endp
*/
	return 0;

}
