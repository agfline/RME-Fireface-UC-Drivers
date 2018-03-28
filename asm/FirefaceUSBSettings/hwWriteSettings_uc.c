
/*
	We know the structure FirefaceSettings from print_settings() function.
	Thank you sooo much guys ;) !!!

		rsi	     = ClockSource
		rsi+0x4  = SingleSpeed
		rsi+0x8  = SpdifOptical
		rsi+0xc  = Professional
		rsi+0x10 = InputLevel
		rsi+0x14 = OutputLevel
		rsi+0x18 = PhonesLevel
		rsi+0x1c = SpdifInput
		rsi+0x20 = BypassDSP
		rsi+0x24 = ???
*/

struct FirefaceSettings {

	unsigned int ClockSource;
	int SingleSpeed;
	int SpdifOptical;
	int Professional;
	signed int InputLevel;
	int OutputLevel;
	int PhonesLevel;
	int SpdifInput;
	int BypassDSP;

	int UNKNOWN;
};

/*
	This function has equivalents for other RME products :

		hwWriteSettings_ufx()
		hwWriteSettings_bf()
		hwWriteSettings_Madiface()
		hwWriteSettings_Madiface_USB()
		hwWriteSettings_Madiface_Pro()
		hwWriteSettings_UFXP()
		hwWriteSettings_UFX2()
		hwWriteSettings_Digiface_USB()

	Note the absence of UCX dedicated function.
	Therefore, the UCX productID could be one
	of the bolow 0x3fc9 or 0x3fcf.
*/

/*

================ B E G I N N I N G   O F   P R O C E D U R E ================



	hwWriteSettings_uc ( IOUSBDeviceStruct245**   rdi
	                     FirefaceSettings*        rsi	// FFSettings
	                     int                      rdx	// productId
	                     int                      rcx
	                   )

	0x100001606	push     rbp
	0x100001607	mov	rbp, rsp
	0x10000160a	push     r15
	0x10000160c	push     r14
	0x10000160e	push     rbx
	0x10000160f	sub	rsp, 0x28
*/

/*
	0x100001613	mov	r14, rdi
	0x100001616	cmp	edx, 0x3fc9
	0x10000161c	jne	0x10000163f
*/

//	int r15d = 0;	// from 0x10000163f


	if ( productId == 0x3fc9 )
	{
/*
		0x10000161e	cmp	dword [ds:rsi+0x24], 0x0
		0x100001622	setne	al
		0x100001625	movzx	eax, al
		0x100001628	shl	eax, 0x3
		0x10000162b	cmp	dword [ds:rsi+0x20], 0x0
		0x10000162f	sete	cl
		0x100001632	movzx	r15d, cl
		0x100001636	shl	r15d, 0x8
		0x10000163a	or	r15d, eax
		0x10000163d	jmp	0x100001675			; end of else / if
*/
		// TODO
/*
	0x10000163f	xor	r15d, r15d
	0x100001642	cmp	edx, 0x3fcf
	0x100001648	jne	0x100001675
*/
	}
	else if ( productId == 0x3fcf )
	{
/*
		0x10000164a	and	ecx, 0x7fff
		0x100001650	cmp	ecx, 0x85
		0x100001656	jb	0x100001675
*/
		if ( (ecx & 0x7fff) >= 0x85 )
		{
/*
			0x100001658	cmp	dword [ds:rsi+0x24], 0x0
			0x10000165c	setne	al
			0x10000165f	movzx	r15d, al
			0x100001663	mov	eax, dword [ds:rsi]
			0x100001665	cmp	eax, 0x3
			0x100001668	je	0x1000016a5
*/
			// TODO
/*
			0x10000166a	cmp	eax, 0x2
			0x10000166d	jne	0x1000016ab
*/
			// TODO
/*
			0x10000166f	or	r15d, 0x4
			0x100001673	jmp	0x1000016b4
*/
			// TODO
		}
	}





	/*** Set ClockSource ***/

