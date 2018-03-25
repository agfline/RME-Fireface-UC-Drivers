
#include <stdio.h>
#include <stdint.h>

#include "../libusb_test/usb.h"


uint32_t hwGetRate( libusb_device_handle *dev, /*uint16_t productId,*/ uint8_t /*dx*/ unknownArg )
{

	uint16_t productId = 0x3fc6;

	int rc = 0;
	uint32_t eax = 0;
	uint32_t ecx = 0;


/*
================ B E G I N N I N G   O F   P R O C E D U R E ================



	hwGetRate ( IOUSBDevice*    rdi,
		    unsigned short      rsi,		productId
		    uint8_t             rdx,		unknownArg (bool ?)
		  )

	0x00001100	push	rbp
	0x00001101	mov	rbp, rsp
	0x00001104	push	r15
	0x00001106	push	r14
	0x00001108	push	rbx
	0x00001109	sub	rsp, 0x68
*/



/*
	...
*/


/*
	...
*/


/*
	...
*/









/**********************************************************************************************************
***********************************************************************************************************

					 F i r e f a c e   U C

***********************************************************************************************************
**********************************************************************************************************/










//x1401:

/*
	0x00001401	lea	rax, qword [ss:rbp+var_24]		; XREF
	0x00001405	mov	qword [ss:rsp+0x8], rax		; argument #8 (wLenDone)      for method
	0x0000140a	mov	dword [ss:rsp], 0x1		; argument #7 (bmRequestType) for method
	0x00001411	mov	esi, 0x11			; argument #2 (bRequest)      for method
	0x00001416	xor	edx, edx			; argument #3 (wValue)        for method
	0x00001418	lea	r8, qword [ss:rbp+var_5C]	; argument #5 (pData)         for method
	0x0000141c	mov	r9d, 0x4			; argument #6 (wLength)       for method
	0x00001422	mov	rdi, r14			; argument #1 (IOUSBDevice)   for method
	0x00001425	xor	ecx, ecx			; argument #4 (wIndex)        for method
	0x00001427	call	Usb_vendor_device_request()
*/
	uint32_t data_4 = 0;		// rbp+var_5C
//	uint32_t num_tx_bytes_4 = 0;	// rbp+var_24

	// 0xc0 0x11 (17) 0x0000 0x0000 0x4

	ctrl_setup ctrl;

	ctrl.bmRequestType = 0xc0;
	ctrl.bRequest = 0x11;
	ctrl.wValue = 0x0000;
	ctrl.wIndex = 0x0000;
	ctrl.wLength = 0x04;

	// rc = send_ctrl_xfr( devh, &ctrl, (unsigned char *)&data_4 );

	rc = send_ctrl_setup( dev, &ctrl, (unsigned char*)&data_4 );

/*
	0x0000142c	test    eax, eax
	0x0000142e	jne	0x1692
*/
	/* TODO: Test is unclear: should send_ctrl_setup() return error code or length ? */
	if ( rc != 0 )
	{
		return 0;
	}

	// printf("ans: 0x%08x\n", data_4);

//	if ( rc != 0 )
//		return 0;


/*
	0x00001434	mov	dword [ss:rbp+var_64], 0x0
	0x0000143b	lea	rax, qword [ss:rbp+var_60]
	0x0000143f	mov	qword [ss:rsp+0x8], rax		; argument #8 (wLenDone)      for method
	0x00001444	mov	dword [ss:rsp], 0x1		; argument #7 (bmRequestType) for method
	0x0000144b	mov	esi, 0x10			; argument #2 (bRequest)      for method
	0x00001450	xor	edx, edx			; argument #3 (wValue)        for method
	0x00001452	lea	r8, qword [ss:rbp+var_64]	; argument #5 (pData)         for method
	0x00001456	mov	r9d, 0x4			; argument #6 (wLength)       for method
	0x0000145c	mov	rdi, r14			; argument #1 (IOUSBDevice)   for method
	0x0000145f	xor	ecx, ecx			; argument #4 (wIndex)        for method
	0x00001461	call	Usb_vendor_device_request()
*/
	uint32_t data_5 = 0;		// rbp+var_64
//	uint32_t num_tx_bytes_5 = 0;	// rbp+var_60

	// 0xc0 0x10 (16) 0x0000 0x0000 0x4
//	rc = Usb_vendor_device_request();
	ctrl.bmRequestType = 0xc0;
	ctrl.bRequest = 0x10;
	ctrl.wValue = 0x0000;
	ctrl.wIndex = 0x0000;
	ctrl.wLength = 0x04;

	// rc = send_ctrl_xfr( devh, &ctrl, (unsigned char *)&data_5 );
	send_ctrl_setup( dev, &ctrl, (unsigned char*)&data_5 );

	// printf("ans: 0x%08x\n", data_5);


/*
	0x00001466	add	r15d, 0xffffc040
	0x0000146d	cmp	r15w, 0xf
	0x00001472	ja	0x1692
*/
	uint16_t r15w = (uint16_t)((productId + 0xffffc040) & 0xffff);

	if ( r15w > 0xf ) /* 0x3fc6 false */
		return 0;

/*
	0x00001478	movzx	eax, r15w
	0x0000147c	mov	ecx, 0x82c1
	0x00001481	bt	rcx, rax
	0x00001485	jb	0x14e3
*/
	if ( ((0x82c1 >> r15w) & 0x1) == 0 )		// if ( CF = 0 ), 0x3fc6 false
	{
/*
		0x00001487	mov	ecx, 0x2100
		0x0000148c	bt	rcx, rax
		0x00001490	jae	0x1692
*/
		if ( ((0x2100 >> r15w) & 0x1) == 0 )
			return 0;
/*
		0x00001496	mov	ecx, dword [ss:rbp+var_5C]	; ecx = data_4
		0x00001499	mov	eax, ecx
		0x0000149b	shr	eax, 0x9
		0x0000149e	and	eax, 0x7
		0x000014a1	lea	edx, qword [ds:rax+0xffffffffffffffff]
		0x000014a4	cmp	edx, 0x5
		0x000014a7	jb	0x14b2

		0x000014a9	test	bx, bx
		0x000014ac	je	0x1692

*/
		ecx = data_4;

		eax = data_4;
		eax >>= 0x9;
		eax &= 0x7;

		if ( (uint32_t)(eax + 0xffffffffffffffff) >= 0x5 && unknownArg == 0 )
			return 0;

/*
		0x000014b2	cmp	eax, 0x1			; XREF 1
		0x000014b5	je	0x15cf
*/
		if ( eax == 0x1 )
		{
			// THAT PART ALWAYS RETURNS
/*
			0x000015cf	test	byte [ss:rbp+var_64], 0x40	; XREF 1 /// data_5
			0x000015d3	jne	0x1644
*/
			if ( (unsigned char)data_5 == 0x40 )
			{
				return 0;
			}
/*
			0x000015d5	shr	ecx, 0xc
			0x000015d8	and	ecx, 0xf
			0x000015db	cmp	ecx, 0xb
			0x000015de	ja	0x1692
*/
			if ( ((data_4 >> 0xc) & 0xf) > 0xb )
			{
				return 0;
			}
/*
			0x000015e4	lea	rax, qword [ds:0x184c]
			0x000015eb	movsxd	rcx, dword [ds:rax+rcx*4]
			0x000015ef	add	rcx, rax
			0x000015f2	jmp	rcx
*/
			switch ( (data_4 >> 0xc) & 0xf )
			{
				case 0:         return 0x7d00;          /*      0x0000163a      */
				case 1:         return 0xac44;          /*      0x000011ad      */
				case 2:                                 /*      0x000015f4      */
				case 3:         return 0xbb80;          /*      0x000015f4      */
				case 4:         return 0xfa00;          /*      0x000015fe      */
				case 5:         return 0x15888;         /*      0x00001608      */
				case 6:                                 /*      0x00001612      */
				case 7:         return 0x17700;         /*      0x00001612      */
				case 8:         return 0x1f400;         /*      0x0000161c      */
				case 9:         return 0x2b110;         /*      0x00001626      */
				case 10:                                /*      0x00001630      */
				case 11:        return 0x2ee00;         /*      0x00001630      */
			}

		}
/*
		0x000014bb	cmp	eax, 0x2
		0x000014be	jne	0x1644
*/
		if ( eax == 0x2 )
		{
			// THAT PART ALWAYS RETURNS
/*
			0x000014c4	shr	ecx, 0x10
			0x000014c7	and	ecx, 0xf
			0x000014ca	cmp	ecx, 0xb
			0x000014cd	ja	0x1692
*/
			if ( ((data_4 >> 0x10) & 0xf) > 0xb )
				return 0;
/*
			0x000014d3	lea	rax, qword [ds:0x181c]
			0x000014da	movsxd	rcx, dword [ds:rax+rcx*4]
			0x000014de	add	rcx, rax
			0x000014e1	jmp	rcx			; switch statement with 12 cases
*/
			switch ( (data_4 >> 0x10) & 0xf )
			{
				case 0:         return 0x7d00;          /*      0x0000163a      */
				case 1:         return 0xac44;          /*      0x000011ad      */
				case 2:                                 /*      0x000015f4      */
				case 3:         return 0xbb80;          /*      0x000015f4      */
				case 4:         return 0xfa00;          /*      0x000015fe      */
				case 5:         return 0x15888;         /*      0x00001608      */
				case 6:                                 /*      0x00001612      */
				case 7:         return 0x17700;         /*      0x00001612      */
				case 8:         return 0x1f400;         /*      0x0000161c      */
				case 9:         return 0x2b110;         /*      0x00001626      */
				case 10:                                /*      0x00001630      */
				case 11:        return 0x2ee00;         /*      0x00001630      */
			}

			/*
				Eg:
					data_4 = 0x00feff01 >> 0x10 & 0xf =
			*/


		}

/*
		0x00001644	mov	eax, ecx		; XREF 2
		0x00001646	and	eax, 0x30000000
		0x0000164b	cmp	eax, 0xfffffff
		0x00001650	jg	0x165d
*/
		if ( (data_4 & 0x30000000) > 0xfffffff ) {
/*
			0x0000165d	cmp	eax, 0x10000000	; XREF 1
			0x00001662	je	0x1676
*/
			if ( (data_4 & 0x30000000) == 0x10000000 ) {
/*
				0x00001676	mov	eax, 0xac44	; XREF 1
				0x0000167b	jmp	0x1682
*/
				eax = 0xac44;
/*
				0x00001682	test	ecx, ecx	; XREF 3
				0x00001684	js	0x1230
*/
				if ( (int32_t)data_4 < 0 ) {
/*
					0x00001230	shl	eax, 0x2	; XREF 3
					0x00001233	jmp	0x11b2
*/
					return eax << 0x2;
				} else {
/*
					0x0000168a	shr	ecx, 0x1e
					0x0000168d	jmp	0x133e

					0x0000133e	and	cl, 0x1		; XREF 3
					0x00001341	shl	eax, cl
					0x00001343	jmp	0x11b2
*/
					data_4 >>= 0x1e;
					data_4 &= 0x1;

					return eax << data_4;
				}
/*
			0x00001664	cmp	eax, 0x20000000
			0x00001669	je	0x167d

			0x0000166b	cmp	eax, 0x30000000
			0x00001670	je	0x167d

*/
			} else if ((data_4 & 0x30000000) == 0x20000000 || (data_4 & 0x30000000) == 0x30000000) {
/*
				0x0000167d	mov	eax, 0xbb80		; XREF 2
*/
				eax = 0xbb80;
/*
				0x00001682	test	ecx, ecx		; XREF 3
				0x00001684	js	 0x1230
*/
				if ( (int32_t)data_4 < 0 ) {
/*
					0x00001230	shl	eax, 0x2	; XREF 3
					0x00001233	jmp	0x11b2
*/
					return eax << 0x2;
				} else {
/*
					0x0000168a	shr	ecx, 0x1e
					0x0000168d	jmp	0x133e

					0x0000133e	and	cl, 0x1		; XREF 3
					0x00001341	shl	eax, cl
					0x00001343	jmp	0x11b2
*/
					data_4 >>= 0x1e;
					data_4 &= 0x1;

					return eax << data_4;
				}

/*
			0x00001672	xor	eax, eax	; XREF 1
			0x00001674	jmp	0x1682
*/
			} else {
				eax = 0;
/*
				0x00001682	test	ecx, ecx	; XREF 3
				0x00001684	js	0x1230
*/
				if ( (int32_t)data_4 < 0 ) {
/*
					0x00001230	shl	eax, 0x2	; XREF 3
					0x00001233	jmp	0x11b2
*/
					return eax << 0x2;
				} else {
/*
					0x0000168a	shr	ecx, 0x1e
					0x0000168d	jmp	0x133e

					0x0000133e	and	cl, 0x1		; XREF 3
					0x00001341	shl	eax, cl
					0x00001343	jmp	0x11b2
*/
					data_4 >>= 0x1e;
					data_4 &= 0x1;

					return eax << data_4;
				}
			}
		}
/*
		0x00001652	test	eax, eax
		0x00001654	jne	0x1672
*/
		if ( (data_4 & 0x30000000) != 0 ) {
/*
			0x00001672	xor	eax, eax	; XREF 1
			0x00001674	jmp	0x1682
*/
			eax = 0;
/*
			0x00001682	test	ecx, ecx	; XREF 3
			0x00001684	js	0x1230
*/
			if ( (int32_t)data_4 < 0 ) {
/*
				0x00001230	shl	eax, 0x2	; XREF 3
				0x00001233	jmp	0x11b2
*/
				return eax << 0x2;
			} else {
/*
				0x0000168a	shr	ecx, 0x1e
				0x0000168d	jmp	0x133e

				0x0000133e	and	cl, 0x1		; XREF 3
				0x00001341	shl	eax, cl
				0x00001343	jmp	0x11b2
*/
				data_4 >>= 0x1e;
				data_4 &= 0x1;

				return eax << data_4;
			}
		}

/*
		0x00001656	mov	eax, 0x7d00
		0x0000165b	jmp	0x1682
*/
		eax = 0x7d00;
/*
		0x00001682	test	ecx, ecx	; XREF 3
		0x00001684	js	0x1230
*/
		if ( (int32_t)data_4 < 0 ) {
/*
			0x00001230	shl	eax, 0x2	; XREF 3
			0x00001233	jmp	0x11b2
*/
			return eax << 0x2;

		} else {
/*
			0x0000168a	shr	ecx, 0x1e
			0x0000168d	jmp	0x133e

			0x0000133e	and	cl, 0x1		; XREF 3
			0x00001341	shl	eax, cl
			0x00001343	jmp	0x11b2
*/
			data_4 >>= 0x1e;
			data_4 &= 0x1;

			return eax << data_4;
		}

	}














	// REPRISE 14e3 ok
/*
	0x000014e3	mov	ecx, dword [ss:rbp+var_5C]		; XREF 1
	0x000014e6	mov	eax, ecx
	0x000014e8	shr	eax, 0x9
	0x000014eb	and	eax, 0x7
	0x000014ee	lea	edx, qword [ds:rax+0xffffffffffffffff]
	0x000014f1	cmp	edx, 0x5
	0x000014f4	jb	0x14ff

	0x000014f6	test	bx, bx
	0x000014f9	je	0x1692
*/
	ecx = data_4;

	eax = data_4;
	eax >>= 0x9;
	eax &= 0x7;

	if ( (((uint32_t)(eax + 0xffffffffffffffff) & 0xffffffffffffffff) >= 0x5) && (unknownArg == 0) )
		return 0;

/*
	0x000014ff	cmp	eax, 0x3			; XREF 1
	0x00001502	je	0x1558
*/
	if ( eax == 0x3 )
	{
/*
		0x00001558	test	byte [ss:rbp+var_64], 0x40	; XREF 1
		0x0000155c	jne	0x157d
*/
		if ( (unsigned char)data_5 == 0x40 )
		{
/*
			0x0000157d	mov	eax, ecx		; XREF 3
			0x0000157f	and	eax, 0x3000000
			0x00001584	cmp	eax, 0xffffff
			0x00001589	jg	0x1596
*/
			if ( (data_4 & 0x3000000) > 0xffffff )
			{
/*
				0x00001596	cmp	eax, 0x1000000	; XREF 1
				0x0000159b	je	0x15af
*/
				if ( (data_4 & 0x3000000) == 0x1000000 )
				{
/*
					0x000015af	mov	eax, 0xac44	; XREF 1
					0x000015b4	jmp	0x15bb
*/
					eax = 0xac44;
/*
					0x000015bb	test	ecx, 0x8000000	; XREF 3
					0x000015c1	jne	0x1230
*/
					if ( (data_4 & 0x8000000) != 0 )
					{
/*
						0x00001230	shl	eax, 0x2	; XREF 3
						0x00001233	jmp	0x11b2
*/
						return eax << 0x2;
					}
/*
					0x000015c7	shr	ecx, 0x1a
					0x000015ca	jmp	0x133e

					0x0000133e	and	cl, 0x1			; XREF 3
					0x00001341	shl	eax, cl
					0x00001343	jmp	0x11b2
*/
					data_4 >>= 0x1a;
					data_4 &= 0x1;
					eax <<= data_4;

					return eax;

				}
/*
				0x0000159d	cmp	eax, 0x2000000
				0x000015a2	je	0x15b6

				0x000015a4	cmp	eax, 0x3000000
				0x000015a9	je	0x15b6
*/
				if ( ((data_4 & 0x3000000) == 0x2000000) || ((data_4 & 0x3000000) == 0x3000000))
				{
/*
					0x000015b6	mov	eax, 0xbb80		; XREF 2
*/
					eax = 0xbb80;
/*
					0x000015bb	test	ecx, 0x8000000		; XREF 3
					0x000015c1	jne	0x1230
*/
					if ( (data_4 & 0x8000000) != 0 )
					{
/*
						0x00001230	shl	eax, 0x2	; XREF 3
						0x00001233	jmp	0x11b2
*/
						return eax << 0x2;
					}
/*
					0x000015c7	shr	ecx, 0x1a
					0x000015ca	jmp	0x133e

					0x0000133e	and	cl, 0x1			; XREF 3
					0x00001341	shl	eax, cl
					0x00001343	jmp	0x11b2
*/
					data_4 >>= 0x1a;
					data_4 &= 0x1;
					eax <<= data_4;

					return eax;

				}
/*
				0x000015ab	xor	eax, eax	; XREF 1
				0x000015ad	jmp	0x15bb
*/
				eax = 0;
/*
				0x000015bb	test	ecx, 0x8000000	; XREF 3
				0x000015c1	jne	0x1230
*/
				if ( (data_4 & 0x8000000) != 0 )
				{
/*
					0x00001230	shl	eax, 0x2	; XREF 3
					0x00001233	jmp	0x11b2
*/
					return eax << 0x2;
				}
/*
				0x000015c7	shr	ecx, 0x1a
				0x000015ca	jmp	0x133e

				0x0000133e	and	cl, 0x1			; XREF 3
				0x00001341	shl	eax, cl
				0x00001343	jmp	0x11b2
*/
				data_4 >>= 0x1a;
				data_4 &= 0x1;
				eax <<= data_4;

				return eax;

			}
/*
			0x0000158b	test	eax, eax
			0x0000158d	jne	0x15ab
*/
			if ( (data_4 & 0x3000000) != 0 )
			{
/*
				0x000015ab	xor	eax, eax	; XREF 1
				0x000015ad	jmp	0x15bb
*/
				eax = 0;
/*
				0x000015bb	test	ecx, 0x8000000	; XREF 3
				0x000015c1	jne	0x1230
*/
				if ( (data_4 & 0x8000000) != 0 )
				{
/*
					0x00001230	shl	eax, 0x2	; XREF 3
					0x00001233	jmp	0x11b2
*/
					return eax << 0x2;
				}
/*
				0x000015c7	shr	ecx, 0x1a
				0x000015ca	jmp	0x133e

				0x0000133e	and	cl, 0x1			; XREF 3
				0x00001341	shl	eax, cl
				0x00001343	jmp	0x11b2
*/
				data_4 >>= 0x1a;
				data_4 &= 0x1;
				eax <<= data_4;

				return eax;
			}
/*
			0x0000158f	mov	eax, 0x7d00
			0x00001594	jmp	0x15bb
*/
			eax = 0x7d00;
/*
			0x000015bb	test	ecx, 0x8000000		; XREF 3
			0x000015c1	jne	0x1230
*/
			if ( (data_4 & 0x8000000) != 0 )
			{
/*
				0x00001230	shl	eax, 0x2	; XREF 3
				0x00001233	jmp	0x11b2
*/
				return eax << 0x2;
			}
/*
			0x000015c7	shr	ecx, 0x1a
			0x000015ca	jmp	0x133e

			0x0000133e	and	cl, 0x1			; XREF 3
			0x00001341	shl	eax, cl
			0x00001343	jmp	0x11b2
*/
			data_4 >>= 0x1a;
			data_4 &= 0x1;
			eax <<= data_4;

			return eax;
		}
/*
		0x0000155e	shr	ecx, 0x14
		0x00001561	and	ecx, 0xf
		0x00001564	cmp	ecx, 0xb
		0x00001567	ja	0x1692
*/
//		data_4 >>= 0x14;
//		data_4 &= 0xf;

		if ( ((data_4 >> 0x14) & 0xf) > 0xb )
			return 0;
/*
		0x0000156d	lea	rax, qword [ds:0x17ec]
		0x00001574	movsxd	rcx, dword [ds:rax+rcx*4]
		0x00001578	add	rcx, rax
		0x0000157b	jmp	rcx				; switch statement with 12 cases
*/
		switch ( (data_4 >> 0x14) & 0xf )
		{
			case 0:         return 0x7d00;          /*      0x0000163a      */
			case 1:         return 0xac44;          /*      0x000011ad      */
			case 2:                                 /*      0x000015f4      */
			case 3:         return 0xbb80;          /*      0x000015f4      */
			case 4:         return 0xfa00;          /*      0x000015fe      */
			case 5:         return 0x15888;         /*      0x00001608      */
			case 6:                                 /*      0x00001612      */
			case 7:         return 0x17700;         /*      0x00001612      */
			case 8:         return 0x1f400;         /*      0x0000161c      */
			case 9:         return 0x2b110;         /*      0x00001626      */
			case 10:                                /*      0x00001630      */
			case 11:        return 0x2ee00;         /*      0x00001630      */
		}

	}
/*
	0x00001504	cmp	eax, 0x2
	0x00001507	je	0x152d
*/
	if ( eax == 0x2 )
	{
/*
		0x0000152d	mov	edx, ecx			; XREF 1
		0x0000152f	test	dh, 0x1
		0x00001532	jne	0x1553
*/
		if ( (((data_4 >> 0x8) & 0xff) & 0x1) != 0 )
		{
/*
			0x00001553	cmp	eax, 0x3			; XREF 1
			0x00001556	jne	0x157d

			0x00001558	test	byte [ss:rbp+var_64], 0x40	; XREF 1
			0x0000155c	jne	0x157d
*/
			if ( (eax != 0x3) || ((unsigned char)data_4 != 0x40) )
			{






/*
				0x0000157d	mov	eax, ecx		; XREF 3
				0x0000157f	and	eax, 0x3000000
				0x00001584	cmp	eax, 0xffffff
				0x00001589	jg	0x1596
*/
				if ( (data_4 & 0x3000000) > 0xffffff )
				{
/*
					0x00001596	cmp	eax, 0x1000000	; XREF 1
					0x0000159b	je	0x15af
*/
					if ( (data_4 & 0x3000000) == 0x1000000 )
					{
/*
						0x000015af	mov	eax, 0xac44	; XREF 1
						0x000015b4	jmp	0x15bb
*/
						eax = 0xac44;
/*
						0x000015bb	test	ecx, 0x8000000	; XREF 3
						0x000015c1	jne	0x1230
*/
						if ( (data_4 & 0x8000000) != 0 )
						{
/*
							0x00001230	shl	eax, 0x2	; XREF 3
							0x00001233	jmp	0x11b2
*/
							return eax << 0x2;
						}
/*
						0x000015c7	shr	ecx, 0x1a
						0x000015ca	jmp	0x133e

						0x0000133e	and	cl, 0x1			; XREF 3
						0x00001341	shl	eax, cl
						0x00001343	jmp	0x11b2
*/
						data_4 >>= 0x1a;
						data_4 &= 0x1;
						eax <<= data_4;

						return eax;

					}
/*
					0x0000159d	cmp	eax, 0x2000000
					0x000015a2	je	0x15b6

					0x000015a4	cmp	eax, 0x3000000
					0x000015a9	je	0x15b6
*/
					if ( ((data_4 & 0x3000000) == 0x2000000) || ((data_4 & 0x3000000) == 0x3000000))
					{
/*
						0x000015b6	mov	eax, 0xbb80		; XREF 2
*/
						eax = 0xbb80;
/*
						0x000015bb	test	ecx, 0x8000000		; XREF 3
						0x000015c1	jne	0x1230
*/
						if ( (data_4 & 0x8000000) != 0 )
						{
/*
							0x00001230	shl	eax, 0x2	; XREF 3
							0x00001233	jmp	0x11b2
*/
							return eax << 0x2;
						}
/*
						0x000015c7	shr	ecx, 0x1a
						0x000015ca	jmp	0x133e

						0x0000133e	and	cl, 0x1			; XREF 3
						0x00001341	shl	eax, cl
						0x00001343	jmp	0x11b2
*/
						data_4 >>= 0x1a;
						data_4 &= 0x1;
						eax <<= data_4;

						return eax;

					}
/*
					0x000015ab	xor	eax, eax	; XREF 1
					0x000015ad	jmp	0x15bb
*/
					eax = 0;
/*
					0x000015bb	test	ecx, 0x8000000	; XREF 3
					0x000015c1	jne	0x1230
*/
					if ( (data_4 & 0x8000000) != 0 )
					{
/*
						0x00001230	shl	eax, 0x2	; XREF 3
						0x00001233	jmp	0x11b2
*/
						return eax << 0x2;
					}
/*
					0x000015c7	shr	ecx, 0x1a
					0x000015ca	jmp	0x133e

					0x0000133e	and	cl, 0x1			; XREF 3
					0x00001341	shl	eax, cl
					0x00001343	jmp	0x11b2
*/
					data_4 >>= 0x1a;
					data_4 &= 0x1;
					eax <<= data_4;

					return eax;

				}
/*
				0x0000158b	test	eax, eax
				0x0000158d	jne	0x15ab
*/
				if ( (data_4 & 0x3000000) != 0 )
				{
/*
					0x000015ab	xor	eax, eax	; XREF 1
					0x000015ad	jmp	0x15bb
*/
					eax = 0;
/*
					0x000015bb	test	ecx, 0x8000000	; XREF 3
					0x000015c1	jne	0x1230
*/
					if ( (data_4 & 0x8000000) != 0 )
					{
/*
						0x00001230	shl	eax, 0x2	; XREF 3
						0x00001233	jmp	0x11b2
*/
						return eax << 0x2;
					}
/*
					0x000015c7	shr	ecx, 0x1a
					0x000015ca	jmp	0x133e

					0x0000133e	and	cl, 0x1			; XREF 3
					0x00001341	shl	eax, cl
					0x00001343	jmp	0x11b2
*/
					data_4 >>= 0x1a;
					data_4 &= 0x1;
					eax <<= data_4;

					return eax;
				}
/*
				0x0000158f	mov	eax, 0x7d00
				0x00001594	jmp	0x15bb
*/
				eax = 0x7d00;
/*
				0x000015bb	test	ecx, 0x8000000		; XREF 3
				0x000015c1	jne	0x1230
*/
				if ( (data_4 & 0x8000000) != 0 )
				{
/*
					0x00001230	shl	eax, 0x2	; XREF 3
					0x00001233	jmp	0x11b2
*/
					return eax << 0x2;
				}
/*
				0x000015c7	shr	ecx, 0x1a
				0x000015ca	jmp	0x133e

				0x0000133e	and	cl, 0x1			; XREF 3
				0x00001341	shl	eax, cl
				0x00001343	jmp	0x11b2
*/
				data_4 >>= 0x1a;
				data_4 &= 0x1;
				eax <<= data_4;

				return eax;






			}
/*
			0x0000155e	shr	ecx, 0x14
			0x00001561	and	ecx, 0xf
			0x00001564	cmp	ecx, 0xb
			0x00001567	ja	0x1692
*/
//			data_4 >>= 0x14;
//			data_4  &= 0xf;

			if ( ((data_4 >> 0x14) & 0xf) > 0xb )
				return 0;

/*
			0x0000156d	lea	rax, qword [ds:0x17ec]
			0x00001574	movsxd	rcx, dword [ds:rax+rcx*4]
			0x00001578	add	rcx, rax
			0x0000157b	jmp	rcx			; switch statement with 12 cases
*/
			switch ( (data_4 >> 0x14) & 0xf )
			{
				case 0:         return 0x7d00;          /*      0x0000163a      */
				case 1:         return 0xac44;          /*      0x000011ad      */
				case 2:                                 /*      0x000015f4      */
				case 3:         return 0xbb80;          /*      0x000015f4      */
				case 4:         return 0xfa00;          /*      0x000015fe      */
				case 5:         return 0x15888;         /*      0x00001608      */
				case 6:                                 /*      0x00001612      */
				case 7:         return 0x17700;         /*      0x00001612      */
				case 8:         return 0x1f400;         /*      0x0000161c      */
				case 9:         return 0x2b110;         /*      0x00001626      */
				case 10:                                /*      0x00001630      */
				case 11:        return 0x2ee00;         /*      0x00001630      */
			}

		}
/*
		0x00001534	shr	ecx, 0x10
		0x00001537	and	ecx, 0xf
		0x0000153a	cmp	ecx, 0xb
		0x0000153d	ja	0x1692
*/
//		data_4 >>= 0x10;
//		data_4  &= 0xf;

		if ( ((data_4 >> 0x10) & 0xf) > 0xb )
			return 0;

/*
		0x00001543	lea	rax, qword [ds:0x17bc]
		0x0000154a	movsxd	rcx, dword [ds:rax+rcx*4]
		0x0000154e	add	rcx, rax
		0x00001551	jmp	rcx				; switch statement with 12 cases
*/
		switch ( (data_4 >> 0x10) & 0xf )
		{
			case 0:         return 0x7d00;          /*      0x0000163a      */
			case 1:         return 0xac44;          /*      0x000011ad      */
			case 2:                                 /*      0x000015f4      */
			case 3:         return 0xbb80;          /*      0x000015f4      */
			case 4:         return 0xfa00;          /*      0x000015fe      */
			case 5:         return 0x15888;         /*      0x00001608      */
			case 6:                                 /*      0x00001612      */
			case 7:         return 0x17700;         /*      0x00001612      */
			case 8:         return 0x1f400;         /*      0x0000161c      */
			case 9:         return 0x2b110;         /*      0x00001626      */
			case 10:                                /*      0x00001630      */
			case 11:        return 0x2ee00;         /*      0x00001630      */
		}

	}

/*
	0x00001509	cmp	eax, 0x1
	0x0000150c	jne	0x157d
*/
	if ( eax == 0x1 )
	{
/*
		0x0000150e	shr	ecx, 0xc
		0x00001511	and	ecx, 0xf
		0x00001514	cmp	ecx, 0xb
		0x00001517	ja	0x1692
*/
//		data_4 >>= 0xc;
//		data_4  &= 0xf;

		if ( ((data_4 >> 0xc) & 0xf) > 0xb )
			return 0;
/*
		0x0000151d	lea	rax, qword [ds:0x178c]
		0x00001524	movsxd	rcx, dword [ds:rax+rcx*4]
		0x00001528	add	rcx, rax
		0x0000152b	jmp	rcx				; switch statement with 12 cases
*/
		switch ( (data_4 >> 0xc) & 0xf )
		{
			case 0:         return 0x7d00;          /*      0x0000163a      */
			case 1:         return 0xac44;          /*      0x000011ad      */
			case 2:                                 /*      0x000015f4      */
			case 3:         return 0xbb80;          /*      0x000015f4      */
			case 4:         return 0xfa00;          /*      0x000015fe      */
			case 5:         return 0x15888;         /*      0x00001608      */
			case 6:                                 /*      0x00001612      */
			case 7:         return 0x17700;         /*      0x00001612      */
			case 8:         return 0x1f400;         /*      0x0000161c      */
			case 9:         return 0x2b110;         /*      0x00001626      */
			case 10:                                /*      0x00001630      */
			case 11:        return 0x2ee00;         /*      0x00001630      */
		}

	}






/*
	0x0000157d	mov	eax, ecx		; XREF 3
	0x0000157f	and	eax, 0x3000000
	0x00001584	cmp	eax, 0xffffff
	0x00001589	jg	0x1596
*/
	if ( (data_4 & 0x3000000) > 0xffffff )	/* 0x00feff01 false */
	{
/*
		0x00001596	cmp	eax, 0x1000000	; XREF 1
		0x0000159b	je	0x15af
*/
		if ( (data_4 & 0x3000000) == 0x1000000 )
		{
/*
			0x000015af	mov	eax, 0xac44	; XREF 1
			0x000015b4	jmp	0x15bb
*/
			eax = 0xac44;
/*
			0x000015bb	test	ecx, 0x8000000	; XREF 3
			0x000015c1	jne	0x1230
*/
			if ( (data_4 & 0x8000000) != 0 )
			{
/*
				0x00001230	shl	eax, 0x2	; XREF 3
				0x00001233	jmp	0x11b2
*/
				return eax << 0x2;
			}
/*
			0x000015c7	shr	ecx, 0x1a
			0x000015ca	jmp	0x133e

			0x0000133e	and	cl, 0x1			; XREF 3
			0x00001341	shl	eax, cl
			0x00001343	jmp	0x11b2
*/
			data_4 >>= 0x1a;
			data_4 &= 0x1;
			eax <<= data_4;

			return eax;

		}
/*
		0x0000159d	cmp	eax, 0x2000000
		0x000015a2	je	0x15b6

		0x000015a4	cmp	eax, 0x3000000
		0x000015a9	je	0x15b6
*/
		if ( ((data_4 & 0x3000000) == 0x2000000) || ((data_4 & 0x3000000) == 0x3000000))
		{
/*
			0x000015b6	mov	eax, 0xbb80		; XREF 2
*/
			eax = 0xbb80;
/*
			0x000015bb	test	ecx, 0x8000000		; XREF 3
			0x000015c1	jne	0x1230
*/
			if ( (data_4 & 0x8000000) != 0 )
			{
/*
				0x00001230	shl	eax, 0x2	; XREF 3
				0x00001233	jmp	0x11b2
*/
				return eax << 0x2;
			}
/*
			0x000015c7	shr	ecx, 0x1a
			0x000015ca	jmp	0x133e

			0x0000133e	and	cl, 0x1			; XREF 3
			0x00001341	shl	eax, cl
			0x00001343	jmp	0x11b2
*/
			data_4 >>= 0x1a;
			data_4 &= 0x1;
			eax <<= data_4;

			return eax;

		}
/*
		0x000015ab	xor	eax, eax	; XREF 1
		0x000015ad	jmp	0x15bb
*/
		eax = 0;
/*
		0x000015bb	test	ecx, 0x8000000	; XREF 3
		0x000015c1	jne	0x1230
*/
		if ( (data_4 & 0x8000000) != 0 )
		{
/*
			0x00001230	shl	eax, 0x2	; XREF 3
			0x00001233	jmp	0x11b2
*/
			return eax << 0x2;
		}
/*
		0x000015c7	shr	ecx, 0x1a
		0x000015ca	jmp	0x133e

		0x0000133e	and	cl, 0x1			; XREF 3
		0x00001341	shl	eax, cl
		0x00001343	jmp	0x11b2
*/
		data_4 >>= 0x1a;
		data_4 &= 0x1;
		eax <<= data_4;

		return eax;

	}
/*
	0x0000158b	test	eax, eax
	0x0000158d	jne	0x15ab
*/
	if ( (data_4 & 0x3000000) != 0 ) /* 0x00feff01 false */
	{
/*
		0x000015ab	xor	eax, eax	; XREF 1
		0x000015ad	jmp	0x15bb
*/
		eax = 0;
/*
		0x000015bb	test	ecx, 0x8000000	; XREF 3
		0x000015c1	jne	0x1230
*/
		if ( (data_4 & 0x8000000) != 0 )
		{
/*
			0x00001230	shl	eax, 0x2	; XREF 3
			0x00001233	jmp	0x11b2
*/
			return eax << 0x2;
		}
/*
		0x000015c7	shr	ecx, 0x1a
		0x000015ca	jmp	0x133e

		0x0000133e	and	cl, 0x1			; XREF 3
		0x00001341	shl	eax, cl
		0x00001343	jmp	0x11b2
*/
		data_4 >>= 0x1a;
		data_4 &= 0x1;
		eax <<= data_4;

		return eax;
	}
/*
	0x0000158f	mov	eax, 0x7d00
	0x00001594	jmp	0x15bb
*/
	eax = 0x7d00;
/*
	0x000015bb	test	ecx, 0x8000000		; XREF 3
	0x000015c1	jne	0x1230
*/
	if ( (data_4 & 0x8000000) != 0 ) /* 0x00feff01 false */
	{
/*
		0x00001230	shl	eax, 0x2	; XREF 3
		0x00001233	jmp	0x11b2
*/
		return eax << 0x2;
	}
/*
	0x000015c7	shr	ecx, 0x1a
	0x000015ca	jmp	0x133e

	0x0000133e	and	cl, 0x1			; XREF 3
	0x00001341	shl	eax, cl
	0x00001343	jmp	0x11b2
*/
	data_4 >>= 0x1a;
	data_4 &= 0x1;
	eax <<= data_4;

	return eax;



	// E O F ?





/*
;	0x0000152d	mov	edx, ecx			; XREF 1
;	0x0000152f	test	dh, 0x1
;	0x00001532	jne	0x1553

;	0x00001534	shr	ecx, 0x10
;	0x00001537	and	ecx, 0xf
;	0x0000153a	cmp	ecx, 0xb
;	0x0000153d	ja	0x1692

;	0x00001543	lea	rax, qword [ds:0x17bc]
;	0x0000154a	movsxd	rcx, dword [ds:rax+rcx*4]
;	0x0000154e	add	rcx, rax
;	0x00001551	jmp	rcx				; switch statement using table at 0x17bc, with 12 cases




;	0x00001553	cmp	eax, 0x3				; XREF=__Z9hwGetRateP11IOUSBDevicett+1074
;	0x00001556	jne	0x157d

;	0x00001558	test	byte [ss:rbp+var_64], 0x40		; XREF 1
;	0x0000155c	jne	0x157d

;	0x0000155e	shr	ecx, 0x14
;	0x00001561	and	ecx, 0xf
;	0x00001564	cmp	ecx, 0xb
;	0x00001567	ja	0x1692

;	0x0000156d	lea	rax, qword [ds:0x17ec]
;	0x00001574	movsxd	rcx, dword [ds:rax+rcx*4]
;	0x00001578	add	rcx, rax
;	0x0000157b	jmp	rcx					; switch statement using table at 0x17ec, with 12 cases




;	0x0000157d	mov	eax, ecx				; XREF=__Z9hwGetRateP11IOUSBDevicett+1036, __Z9hwGetRateP11IOUSBDevicett+1110, __Z9hwGetRateP11IOUSBDevicett+1116
;	0x0000157f	and	eax, 0x3000000
;	0x00001584	cmp	eax, 0xffffff
;	0x00001589	jg	0x1596

;	0x0000158b	test	eax, eax
;	0x0000158d	jne	0x15ab

;	0x0000158f	mov	eax, 0x7d00
;	0x00001594	jmp	0x15bb




	0x00001596	cmp	eax, 0x1000000			; XREF=__Z9hwGetRateP11IOUSBDevicett+1161
	0x0000159b	je	0x15af

	0x0000159d	cmp	eax, 0x2000000
	0x000015a2	je	0x15b6

	0x000015a4	cmp	eax, 0x3000000
	0x000015a9	je	0x15b6

	0x000015ab	xor	eax, eax				; XREF=__Z9hwGetRateP11IOUSBDevicett+1165
	0x000015ad	jmp	0x15bb




	0x000015af	mov	eax, 0xac44				; "Channels", XREF=__Z9hwGetRateP11IOUSBDevicett+1179
	0x000015b4	jmp	0x15bb

	0x000015b6	mov	eax, 0xbb80				; 0xbb80 (__ZL21gChannelNames_UCX_out + 0x50), XREF=__Z9hwGetRateP11IOUSBDevicett+1186, __Z9hwGetRateP11IOUSBDevicett+1193

	0x000015bb	test	ecx, 0x8000000			; XREF=__Z9hwGetRateP11IOUSBDevicett+1172, __Z9hwGetRateP11IOUSBDevicett+1197, __Z9hwGetRateP11IOUSBDevicett+1204
	0x000015c1	jne	0x1230

	0x000015c7	shr	ecx, 0x1a
	0x000015ca	jmp	0x133e

	0x000015cf	test	byte [ss:rbp+var_64], 0x40		; XREF=__Z9hwGetRateP11IOUSBDevicett+949
	0x000015d3	jne	0x1644

	0x000015d5	shr	ecx, 0xc
	0x000015d8	and	ecx, 0xf
	0x000015db	cmp	ecx, 0xb
	0x000015de	ja	0x1692

	0x000015e4	lea	rax, qword [ds:0x184c]
	0x000015eb	movsxd	rcx, dword [ds:rax+rcx*4]
	0x000015ef	add	rcx, rax
	0x000015f2	jmp	rcx					; switch statement using table at 0x184c, with 12 cases

	0x000015f4	mov	eax, 0xbb80				; case 3, 0xbb80 (__ZL21gChannelNames_UCX_out + 0x50), XREF=__Z9hwGetRateP11IOUSBDevicett+170, __Z9hwGetRateP11IOUSBDevicett+227, __Z9hwGetRateP11IOUSBDevicett+485, __Z9hwGetRateP11IOUSBDevicett+528, __Z9hwGetRateP11IOUSBDevicett+740, __Z9hwGetRateP11IOUSBDevicett+993, __Z9hwGetRateP11IOUSBDevicett+1067, __Z9hwGetRateP11IOUSBDevicett+1105, __Z9hwGetRateP11IOUSBDevicett+1147, __Z9hwGetRateP11IOUSBDevicett+1266
	0x000015f9	jmp	0x11b2

	0x000015fe	mov	eax, 0xfa00				; case 4, XREF=__Z9hwGetRateP11IOUSBDevicett+170, __Z9hwGetRateP11IOUSBDevicett+227, __Z9hwGetRateP11IOUSBDevicett+485, __Z9hwGetRateP11IOUSBDevicett+528, __Z9hwGetRateP11IOUSBDevicett+740, __Z9hwGetRateP11IOUSBDevicett+993, __Z9hwGetRateP11IOUSBDevicett+1067, __Z9hwGetRateP11IOUSBDevicett+1105, __Z9hwGetRateP11IOUSBDevicett+1147, __Z9hwGetRateP11IOUSBDevicett+1266
	0x00001603	jmp	0x11b2

	0x00001608	mov	eax, 0x15888				; case 5, XREF=__Z9hwGetRateP11IOUSBDevicett+170, __Z9hwGetRateP11IOUSBDevicett+227, __Z9hwGetRateP11IOUSBDevicett+485, __Z9hwGetRateP11IOUSBDevicett+528, __Z9hwGetRateP11IOUSBDevicett+740, __Z9hwGetRateP11IOUSBDevicett+993, __Z9hwGetRateP11IOUSBDevicett+1067, __Z9hwGetRateP11IOUSBDevicett+1105, __Z9hwGetRateP11IOUSBDevicett+1147, __Z9hwGetRateP11IOUSBDevicett+1266
	0x0000160d	jmp	0x11b2

	0x00001612	mov	eax, 0x17700				; case 7, XREF=__Z9hwGetRateP11IOUSBDevicett+170, __Z9hwGetRateP11IOUSBDevicett+227, __Z9hwGetRateP11IOUSBDevicett+485, __Z9hwGetRateP11IOUSBDevicett+528, __Z9hwGetRateP11IOUSBDevicett+740, __Z9hwGetRateP11IOUSBDevicett+993, __Z9hwGetRateP11IOUSBDevicett+1067, __Z9hwGetRateP11IOUSBDevicett+1105, __Z9hwGetRateP11IOUSBDevicett+1147, __Z9hwGetRateP11IOUSBDevicett+1266
	0x00001617	jmp	0x11b2

	0x0000161c	mov	eax, 0x1f400				; case 8, XREF=__Z9hwGetRateP11IOUSBDevicett+170, __Z9hwGetRateP11IOUSBDevicett+227, __Z9hwGetRateP11IOUSBDevicett+485, __Z9hwGetRateP11IOUSBDevicett+528, __Z9hwGetRateP11IOUSBDevicett+740, __Z9hwGetRateP11IOUSBDevicett+993, __Z9hwGetRateP11IOUSBDevicett+1067, __Z9hwGetRateP11IOUSBDevicett+1105, __Z9hwGetRateP11IOUSBDevicett+1147, __Z9hwGetRateP11IOUSBDevicett+1266
	0x00001621	jmp	0x11b2

	0x00001626	mov	eax, 0x2b110				; case 9, XREF=__Z9hwGetRateP11IOUSBDevicett+170, __Z9hwGetRateP11IOUSBDevicett+227, __Z9hwGetRateP11IOUSBDevicett+485, __Z9hwGetRateP11IOUSBDevicett+528, __Z9hwGetRateP11IOUSBDevicett+740, __Z9hwGetRateP11IOUSBDevicett+993, __Z9hwGetRateP11IOUSBDevicett+1067, __Z9hwGetRateP11IOUSBDevicett+1105, __Z9hwGetRateP11IOUSBDevicett+1147, __Z9hwGetRateP11IOUSBDevicett+1266
	0x0000162b	jmp	0x11b2

	0x00001630	mov	eax, 0x2ee00				; case 11, XREF=__Z9hwGetRateP11IOUSBDevicett+170, __Z9hwGetRateP11IOUSBDevicett+227, __Z9hwGetRateP11IOUSBDevicett+485, __Z9hwGetRateP11IOUSBDevicett+528, __Z9hwGetRateP11IOUSBDevicett+740, __Z9hwGetRateP11IOUSBDevicett+993, __Z9hwGetRateP11IOUSBDevicett+1067, __Z9hwGetRateP11IOUSBDevicett+1105, __Z9hwGetRateP11IOUSBDevicett+1147, __Z9hwGetRateP11IOUSBDevicett+1266
	0x00001635	jmp	0x11b2

	0x0000163a	mov	eax, 0x7d00				; case 0, XREF=__Z9hwGetRateP11IOUSBDevicett+170, __Z9hwGetRateP11IOUSBDevicett+227, __Z9hwGetRateP11IOUSBDevicett+485, __Z9hwGetRateP11IOUSBDevicett+528, __Z9hwGetRateP11IOUSBDevicett+740, __Z9hwGetRateP11IOUSBDevicett+993, __Z9hwGetRateP11IOUSBDevicett+1067, __Z9hwGetRateP11IOUSBDevicett+1105, __Z9hwGetRateP11IOUSBDevicett+1147, __Z9hwGetRateP11IOUSBDevicett+1266
	0x0000163f	jmp	0x11b2

	0x00001644	mov	eax, ecx				; XREF=__Z9hwGetRateP11IOUSBDevicett+958, __Z9hwGetRateP11IOUSBDevicett+1235
	0x00001646	and	eax, 0x30000000
	0x0000164b	cmp	eax, 0xfffffff
	0x00001650	jg	0x165d

	0x00001652	test	eax, eax
	0x00001654	jne	0x1672

	0x00001656	mov	eax, 0x7d00
	0x0000165b	jmp	0x1682

	0x0000165d	cmp	eax, 0x10000000			; XREF=__Z9hwGetRateP11IOUSBDevicett+1360
	0x00001662	je	0x1676

	0x00001664	cmp	eax, 0x20000000
	0x00001669	je	0x167d

	0x0000166b	cmp	eax, 0x30000000
	0x00001670	je	0x167d

	0x00001672	xor	eax, eax				; XREF=__Z9hwGetRateP11IOUSBDevicett+1364
	0x00001674	jmp	0x1682

	0x00001676	mov	eax, 0xac44				; "Channels", XREF=__Z9hwGetRateP11IOUSBDevicett+1378
	0x0000167b	jmp	0x1682

	0x0000167d	mov	eax, 0xbb80				; 0xbb80 (__ZL21gChannelNames_UCX_out + 0x50), XREF=__Z9hwGetRateP11IOUSBDevicett+1385, __Z9hwGetRateP11IOUSBDevicett+1392

	0x00001682	test	ecx, ecx				; XREF=__Z9hwGetRateP11IOUSBDevicett+1371, __Z9hwGetRateP11IOUSBDevicett+1396, __Z9hwGetRateP11IOUSBDevicett+1403
	0x00001684	js	 0x1230

	0x0000168a	shr	ecx, 0x1e
	0x0000168d	jmp	0x133e

	0x00001692	xor	eax, eax				; XREF=__Z9hwGetRateP11IOUSBDevicett+92, __Z9hwGetRateP11IOUSBDevicett+118, __Z9hwGetRateP11IOUSBDevicett+150, __Z9hwGetRateP11IOUSBDevicett+207, __Z9hwGetRateP11IOUSBDevicett+383, __Z9hwGetRateP11IOUSBDevicett+409, __Z9hwGetRateP11IOUSBDevicett+465, __Z9hwGetRateP11IOUSBDevicett+508, __Z9hwGetRateP11IOUSBDevicett+641, __Z9hwGetRateP11IOUSBDevicett+673, __Z9hwGetRateP11IOUSBDevicett+720, …
	0x00001694	jmp	0x11b2
			; endp
	0x00001699	nop	qword [ds:rax]
	0x0000169c	dd	0xffffff9e, 0xfffffb11, 0xffffff58, 0xffffff58; switch table, XREF=__Z9hwGetRateP11IOUSBDevicett+156
	0x000016ac	dd	0xffffff62, 0xffffff6c, 0xffffff76, 0xffffff76
	0x000016bc	dd	0xffffff80, 0xffffff8a, 0xffffff94, 0xffffff94
	0x000016cc	dd	0xffffff6e, 0xfffffae1, 0xffffff28, 0xffffff28; switch table, XREF=__Z9hwGetRateP11IOUSBDevicett+213
	0x000016dc	dd	0xffffff32, 0xffffff3c, 0xffffff46, 0xffffff46
	0x000016ec	dd	0xffffff50, 0xffffff5a, 0xffffff64, 0xffffff64
	0x000016fc	dd	0xffffff3e, 0xfffffab1, 0xfffffef8, 0xfffffef8; switch table, XREF=__Z9hwGetRateP11IOUSBDevicett+471
	0x0000170c	dd	0xffffff02, 0xffffff0c, 0xffffff16, 0xffffff16
	0x0000171c	dd	0xffffff20, 0xffffff2a, 0xffffff34, 0xffffff34
	0x0000172c	dd	0xffffff0e, 0xfffffa81, 0xfffffec8, 0xfffffec8; switch table, XREF=__Z9hwGetRateP11IOUSBDevicett+514
	0x0000173c	dd	0xfffffed2, 0xfffffedc, 0xfffffee6, 0xfffffee6
	0x0000174c	dd	0xfffffef0, 0xfffffefa, 0xffffff04, 0xffffff04
	0x0000175c	dd	0xfffffede, 0xfffffa51, 0xfffffe98, 0xfffffe98; switch table, XREF=__Z9hwGetRateP11IOUSBDevicett+726
	0x0000176c	dd	0xfffffea2, 0xfffffeac, 0xfffffeb6, 0xfffffeb6
	0x0000177c	dd	0xfffffec0, 0xfffffeca, 0xfffffed4, 0xfffffed4
	0x0000178c	dd	0xfffffeae, 0xfffffa21, 0xfffffe68, 0xfffffe68; switch table, XREF=__Z9hwGetRateP11IOUSBDevicett+1053
	0x0000179c	dd	0xfffffe72, 0xfffffe7c, 0xfffffe86, 0xfffffe86
	0x000017ac	dd	0xfffffe90, 0xfffffe9a, 0xfffffea4, 0xfffffea4
	0x000017bc	dd	0xfffffe7e, 0xfffff9f1, 0xfffffe38, 0xfffffe38; switch table, XREF=__Z9hwGetRateP11IOUSBDevicett+1091
	0x000017cc	dd	0xfffffe42, 0xfffffe4c, 0xfffffe56, 0xfffffe56
	0x000017dc	dd	0xfffffe60, 0xfffffe6a, 0xfffffe74, 0xfffffe74
	0x000017ec	dd	0xfffffe4e, 0xfffff9c1, 0xfffffe08, 0xfffffe08; switch table, XREF=__Z9hwGetRateP11IOUSBDevicett+1133
	0x000017fc	dd	0xfffffe12, 0xfffffe1c, 0xfffffe26, 0xfffffe26
	0x0000180c	dd	0xfffffe30, 0xfffffe3a, 0xfffffe44, 0xfffffe44
	0x0000181c	dd	0xfffffe1e, 0xfffff991, 0xfffffdd8, 0xfffffdd8; switch table, XREF=__Z9hwGetRateP11IOUSBDevicett+979
	0x0000182c	dd	0xfffffde2, 0xfffffdec, 0xfffffdf6, 0xfffffdf6
	0x0000183c	dd	0xfffffe00, 0xfffffe0a, 0xfffffe14, 0xfffffe14
	0x0000184c	dd	0xfffffdee, 0xfffff961, 0xfffffda8, 0xfffffda8; switch table, XREF=__Z9hwGetRateP11IOUSBDevicett+1252
	0x0000185c	dd	0xfffffdb2, 0xfffffdbc, 0xfffffdc6, 0xfffffdc6
	0x0000186c	dd	0xfffffdd0, 0xfffffdda, 0xfffffde4, 0xfffffde4

*/

}
