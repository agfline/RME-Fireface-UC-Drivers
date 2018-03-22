
hwGetStatusReg() {

/*
	hwGetStatusReg ( IOUSBDevice*, 		rdi	arg_1	IOUSBDevice
			 unsigned int*, 	rsi	arg_2	returned data
			 int			rdx	arg_3	wLength
		       )



	================ B E G I N N I N G   O F   P R O C E D U R E ================

	0x00000fe7	push	rbp
	0x00000fe8	mov	rbp, rsp
	0x00000feb	sub	rsp, 0x20
*/
	uint32_t len = 0;	// TODO: Does someone care ?


/*
	0x00000fef	mov	r8, rsi				; argument #5 for method
	0x00000ff2	lea	rax, qword [ss:rbp-0x04]
	0x00000ff6	mov	qword [ss:rsp+0x8], rax		; argument "var_18" for method
	0x00000ffb	mov	dword [ss:rsp], 0x1		; argument "var_10" for method
	0x00001002	shl	rdx, 0x2
	0x00001006	movzx	r9d, dx				; argument #6 for method
	0x0000100a	mov	esi, 0x11			; argument #2 for method
	0x0000100f	xor	edx, edx			; argument #3 for method
	0x00001011	xor	ecx, ecx			; argument #4 for method
	0x00001013	call	Usb_vendor_device_request( IOUSBDevice*, 
							   unsigned char, 
							   unsigned short,
							   unsigned short,
							   void*, 
							   unsigned short,
							   unsigned char,
							   unsigned int*
							 )
*/
	Usb_vendor_device_request( IOUSBDevice, 0x11, 0, 0, arg_2, (arg_3 << 0x02), 0x1, &len );

/*
	0x00001018	add	rsp, 0x20
	0x0000101c	pop	rbp
	0x0000101d	ret
			; endp
*/
	return;		// TODO: depends on Usb_vendor_device_request() return (eax ?)
			// 	 eax = &len ?	LAC
}

