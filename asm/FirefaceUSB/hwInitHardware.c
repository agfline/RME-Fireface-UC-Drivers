
#include <stdio.h>
#include <stdint.h>

#include "../libusb_test/usb.h"



void hwInitHardware ( libusb_device_handle *dev/*, uint16_t productId*/ )
{
	uint16_t productId = 0x3fc6;
	ctrl_setup ctrl;

/*
================ B E G I N N I N G   O F   P R O C E D U R E ================



		hwInitHardware ( IOUSBDevice*,   rdi
		                 unsigned short  rsi  productId
		               )


	0x00001d5d  push  rbp							; XREF 1
	0x00001d5e  mov   rbp, rsp
	0x00001d61  push  r15
	0x00001d63  push  r14
	0x00001d65  push  r12
	0x00001d67  push  rbx
	0x00001d68  sub   rsp, 0x90
*/

/*
	0x00001d6f  lea  eax, qword [ds:rsi+0xffffffffffffc036]
	0x00001d75  cmp  ax, 0x3
	0x00001d79  mov  rbx, rdi
	0x00001d7c  jb   0x1eb5

	0x00001d82  cmp  si, 0x3fc2
	0x00001d87  je   0x1eb5
*/

	// rbx = IOUSBDevice;

	if ( ( (uint16_t)((productId + 0xffffffffffffc036) & 0xffff) < 0x3 ) || // 0x3fc6 false
		 ( productId == 0x3fc2 ) )
	{

/*
		0x00001eb5  cmp  si, 0x3fc3							; XREF 2
		0x00001eba  jne  0x1f05
*/
		if ( productId == 0x3fc3 )
		{
/*
			0x00001ebc  mov  byte [ss:rbp+var_B0], 0x40		; XREF 1
			0x00001ec3  mov  byte [ss:rbp+var_AF], 0x10
			0x00001eca  mov  word [ss:rbp+var_AE], 0x88
			0x00001ed3  mov  word [ss:rbp+var_AC], 0x7fff
			0x00001edc  mov  word [ss:rbp+var_AA], 0x0
			0x00001ee5  mov  qword [ss:rbp+var_A8], 0x0
			0x00001ef0  mov  rax, qword [ds:rbx]
			0x00001ef3  lea  rsi, qword [ss:rbp+var_B0]
			0x00001efa  xor  edx, edx
			0x00001efc  mov  rdi, rbx
			0x00001eff  call qword [ds:rax+0x938]
*/
		}
/*
		0x00001f05  mov  byte [ss:rbp+var_38], 0x40			; XREF 4
		0x00001f09  mov  byte [ss:rbp+var_37], 0x10
		0x00001f0d  mov  word [ss:rbp+var_36], 0x800
		0x00001f13  mov  word [ss:rbp+var_34], 0x800
		0x00001f19  mov  word [ss:rbp+var_32], 0x0
		0x00001f1f  mov  qword [ss:rbp+var_30], 0x0
		0x00001f27  mov  rax, qword [ds:rbx]
		0x00001f2a  lea  rsi, qword [ss:rbp+var_38]
		0x00001f2e  xor  edx, edx
		0x00001f30  mov  rdi, rbx

		0x00001f33  call qword [ds:rax+0x938]			; XREF 1
		0x00001f39  add  rsp, 0x90
		0x00001f40  pop  rbx							; XREF 3
		0x00001f41  pop  r12
		0x00001f43  pop  r14
		0x00001f45  pop  r15
		0x00001f47  pop  rbp
		0x00001f48  ret
					; endp
*/
		return;

	}

/*
	0x00001d8d  cmp si, 0x3fc0
	0x00001d92  jg  0x1da0
*/
	if ( productId < 0x3fc0 )
	{
/*
		0x00001d94  cmp si, 0x3fa0
		0x00001d99  jne 0x1dc1			; end of if / else

		0x00001d9b  jmp 0x1f05
*/
		if ( productId == 0x3fa0 )
		{
/*
			0x00001f05  mov  byte [ss:rbp+var_38], 0x40		; XREF 4
			0x00001f09  mov  byte [ss:rbp+var_37], 0x10
			0x00001f0d  mov  word [ss:rbp+var_36], 0x800
			0x00001f13  mov  word [ss:rbp+var_34], 0x800
			0x00001f19  mov  word [ss:rbp+var_32], 0x0
			0x00001f1f  mov  qword [ss:rbp+var_30], 0x0
			0x00001f27  mov  rax, qword [ds:rbx]
			0x00001f2a  lea  rsi, qword [ss:rbp+var_38]
			0x00001f2e  xor  edx, edx
			0x00001f30  mov  rdi, rbx

			0x00001f33  call qword [ds:rax+0x938]		; XREF 1
			0x00001f39  add  rsp, 0x90
			0x00001f40  pop  rbx								; XREF 3
			0x00001f41  pop  r12
			0x00001f43  pop  r14
			0x00001f45  pop  r15
			0x00001f47  pop  rbp
			0x00001f48  ret
						; endp			; end of function
*/
			return;

		}

	}
	else
	{
/*
		0x00001da0  cmp  si, 0x3fc1						; XREF 1
		0x00001da5  je   0x1f05

		0x00001dab  cmp  si, 0x3fc3
		0x00001db0  je   0x1ebc

		0x00001db6  cmp  si, 0x3fc4
		0x00001dbb  je   0x1f05
										; end of if / else
*/
		if ( productId == 0x3fc1 || productId == 0x3fc4 )
		{
/*
			0x00001f05  mov  byte [ss:rbp+var_38], 0x40		; XREF 4
			0x00001f09  mov  byte [ss:rbp+var_37], 0x10
			0x00001f0d  mov  word [ss:rbp+var_36], 0x800
			0x00001f13  mov  word [ss:rbp+var_34], 0x800
			0x00001f19  mov  word [ss:rbp+var_32], 0x0
			0x00001f1f  mov  qword [ss:rbp+var_30], 0x0
			0x00001f27  mov  rax, qword [ds:rbx]
			0x00001f2a  lea  rsi, qword [ss:rbp+var_38]
			0x00001f2e  xor  edx, edx
			0x00001f30  mov  rdi, rbx

			0x00001f33  call qword [ds:rax+0x938]		; XREF 1
			0x00001f39  add  rsp, 0x90
			0x00001f40  pop  rbx								; XREF 3
			0x00001f41  pop  r12
			0x00001f43  pop  r14
			0x00001f45  pop  r15
			0x00001f47  pop  rbp
			0x00001f48  ret
						; endp			; end of function
*/
			return;

		}

		if ( productId == 0x3fc3 )
		{
/*
			0x00001ebc  mov  byte [ss:rbp+var_B0], 0x40		; XREF 1
			0x00001ec3  mov  byte [ss:rbp+var_AF], 0x10
			0x00001eca  mov  word [ss:rbp+var_AE], 0x88
			0x00001ed3  mov  word [ss:rbp+var_AC], 0x7fff
			0x00001edc  mov  word [ss:rbp+var_AA], 0x0
			0x00001ee5  mov  qword [ss:rbp+var_A8], 0x0
			0x00001ef0  mov  rax, qword [ds:rbx]
			0x00001ef3  lea  rsi, qword [ss:rbp+var_B0]
			0x00001efa  xor  edx, edx
			0x00001efc  mov  rdi, rbx
			0x00001eff  call qword [ds:rax+0x938]

			0x00001f05  mov  byte [ss:rbp+var_38], 0x40		; XREF 4
			0x00001f09  mov  byte [ss:rbp+var_37], 0x10
			0x00001f0d  mov  word [ss:rbp+var_36], 0x800
			0x00001f13  mov  word [ss:rbp+var_34], 0x800
			0x00001f19  mov  word [ss:rbp+var_32], 0x0
			0x00001f1f  mov  qword [ss:rbp+var_30], 0x0
			0x00001f27  mov  rax, qword [ds:rbx]
			0x00001f2a  lea  rsi, qword [ss:rbp+var_38]
			0x00001f2e  xor  edx, edx
			0x00001f30  mov  rdi, rbx

			0x00001f33  call qword [ds:rax+0x938]		; XREF 1
			0x00001f39  add  rsp, 0x90
			0x00001f40  pop  rbx								; XREF 3
			0x00001f41  pop  r12
			0x00001f43  pop  r14
			0x00001f45  pop  r15
			0x00001f47  pop  rbp
			0x00001f48  ret
						; endp			; end of function
*/
			return;

		}

	}

	/*** 0x3fc6 begins here ***/

/*
	0x00001dc1  xor  r14d, r14d							; XREF 1
	0x00001dc4  lea  r15, qword [ss:rbp+var_50]
	0x00001dc8  lea  r12, qword [ss:rbp+var_68]
*/
	int r14d = 0; // i

	// r15 = var_50; // second argument for the first  Usb_vendor_device_request() call inside the loop
	                 // pointer to the first  ctrl_setup struct on the stack.

	// r12 = var_68; // second argument for the second Usb_vendor_device_request() call inside the loop.
	                 // pointer to the second ctrl_setup struct on the stack.

	do {
/*
		0x00001dcc  mov  byte [ss:rbp+var_50], 0x40			; XREF 1
		0x00001dd0  mov  byte [ss:rbp+var_4F], 0x16
		0x00001dd4  mov  word [ss:rbp+var_4E], 0x1
		0x00001dda  mov  word [ss:rbp+var_4C], r14w
		0x00001ddf  mov  word [ss:rbp+var_4A], 0x0
		0x00001de5  mov  qword [ss:rbp+var_48], 0x0
		0x00001ded  mov  rax, qword [ds:rbx]
		0x00001df0  mov  rdi, rbx
		0x00001df3  mov  rsi, r15
		0x00001df6  xor  edx, edx
		0x00001df8  call qword [ds:rax+0x938]
*/

		ctrl.bmRequestType = 0x40;
		ctrl.bRequest  = 0x16;
		ctrl.wValue  = 0x0001;
		ctrl.wIndex  = (uint16_t)(r14d & 0xffff);
		ctrl.wLength = 0x0000;

		send_ctrl_setup( dev, &ctrl, NULL );

/*
		0x00001dfe  mov  byte [ss:rbp+var_68], 0x40
		0x00001e02  mov  byte [ss:rbp+var_67], 0x16
		0x00001e06  mov  word [ss:rbp+var_66], 0x1
		0x00001e0c  lea  eax, qword [ds:r14+0x20]
		0x00001e10  mov  word [ss:rbp+var_64], ax
		0x00001e14  mov  word [ss:rbp+var_62], 0x0
		0x00001e1a  mov  qword [ss:rbp+var_60], 0x0
		0x00001e22  mov  rax, qword [ds:rbx]
		0x00001e25  mov  rdi, rbx
		0x00001e28  mov  rsi, r12
		0x00001e2b  xor  edx, edx
		0x00001e2d  call qword [ds:rax+0x938]
*/

		ctrl.bmRequestType = 0x40;
		ctrl.bRequest  = 0x16;
		ctrl.wValue  = 0x0001;
		ctrl.wIndex  = (uint16_t)((r14d + 0x20) & 0xffff);
		ctrl.wLength = 0x0000;

		send_ctrl_setup( dev, &ctrl, NULL );

/*
		0x00001e33  inc  r14d
		0x00001e36  cmp  r14d, 0x12
		0x00001e3a  jne  0x1dcc
*/
		r14d++;

	} while ( r14d != 0x12 );

/*
	0x00001e3c  mov  byte [ss:rbp+var_80], 0x40
	0x00001e40  mov  byte [ss:rbp+var_7F], 0x10
	0x00001e44  mov  word [ss:rbp+var_7E], 0x800
	0x00001e4a  mov  word [ss:rbp+var_7C], 0xb800	; "/SPDIF 1"
	0x00001e50  mov  word [ss:rbp+var_7A], 0x0
	0x00001e56  mov  qword [ss:rbp+var_78], 0x0
	0x00001e5e  mov  rax, qword [ds:rbx]
	0x00001e61  lea  rsi, qword [ss:rbp+var_80]
	0x00001e65  mov  rdi, rbx
	0x00001e68  xor  edx, edx
	0x00001e6a  call qword [ds:rax+0x938]
*/

	ctrl.bmRequestType = 0x40;
	ctrl.bRequest  = 0x10;
	ctrl.wValue  = 0x0800;
	ctrl.wIndex  = 0xb800;
	ctrl.wLength = 0x0000;

	send_ctrl_setup( dev, &ctrl, NULL );

/*
	0x00001e70  mov  byte [ss:rbp+var_98], 0x40
	0x00001e77  mov  byte [ss:rbp+var_97], 0x20
	0x00001e7e  mov  word [ss:rbp+var_96], 0x1
	0x00001e87  mov  word [ss:rbp+var_94], 0x0
	0x00001e90  mov  word [ss:rbp+var_92], 0x0
	0x00001e99  mov  qword [ss:rbp+var_90], 0x0
	0x00001ea4  mov  rax, qword [ds:rbx]
	0x00001ea7  lea  rsi, qword [ss:rbp+var_98]
	0x00001eae  mov  rdi, rbx
	0x00001eb1  xor  edx, edx
	0x00001eb3  jmp  0x1f33

	0x00001f33  call qword [ds:rax+0x938]		; XREF 1
*/

	ctrl.bmRequestType = 0x40;
	ctrl.bRequest  = 0x20;
	ctrl.wValue  = 0x0001;
	ctrl.wIndex  = 0x0000;
	ctrl.wLength = 0x0000;

	send_ctrl_setup( dev, &ctrl, NULL );

/*
	0x00001f39  add  rsp, 0x90
	0x00001f40  pop  rbx								; XREF 3
	0x00001f41  pop  r12
	0x00001f43  pop  r14
	0x00001f45  pop  r15
	0x00001f47  pop  rbp
	0x00001f48  ret
				; endp
*/
	return;

}