/*
	0x100001675	mov	eax, dword [ds:rsi]
	0x100001677	cmp	rax, 0x3
	0x10000167b	ja	0x1000016b4
*/
	if ( FFSettings->ClockSource <= 0x3 ) {
/*
		0x10000167d	lea	rcx, qword [ds:0x1000017e8]
		0x100001684	movsxd	rax, dword [ds:rcx+rax*4]
		0x100001688	add	rax, rcx
		0x10000168b	jmp	rax				; switch statement with 4 cases

		0x10000168d	or	r15d, 0x1			; case 0
		0x100001691	jmp	0x1000016b4

		0x100001693	or	r15d, 0x6			; case 1
		0x100001697	jmp	0x1000016b4

		0x100001699	or	r15d, 0x4			; case 2
		0x10000169d	jmp	0x1000016b4

		0x10000169f	or	r15d, 0x2			; case 3
		0x1000016a3	jmp	0x1000016b4
*/
		switch ( FFSettings->ClockSource ) {
			case 0:		p2_wValue |= 0x1;	break;	// internal
			case 1:		p2_wValue |= 0x6;	break;	// WordClock
			case 2:		p2_wValue |= 0x4;	break;	// Optical
			case 3:		p2_wValue |= 0x2;	break;	// Coaxial
		}

/* TODO: The following is called above : 0x100001668	je	0x1000016a5

;	0x1000016a5	or	r15d, 0x2			; XREF
:	0x1000016a9	jmp	0x1000016b4

:	0x1000016ab	cmp	eax, 0x1			; XREF
:	0x1000016ae	jne	0x1000016b4

;	0x1000016b0	or	r15d, 0x6
*/
	}





	/*** Set SingleSpeed ***/

/*
	0x1000016b4	cmp	dword [ds:rsi+0x4], 0x0		; XREF
	0x1000016b8	setne	r9b
*/

	if ( FFSettings->SingleSpeed != 0 )	 singleSpeed_flag  = 0x1;	// r9b
	else                                 singleSpeed_flag  = 0x0;	// r9b


	/*** Set SPDIF ***/

/*
	0x1000016bc	cmp	dword [ds:rsi+0x8], 0x0
	0x1000016c0	setne	r8b
*/

	if ( FFSettings->SpdifOptical != 0 ) spdifOptical_flag = 0x1;	// r8b
	else                                 spdifOptical_flag = 0x0;	// r8b


	/*** Set AES ***/

/*
	0x1000016c4	cmp	dword [ds:rsi+0xc], 0x0
	0x1000016c8	setne	cl
*/

	if ( FFSettings->Professional != 0 ) professional_flag = 0x1;	// cl
	else                                 professional_flag = 0x0;	// cl


	/*** Set Input Level ***/

/*
	0x1000016cb	movsxd	rdi, dword [ds:rsi+0x10]	; rdi = InputLevel
	0x1000016cf	xor	eax, eax
	0x1000016d1	cmp	rdi, 0x2
	0x1000016d5	ja	0x1000016e1
*/

	if ( FFSettings->InputLevel <= 0x2 )
	{

/*
		0x1000016d7	lea	rax, qword [ds:0x10000ad50]	; 0x0000010000000000
		0x1000016de	mov	eax, dword [ds:rax+rdi*4]
*/

		p1_wValue = (0x0000010000000000 + FFSettings->InputLevel * 4);

		/*  looks like :
		 *  	0x00	Low Gain
		 *  	0x40	+4dBu
		 *  	0xc0	-10dBV
		 */
	}

/*
	0x1000016e1	movzx	edi, r9b			; XREF
	0x1000016e5	movzx	r9d, r8b
	0x1000016e9	movzx	r8d, cl
	0x1000016ed	mov	ecx, dword [ds:rsi+0x14]
	0x1000016f0	cmp	ecx, 0x2
	0x1000016f3	je	0x100001701
*/

//	edi = r9b		// edi = singleSpeed_mask
//	r9d = r8b		// r9d = spdifOptical_mask
//	r8d = cl		// r8d = professional_mask

	if ( FFSettings->OutputLevel != 0x2 )
	{
/*
		0x1000016f5	cmp	ecx, 0x1
		0x1000016f8	jne	0x100001706
*/
		if ( FFSettings->OutputLevel != 0x1 )
		{
/*
			0x100001706	test	ecx, ecx	; XREF
			0x100001708	jne	0x10000170f

			0x10000170a	or	eax, 0x80
*/
			if ( FFSettings->OutputLevel == 0 )
				p1_wValue |= 0x80;	// Hi Gain

		}
		else
		{
/*
			0x1000016fa	or	eax, 0xc0
			0x1000016ff	jmp	0x10000170f
*/
			p1_wValue |= 0xc0;	// +4dBu
		}

	}
	else
	{
/*
		0x100001701	or	eax, 0x40		; XREF
		0x100001704	jmp	0x10000170f
*/
		p1_wValue |= 0x40;	// -10dBV
	}
