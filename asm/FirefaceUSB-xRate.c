#include <stdint.h>

// SAME AS DEV

/*
 *	For any given real rate, xRate() returns the closest exact rate.
 */

uint32_t xRate( uint32_t edi )
{

/*
	================ B E G I N N I N G   O F   P R O C E D U R E ================


	xRate(
			unsigned int		rdi
	     );


	0x00001aaa	push	rbp
	0x00001aab	mov	rbp, rsp
*/

/*
	0x00001aae	cmp	edi, 0x94a1
	0x00001ab4	ja	0x1abd
*/
	if ( edi <= 0x94a1 ) { /* 38049 */
/*
		0x00001ab6	mov	eax, 0x7d00
		0x00001abb	jmp	0x1b2a
*/
		return 0x7d00;		/* 32000 Hz */
	}
/*
	0x00001abd	cmp	edi, 0xb3b7
	0x00001ac3	ja	0x1acc
*/
	if ( edi <= 0xb3b7 ) { /* prev 0x1acc */
/*
		0x00001ac5	mov	eax, 0xac44
		0x00001aca	jmp	0x1b2a
*/
		return 0xac44;		/* 44100 Hz */
	}
/*
	0x00001acc	cmp	edi, 0xdea7
	0x00001ad2	ja	0x1adb
*/
	if ( edi <= 0xdea7 ) {
/*
		0x00001ad4	mov	eax, 0xbb80
		0x00001ad9	jmp	0x1b2a
*/
		return 0xbb80;		/* 48000 Hz*/
	}
/*
	0x00001adb	cmp	edi, 0x12943
	0x00001ae1	ja	0x1aea
*/
	if ( edi <= 0x12943 ) {
/*
		0x00001ae3	mov	eax, 0xfa00
		0x00001ae8	jmp	0x1b2a
*/
		return 0xfa00;		/* 64000 Hz */
	}
/*
	0x00001aea	cmp	edi, 0x167c3
	0x00001af0	ja	0x1af9
*/
	if ( edi <= 0x167c3 ) {
/*
		0x00001af2	mov	eax, 0x15888
		0x00001af7	jmp	0x1b2a
*/
		return 0x15888;		/* 88200 Hz */
	}
/*
	0x00001af9	cmp	edi, 0x1bd4f
	0x00001aff	ja	0x1b08
*/
	if ( edi <= 0x1bd4f ) {
/*
		0x00001b01	mov	eax, 0x17700
		0x00001b06	jmp	0x1b2a
*/
		return 0x17700;		/* 96000 Hz */
	}
/*
	0x00001b08	cmp	edi, 0x25287
	0x00001b0e	ja	0x1b17
*/
	if ( edi <= 0x25287 ) {
/*
		0x00001b10	mov	eax, 0x1f400
		0x00001b15	jmp	0x1b2a
*/
		return 0x1f400;		/* 128000 Hz */
	}
/*
	0x00001b17	cmp	edi, 0x2cf88
	0x00001b1d	mov	ecx, 0x2b110
	0x00001b22	mov	eax, 0x2ee00
	0x00001b27	cmovb	eax, ecx
*/
	if ( edi < 0x2cf88 )	return 0x2b110;		/* 176400 Hz */
	else					return 0x2ee00;		/* 192000 Hz */
/*
	0x00001b2a	pop	rbp
	0x00001b2b	ret
			; endp
*/

}
