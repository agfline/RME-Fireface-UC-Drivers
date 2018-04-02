

uint32_t ufx_id_to_freq ( int id )
{

/*
	================ B E G I N N I N G   O F   P R O C E D U R E ================



		ufx_id_to_freq ( int )


	0x0000106f  push rbp
	0x00001070  mov  rbp, rsp
	0x00001073  cmp  edi, 0xb
	0x00001076  ja   0x10c9
*/
	if ( id > 11 )
	{
		return 0;
	}

/*
	0x00001078  mov    eax, edi
	0x0000107a  lea    rcx, qword [ds:0x10d0]
	0x00001081  movsxd rax, dword [ds:rcx+rax*4]
	0x00001085  add    rax, rcx
	0x00001088  jmp    rax			; switch statement with 12 cases
*/
	switch ( id )
	{
/*

	0x0000108a  mov  eax, 0x7d00			; case 0
	0x0000108f  pop  rbp
	0x00001090  ret
*/
		case 0:		return 0x7d00;	/* 32000 Hz */
/*
	0x00001091  mov  eax, 0xac44			; case 1
	0x00001096  pop  rbp
	0x00001097  ret
*/
		case 1:		return 0xac44;	/* 44100 Hz */
/*
	0x00001098  mov  eax, 0xbb80			; case 3
	0x0000109d  pop  rbp
	0x0000109e  ret
*/
		case 2:
		case 3:		return 0xbb80;	/* 48000 Hz*/
/*
	0x0000109f  mov  eax, 0xfa00			; case 4
	0x000010a4  pop  rbp
	0x000010a5  ret
*/
		case 4:		return 0xfa00;	/* 64000 Hz */
/*
	0x000010a6  mov  eax, 0x15888		; case 5
	0x000010ab  pop  rbp
	0x000010ac  ret
*/
		case 5:		return 0x15888;	/* 88200 Hz */
/*
	0x000010ad  mov  eax, 0x17700		; case 7
	0x000010b2  pop  rbp
	0x000010b3  ret
*/
		case 6:
		case 7:		return 0x17700;	/* 96000 Hz */
/*
	0x000010b4  mov  eax, 0x1f400		; case 8
	0x000010b9  pop  rbp
	0x000010ba  ret
*/
		case 8:		return 0x1f400;	/* 128000 Hz */
/*
	0x000010bb  mov  eax, 0x2b110		; case 9
	0x000010c0  pop  rbp
	0x000010c1  ret
*/
		case 9:		return 0x2b110;	/* 176400 Hz */
/*
	0x000010c2  mov  eax, 0x2ee00		; case 11
	0x000010c7  pop  rbp
	0x000010c8  ret
*/
		case 10:
		case 11:	return 0x2ee00;	/* 192000 Hz */
/*
	0x000010c9  xor  eax, eax
	0x000010cb  pop  rbp
	0x000010cc  ret
			; endp
*/
		default:	return 0;

	}

/*
	0x000010cd  nop  qword [ds:rax]
	0x000010d0  dd   0xffffffba, 0xffffffc1, 0xffffffc8, 0xffffffc8		; switch table
	0x000010e0  dd   0xffffffcf, 0xffffffd6, 0xffffffdd, 0xffffffdd
	0x000010f0  dd   0xffffffe4, 0xffffffeb, 0xfffffff2, 0xfffffff2

*/

}
