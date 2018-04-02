
/*
    ================ B E G I N N I N G   O F   P R O C E D U R E ================



    de_RME_driver_USBAudioUserClient::sUserClientWriteSettings (
                                                                 de_RME_driver_USBAudioDevice*,    rdi
                                                                 void*,                            rsi
                                                                 IOExternalMethodArguments*        rdx
                                                               )

    0x00009b88    push   rbp
    0x00009b89    mov    rbp, rsp
    0x00009b8c    sub    rsp, 0x10
*/

/*
    0x00009b90    cmp    word [ds:rdi+0x124], 0x3fc3
    0x00009b99    mov    rdi, qword [ds:rdi+0xf0]    ; argument #1 (IOUSBDevice*)  for method
    0x00009ba0    mov    rax, qword [ds:rdx+0x20]
    0x00009ba4    movzx  ecx, word [ds:rax]
    0x00009ba7    movzx  eax, word [ds:rax+0x8]
    0x00009bab    je     0x9bd9
*/
    IOUSBDevice = IOUSBDevice;

    if ( productId == 0x3fc3 ) {
/*
        0x00009bd9    mov    qword [ss:rsp+0x8], 0x0    ; argument #7 (bmRequestType) for method
        0x00009be2    mov    dword [ss:rsp], 0x0        ; argument #8 (wLenDone*)     for method
        0x00009be9    movzx  edx, cx                    ; argument #3 (wValue)        for method
        0x00009bec    movzx  ecx, ax                    ; argument #4 (wIndex)        for method
        0x00009bef    mov    esi, 0x12                  ; argument #2 (bRequest)      for method
        0x00009bf4    jmp    0x9bc8
*/
        bmRequestType = 0x0;    // Usb_vendor_device_request() will send 0x40
        wLenDone = 0x0;
        wValue = wValue;
        wIndex = wIndex;
        bRequest = 0x12;

    } else {
/*
        0x00009bad    mov    qword [ss:rsp+0x8], 0x0    ; argument #7 (bmRequestType) for method
        0x00009bb6    mov    dword [ss:rsp], 0x0        ; argument #8 (wLenDone*)     for method
        0x00009bbd    movzx  edx, cx                    ; argument #3 (wValue)        for method
        0x00009bc0    movzx  ecx, ax                    ; argument #4 (wIndex)        for method
        0x00009bc3    mov    esi, 0x17                  ; argument #2 (bRequest)      for method
*/
        bmRequestType = 0x0;    // Usb_vendor_device_request() will send 0x40
        wLenDone = 0x0;
        wValue = wValue;
        wIndex = wIndex;
        bRequest = 0x17;

    }
/*
    0x00009bc8    xor    r8d, r8d            ; argument #5 (pData*)        for method
    0x00009bcb    xor    r9d, r9d            ; argument #6 (wLength)       for method
    0x00009bce    call   Usb_vendor_device_request()
*/
    wLength = 0;
    pData = NULL;

    Usb_vendor_device_request ( IOUSBDevice,
                    bRequest,
                    wValue,
                    wIndex,
                    pData,
                    wLength,
                    bmRequestType,
                    wLenDone );
/*
    0x00009bd3    add    rsp, 0x10
    0x00009bd7    pop    rbp
    0x00009bd8    ret
            ; endp
*/

    return ?;
