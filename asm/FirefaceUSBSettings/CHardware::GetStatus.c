
================ B E G I N N I N G   O F   P R O C E D U R E ================



                       __ZN9CHardware9GetStatusEiP14FirefaceStatus:        // CHardware::GetStatus(int, FirefaceStatus*)
0x0000000100003632         push       rbp                                       ; XREF=-[Controller timerAction:]+44
0x0000000100003633         mov        rbp, rsp
0x0000000100003636         push       r15
0x0000000100003638         push       r14
0x000000010000363a         push       r13
0x000000010000363c         push       r12
0x000000010000363e         push       rbx
0x000000010000363f         sub        rsp, 0x88
0x0000000100003646         mov        r15, rdx
0x0000000100003649         mov        ebx, esi
0x000000010000364b         mov        r14, rdi
0x000000010000364e         mov        r12, qword [ds:imp___got____stack_chk_guard] ; imp___got____stack_chk_guard
0x0000000100003655         mov        r12, qword [ds:r12]
0x0000000100003659         mov        qword [ss:rbp+var_30], r12
0x000000010000365d         mov        esi, 0x84                                 ; argument #2 for method imp___stubs____bzero
0x0000000100003662         mov        rdi, r15                                  ; argument #1 for method imp___stubs____bzero
0x0000000100003665         call       imp___stubs____bzero
0x000000010000366a         movsxd     rbx, ebx
0x000000010000366d         mov        eax, dword [ds:r14+rbx*4+0x594]
0x0000000100003675         cmp        eax, 0x3fbf
0x000000010000367a         jg         0x100003860

0x0000000100003680         cmp        eax, 0x3fa0
0x0000000100003685         jne        0x100004371

0x000000010000368b         mov        rdi, qword [ds:r14+rbx*8+0x218]
0x0000000100003693         mov        byte [ss:rbp+var_80], 0xc0
0x0000000100003697         mov        byte [ss:rbp+var_7F], 0x11
0x000000010000369b         mov        word [ss:rbp+var_7E], 0x0
0x00000001000036a1         mov        word [ss:rbp+var_7C], 0x0
0x00000001000036a7         mov        word [ss:rbp+var_7A], 0x10
0x00000001000036ad         lea        rax, qword [ss:rbp+var_60]
0x00000001000036b1         mov        qword [ss:rbp+var_78], rax
0x00000001000036b5         mov        dword [ss:rbp+var_6C], 0x1e
0x00000001000036bc         mov        dword [ss:rbp+var_68], 0x1e
0x00000001000036c3         mov        rax, qword [ds:rdi]
0x00000001000036c6         lea        rsi, qword [ss:rbp+var_80]
0x00000001000036ca         call       qword [ds:rax+0xf0]
0x00000001000036d0         test       eax, eax
0x00000001000036d2         jne        0x100004371

0x00000001000036d8         mov        ebx, dword [ss:rbp+var_60]
0x00000001000036db         mov        r13d, dword [ss:rbp+var_5C]
0x00000001000036df         mov        ecx, ebx
0x00000001000036e1         and        ecx, 0x1
0x00000001000036e4         mov        dword [ss:rbp+var_90], ecx
0x00000001000036ea         mov        eax, ebx
0x00000001000036ec         and        eax, 0x21
0x00000001000036ef         cmp        eax, 0x21
0x00000001000036f2         mov        eax, 0x2
0x00000001000036f7         cmovne     eax, ecx
0x00000001000036fa         mov        dword [ds:r15+0x2c], eax
0x00000001000036fe         mov        eax, ebx
0x0000000100003700         and        eax, 0x42
0x0000000100003703         mov        ecx, ebx
0x0000000100003705         shr        ecx, 0x1
0x0000000100003707         and        ecx, 0x1
0x000000010000370a         mov        dword [ss:rbp+var_94], ecx
0x0000000100003710         cmp        eax, 0x42
0x0000000100003713         mov        eax, 0x2
0x0000000100003718         cmovne     eax, ecx
0x000000010000371b         mov        dword [ds:r15+0x30], eax
0x000000010000371f         mov        eax, ebx
0x0000000100003721         and        eax, 0x84
0x0000000100003726         mov        r12d, ebx
0x0000000100003729         shr        r12d, 0x2
0x000000010000372d         and        r12d, 0x1
0x0000000100003731         cmp        eax, 0x84
0x0000000100003736         mov        eax, 0x2
0x000000010000373b         cmovne     eax, r12d
0x000000010000373f         mov        dword [ds:r15+0x34], eax
0x0000000100003743         mov        eax, ebx
0x0000000100003745         and        eax, 0x108
0x000000010000374a         mov        r14d, ebx
0x000000010000374d         shr        r14d, 0x3
0x0000000100003751         and        r14d, 0x1
0x0000000100003755         cmp        eax, 0x108
0x000000010000375a         mov        eax, 0x2
0x000000010000375f         cmovne     eax, r14d
0x0000000100003763         mov        dword [ds:r15+0x38], eax
0x0000000100003767         mov        edi, 0x1                                  ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x000000010000376c         mov        edx, 0x1                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003771         mov        esi, r13d                                 ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003774         mov        ecx, ebx                                  ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003776         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x000000010000377b         mov        dword [ds:r15+0x40], eax
0x000000010000377f         mov        edi, 0x10                                 ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003784         mov        edx, 0x2                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003789         mov        esi, r13d                                 ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x000000010000378c         mov        ecx, ebx                                  ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x000000010000378e         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003793         mov        dword [ds:r15+0x44], eax
0x0000000100003797         mov        edi, 0x100                                ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x000000010000379c         mov        edx, 0x4                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x00000001000037a1         mov        esi, r13d                                 ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x00000001000037a4         mov        ecx, ebx                                  ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x00000001000037a6         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x00000001000037ab         mov        dword [ds:r15+0x48], eax
0x00000001000037af         mov        edi, 0x1000                               ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x00000001000037b4         mov        edx, 0x8                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x00000001000037b9         mov        esi, r13d                                 ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x00000001000037bc         mov        ecx, ebx                                  ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x00000001000037be         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x00000001000037c3         mov        dword [ds:r15+0x4c], eax
0x00000001000037c7         mov        eax, ebx
0x00000001000037c9         and        eax, 0x201
0x00000001000037ce         cmp        eax, 0x201
0x00000001000037d3         mov        ecx, 0x2
0x00000001000037d8         mov        eax, dword [ss:rbp+var_90]
0x00000001000037de         cmove      eax, ecx
0x00000001000037e1         mov        dword [ds:r15+0x6c], eax
0x00000001000037e5         mov        eax, ebx
0x00000001000037e7         and        eax, 0x2002
0x00000001000037ec         cmp        eax, 0x2002
0x00000001000037f1         mov        eax, dword [ss:rbp+var_94]
0x00000001000037f7         cmove      eax, ecx
0x00000001000037fa         mov        dword [ds:r15+0x70], eax
0x00000001000037fe         mov        eax, ebx
0x0000000100003800         and        eax, 0x4004
0x0000000100003805         cmp        eax, 0x4004
0x000000010000380a         cmove      r12d, ecx
0x000000010000380e         mov        ecx, 0x2
0x0000000100003813         mov        dword [ds:r15+0x74], r12d
0x0000000100003817         mov        eax, ebx
0x0000000100003819         and        eax, 0x8008
0x000000010000381e         cmp        eax, 0x8008
0x0000000100003823         cmove      r14d, ecx
0x0000000100003827         mov        dword [ds:r15+0x78], r14d
0x000000010000382b         and        ebx, 0x1c00
0x0000000100003831         xor        eax, eax
0x0000000100003833         cmp        ebx, 0x7ff
0x0000000100003839         jg         0x100003eb8

