/*
================ B E G I N N I N G   O F   P R O C E D U R E ================


	rsi contains one of the following values :

		0x160001	CH_1 : +48v on		0x40 0x17 0x0001 0x0001 0x0000
		0x160000	CH_1 : +48v off		0x40 0x17 0x0000 0x0001 0x0000

		0x170001	CH_2 : +48v on		0x40 0x17 0x0002 0x0002 0x0000
		0x170000	CH_2 : +48v off		0x40 0x17 0x0000 0x0002 0x0000

		0x200001	CH_3 : PAD  on		0x40 0x17 0x0008 0x0008 0x0000
		0x200000	CH_3 : PAD  off		0x40 0x17 0x0000 0x0008 0x0000

		0x1c0001	CH_3 : INST on		0x40 0x17 0x0020 0x0020 0x0000
		0x1c0000	CH_3 : INST off		0x40 0x17 0x0000 0x0020 0x0000

		0x210001	CH_4 : PAD  on		0x40 0x17 0x0004 0x0004 0x0000
		0x210000	CH_4 : PAD  off		0x40 0x17 0x0000 0x0004 0x0000

		0x1d0001	CH_4 : INST on		0x40 0x17 0x0010 0x0010 0x0000
		0x1d0000	CH_4 : INST off		0x40 0x17 0x0000 0x0010 0x0000

	CCardIOUC::WriteDWORD( unsigned int	rsi	val
			     )

	0x100061eaa	push	rbp
	0x100061eab	mov	rbp, rsp
	0x100061eae	push	rbx
	0x100061eaf	sub	rsp, 0x28
	0x100061eb3	mov	rbx, qword [ds:imp___got____stack_chk_guard]
	0x100061eba	mov	rbx, qword [ds:rbx]
	0x100061ebd	mov	qword [ss:rbp+var_10], rbx
*/
	// Stack Smashing Protector stuff ?

/*
	0x100061ec1	mov	eax, esi
	0x100061ec3	sar	eax, 0x10
	0x100061ec6	cmp	eax, 0x12
	0x100061ec9	jl	0x100061ef6

	0x100061ecb	add	eax, 0xffffffea
	0x100061ece	cmp	eax, 0xb
	0x100061ed1	ja	0x100061ef6
*/
	if ( ((val >> 0x10) < 0x12) ||
 	      (val >> 0x10) + 0xffffffea > 0xb ) )
	{
/*
		0x100061ef6	mov	byte [ds:rdi+0x2a0], 0x1	; case 9
		0x100061efd	mov	al, 0x1
		0x100061eff	jmp	0x100061ff4
*/
		return 1;
	}


/*
	0x100061ed3	lea	rcx, qword [ds:0x10006200c]
	0x100061eda	movsxd	rax, dword [ds:rcx+rax*4]
	0x100061ede	add	rax, rcx
	0x100061ee1	jmp	rax				; switch statement with 12 cases
*/
	switch ( (val >> 0x10) + 0xffffffea ) {
/*
		0x100061ee3	test	si, si				; case 0
		0x100061ee6	setne	al
		0x100061ee9	movzx	esi, al
		0x100061eec	mov	eax, 0x1
		0x100061ef1	jmp	0x100061fc0
*/
		case 0:	// Channel 1 : +48v
			if ( (val & 0x0000ffff) > 0 )	// if on
				wValue = 0x0001;
			else				// if off
				wValue = 0x0000;

			wIndex = 0x0001;

			break;
/*
		0x100061ef6	mov	byte [ds:rdi+0x2a0], 0x1	; case 2, 3, 4, 5, 8, 9
		0x100061efd	mov	al, 0x1
		0x100061eff	jmp	0x100061ff4
*/
		case 2:
		case 3:
		case 4:
		case 5:
		case 8:
		case 9:

			return 1;
/*
		0x100061f04	test	si, si				; case 1
		0x100061f07	setne	al
		0x100061f0a	movzx	esi, al
		0x100061f0d	add	rsi, rsi
		0x100061f10	mov	eax, 0x2
		0x100061f15	jmp	0x100061fc0
*/
		case 1:	// Channel 2 : +48v
			if ( (val & 0x0000ffff) > 0 )	// if on
				wValue = 0x0002;
			else				// if off
				wValue = 0x0000;

			wIndex = 0x0002;

			break;
/*
		0x100061f1a	test	si, si				; case 6
		0x100061f1d	setne	al
		0x100061f20	movzx	esi, al
		0x100061f23	shl	rsi, 0x5
		0x100061f27	mov	eax, 0x20
		0x100061f2c	jmp	0x100061fc0
*/
		case 6:	// Channel 3 : INST
			if ( (val & 0x0000ffff) > 0 )	// if on
				wValue = 0x0020;
			else				// if off
				wValue = 0x0000;

			wIndex = 0x0020;

			break;
/*
		0x100061f31	test	si, si				; case 7
		0x100061f34	setne	al
		0x100061f37	movzx	esi, al
		0x100061f3a	shl	rsi, 0x4
		0x100061f3e	mov	eax, 0x10
		0x100061f43	jmp	0x100061fc0
*/
		case 7: // Channel 4 : INST
			if ( (val & 0x0000ffff) > 0 )	// if on
				wValue = 0x0010;
			else				// if off
				wValue = 0x0000;

			wIndex = 0x0010;

			break;
/*
		0x100061f45	cmp	byte [ds:rdi+0x2a8], 0x0	; case 10
		0x100061f4c	je	0x100061f9a
*/
		case 10: // Channel 3 : PAD
			if ( /*TODO*/ == 0 ) {
/*
				0x100061f9a	test	si, si
				0x100061f9d	setne	al
				0x100061fa0	movzx	esi, al
				0x100061fa3	shl	rsi, 0x3
				0x100061fa7	mov	eax, 0x8
				0x100061fac	jmp	0x100061fc0
*/
				if ( (val & 0x0000ffff) > 0 )	// if on
					wValue = 0x0008;
				else				// if off
					wValue = 0x0000;

				wIndex = 0x0008;

			} else {

/*
				0x100061f4e	test	si, si
				0x100061f51	sete	al
				0x100061f54	movzx	eax, al
				0x100061f57	shl	rax, 0xf
				0x100061f5b	and	esi, 0x2
				0x100061f5e	shl	rsi, 0x2
				0x100061f62	or	rsi, rax
				0x100061f65	xor	rsi, 0x8
				; rsi = (((val & 0x2) << 0x2) | (1 << 0xf)) ^ 0x8 = 0x8008
				0x100061f69	mov	eax, 0x8008
				0x100061f6e	jmp	0x100061fc0
*/
				if ( (val & 0x0000ffff) > 0 )	// if on
					wValue = 0x8008;
				else				// if off
					wValue = 0x0000;

				wIndex = 0x8008;
			}

			break;
/*
		0x100061f70	cmp	byte [ds:rdi+0x2a8], 0x0	; case 11
		0x100061f77	je	0x100061fae
*/
		case 11: // Channel 4 : PAD

			if ( /*TODO*/ == 0 ) {
/*
				0x100061fae	test	si, si
				0x100061fb1	setne	al
				0x100061fb4	movzx	esi, al
				0x100061fb7	shl	rsi, 0x2
				0x100061fbb	mov	eax, 0x4
*/
				if ( (val & 0x0000ffff) > 0 )	// if on
					wValue = 0x0004;
				else				// if off
					wValue = 0x0000;

				wIndex = 0x0004;

			} else {
/*
				0x100061f79	test	si, si
				0x100061f7c	sete	al
				0x100061f7f	movzx	eax, al
				0x100061f82	shl	rax, 0xe
				0x100061f86	and	esi, 0x2
				0x100061f89	add	rsi, rsi
				0x100061f8c	or	rsi, rax
				0x100061f8f	xor	rsi, 0x4
				; rsi = (((val & 0x2) * 2) | (0x1 << 0xe)) ^ 0x4 = 0x4004
				0x100061f93	mov	eax, 0x4004
				0x100061f98	jmp	0x100061fc0
*/
				if ( (val & 0x0000ffff) > 0 )	// if on
					wValue = 0x4004;
				else				// if off
					wValue = 0x0000;

				wIndex = 0x4004;

			}

			break

	}
/*

	0x100061fc0	mov	qword [ss:rbp+var_20], rsi	; wValue
	0x100061fc4	mov	qword [ss:rbp+var_18], rax	; wIndex
	0x100061fc8	mov	dword [ss:rbp+var_24], 0x0
	0x100061fcf	mov	edi, dword [ds:rdi+0x2a4]	; argument "connection" for method
	0x100061fd5	lea	rdx, qword [ss:rbp+var_20]	; argument "input"      for method
	0x100061fd9	lea	r9, qword [ss:rbp+var_24]	; argument "outputCnt"  for method
	0x100061fdd	mov	esi, 0x4			; argument "selector"   for method
	0x100061fe2	mov	ecx, 0x2			; argument "inputCnt"   for method
	0x100061fe7	xor	r8d, r8d			; argument "output"     for method
	0x100061fea	call	imp___stubs__IOConnectCallScalarMethod
	0x100061fef	test	eax, eax
	0x100061ff1	sete	al

	0x100061ff4	cmp	rbx, qword [ss:rbp+var_10]	; XREF=__ZN9CCardIOUC10WriteDWORDEj+85
	0x100061ff8	jne	0x100062004

	0x100061ffa	movzx	eax, al
	0x100061ffd	add	rsp, 0x28
	0x100062001	pop	rbx
	0x100062002	pop	rbp
	0x100062003	ret

	0x100062004	call	imp___stubs____stack_chk_fail	; XREF=__ZN9CCardIOUC10WriteDWORDEj+334
			; endp
	0x100062009	nop	qword [ds:rax]
	0x10006200c	dd	0xfffffed7, 0xfffffef8, 0xfffffeea, 0xfffffeea ; switch table
	0x10006201c	dd	0xfffffeea, 0xfffffeea, 0xffffff0e, 0xffffff25
	0x10006202c	dd	0xfffffeea, 0xfffffeea, 0xffffff39, 0xffffff64
*/
