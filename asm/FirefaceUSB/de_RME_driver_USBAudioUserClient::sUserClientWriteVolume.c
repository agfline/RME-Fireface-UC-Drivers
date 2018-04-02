#include <stdio.h>
#include <stdint.h>


union r8 {
    int8_t  b;
    int16_t w;
    int32_t d;
} r8;


main ( void ) {

    /*
        It seems that all devices send 0x12
        bRequest, except the following :

            * 0x3fc1
            * 0x3fc2
            * 0x3fc3
            * 0x3fc4
            * 0x3fa0

        which send 0x15 bRequest.
    */

    r8.w = 0;

    int8_t  al  = 0;
    int8_t  cl  = 0;

    uint16_t productId = 0x3fc6;
/*
    ================ B E G I N N I N G   O F   P R O C E D U R E ================



    de_RME_driver_USBAudioUserClient::sUserClientWriteVolume (
                                                               de_RME_driver_USBAudioDevice*,    rdi
                                                               void*,                            rsi
                                                               IOExternalMethodArguments*        rdx
                                                             )

    0x00009ad2     push   rbp
    0x00009ad3     mov    rbp, rsp
    0x00009ad6     sub    rsp, 0x10
*/

/*
    0x00009ada     movzx  eax, word [ds:rdi+0x124]
    0x00009ae1     cmp    ax, 0x3fc2
    0x00009ae5     sete   cl
*/
    if ( productId == 0x3fc2 )                            // 0x40 0x15
        cl = 1;
    else
        cl = 0;

/*
    0x00009ae8     mov    r8d, eax
    0x00009aeb     add    r8d, 0xffffc036
    0x00009af2     cmp    r8w, 0x3
    0x00009af7     sbb    r8b, r8b
    0x00009afa     and    r8b, 0x1
    0x00009afe     or     r8b, cl
*/
    r8.d = productId;
    r8.d += 0xffffc036;

    if ( (uint16_t)r8.w < 0x3 )
        r8.b = r8.b - (r8.b + 1);    // sbb : Destination = Destination - (Source + CF);
                        // = -1
    else
        r8.b = r8.b - (r8.b);        // = 0


    r8.b &= 0x1;
    r8.b |= cl;

/*
    0x00009b01     cmp    ax, 0x3fc1
    0x00009b05     sete   cl
    0x00009b08     or     cl, r8b
*/
    if ( productId == 0x3fc1 )                            // 0x40 0x15
        cl = 1;
    else
        cl = 0;

    cl |= r8.b;

/*
    0x00009b0b     cmp    ax, 0x3fc3
    0x00009b0f     sete   r8b
    0x00009b13     or     r8b, cl
*/
    if ( productId == 0x3fc3 )                            // 0x40 0x15
        r8.b = 0x1;
    else
        r8.b = 0x0;

    r8.b |= cl;

/*
    0x00009b16     cmp    ax, 0x3fc4
    0x00009b1a     sete   cl
    0x00009b1d     or     cl, r8b
*/
    if ( productId == 0x3fc4 )                            // 0x40 0x15
        cl = 1;
    else
        cl = 0;

    cl |= r8.b;

/*
    0x00009b20     cmp    ax, 0x3fa0
    0x00009b24     sete   al
    0x00009b27     or     al, cl
    0x00009b29     test   al, 0x1
    0x00009b2b     mov    rdi, qword [ds:rdi+0xf0]    ; argument #1 (IOUSBDevice*)  for method
    0x00009b32     mov    rax, qword [ds:rdx+0x20]
    0x00009b36     movzx  ecx, word [ds:rax]
    0x00009b39     movzx  eax, word [ds:rax+0x8]
    0x00009b3d     je     0x9b6b
*/
    if ( productId == 0x3fa0 )                            // 0x40 0x15
        al = 1;
    else
        al = 0;

    al |= cl;

    if ( (al & 0x1) == 0 ) {
/*
        0x00009b6b     mov    qword [ss:rsp+0x8], 0x0  ; argument #7 (bmRequestType) for method
        0x00009b74     mov    dword [ss:rsp], 0x0      ; argument #8 (wLenDone*)     for method
        0x00009b7b     movzx  edx, cx                  ; argument #3 (wValue)        for method
        0x00009b7e     movzx  ecx, ax                  ; argument #4 (wIndex)        for method
        0x00009b81     mov    esi, 0x12                ; argument #2 (bRequest)      for method
        0x00009b86     jmp    0x9b5a
*/
        printf("0x%04x > 0x40 0x12 (18)\n", productId);

    } else {
/*
        0x00009b3f     mov    qword [ss:rsp+0x8], 0x0  ; argument #7 (bmRequestType) for method
        0x00009b48     mov    dword [ss:rsp], 0x0      ; argument #8 (wLenDone*)     for method
        0x00009b4f     movzx  edx, cx                  ; argument #3 (wValue)        for method
        0x00009b52     movzx  ecx, ax                  ; argument #4 (wIndex)        for method
        0x00009b55     mov    esi, 0x15                ; argument #2 (bRequest)      for method
*/
        printf("0x%04x > 0x40 0x15 (21)\n", productId);

    }
/*
    0x00009b5a     xor    r8d, r8d                 ; argument #5 (pData*)        for method
    0x00009b5d     xor    r9d, r9d                 ; argument #6 (wLength)       for method
    0x00009b60     call   Usb_vendor_device_request()
*/
/*    Usb_vendor_device_request ( IOUSBDevice,
                    bRequest,
                    wValue,
                    wIndex,
                    pData,
                    wLength,
                    bmRequestType,
                    wLenDone )
*/
/*
    0x00009b65     add    rsp, 0x10
    0x00009b69     pop    rbp
    0x00009b6a     ret
            ; endp
*/

}