0x000000010000383f         cmp        ebx, 0x400
0x0000000100003845         mov        r12, qword [ds:imp___got____stack_chk_guard] ; imp___got____stack_chk_guard
0x000000010000384c         mov        r12, qword [ds:r12]
0x0000000100003850         jne        0x10000403f

0x0000000100003856         mov        eax, 0x1
0x000000010000385b         jmp        0x10000403f

0x0000000100003860         add        eax, 0xffffc040                           ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+72
0x0000000100003865         cmp        eax, 0xf
0x0000000100003868         ja         0x100004371

0x000000010000386e         lea        rcx, qword [ds:0x100004420]
0x0000000100003875         movsxd     rax, dword [ds:rcx+rax*4]
0x0000000100003879         add        rax, rcx
0x000000010000387c         jmp        rax                                       ; switch statement using table at 0x100004420, with 16 cases

0x000000010000387e         mov        dword [ss:rbp+var_84], 0x0                ; case 15, XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+586
0x0000000100003888         mov        rdi, qword [ds:r14+rbx*8+0x218]
0x0000000100003890         mov        byte [ss:rbp+var_80], 0xc0
0x0000000100003894         mov        byte [ss:rbp+var_7F], 0x11
0x0000000100003898         mov        word [ss:rbp+var_7E], 0x0
0x000000010000389e         mov        word [ss:rbp+var_7C], 0x0
0x00000001000038a4         mov        word [ss:rbp+var_7A], 0x4
0x00000001000038aa         lea        rax, qword [ss:rbp+var_84]
0x00000001000038b1         mov        qword [ss:rbp+var_78], rax
0x00000001000038b5         mov        dword [ss:rbp+var_6C], 0x1e
0x00000001000038bc         mov        dword [ss:rbp+var_68], 0x1e
0x00000001000038c3         mov        rax, qword [ds:rdi]
0x00000001000038c6         lea        rsi, qword [ss:rbp+var_80]
0x00000001000038ca         call       qword [ds:rax+0xf0]
0x00000001000038d0         mov        ecx, dword [ss:rbp+var_84]
0x00000001000038d6         mov        edx, ecx
0x00000001000038d8         shr        edx, 0x9
0x00000001000038db         and        edx, 0x7
0x00000001000038de         test       ch, 0x1
0x00000001000038e1         mov        esi, 0x5
0x00000001000038e6         cmove      esi, edx
0x00000001000038e9         cmp        edx, 0x2
0x00000001000038ec         cmovne     esi, edx
0x00000001000038ef         mov        dword [ds:r15], esi
0x00000001000038f2         test       eax, eax
0x00000001000038f4         je         0x100003fa2

0x00000001000038fa         mov        dword [ds:r15], 0x6
0x0000000100003901         mov        dword [ds:r15+0x4], 0x0
0x0000000100003909         mov        dword [ds:r15+0x8], 0x3
0x0000000100003911         mov        dword [ds:r15+0x18], 0xc
0x0000000100003919         mov        dword [ds:r15+0xc], 0x3
0x0000000100003921         mov        dword [ds:r15+0x1c], 0xc
0x0000000100003929         mov        dword [ds:r15+0x14], 0x3
0x0000000100003931         shr        ecx, 0xc
0x0000000100003934         and        ecx, 0xf
0x0000000100003937         mov        dword [ds:r15+0x24], ecx
0x000000010000393b         add        r15, 0x24
0x000000010000393f         mov        rsi, r15
0x0000000100003942         jmp        0x10000436b

0x0000000100003947         mov        rdi, qword [ds:r14+rbx*8+0x218]           ; case 12, XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+586
0x000000010000394f         mov        byte [ss:rbp+var_80], 0xc0
0x0000000100003953         mov        byte [ss:rbp+var_7F], 0x11
0x0000000100003957         mov        word [ss:rbp+var_7E], 0x0
0x000000010000395d         mov        word [ss:rbp+var_7C], 0x0
0x0000000100003963         mov        word [ss:rbp+var_7A], 0x10
0x0000000100003969         lea        rax, qword [ss:rbp+var_40]
0x000000010000396d         mov        qword [ss:rbp+var_78], rax
0x0000000100003971         mov        dword [ss:rbp+var_6C], 0x1e
0x0000000100003978         mov        dword [ss:rbp+var_68], 0x1e
0x000000010000397f         mov        rax, qword [ds:rdi]
0x0000000100003982         lea        rsi, qword [ss:rbp+var_80]
0x0000000100003986         call       qword [ds:rax+0xf0]
0x000000010000398c         test       eax, eax
0x000000010000398e         jne        0x100004371

