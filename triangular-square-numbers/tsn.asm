        xor     rdx, rdx
        mov     rax, 0
        mov     rbx, 1
        mov     rax, rbx
        mov     rcx, 11
 .loop:
        jrcxz   .exit_loop
        imul    rax, rax, 0x22
        sub     rax, rdx
        add     rax, 0x2
        mov     r8, rax
        add     rdx, 1
        sub     rdx, 1
        xchg    rdx, rbx
        mov     rbx, r8
        loop    .loop
 .exit_loop:
