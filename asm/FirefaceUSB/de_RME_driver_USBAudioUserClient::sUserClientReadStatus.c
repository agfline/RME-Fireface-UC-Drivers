
#include <stdio.h>
#include <stdint.h>

#include "../libusb_test/usb.h"


int sUserClientReadStatus( libusb_device_handle *dev, /*uint32_t productId,*/ uint32_t *status )
{
    uint16_t productId = 0x3fc6;

    ctrl_setup ctrl;

/*
================ B E G I N N I N G   O F   P R O C E D U R E ================



             de_RME_driver_USBAudioUserClient::sUserClientReadStatus (
                                                                       de_RME_driver_USBAudioDevice*,
                                                                       void*,
                                                                       IOExternalMethodArguments*
                                                                     )

0x00009cac     push   rbp
0x00009cad     mov    rbp, rsp
0x00009cb0     push   r14
0x00009cb2     push   rbx
0x00009cb3     sub    rsp, 0x30
*/

/*
    0x00009cb7     mov    dword [ss:rbp+var_28], 0x8
*/
    // uint32_t var_28 = 0x8;

/*
    0x00009cbe     movzx   eax, word [ds:rdi+0x124]            ; contains the productId
    0x00009cc5     lea     ecx, qword [ds:rax+0xffffffffffffc036]
    0x00009ccb     cmp     cx, 0x3
    0x00009ccf     mov     rbx, rdx
    0x00009cd2     jb      0x9cfb

    0x00009cd4     cmp     ax, 0x3fc2
    0x00009cd8     je      0x9cfb

    0x00009cda     cmp     ax, 0x3fc1
    0x00009cde     je      0x9cfb

    0x00009ce0     cmp     ax, 0x3fa0
    0x00009ce4     je      0x9cfb

    0x00009ce6     cmp     ax, 0x3fc4
    0x00009cea     je      0x9cfb
*/

    /* 0x3fc6 false */

    if ( ( (uint16_t)((productId + 0xffffc036) & 0xffff) < 0x3 ) ||
         ( productId == 0x3fc2 ) ||
         ( productId == 0x3fc1 ) ||
         ( productId == 0x3fc0 ) ||
         ( productId == 0x3fc4 ) )
    {
        // TODO: WTF ? can never be 0x3fc3
/*
        0x00009cfb     cmp    ax, 0x3fc3                ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+38, __ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+44, __ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+50, __ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+56, __ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+62
        0x00009cff     mov    rdi, qword [ds:rdi+0xf0]
        0x00009d06     jne    0x9d38
*/
        if ( productId != 0x3fc3 )
        {
/*
            0x00009d38     lea    rax, qword [ss:rbp+var_28]        ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+90
            0x00009d3c     mov    qword [ss:rsp+0x8], rax
            0x00009d41     mov    dword [ss:rsp], 0x1
            0x00009d48     mov    esi, 0x11
            0x00009d4d     xor    edx, edx
            0x00009d4f     lea    r8, qword [ss:rbp+var_24]
            0x00009d53     mov    r9d, 0x10
            0x00009d59     jmp    0x9da0

            0x00009da0     xor    ecx, ecx                ; argument #4 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj, XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+173
            0x00009da2     call   Usb_vendor_device_request(IOUSBDevice*, unsigned char, unsigned short, unsigned short, void*, unsigned short, unsigned char, unsigned int*)
*/

            // next is 0x00009da7
        }
        else
        {
/*
            0x00009d08     lea    r8, qword [ss:rbp+var_24]   ; argument #5 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj, XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+77
            0x00009d0c     lea    rax, qword [ss:rbp+var_28]
            0x00009d10     mov    qword [ss:rsp+0x8], rax     ; argument "var_18" for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
            0x00009d15     mov    dword [ss:rsp], 0x1         ; argument "var_10" for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
            0x00009d1c     mov    esi, 0x11                   ; argument #2 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
            0x00009d21     xor    edx, edx                    ; argument #3 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
            0x00009d23     mov    r9d, 0x14                   ; argument #6 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
            0x00009d29     xor    ecx, ecx                    ; argument #4 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
            0x00009d2b     call   Usb_vendor_device_request(IOUSBDevice*, unsigned char, unsigned short, unsigned short, void*, unsigned short, unsigned char, unsigned int*)
            0x00009d30     mov    ecx, dword [ss:rbp+var_14]
            0x00009d33     mov    dword [ss:rbp+var_18], ecx
            0x00009d36     jmp    0x9da7
*/
        }
/*
        0x00009da7     mov    r14d, eax                       ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+138
        0x00009daa     mov    rdi, qword [ds:rbx+0x58]        ; argument "dst" for method _memcpy
        0x00009dae     lea    rsi, qword [ss:rbp+var_24]      ; argument "src" for method _memcpy
        0x00009db2     mov    edx, 0x10                       ; argument "n" for method _memcpy
        0x00009db7     call       _memcpy
        0x00009dbc     mov    eax, r14d
        0x00009dbf     add    rsp, 0x30
        0x00009dc3     pop    rbx
        0x00009dc4     pop    r14
        0x00009dc6     pop    rbp
        0x00009dc7     ret
                    ; endp
*/
    }
/*
    0x00009cec     cmp    ax, 0x3fc3
    0x00009cf0     jne    0x9d5b
*/

    /* 0x3fc6 true */

    else if ( productId != 0x3fc3 )
    {
/*
        0x00009d5b     cmp    ax, 0x3fc0                      ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+68
        0x00009d5f     mov    rdi, qword [ds:rdi+0xf0]        ; NOTE pointer to IOUSBDevice*, argument #1 for method Usb_vendor_device_request()
        0x00009d66     je     0x9d7f
*/

        if ( productId == 0x3fc0 )
        {
/*
            0x00009d7f     lea    rax, qword [ss:rbp+var_28]   ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+186
            0x00009d83     mov    qword [ss:rsp+0x8], rax
            0x00009d88     mov    dword [ss:rsp], 0x1          ; 0x1 -> 0xc0
            0x00009d8f     mov    esi, 0x17                    ; argument #2 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
*/

            // next is 0x00009d94
        }

        else
        {
/*
            0x00009d68     lea    rax, qword [ss:rbp+var_28]
            0x00009d6c     mov    qword [ss:rsp+0x8], rax
            0x00009d71     mov    dword [ss:rsp], 0x1            ; 0x1 -> 0xc0
            0x00009d78     mov    esi, 0x19                      ; argument #2 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
            0x00009d7d     jmp    0x9d94
*/
            ctrl.bmRequestType = 0xc0;
            ctrl.bRequest = 0x19;
        }
/*
        0x00009d94     xor    edx, edx                        ; argument #3 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj, XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+209
        0x00009d96     lea    r8, qword [ss:rbp+var_24]       ; argument #5 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
        0x00009d9a     mov    r9d, 0x4                        ; argument #6 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj

        0x00009da0     xor    ecx, ecx                        ; argument #4 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj, XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+173
        0x00009da2     call   Usb_vendor_device_request(IOUSBDevice*, unsigned char, unsigned short, unsigned short, void*, unsigned short, unsigned char, unsigned int*)
*/
        ctrl.wValue = 0x0000;
        ctrl.wIndex = 0x0000;
        ctrl.wLength = 0x0004;

        int rc = send_ctrl_setup( dev, &ctrl, (unsigned char*)status );
/*
        0x00009da7     mov    r14d, eax                       ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+138
        0x00009daa     mov    rdi, qword [ds:rbx+0x58]        ; argument "dst" for method _memcpy
        0x00009dae     lea    rsi, qword [ss:rbp+var_24]      ; argument "src" for method _memcpy
        0x00009db2     mov    edx, 0x10                       ; argument "n" for method _memcpy
        0x00009db7     call   _memcpy
        0x00009dbc     mov    eax, r14d
        0x00009dbf     add    rsp, 0x30
        0x00009dc3     pop    rbx
        0x00009dc4     pop    r14
        0x00009dc6     pop    rbp
        0x00009dc7     ret
                    ; endp
*/
        return rc;
    }

    else
    {
/*
        0x00009cf2     mov    rdi, qword [ds:rdi+0xf0]
        0x00009cf9     jmp    0x9d08

        0x00009d08     lea    r8, qword [ss:rbp+var_24]   ; argument #5 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj, XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+77
        0x00009d0c     lea    rax, qword [ss:rbp+var_28]
        0x00009d10     mov    qword [ss:rsp+0x8], rax     ; argument "var_18" for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
        0x00009d15     mov    dword [ss:rsp], 0x1         ; argument "var_10" for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
        0x00009d1c     mov    esi, 0x11                   ; argument #2 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
        0x00009d21     xor    edx, edx                    ; argument #3 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
        0x00009d23     mov    r9d, 0x14                   ; argument #6 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
        0x00009d29     xor    ecx, ecx                    ; argument #4 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
        0x00009d2b     call   Usb_vendor_device_request(IOUSBDevice*, unsigned char, unsigned short, unsigned short, void*, unsigned short, unsigned char, unsigned int*)
        0x00009d30     mov    ecx, dword [ss:rbp+var_14]
        0x00009d33     mov    dword [ss:rbp+var_18], ecx
        0x00009d36     jmp    0x9da7

        0x00009da7     mov    r14d, eax                   ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+138
        0x00009daa     mov    rdi, qword [ds:rbx+0x58]    ; argument "dst" for method _memcpy
        0x00009dae     lea    rsi, qword [ss:rbp+var_24]  ; argument "src" for method _memcpy
        0x00009db2     mov    edx, 0x10                   ; argument "n" for method _memcpy
        0x00009db7     call   _memcpy
        0x00009dbc     mov    eax, r14d
        0x00009dbf     add    rsp, 0x30
        0x00009dc3     pop    rbx
        0x00009dc4     pop    r14
        0x00009dc6     pop    rbp
        0x00009dc7     ret
                    ; endp
*/

    }





/*
0x00009cf2     mov    rdi, qword [ds:rdi+0xf0]
0x00009cf9     jmp    0x9d08

0x00009cfb     cmp    ax, 0x3fc3                ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+38, __ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+44, __ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+50, __ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+56, __ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+62
0x00009cff     mov    rdi, qword [ds:rdi+0xf0]
0x00009d06     jne    0x9d38

0x00009d08     lea    r8, qword [ss:rbp+var_24]     ; argument #5 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj, XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+77
0x00009d0c     lea    rax, qword [ss:rbp+var_28]
0x00009d10     mov    qword [ss:rsp+0x8], rax       ; argument "var_18" for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
0x00009d15     mov    dword [ss:rsp], 0x1           ; argument "var_10" for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
0x00009d1c     mov    esi, 0x11                     ; argument #2 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
0x00009d21     xor    edx, edx                      ; argument #3 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
0x00009d23     mov    r9d, 0x14                     ; argument #6 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
0x00009d29     xor    ecx, ecx                      ; argument #4 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj
0x00009d2b     call   Usb_vendor_device_request(IOUSBDevice*, unsigned char, unsigned short, unsigned short, void*, unsigned short, unsigned char, unsigned int*)
0x00009d30     mov    ecx, dword [ss:rbp+var_14]
0x00009d33     mov    dword [ss:rbp+var_18], ecx
0x00009d36     jmp    0x9da7

0x00009d38     lea    rax, qword [ss:rbp+var_28]        ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+90
0x00009d3c     mov    qword [ss:rsp+0x8], rax
0x00009d41     mov    dword [ss:rsp], 0x1
0x00009d48     mov    esi, 0x11
0x00009d4d     xor    edx, edx
0x00009d4f     lea    r8, qword [ss:rbp+var_24]
0x00009d53     mov    r9d, 0x10
0x00009d59     jmp    0x9da0

0x00009d5b     cmp    ax, 0x3fc0                 ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+68
0x00009d5f     mov    rdi, qword [ds:rdi+0xf0]
0x00009d66     je     0x9d7f

0x00009d68     lea    rax, qword [ss:rbp+var_28]
0x00009d6c     mov    qword [ss:rsp+0x8], rax
0x00009d71     mov    dword [ss:rsp], 0x1
0x00009d78     mov    esi, 0x19
0x00009d7d     jmp    0x9d94

0x00009d7f     lea    rax, qword [ss:rbp+var_28]  ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+186
0x00009d83     mov    qword [ss:rsp+0x8], rax
0x00009d88     mov    dword [ss:rsp], 0x1
0x00009d8f     mov    esi, 0x17

0x00009d94     xor    edx, edx                    ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+209
0x00009d96     lea    r8, qword [ss:rbp+var_24]
0x00009d9a     mov    r9d, 0x4

0x00009da0     xor    ecx, ecx                    ; argument #4 for method __Z25Usb_vendor_device_requestP11IOUSBDevicehttPvthPj, XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+173
0x00009da2     call   Usb_vendor_device_request(IOUSBDevice*, unsigned char, unsigned short, unsigned short, void*, unsigned short, unsigned char, unsigned int*)

0x00009da7     mov    r14d, eax                   ; XREF=__ZN32de_RME_driver_USBAudioUserClient21sUserClientReadStatusEP28de_RME_driver_USBAudioDevicePvP25IOExternalMethodArguments+138
0x00009daa     mov    rdi, qword [ds:rbx+0x58]    ; argument "dst" for method _memcpy
0x00009dae     lea    rsi, qword [ss:rbp+var_24]  ; argument "src" for method _memcpy
0x00009db2     mov    edx, 0x10                   ; argument "n" for method _memcpy
0x00009db7     call   _memcpy
0x00009dbc     mov    eax, r14d
0x00009dbf     add    rsp, 0x30
0x00009dc3     pop    rbx
0x00009dc4     pop    r14
0x00009dc6     pop    rbp
0x00009dc7     ret
            ; endp
*/

    return 0;
}