0x0000000100003994         mov        r13, r15
0x0000000100003997         mov        qword [ss:rbp+var_A0], r13
0x000000010000399e         mov        r15, qword [ss:rbp+var_40]
0x00000001000039a2         mov        rax, r15
0x00000001000039a5         shr        rax, 0x20
0x00000001000039a9         mov        qword [ss:rbp+var_90], rax
0x00000001000039b0         mov        rsi, rax                                  ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x00000001000039b3         mov        ecx, r15d
0x00000001000039b6         and        ecx, 0x1
0x00000001000039b9         mov        eax, r15d
0x00000001000039bc         and        eax, 0x21
0x00000001000039bf         cmp        eax, 0x21
0x00000001000039c2         mov        eax, 0x2
0x00000001000039c7         cmove      ecx, eax
0x00000001000039ca         mov        dword [ds:r13+0x28], ecx
0x00000001000039ce         mov        ecx, r15d
0x00000001000039d1         and        ecx, 0x42
0x00000001000039d4         mov        edx, r15d
0x00000001000039d7         shr        edx, 0x1
0x00000001000039d9         and        edx, 0x1
0x00000001000039dc         cmp        ecx, 0x42
0x00000001000039df         cmove      edx, eax
0x00000001000039e2         mov        dword [ds:r13+0x2c], edx
0x00000001000039e6         mov        ecx, r15d
0x00000001000039e9         and        ecx, 0x84
0x00000001000039ef         mov        edx, r15d
0x00000001000039f2         and        edx, 0x4
0x00000001000039f5         shr        edx, 0x2
0x00000001000039f8         cmp        ecx, 0x84
0x00000001000039fe         cmove      edx, eax
0x0000000100003a01         mov        dword [ds:r13+0x30], edx
0x0000000100003a05         mov        edx, r15d
0x0000000100003a08         and        edx, 0x8
0x0000000100003a0b         mov        dword [ss:rbp+var_A4], edx
0x0000000100003a11         mov        ecx, r15d
0x0000000100003a14         and        ecx, 0x108
0x0000000100003a1a         shr        edx, 0x3
0x0000000100003a1d         cmp        ecx, 0x108
0x0000000100003a23         cmove      edx, eax
0x0000000100003a26         mov        dword [ds:r13+0x34], edx
0x0000000100003a2a         mov        edx, r15d
0x0000000100003a2d         and        edx, 0x10
0x0000000100003a30         mov        dword [ss:rbp+var_94], edx
0x0000000100003a36         mov        ecx, r15d
0x0000000100003a39         and        ecx, 0x210
0x0000000100003a3f         shr        edx, 0x4
0x0000000100003a42         cmp        ecx, 0x210
0x0000000100003a48         cmove      edx, eax
0x0000000100003a4b         mov        dword [ds:r13+0x38], edx
0x0000000100003a4f         mov        edi, 0x1                                  ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003a54         mov        edx, 0x1                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003a59         mov        ecx, r15d                                 ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003a5c         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003a61         mov        dword [ds:r13+0x3c], eax
0x0000000100003a65         mov        edi, 0x10                                 ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003a6a         mov        edx, 0x2                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003a6f         mov        r13, qword [ss:rbp+var_90]
0x0000000100003a76         mov        esi, r13d                                 ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003a79         mov        ecx, r15d                                 ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003a7c         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003a81         mov        rcx, qword [ss:rbp+var_A0]
0x0000000100003a88         mov        dword [ds:rcx+0x40], eax
0x0000000100003a8b         mov        edi, 0x100                                ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003a90         mov        edx, 0x4                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003a95         mov        esi, r13d                                 ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003a98         mov        ecx, r15d                                 ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003a9b         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003aa0         mov        dword [ss:rbp+var_AC], eax
0x0000000100003aa6         mov        r13, qword [ss:rbp+var_A0]
0x0000000100003aad         mov        dword [ds:r13+0x44], eax
0x0000000100003ab1         mov        edi, 0x1000                               ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003ab6         mov        edx, 0x8                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003abb         mov        rsi, qword [ss:rbp+var_90]                ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003ac2         mov        ecx, r15d                                 ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003ac5         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003aca         mov        dword [ss:rbp+var_A8], eax
0x0000000100003ad0         mov        dword [ds:r13+0x48], eax
0x0000000100003ad4         mov        edi, 0x10000                              ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003ad9         mov        edx, 0x10                                 ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003ade         mov        rsi, qword [ss:rbp+var_90]                ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003ae5         mov        ecx, r15d                                 ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003ae8         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003aed         mov        r10d, r15d
0x0000000100003af0         and        r10d, 0x4
0x0000000100003af4         mov        dword [ds:r13+0x4c], eax
0x0000000100003af8         mov        edx, 0x6
0x0000000100003afd         mov        esi, 0x6
0x0000000100003b02         je         0x100003b27

0x0000000100003b04         mov        esi, r15d
0x0000000100003b07         shr        esi, 0xd
0x0000000100003b0a         not        esi
0x0000000100003b0c         and        esi, 0x1
0x0000000100003b0f         lea        edi, qword [ds:rsi+0x2]
0x0000000100003b12         mov        ecx, dword [ss:rbp+var_AC]
0x0000000100003b18         cmp        ecx, 0x3
0x0000000100003b1b         cmovle     edi, esi
0x0000000100003b1e         lea        esi, qword [ds:rdi+0x2]
0x0000000100003b21         cmp        ecx, 0x7
0x0000000100003b24         cmovle     esi, edi

0x0000000100003b27         mov        dword [ds:r13+0x50], esi                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+1232
0x0000000100003b2b         mov        r9d, dword [ss:rbp+var_A4]
0x0000000100003b32         test       r9d, r9d
0x0000000100003b35         je         0x100003b5a

0x0000000100003b37         mov        edx, r15d
0x0000000100003b3a         shr        edx, 0xe
0x0000000100003b3d         not        edx
0x0000000100003b3f         and        edx, 0x1
0x0000000100003b42         lea        esi, qword [ds:rdx+0x2]
0x0000000100003b45         mov        edi, dword [ss:rbp+var_A8]
0x0000000100003b4b         cmp        edi, 0x3
0x0000000100003b4e         cmovle     esi, edx
0x0000000100003b51         lea        edx, qword [ds:rsi+0x2]
0x0000000100003b54         cmp        edi, 0x7
0x0000000100003b57         cmovle     edx, esi

0x0000000100003b5a         mov        dword [ds:r13+0x54], edx                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+1283
0x0000000100003b5e         mov        edx, 0x6
0x0000000100003b63         mov        edi, dword [ss:rbp+var_94]
0x0000000100003b69         test       edi, edi
0x0000000100003b6b         je         0x100003b8a

0x0000000100003b6d         mov        edx, r15d
0x0000000100003b70         shr        edx, 0xf
0x0000000100003b73         not        edx
0x0000000100003b75         and        edx, 0x1
0x0000000100003b78         lea        esi, qword [ds:rdx+0x2]
0x0000000100003b7b         cmp        eax, 0x3
0x0000000100003b7e         cmovle     esi, edx
0x0000000100003b81         lea        edx, qword [ds:rsi+0x2]
0x0000000100003b84         cmp        eax, 0x7
0x0000000100003b87         cmovle     edx, esi

0x0000000100003b8a         test       r10d, r10d                                ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+1337
0x0000000100003b8d         mov        dword [ds:r13+0x58], edx
0x0000000100003b91         mov        ecx, 0x3
0x0000000100003b96         mov        edx, 0x3
0x0000000100003b9b         je         0x100003baa

0x0000000100003b9d         cmp        dword [ss:rbp+var_AC], 0x2
0x0000000100003ba4         setg       dl
0x0000000100003ba7         movzx      edx, dl

0x0000000100003baa         test       r9d, r9d                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+1385
0x0000000100003bad         mov        dword [ds:r13+0x5c], edx
0x0000000100003bb1         je         0x100003bc0

