
#include <stdint.h>
#include <stdio.h>

void main( void ) {

	uint16_t wIndex = 0;
	uint8_t  is_output = 0;
	uint16_t wValue = 1;
	uint16_t productId = 0x3fc6;

/*
	================ B E G I N N I N G   O F   P R O C E D U R E ================



	hwWriteLedAndPga ( IOUSBDevice*, 	rdi
			   unsigned int, 	rsi		wIndex ?
			   bool, 		rdx		is_output ?
			   unsigned int, 	rcx		wValue ?
			   unsigned short	r8		productId
			 )

	0x000019d2	push	rbp
	0x000019d3	mov	rbp, rsp
	0x000019d6	sub	rsp, 0x20
*/

/*
	0x000019da	test	dl, dl
	0x000019dc	je	0x1a13
*/
	if ( is_output != 0 ) {
/*
		0x000019de	cmp	r8w, 0x3fc7
		0x000019e4	jne	0x19ee
*/
		if ( productId == 0x3fc7 ) {
/*
			0x000019e6	add	esi, 0x2
			0x000019e9	jmp	0x1a77
*/
			wIndex += 0x2;

		} else {
/*
			0x000019ee	mov	eax, 0x3f
			0x000019f3	sub	eax, ecx
			0x000019f5	cmp	r8w, 0x3fc3
			0x000019fb	setne	dl
			0x000019fe	cmp	r8w, 0x3fc0
			0x00001a04	setne	r8b
			0x00001a08	test	dl, r8b
			0x00001a0b	cmovne	ecx, eax
			0x00001a0e	add	esi, 0x4
			0x00001a11	jmp	0x1a77
*/

//			eax = 0x3f - ecx;

//			if ( productId != 0x3fc3 )	dl = 1;
//			else				dl = 0;

//			if ( productId != 0x3fc0 )	r8w = 1;
//			else				r8w = 0;

//			if ( (dl & r8) == 0 )
//				ecx = eax;

			if ( productId != 0x3fc0 && productId != 0x3fc3 )
				wValue = 0x3f - wValue;

			wIndex += 0x4;
		}

	} else {

/*
		0x00001a13	test	ecx, ecx
		0x00001a15	je	0x1a31

		0x00001a17	cmp	esi, 0x1
		0x00001a1a	ja	0x1a31

		0x00001a1c	cmp	r8w, 0x3fc6
		0x00001a22	je	0x1a2c

		0x00001a24	cmp	r8w, 0x3fcf
		0x00001a2a	jne	0x1a31
*/
		if ( wValue != 0 && wIndex <= 0x1 && (productId == 0x3fc6 || productId == 0x3fcf)) {
/*
			0x00001a2c	add	ecx, 0x9
			0x00001a2f	jmp	0x1a77
*/
			wValue += 0x9;

		} else {

/*
			0x00001a31	cmp	r8w, 0x3fc3
			0x00001a37	sete	al
			0x00001a3a	cmp	r8w, 0x3fc0
			0x00001a40	sete	dl
			0x00001a43	or	dl, al
*/
//			if ( productId == 0x3fc3 )	al = 1;
//			else				al = 0;

//			if ( productId == 0x3fc0 )	dl = 1;
//			else				dl = 0;

//			dl |= al;

/*
			0x00001a45	cmp	dl, 0x1
			0x00001a48	jne	0x1a77
			0x00001a4a	cmp	esi, 0x2
			0x00001a4d	jae	0x1a77
*/

//			if ( (dl == 0x1) || (wIndex < 0x1a77) ) {
			if ( (productId == 0x3fc3 || productId == 0x3fc0) || (wIndex < 0x2)) {
/*
				0x00001a4f	cmp	ecx, 0x3d
				0x00001a52	jb	0x1a62
*/
				if ( wValue >= 0x3d ) {
/*
					0x00001a54	shl	ecx, 0x5
					0x00001a57	add	ecx, 0xfffff880
					0x00001a5d	or	ecx, 0x14
					0x00001a60	jmp	0x1a77
*/
					wValue <<= 0x5;
					wValue += 0xfffff880;
					wValue |= 0x14;

				} else {
/*
					0x00001a62	mov	edx, 0xaaaaaaab
					0x00001a67	mov	eax, ecx
					0x00001a69	mul	edx
					0x00001a6b	shr	edx, 0x1
					0x00001a6d	lea	eax, qword [ds:rdx+rdx*2]
					0x00001a70	sub	ecx, eax
					0x00001a72	shl	ecx, 0x5
					0x00001a75	or	ecx, edx
*/
					long edx = 0xaaaaaaab;
					int eax = wValue;
					edx = (eax * edx) >> 32 & 0xffffffff;
					edx >>= 0x1;
					eax = edx*3;
					wValue -= eax;
					wValue <<= 0x5;
					wValue |= edx;
				}
			}
		}
	}

/*
	0x00001a77	mov	byte [ss:rbp+var_18], 0x40	; bmRequestType
	0x00001a7b	mov	byte [ss:rbp+var_17], 0x1a	; bRequest
	0x00001a7f	mov	word [ss:rbp+var_16], cx	; wValue
	0x00001a83	mov	word [ss:rbp+var_14], si	; wIndex
	0x00001a87	mov	word [ss:rbp+var_12], 0x0	; wLength
	0x00001a8d	mov	qword [ss:rbp+var_10], 0x0	; ????
	0x00001a95	mov	rax, qword [ds:rdi]
	0x00001a98	lea	rsi, qword [ss:rbp+var_18]
	0x00001a9c	xor	edx, edx
	0x00001a9e	call	qword [ds:rax+0x938]
*/
	printf("wValue : 0x%04x\n", wValue);
	printf("wIndex : 0x%04x\n", wIndex);


/*
	0x00001aa4	add	rsp, 0x20
	0x00001aa8	pop	rbp
	0x00001aa9	ret	
			; endp
*/
}