/*
;	0x100001706	test	ecx, ecx			; XREF
;	0x100001708	jne	0x10000170f

;	0x10000170a	or	eax, 0x80

	0x10000170f	shl	edi, 0x6			; XREF
	0x100001712	shl	r9d, 0xa
	0x100001716	shl	r8d, 0x7
	0x10000171a	mov	ecx, dword [ds:rsi+0x18]
	0x10000171d	cmp	ecx, 0x2
	0x100001720	je	0x10000172e
*/
	singleSpeed_flag  <<= 0x6;	// edi
	spdifOptical_flag <<= 0xa;	// r9d
	professional_flag <<= 0x7;	// r8d

	if ( FFSettings->PhonesLevel != 0x2 )
	{
/*
		0x100001722	cmp	ecx, 0x1
		0x100001725	jne	0x100001735
*/
		if ( FFSettings->PhonesLevel != 0x1 )
		{
/*
			0x100001735	test	ecx, ecx	 XREF
			0x100001737	jne	0x10000173e		; end of else / if

			0x100001739	or	eax, 0x400
									; end of else / if
*/
			if ( FFSettings->PhonesLevel == 0 )
				p1_wValue |= 0x400;	// Hi Gain
		}
		else
		{
/*
			0x100001727	or	eax, 0xc00
			0x10000172c	jmp	0x10000173e		; end of else / if
*/
			p1_wValue |= 0xc00;	// + 4dBu
		}

	}
	else
	{
/*
		0x10000172e	or	eax, 0x800		; XREF
		0x100001733	jmp	0x10000173e			; end of else / if
*/
		p1_wValue |= 0x800;	// -10 dBV
	}
/*

;	0x100001735	test	ecx, ecx			; XREF
;	0x100001737	jne	0x10000173e

;	0x100001739	or	eax, 0x400

	0x10000173e	or	r15d, edi				; XREF
	0x100001741	or	r15d, r9d
	0x100001744	or	r15d, r8d
	0x100001747	or	r15d, 0x4200
	0x10000174e	cmp	edx, 0x3fc9
	0x100001754	mov	cx, 0x47cf
	0x100001758	mov	bx, 0x46cf
	0x10000175c	cmove	bx, cx
*/
	p2_wValue |= singleSpeed_flag;
	p2_wValue |= spdifOptical_flag;
	p2_wValue |= professional_flag;
	p2_wValue |= 0x4200;

	if ( productId == 0x3fc9 )	p2_wIndex = 0x47cf;	// bx
	else                        p2_wIndex = 0x46cf;	// bx

/*
	0x100001760	mov	byte [ss:rbp+var_38], 0x40		; p1_bmRequestType
	0x100001764	mov	byte [ss:rbp+var_37], 0x17		; p1_bRequest
	0x100001768	mov	word [ss:rbp+var_36], ax		; p1_wValue
	0x10000176c	mov	word [ss:rbp+var_34], 0xfc0		; p1_wIndex
	0x100001772	mov	word [ss:rbp+var_32], 0x0		; p1_wLength
	0x100001778	mov	qword [ss:rbp+var_30], 0x0		; null pointer for data response ?

	0x100001780	mov	dword [ss:rbp+var_24], 0x1e		; unknown
	0x100001787	mov	dword [ss:rbp+var_20], 0x1e		; unknown

	0x10000178e	mov	rax, qword [ds:r14]
	0x100001791	lea	rsi, qword [ss:rbp+var_38]
	0x100001795	mov	rdi, r14
	0x100001798	call	qword [ds:rax+0xf0]			; IOUSBDeviceStruct245 + 0xf0
												 	; This call is the same as in Usb_vendor_device_request().
												 	; This call should be to send USB Setup packet
*/



/*
	0x10000179e	mov	byte [ss:rbp+var_38], 0x40		; p1_bmRequestType
	0x1000017a2	mov	byte [ss:rbp+var_37], 0x10		; p1_bRequest
	0x1000017a6	mov	word [ss:rbp+var_36], r15w		; p2_wValue
	0x1000017ab	mov	word [ss:rbp+var_34], bx		; p2_wIndex
	0x1000017af	mov	word [ss:rbp+var_32], 0x0		; p1_wLength
	0x1000017b5	mov	qword [ss:rbp+var_30], 0x0		; null pointer for data response ?

	0x1000017bd	mov	dword [ss:rbp+var_24], 0x1e		; unknown
	0x1000017c4	mov	dword [ss:rbp+var_20], 0x1e		; unknown

	0x1000017cb	mov	rax, qword [ds:r14]
	0x1000017ce	lea	rsi, qword [ss:rbp+var_38]
	0x1000017d2	mov	rdi, r14
	0x1000017d5	call	qword [ds:rax+0xf0]			; IOUSBDeviceStruct245 + 0xf0
												 	; This call is the same as in Usb_vendor_device_request().
												 	; This call should be to send USB Setup packet
*/

/*
	0x1000017db	add	rsp, 0x28
	0x1000017df	pop	rbx
	0x1000017e0	pop	r14
	0x1000017e2	pop	r15
	0x1000017e4	pop	rbp
	0x1000017e5	ret
		; endp
	0x1000017e6	nop
	0x1000017e8	dd	0xfffffea5, 0xfffffeab, 0xfffffeb1, 0xfffffeb7 		; ClockSource switch table

*/