0x0000000100003bb3         cmp        dword [ss:rbp+var_A8], 0x2
0x0000000100003bba         setg       cl
0x0000000100003bbd         movzx      ecx, cl

0x0000000100003bc0         test       edi, edi                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+1407
0x0000000100003bc2         mov        dword [ds:r13+0x60], ecx
0x0000000100003bc6         mov        ecx, 0x3
0x0000000100003bcb         je         0x100003bd6

0x0000000100003bcd         cmp        eax, 0x2
0x0000000100003bd0         setg       al
0x0000000100003bd3         movzx      ecx, al

0x0000000100003bd6         mov        dword [ds:r13+0x64], ecx                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+1433
0x0000000100003bda         mov        ecx, r15d
0x0000000100003bdd         and        ecx, 0x1c00
0x0000000100003be3         xor        eax, eax
0x0000000100003be5         cmp        ecx, 0x7ff
0x0000000100003beb         jg         0x100003fe4

0x0000000100003bf1         cmp        ecx, 0x400
0x0000000100003bf7         jne        0x1000041d4

0x0000000100003bfd         mov        eax, 0x1
0x0000000100003c02         jmp        0x1000041d4

0x0000000100003c07         mov        rdi, qword [ds:r14+rbx*8+0x218]           ; case 4, XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+586
0x0000000100003c0f         mov        byte [ss:rbp+var_80], 0xc0
0x0000000100003c13         mov        byte [ss:rbp+var_7F], 0x11
0x0000000100003c17         mov        word [ss:rbp+var_7E], 0x0
0x0000000100003c1d         mov        word [ss:rbp+var_7C], 0x0
0x0000000100003c23         mov        word [ss:rbp+var_7A], 0x10
0x0000000100003c29         lea        rax, qword [ss:rbp+var_50]
0x0000000100003c2d         mov        qword [ss:rbp+var_78], rax
0x0000000100003c31         mov        dword [ss:rbp+var_6C], 0x1e
0x0000000100003c38         mov        dword [ss:rbp+var_68], 0x1e
0x0000000100003c3f         mov        rax, qword [ds:rdi]
0x0000000100003c42         lea        rsi, qword [ss:rbp+var_80]
0x0000000100003c46         call       qword [ds:rax+0xf0]
0x0000000100003c4c         test       eax, eax
0x0000000100003c4e         jne        0x100004371

0x0000000100003c54         mov        r13, r15
0x0000000100003c57         mov        qword [ss:rbp+var_A0], r13
0x0000000100003c5e         mov        r15, qword [ss:rbp+var_50]
0x0000000100003c62         mov        rax, r15
0x0000000100003c65         shr        rax, 0x20
0x0000000100003c69         mov        qword [ss:rbp+var_90], rax
0x0000000100003c70         mov        rsi, rax                                  ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003c73         mov        ecx, r15d
0x0000000100003c76         and        ecx, 0x1
0x0000000100003c79         mov        eax, r15d
0x0000000100003c7c         and        eax, 0x41
0x0000000100003c7f         cmp        eax, 0x41
0x0000000100003c82         mov        eax, 0x2
0x0000000100003c87         cmove      ecx, eax
0x0000000100003c8a         mov        dword [ds:r13+0x28], ecx
0x0000000100003c8e         mov        ecx, r15d
0x0000000100003c91         and        ecx, 0x82
0x0000000100003c97         mov        edx, r15d
0x0000000100003c9a         shr        edx, 0x1
0x0000000100003c9c         and        edx, 0x1
0x0000000100003c9f         cmp        ecx, 0x82
0x0000000100003ca5         cmove      edx, eax
0x0000000100003ca8         mov        dword [ds:r13+0x2c], edx
0x0000000100003cac         mov        ecx, r15d
0x0000000100003caf         and        ecx, 0x104
0x0000000100003cb5         mov        edx, r15d
0x0000000100003cb8         shr        edx, 0x2
0x0000000100003cbb         and        edx, 0x1
0x0000000100003cbe         cmp        ecx, 0x104
0x0000000100003cc4         cmove      edx, eax
0x0000000100003cc7         mov        dword [ds:r13+0xc], edx
0x0000000100003ccb         mov        ecx, r15d
0x0000000100003cce         and        ecx, 0x208
0x0000000100003cd4         mov        edx, r15d
0x0000000100003cd7         shr        edx, 0x3
0x0000000100003cda         and        edx, 0x1
0x0000000100003cdd         cmp        ecx, 0x208
0x0000000100003ce3         cmove      edx, eax
0x0000000100003ce6         mov        dword [ds:r13+0x10], edx
0x0000000100003cea         mov        ecx, r15d
0x0000000100003ced         and        ecx, 0x410
0x0000000100003cf3         mov        edx, r15d
0x0000000100003cf6         and        edx, 0x10
0x0000000100003cf9         shr        edx, 0x4
0x0000000100003cfc         cmp        ecx, 0x410
0x0000000100003d02         cmove      edx, eax
0x0000000100003d05         mov        dword [ds:r13+0x30], edx
0x0000000100003d09         mov        edx, r15d
0x0000000100003d0c         and        edx, 0x20
0x0000000100003d0f         mov        dword [ss:rbp+var_94], edx
0x0000000100003d15         mov        ecx, r15d
0x0000000100003d18         and        ecx, 0x820
0x0000000100003d1e         shr        edx, 0x5
0x0000000100003d21         cmp        ecx, 0x820
0x0000000100003d27         cmove      edx, eax
0x0000000100003d2a         mov        dword [ds:r13+0x34], edx
0x0000000100003d2e         mov        edi, 0x1                                  ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d33         mov        edx, 0x1                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d38         mov        ecx, r15d                                 ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d3b         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003d40         mov        dword [ds:r13+0x3c], eax
0x0000000100003d44         mov        edi, 0x10                                 ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d49         mov        edx, 0x2                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d4e         mov        r13, qword [ss:rbp+var_90]
0x0000000100003d55         mov        esi, r13d                                 ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d58         mov        ecx, r15d                                 ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d5b         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003d60         mov        rcx, qword [ss:rbp+var_A0]
0x0000000100003d67         mov        dword [ds:rcx+0x40], eax
0x0000000100003d6a         mov        edi, 0x100                                ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d6f         mov        edx, 0x4                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d74         mov        esi, r13d                                 ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d77         mov        ecx, r15d                                 ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d7a         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003d7f         mov        r13, qword [ss:rbp+var_A0]
0x0000000100003d86         mov        dword [ds:r13+0x1c], eax
0x0000000100003d8a         mov        edi, 0x1000                               ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d8f         mov        edx, 0x8                                  ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d94         mov        rsi, qword [ss:rbp+var_90]                ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d9b         mov        ecx, r15d                                 ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003d9e         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003da3         mov        dword [ds:r13+0x20], eax
0x0000000100003da7         mov        edi, 0x10000                              ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003dac         mov        edx, 0x10                                 ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003db1         mov        r13, qword [ss:rbp+var_90]
0x0000000100003db8         mov        esi, r13d                                 ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003dbb         mov        ecx, r15d                                 ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003dbe         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003dc3         mov        dword [ss:rbp+var_A4], eax
0x0000000100003dc9         mov        rcx, qword [ss:rbp+var_A0]
0x0000000100003dd0         mov        dword [ds:rcx+0x44], eax
0x0000000100003dd3         mov        edi, 0x100000                             ; argument #1 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003dd8         mov        edx, 0x20                                 ; argument #3 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003ddd         mov        esi, r13d                                 ; argument #2 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003de0         mov        ecx, r15d                                 ; argument #4 for method __Z17getFreqIndex_mfxtiiii
0x0000000100003de3         call       __Z17getFreqIndex_mfxtiiii                ; getFreqIndex_mfxt(int, int, int, int)
0x0000000100003de8         mov        r9d, r15d
0x0000000100003deb         and        r9d, 0x10
0x0000000100003def         mov        rcx, qword [ss:rbp+var_A0]
0x0000000100003df6         mov        dword [ds:rcx+0x48], eax
0x0000000100003df9         mov        r8, rcx
0x0000000100003dfc         mov        edx, 0x6
0x0000000100003e01         mov        esi, 0x6
0x0000000100003e06         je         0x100003e2b

