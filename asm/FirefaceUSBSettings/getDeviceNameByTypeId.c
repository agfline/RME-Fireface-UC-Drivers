
#include <stdint.h>

/*
    Finaly we found it !!!

    0x3fc0 : Babyface Pro
    0x3fc1 : UFX+
    0x3fc2 : UFX+
    0x3fc3 : MADIface Pro
    0x3fc4 : UFX II
    0x3fc5 : undefined
    0x3fc6 : Fireface UC
    0x3fc7 : Babyface
    0x3fc8 : Fireface UFX
    0x3fc9 : Fireface UCX
    0x3fca : MADIface XT
    0x3fcb : MADIface XT
    0x3fcc : MADIface
    0x3fcd : Fireface 802
    0x3fce : undefined
    0x3fcf : Fireface UC2

    0x3fa0 : Digiface USB
*/

int getDeviceNameByTypeId( uint16_t productId, char **productName )
{
    int rc = 0;

/*
================ B E G I N N I N G   O F   P R O C E D U R E ================



                       __Z21getDeviceNameByTypeIdjPc:        // getDeviceNameByTypeId(unsigned int, char*)
0x0000000100001321         push       rbp                                       ; XREF=__ZN9CHardware12LoadSettingsEi+185, __ZN9CHardware13StoreSettingsEi+548
0x0000000100001322         mov        rbp, rsp
*/

/*
    0x0000000100001325         cmp        edi, 0x3fbf
    0x000000010000132b         jg         0x100001351
*/

    if ( productId > 0x3fbf )
    {
// /*
//         0x0000000100001351         add        edi, 0xffffc040                           ; XREF=__Z21getDeviceNameByTypeIdjPc+10
//         0x0000000100001357         cmp        edi, 0xf
//         0x000000010000135a         ja         0x10000137a
// */
//         if ( (uint32_t)((productId + 0xffffc040) & 0xffffffff) > 0xf )
//         {
//             /* NOTE Switch statement's default */
// /*
//             0x000000010000137a         mov        rax, 0x656e696665646e75                   ; case 14, XREF=__Z21getDeviceNameByTypeIdjPc+18, __Z21getDeviceNameByTypeIdjPc+57, __Z21getDeviceNameByTypeIdjPc+73
//             0x0000000100001384         mov        qword [ds:rsi], rax
//             0x0000000100001387         mov        word [ds:rsi+0x8], 0x64
//             0x000000010000138d         xor        eax, eax
//
//             0x000000010000138f         movzx      eax, al                                   ; XREF=__Z21getDeviceNameByTypeIdjPc+46, __Z21getDeviceNameByTypeIdjPc+87, __Z21getDeviceNameByTypeIdjPc+137, __Z21getDeviceNameByTypeIdjPc+177, __Z21getDeviceNameByTypeIdjPc+197, __Z21getDeviceNameByTypeIdjPc+221, __Z21getDeviceNameByTypeIdjPc+242, __Z21getDeviceNameByTypeIdjPc+273, __Z21getDeviceNameByTypeIdjPc+304, __Z21getDeviceNameByTypeIdjPc+350, __Z21getDeviceNameByTypeIdjPc+381
//             0x0000000100001392         pop        rbp
//             0x0000000100001393         ret
// */
//             productName = "undefine";
//             rc = 0;
//
//             return rc;
//         }
/*
        0x000000010000135c         lea        rax, qword [ds:0x1000014a4]
        0x0000000100001363         movsxd     rcx, dword [ds:rax+rdi*4]
        0x0000000100001367         add        rcx, rax
        0x000000010000136a         jmp        rcx                                       ; switch statement using table at 0x1000014a4, with 16 cases
*/

        switch ( (uint32_t)((productId + 0xffffc040) & 0xffffffff) )
        {
            case 0:
/*
                0x00000001000013ac         mov        rax, 0x6563616679626142                   ; case 0, XREF=__Z21getDeviceNameByTypeIdjPc+73
                0x00000001000013b6         jmp        0x1000013c2

                0x00000001000013c2         mov        qword [ds:rsi], rax                       ; XREF=__Z21getDeviceNameByTypeIdjPc+149
                0x00000001000013c5         mov        byte [ds:rsi+0xc], 0x0
                0x00000001000013c9         mov        dword [ds:rsi+0x8], 0x6f725020
                0x00000001000013d0         mov        al, 0x1
                0x00000001000013d2         jmp        0x10000138f
*/
                *productName = "Babyface Pro";
                rc = 1;

                break;

            case 1:
            case 2:
/*
                0x000000010000136c         mov        byte [ds:rsi+0x4], 0x0                    ; case 1, 2, XREF=__Z21getDeviceNameByTypeIdjPc+73
                0x0000000100001370         mov        dword [ds:rsi], 0x2b584655
                0x0000000100001376         mov        al, 0x1
                0x0000000100001378         jmp        0x10000138f
*/
                *productName = "UFX+";
                rc = 1;

                break;

            case 3:
/*
                0x00000001000013b8         mov        rax, 0x656361664944414d                   ; case 3, XREF=__Z21getDeviceNameByTypeIdjPc+73

                0x00000001000013c2         mov        qword [ds:rsi], rax                       ; XREF=__Z21getDeviceNameByTypeIdjPc+149
                0x00000001000013c5         mov        byte [ds:rsi+0xc], 0x0
                0x00000001000013c9         mov        dword [ds:rsi+0x8], 0x6f725020
                0x00000001000013d0         mov        al, 0x1
                0x00000001000013d2         jmp        0x10000138f
*/
                *productName = "MADIface Pro";
                rc = 1;

                break;

            case 4:
/*
                0x00000001000013d4         mov        byte [ds:rsi+0x6], 0x0                    ; case 4, XREF=__Z21getDeviceNameByTypeIdjPc+73
                0x00000001000013d8         mov        word [ds:rsi+0x4], 0x4949
                0x00000001000013de         mov        dword [ds:rsi], 0x20584655
                0x00000001000013e4         mov        al, 0x1
                0x00000001000013e6         jmp        0x10000138f
*/
                *productName = "UFX II";
                rc = 1;

                break;

            case 5:
            case 14:
/*
                0x000000010000137a         mov        rax, 0x656e696665646e75                   ; case 14, XREF=__Z21getDeviceNameByTypeIdjPc+18, __Z21getDeviceNameByTypeIdjPc+57, __Z21getDeviceNameByTypeIdjPc+73
                0x0000000100001384         mov        qword [ds:rsi], rax
                0x0000000100001387         mov        word [ds:rsi+0x8], 0x64
                0x000000010000138d         xor        eax, eax
        // next 0x000000010000138f
*/
                *productName = "undefine";
                rc = 0;

                break;

            case 6:

/*
                0x00000001000013e8         mov        rax, 0x6563616665726946                   ; case 6, XREF=__Z21getDeviceNameByTypeIdjPc+73
                0x00000001000013f2         mov        qword [ds:rsi], rax
                0x00000001000013f5         mov        dword [ds:rsi+0x8], 0x435520
                0x00000001000013fc         mov        al, 0x1
                0x00000001000013fe         jmp        0x10000138f
*/
                *productName = "Fireface UC";
                rc = 1;

                break;

            case 7:
/*
                0x0000000100001400         mov        rax, 0x6563616679626142                   ; case 7, XREF=__Z21getDeviceNameByTypeIdjPc+73
                0x000000010000140a         mov        qword [ds:rsi], rax
                0x000000010000140d         mov        byte [ds:rsi+0x8], 0x0
                0x0000000100001411         mov        al, 0x1
                0x0000000100001413         jmp        0x10000138f
*/
                *productName = "Babyface";
                rc = 1;

                break;

            case 8:
/*
                0x0000000100001418         mov        rax, 0x6563616665726946                   ; case 8, XREF=__Z21getDeviceNameByTypeIdjPc+73
                0x0000000100001422         mov        qword [ds:rsi], rax
                0x0000000100001425         mov        byte [ds:rsi+0xc], 0x0
                0x0000000100001429         mov        dword [ds:rsi+0x8], 0x58465520
                0x0000000100001430         mov        al, 0x1
                0x0000000100001432         jmp        0x10000138f
*/
                *productName = "Fireface UFX";
                rc = 1;

                break;

            case 9:
/*
                0x0000000100001437         mov        rax, 0x6563616665726946                   ; case 9, XREF=__Z21getDeviceNameByTypeIdjPc+73
                0x0000000100001441         mov        qword [ds:rsi], rax
                0x0000000100001444         mov        byte [ds:rsi+0xc], 0x0
                0x0000000100001448         mov        dword [ds:rsi+0x8], 0x58435520
                0x000000010000144f         mov        al, 0x1
                0x0000000100001451         jmp        0x10000138f
*/
                *productName = "Fireface UCX";
                rc = 1;

                break;

            case 10:
            case 11:
/*
                0x0000000100001394         mov        rax, 0x656361664944414d                   ; case 11, XREF=__Z21getDeviceNameByTypeIdjPc+73
                0x000000010000139e         mov        qword [ds:rsi], rax
                0x00000001000013a1         mov        dword [ds:rsi+0x8], 0x545820
                0x00000001000013a8         mov        al, 0x1
                0x00000001000013aa         jmp        0x10000138f
*/
                *productName = "MADIface XT";
                rc = 1;

                break;

            case 12:
/*
                0x0000000100001456         mov        rax, 0x656361664944414d                   ; case 12, XREF=__Z21getDeviceNameByTypeIdjPc+73
                0x0000000100001460         jmp        0x10000133f
*/
                *productName = "MADIface";
                rc = 1;

                break;

            case 13:
/*
                0x0000000100001465         mov        rax, 0x6563616665726946                   ; case 13, XREF=__Z21getDeviceNameByTypeIdjPc+73
                0x000000010000146f         mov        qword [ds:rsi], rax
                0x0000000100001472         mov        byte [ds:rsi+0xc], 0x0
                0x0000000100001476         mov        dword [ds:rsi+0x8], 0x32303820
                0x000000010000147d         mov        al, 0x1
                0x000000010000147f         jmp        0x10000138f
*/
                *productName = "Fireface 802";
                rc = 1;

                break;

            case 15:
/*
                0x0000000100001484         mov        rax, 0x6563616665726946                   ; case 15, XREF=__Z21getDeviceNameByTypeIdjPc+73
                0x000000010000148e         mov        qword [ds:rsi], rax
                0x0000000100001491         mov        byte [ds:rsi+0xc], 0x0
                0x0000000100001495         mov        dword [ds:rsi+0x8], 0x32435520
                0x000000010000149c         mov        al, 0x1
                0x000000010000149e         jmp        0x10000138f
*/
                *productName = "Fireface UC2";
                rc = 1;

                break;

            default:
/*
                0x000000010000137a         mov        rax, 0x656e696665646e75                   ; case 14, XREF=__Z21getDeviceNameByTypeIdjPc+18, __Z21getDeviceNameByTypeIdjPc+57, __Z21getDeviceNameByTypeIdjPc+73
                0x0000000100001384         mov        qword [ds:rsi], rax
                0x0000000100001387         mov        word [ds:rsi+0x8], 0x64
                0x000000010000138d         xor        eax, eax

                0x000000010000138f         movzx      eax, al                                   ; XREF=__Z21getDeviceNameByTypeIdjPc+46, __Z21getDeviceNameByTypeIdjPc+87, __Z21getDeviceNameByTypeIdjPc+137, __Z21getDeviceNameByTypeIdjPc+177, __Z21getDeviceNameByTypeIdjPc+197, __Z21getDeviceNameByTypeIdjPc+221, __Z21getDeviceNameByTypeIdjPc+242, __Z21getDeviceNameByTypeIdjPc+273, __Z21getDeviceNameByTypeIdjPc+304, __Z21getDeviceNameByTypeIdjPc+350, __Z21getDeviceNameByTypeIdjPc+381
                0x0000000100001392         pop        rbp
                0x0000000100001393         ret
*/
                *productName = "undefine";
                rc = 0;

                break;
        }

    }
/*
    0x000000010000132d         cmp        edi, 0x3fa0
    0x0000000100001333         jne        0x10000137a
*/
    else if ( productId == 0x3fa0 )
    {
/*
        0x0000000100001335         mov        rax, 0x6563616669676944

        0x000000010000133f         mov        qword [ds:rsi], rax                       ; XREF=__Z21getDeviceNameByTypeIdjPc+319
        0x0000000100001342         mov        byte [ds:rsi+0xc], 0x0
        0x0000000100001346         mov        dword [ds:rsi+0x8], 0x42535520
        0x000000010000134d         mov        al, 0x1
        0x000000010000134f         jmp        0x10000138f
*/
        *productName = "Digiface USB";
        rc = 1;
    }
    else
    {
/*
        0x000000010000137a         mov        rax, 0x656e696665646e75                   ; case 14, XREF=__Z21getDeviceNameByTypeIdjPc+18, __Z21getDeviceNameByTypeIdjPc+57, __Z21getDeviceNameByTypeIdjPc+73
        0x0000000100001384         mov        qword [ds:rsi], rax
        0x0000000100001387         mov        word [ds:rsi+0x8], 0x64
        0x000000010000138d         xor        eax, eax

// next 0x000000010000138f
*/
        *productName = "undefine";
        rc = 0;
    }

/*
    0x000000010000138f         movzx      eax, al                                   ; XREF=__Z21getDeviceNameByTypeIdjPc+46, __Z21getDeviceNameByTypeIdjPc+87, __Z21getDeviceNameByTypeIdjPc+137, __Z21getDeviceNameByTypeIdjPc+177, __Z21getDeviceNameByTypeIdjPc+197, __Z21getDeviceNameByTypeIdjPc+221, __Z21getDeviceNameByTypeIdjPc+242, __Z21getDeviceNameByTypeIdjPc+273, __Z21getDeviceNameByTypeIdjPc+304, __Z21getDeviceNameByTypeIdjPc+350, __Z21getDeviceNameByTypeIdjPc+381
    0x0000000100001392         pop        rbp
    0x0000000100001393         ret
*/

    return rc;
}