0x0000000100003e08         mov        esi, r15d
0x0000000100003e0b         shr        esi, 0x10
0x0000000100003e0e         not        esi
0x0000000100003e10         and        esi, 0x1
0x0000000100003e13         lea        edi, qword [ds:rsi+0x2]
0x0000000100003e16         mov        ecx, dword [ss:rbp+var_A4]
0x0000000100003e1c         cmp        ecx, 0x3
0x0000000100003e1f         cmovle     edi, esi
0x0000000100003e22         lea        esi, qword [ds:rdi+0x2]
0x0000000100003e25         cmp        ecx, 0x7
0x0000000100003e28         cmovle     esi, edi

0x0000000100003e2b         mov        dword [ds:r8+0x50], esi                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2004
0x0000000100003e2f         mov        edi, dword [ss:rbp+var_94]
0x0000000100003e35         test       edi, edi
0x0000000100003e37         je         0x100003e56

0x0000000100003e39         mov        edx, r15d
0x0000000100003e3c         shr        edx, 0x11
0x0000000100003e3f         not        edx
0x0000000100003e41         and        edx, 0x1
0x0000000100003e44         lea        esi, qword [ds:rdx+0x2]
0x0000000100003e47         cmp        eax, 0x3
0x0000000100003e4a         cmovle     esi, edx
0x0000000100003e4d         lea        edx, qword [ds:rsi+0x2]
0x0000000100003e50         cmp        eax, 0x7
0x0000000100003e53         cmovle     edx, esi

0x0000000100003e56         test       r9d, r9d                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2053
0x0000000100003e59         mov        dword [ds:r8+0x54], edx
0x0000000100003e5d         mov        ecx, 0x3
0x0000000100003e62         mov        edx, 0x3
0x0000000100003e67         je         0x100003e76

0x0000000100003e69         cmp        dword [ss:rbp+var_A4], 0x2
0x0000000100003e70         setg       dl
0x0000000100003e73         movzx      edx, dl

0x0000000100003e76         test       edi, edi                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2101
0x0000000100003e78         mov        dword [ds:r8+0x5c], edx
0x0000000100003e7c         je         0x100003e87

0x0000000100003e7e         cmp        eax, 0x2
0x0000000100003e81         setg       al
0x0000000100003e84         movzx      ecx, al

0x0000000100003e87         mov        dword [ds:r8+0x60], ecx                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2122
0x0000000100003e8b         mov        ecx, r15d
0x0000000100003e8e         and        ecx, 0xe000
0x0000000100003e94         xor        eax, eax
0x0000000100003e96         cmp        ecx, 0x5fff
0x0000000100003e9c         jg         0x100004047

0x0000000100003ea2         cmp        ecx, 0x2000
0x0000000100003ea8         jne        0x10000418c

0x0000000100003eae         mov        eax, 0x1
0x0000000100003eb3         jmp        0x1000043a9

0x0000000100003eb8         cmp        ebx, 0xfff                                ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+519
0x0000000100003ebe         mov        r12, qword [ds:imp___got____stack_chk_guard] ; imp___got____stack_chk_guard
0x0000000100003ec5         mov        r12, qword [ds:r12]
0x0000000100003ec9         jg         0x100003fbf

0x0000000100003ecf         cmp        ebx, 0x800
0x0000000100003ed5         jne        0x100004023

0x0000000100003edb         mov        eax, 0x2
0x0000000100003ee0         jmp        0x10000403f

0x0000000100003ee5         mov        dword [ss:rbp+var_88], 0x0                ; case 13, XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+586
0x0000000100003eef         mov        rdi, qword [ds:r14+rbx*8+0x218]
0x0000000100003ef7         mov        byte [ss:rbp+var_80], 0xc0
0x0000000100003efb         mov        byte [ss:rbp+var_7F], 0x11
0x0000000100003eff         mov        word [ss:rbp+var_7E], 0x0
0x0000000100003f05         mov        word [ss:rbp+var_7C], 0x0
0x0000000100003f0b         mov        word [ss:rbp+var_7A], 0x4
0x0000000100003f11         lea        rax, qword [ss:rbp+var_88]
0x0000000100003f18         mov        qword [ss:rbp+var_78], rax
0x0000000100003f1c         mov        dword [ss:rbp+var_6C], 0x1e
0x0000000100003f23         mov        dword [ss:rbp+var_68], 0x1e
0x0000000100003f2a         mov        rax, qword [ds:rdi]
0x0000000100003f2d         lea        rsi, qword [ss:rbp+var_80]
0x0000000100003f31         call       qword [ds:rax+0xf0]
0x0000000100003f37         mov        ecx, dword [ss:rbp+var_88]
0x0000000100003f3d         mov        edx, ecx
0x0000000100003f3f         shr        edx, 0x9
0x0000000100003f42         and        edx, 0x7
0x0000000100003f45         test       ch, 0x1
0x0000000100003f48         mov        esi, 0x5
0x0000000100003f4d         cmove      esi, edx
0x0000000100003f50         cmp        edx, 0x3
0x0000000100003f53         cmovne     esi, edx
0x0000000100003f56         mov        dword [ds:r15], esi
0x0000000100003f59         test       eax, eax
0x0000000100003f5b         je         0x100004006

0x0000000100003f61         mov        dword [ds:r15], 0x6
0x0000000100003f68         mov        dword [ds:r15+0x18], 0xc
0x0000000100003f70         mov        dword [ds:r15+0x24], 0xc
0x0000000100003f78         mov        dword [ds:r15+0x1c], 0xc
0x0000000100003f80         movaps     xmm0, xmmword [ds:0x10000ad40]            ; 0x10000ad40
0x0000000100003f87         movups     xmmword [ds:r15+0x8], xmm0
0x0000000100003f8c         shr        ecx, 0x18
0x0000000100003f8f         and        ecx, 0xf
0x0000000100003f92         mov        dword [ds:r15+0x20], ecx
0x0000000100003f96         add        r15, 0x20
0x0000000100003f9a         mov        rsi, r15
0x0000000100003f9d         jmp        0x10000436b

0x0000000100003fa2         mov        edx, ecx                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+706
0x0000000100003fa4         and        edx, 0x102
0x0000000100003faa         cmp        edx, 0x102
0x0000000100003fb0         jne        0x100003fce

0x0000000100003fb2         mov        dword [ds:r15+0x4], 0x1
0x0000000100003fba         jmp        0x100004071

0x0000000100003fbf         cmp        ebx, 0x1000                               ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2199
0x0000000100003fc5         jne        0x100004032

0x0000000100003fc7         mov        eax, 0x4
0x0000000100003fcc         jmp        0x10000403f

0x0000000100003fce         cmp        edx, 0x2                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2430
0x0000000100003fd1         jne        0x100004069

0x0000000100003fd7         mov        dword [ds:r15+0x4], 0x2
0x0000000100003fdf         jmp        0x100004071

0x0000000100003fe4         cmp        ecx, 0xfff                                ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+1465
0x0000000100003fea         jg         0x100004165

0x0000000100003ff0         cmp        ecx, 0x800
0x0000000100003ff6         jne        0x1000041b8

0x0000000100003ffc         mov        eax, 0x2
0x0000000100004001         jmp        0x1000041d4

0x0000000100004006         mov        edx, ecx                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2345
0x0000000100004008         and        edx, 0x11
0x000000010000400b         cmp        edx, 0x11
0x000000010000400e         jne        0x100004174

0x0000000100004014         mov        dword [ds:r15+0x8], 0x2
0x000000010000401c         xor        edx, edx
0x000000010000401e         jmp        0x10000424e

0x0000000100004023         cmp        ebx, 0xc00                                ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2211
0x0000000100004029         jne        0x10000403f

0x000000010000402b         mov        eax, 0x3
0x0000000100004030         jmp        0x10000403f

0x0000000100004032         cmp        ebx, 0x1400                               ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2451
0x0000000100004038         jne        0x10000403f

0x000000010000403a         mov        eax, 0x5

0x000000010000403f         mov        dword [ds:r15], eax                       ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+542, __ZN9CHardware9GetStatusEiP14FirefaceStatus+553, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2222, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2458, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2551, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2558, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2566
0x0000000100004042         jmp        0x100004371

0x0000000100004047         cmp        ecx, 0x9fff                               ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2154
0x000000010000404d         jg         0x1000041a2

0x0000000100004053         cmp        ecx, 0x6000
0x0000000100004059         jne        0x10000438d

0x000000010000405f         mov        eax, 0x3
0x0000000100004064         jmp        0x1000043a9

0x0000000100004069         mov        dword [ds:r15+0x4], 0x0                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2463

0x0000000100004071         mov        edx, ecx                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2440, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2477
0x0000000100004073         and        edx, 0x44
0x0000000100004076         cmp        edx, 0x44
0x0000000100004079         jne        0x100004087

0x000000010000407b         mov        dword [ds:r15+0x8], 0x2
0x0000000100004083         xor        edx, edx
0x0000000100004085         jmp        0x1000040a2

0x0000000100004087         test       cl, 0x4                                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2631
0x000000010000408a         jne        0x100004098

0x000000010000408c         mov        dword [ds:r15+0x8], 0x0
0x0000000100004094         mov        dl, 0x1
0x0000000100004096         jmp        0x1000040a2

0x0000000100004098         mov        dword [ds:r15+0x8], 0x1                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2648
0x00000001000040a0         xor        edx, edx

0x00000001000040a2         mov        esi, ecx                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2643, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2660
0x00000001000040a4         shr        esi, 0x14
0x00000001000040a7         and        esi, 0xf
0x00000001000040aa         test       dl, dl
0x00000001000040ac         mov        edx, 0xc
0x00000001000040b1         mov        edi, esi
0x00000001000040b3         cmovne     edi, edx
0x00000001000040b6         cmp        esi, 0xc
0x00000001000040b9         cmova      edi, edx
0x00000001000040bc         test       eax, eax
0x00000001000040be         cmovne     edi, edx
0x00000001000040c1         mov        dword [ds:r15+0x18], edi
0x00000001000040c5         mov        edx, ecx
0x00000001000040c7         and        edx, 0x22
0x00000001000040ca         cmp        edx, 0x22
0x00000001000040cd         jne        0x1000040db

0x00000001000040cf         mov        dword [ds:r15+0xc], 0x2
0x00000001000040d7         xor        edx, edx
0x00000001000040d9         jmp        0x1000040f6

0x00000001000040db         test       cl, 0x2                                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2715
0x00000001000040de         jne        0x1000040ec

0x00000001000040e0         mov        dword [ds:r15+0xc], 0x0
0x00000001000040e8         mov        dl, 0x1
0x00000001000040ea         jmp        0x1000040f6

0x00000001000040ec         mov        dword [ds:r15+0xc], 0x1                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2732
0x00000001000040f4         xor        edx, edx

0x00000001000040f6         mov        esi, ecx                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2727, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2744
0x00000001000040f8         shr        esi, 0x10
0x00000001000040fb         and        esi, 0xf
0x00000001000040fe         test       dl, dl
0x0000000100004100         mov        edx, 0xc
0x0000000100004105         mov        edi, esi
0x0000000100004107         cmovne     edi, edx
0x000000010000410a         cmp        esi, 0xc
0x000000010000410d         cmova      edi, edx
0x0000000100004110         test       eax, eax
0x0000000100004112         cmovne     edi, edx
0x0000000100004115         mov        dword [ds:r15+0x1c], edi
0x0000000100004119         mov        edx, ecx
0x000000010000411b         and        edx, 0x11
0x000000010000411e         cmp        edx, 0x11
0x0000000100004121         jne        0x10000412f

0x0000000100004123         mov        dword [ds:r15+0x14], 0x2
0x000000010000412b         xor        edx, edx
0x000000010000412d         jmp        0x10000414a

0x000000010000412f         test       cl, 0x1                                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2799
0x0000000100004132         jne        0x100004140

0x0000000100004134         mov        dword [ds:r15+0x14], 0x0
0x000000010000413c         mov        dl, 0x1
0x000000010000413e         jmp        0x10000414a

0x0000000100004140         mov        dword [ds:r15+0x14], 0x1                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2816
0x0000000100004148         xor        edx, edx

0x000000010000414a         shr        ecx, 0xc                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2811, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2828
0x000000010000414d         and        ecx, 0xf
0x0000000100004150         lea        rsi, qword [ds:r15+0x24]
0x0000000100004154         test       eax, eax
0x0000000100004156         mov        dword [ds:r15+0x24], ecx
0x000000010000415a         je         0x100004362

0x0000000100004160         jmp        0x10000436b

0x0000000100004165         cmp        ecx, 0x1000                               ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2488
0x000000010000416b         jne        0x1000041c7

0x000000010000416d         mov        eax, 0x4
0x0000000100004172         jmp        0x1000041d4

0x0000000100004174         test       cl, 0x1                                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2524
0x0000000100004177         jne        0x100004244

0x000000010000417d         mov        dword [ds:r15+0x8], 0x0
0x0000000100004185         mov        dl, 0x1
0x0000000100004187         jmp        0x10000424e

0x000000010000418c         cmp        ecx, 0x4000                               ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2166
0x0000000100004192         jne        0x1000043a9

0x0000000100004198         mov        eax, 0x2
0x000000010000419d         jmp        0x1000043a9

0x00000001000041a2         cmp        ecx, 0xa000                               ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2587
0x00000001000041a8         jne        0x10000439c

0x00000001000041ae         mov        eax, 0x5
0x00000001000041b3         jmp        0x1000043a9

0x00000001000041b8         cmp        ecx, 0xc00                                ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2500
0x00000001000041be         jne        0x1000041d4

0x00000001000041c0         mov        eax, 0x3
0x00000001000041c5         jmp        0x1000041d4

0x00000001000041c7         cmp        ecx, 0x1400                               ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2873
0x00000001000041cd         jne        0x1000041d4

0x00000001000041cf         mov        eax, 0x5

0x00000001000041d4         mov        dword [ds:r13+0x0], eax                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+1477, __ZN9CHardware9GetStatusEiP14FirefaceStatus+1488, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2511, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2880, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2956, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2963, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2971
0x00000001000041d8         mov        eax, r15d
0x00000001000041db         shr        eax, 0x10
0x00000001000041de         and        eax, 0x3
0x00000001000041e1         mov        dword [ds:r13+0x68], eax
0x00000001000041e5         mov        rax, r15
0x00000001000041e8         shr        rax, 0x38
0x00000001000041ec         shr        r15d, 0x1b
0x00000001000041f0         add        r15d, eax
0x00000001000041f3         and        r15d, 0x1f
0x00000001000041f7         mov        eax, dword [ds:r14+rbx*4+0x5e8]
0x00000001000041ff         test       eax, eax
0x0000000100004201         jns        0x10000420e

0x0000000100004203         mov        dword [ds:r14+rbx*4+0x5e8], r15d
0x000000010000420b         mov        eax, r15d

0x000000010000420e         mov        ecx, dword [ds:r14+rbx*4+0x5d0]           ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3023
0x0000000100004216         mov        edx, ecx
0x0000000100004218         and        edx, 0x1f
0x000000010000421b         cmp        edx, r15d
0x000000010000421e         jbe        0x10000422b

0x0000000100004220         add        ecx, 0x20
0x0000000100004223         mov        dword [ds:r14+rbx*4+0x5d0], ecx

0x000000010000422b         and        ecx, 0xffffffe0                           ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3052
0x000000010000422e         or         ecx, r15d
0x0000000100004231         mov        dword [ds:r14+rbx*4+0x5d0], ecx
0x0000000100004239         sub        ecx, eax
0x000000010000423b         mov        dword [ds:r13+0x7c], ecx
0x000000010000423f         jmp        0x100004371

0x0000000100004244         mov        dword [ds:r15+0x8], 0x1                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2885
0x000000010000424c         xor        edx, edx

0x000000010000424e         mov        esi, ecx                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2540, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2901
0x0000000100004250         shr        esi, 0xc
0x0000000100004253         and        esi, 0xf
0x0000000100004256         test       dl, dl
0x0000000100004258         mov        edx, 0xc
0x000000010000425d         mov        edi, esi
0x000000010000425f         cmovne     edi, edx
0x0000000100004262         cmp        esi, 0xc
0x0000000100004265         cmova      edi, edx
0x0000000100004268         test       eax, eax
0x000000010000426a         cmovne     edi, edx
0x000000010000426d         mov        dword [ds:r15+0x18], edi
0x0000000100004271         mov        edx, ecx
0x0000000100004273         and        edx, 0x22
0x0000000100004276         cmp        edx, 0x22
0x0000000100004279         jne        0x100004287

0x000000010000427b         mov        dword [ds:r15+0x14], 0x2
0x0000000100004283         xor        edx, edx
0x0000000100004285         jmp        0x1000042a2

0x0000000100004287         test       cl, 0x2                                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3143
0x000000010000428a         jne        0x100004298

0x000000010000428c         mov        dword [ds:r15+0x14], 0x0
0x0000000100004294         mov        dl, 0x1
0x0000000100004296         jmp        0x1000042a2

0x0000000100004298         mov        dword [ds:r15+0x14], 0x1                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3160
0x00000001000042a0         xor        edx, edx

0x00000001000042a2         mov        esi, ecx                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3155, __ZN9CHardware9GetStatusEiP14FirefaceStatus+3172
0x00000001000042a4         shr        esi, 0x10
0x00000001000042a7         and        esi, 0xf
0x00000001000042aa         test       dl, dl
0x00000001000042ac         mov        edx, 0xc
0x00000001000042b1         mov        edi, esi
0x00000001000042b3         cmovne     edi, edx
0x00000001000042b6         cmp        esi, 0xc
0x00000001000042b9         cmova      edi, edx
0x00000001000042bc         test       eax, eax
0x00000001000042be         cmovne     edi, edx
0x00000001000042c1         mov        dword [ds:r15+0x24], edi
0x00000001000042c5         mov        edx, ecx
0x00000001000042c7         and        edx, 0x44
0x00000001000042ca         cmp        edx, 0x44
0x00000001000042cd         jne        0x1000042db

0x00000001000042cf         mov        dword [ds:r15+0xc], 0x2
0x00000001000042d7         xor        edx, edx
0x00000001000042d9         jmp        0x1000042f6

0x00000001000042db         test       cl, 0x4                                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3227
0x00000001000042de         jne        0x1000042ec

0x00000001000042e0         mov        dword [ds:r15+0xc], 0x0
0x00000001000042e8         mov        dl, 0x1
0x00000001000042ea         jmp        0x1000042f6

0x00000001000042ec         mov        dword [ds:r15+0xc], 0x1                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3244
0x00000001000042f4         xor        edx, edx

0x00000001000042f6         mov        esi, ecx                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3239, __ZN9CHardware9GetStatusEiP14FirefaceStatus+3256
0x00000001000042f8         shr        esi, 0x14
0x00000001000042fb         and        esi, 0xf
0x00000001000042fe         test       dl, dl
0x0000000100004300         mov        edx, 0xc
0x0000000100004305         mov        edi, esi
0x0000000100004307         cmovne     edi, edx
0x000000010000430a         cmp        esi, 0xc
0x000000010000430d         cmova      edi, edx
0x0000000100004310         test       eax, eax
0x0000000100004312         cmovne     edi, edx
0x0000000100004315         mov        dword [ds:r15+0x1c], edi
0x0000000100004319         mov        edx, ecx
0x000000010000431b         and        edx, 0x88
0x0000000100004321         cmp        edx, 0x88
0x0000000100004327         jne        0x100004335

0x0000000100004329         mov        dword [ds:r15+0x10], 0x2
0x0000000100004331         xor        edx, edx
0x0000000100004333         jmp        0x100004350

0x0000000100004335         test       cl, 0x8                                   ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3317
0x0000000100004338         jne        0x100004346

0x000000010000433a         mov        dword [ds:r15+0x10], 0x0
0x0000000100004342         mov        dl, 0x1
0x0000000100004344         jmp        0x100004350

0x0000000100004346         mov        dword [ds:r15+0x10], 0x1                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3334
0x000000010000434e         xor        edx, edx

0x0000000100004350         shr        ecx, 0x18                                 ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3329, __ZN9CHardware9GetStatusEiP14FirefaceStatus+3346
0x0000000100004353         and        ecx, 0xf
0x0000000100004356         lea        rsi, qword [ds:r15+0x20]
0x000000010000435a         test       eax, eax
0x000000010000435c         mov        dword [ds:r15+0x20], ecx
0x0000000100004360         jne        0x10000436b

0x0000000100004362         cmp        ecx, 0xc                                  ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2856
0x0000000100004365         ja         0x10000436b

0x0000000100004367         test       dl, dl
0x0000000100004369         je         0x100004371

0x000000010000436b         mov        dword [ds:rsi], 0xc                       ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+784, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2411, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2862, __ZN9CHardware9GetStatusEiP14FirefaceStatus+3374, __ZN9CHardware9GetStatusEiP14FirefaceStatus+3379

0x0000000100004371         cmp        r12, qword [ss:rbp+var_30]                ; case 14, XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+83, __ZN9CHardware9GetStatusEiP14FirefaceStatus+160, __ZN9CHardware9GetStatusEiP14FirefaceStatus+566, __ZN9CHardware9GetStatusEiP14FirefaceStatus+586, __ZN9CHardware9GetStatusEiP14FirefaceStatus+860, __ZN9CHardware9GetStatusEiP14FirefaceStatus+1564, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2576, __ZN9CHardware9GetStatusEiP14FirefaceStatus+3085, __ZN9CHardware9GetStatusEiP14FirefaceStatus+3383, __ZN9CHardware9GetStatusEiP14FirefaceStatus+3555
0x0000000100004375         jne        0x10000441a

0x000000010000437b         add        rsp, 0x88
0x0000000100004382         pop        rbx
0x0000000100004383         pop        r12
0x0000000100004385         pop        r13
0x0000000100004387         pop        r14
0x0000000100004389         pop        r15
0x000000010000438b         pop        rbp
0x000000010000438c         ret

0x000000010000438d         cmp        ecx, 0x8000                               ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2599
0x0000000100004393         jne        0x1000043a9

0x0000000100004395         mov        eax, 0x4
0x000000010000439a         jmp        0x1000043a9

0x000000010000439c         cmp        ecx, 0xc000                               ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2934
0x00000001000043a2         jne        0x1000043a9

0x00000001000043a4         mov        eax, 0x6

0x00000001000043a9         mov        dword [ds:r8], eax                        ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+2177, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2610, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2912, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2923, __ZN9CHardware9GetStatusEiP14FirefaceStatus+2945, __ZN9CHardware9GetStatusEiP14FirefaceStatus+3425, __ZN9CHardware9GetStatusEiP14FirefaceStatus+3432, __ZN9CHardware9GetStatusEiP14FirefaceStatus+3440
0x00000001000043ac         mov        eax, r15d
0x00000001000043af         shr        eax, 0xc
0x00000001000043b2         and        eax, 0x1
0x00000001000043b5         mov        dword [ds:r8+0x68], eax
0x00000001000043b9         mov        rsi, r8
0x00000001000043bc         mov        rax, r15
0x00000001000043bf         shr        rax, 0x38
0x00000001000043c3         shr        r15d, 0x1b
0x00000001000043c7         add        r15d, eax
0x00000001000043ca         and        r15d, 0x1f
0x00000001000043ce         mov        eax, dword [ds:r14+rbx*4+0x5e8]
0x00000001000043d6         test       eax, eax
0x00000001000043d8         jns        0x1000043e5

0x00000001000043da         mov        dword [ds:r14+rbx*4+0x5e8], r15d
0x00000001000043e2         mov        eax, r15d

0x00000001000043e5         mov        ecx, dword [ds:r14+rbx*4+0x5d0]           ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3494
0x00000001000043ed         mov        edx, ecx
0x00000001000043ef         and        edx, 0x1f
0x00000001000043f2         cmp        edx, r15d
0x00000001000043f5         jbe        0x100004402

0x00000001000043f7         add        ecx, 0x20
0x00000001000043fa         mov        dword [ds:r14+rbx*4+0x5d0], ecx

0x0000000100004402         and        ecx, 0xffffffe0                           ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3523
0x0000000100004405         or         ecx, r15d
0x0000000100004408         mov        dword [ds:r14+rbx*4+0x5d0], ecx
0x0000000100004410         sub        ecx, eax
0x0000000100004412         mov        dword [ds:rsi+0x7c], ecx
0x0000000100004415         jmp        0x100004371

0x000000010000441a         call       imp___stubs____stack_chk_fail             ; XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+3395
                        ; endp
0x000000010000441f         nop
0x0000000100004420         dd         0xfffff45e, 0xfffff7e7, 0xfffff7e7, 0xfffff527 ; switch table, XREF=__ZN9CHardware9GetStatusEiP14FirefaceStatus+572
0x0000000100004430         dd         0xfffff7e7, 0xffffff51, 0xfffff45e, 0xfffff45e
0x0000000100004440         dd         0xfffffac5, 0xfffff45e, 0xfffff527, 0xfffff527
0x0000000100004450         dd         0xfffff527, 0xfffffac5, 0xffffff51, 0xfffff45e
