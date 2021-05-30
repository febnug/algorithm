;;
;; credits : TfA
;;
;; Thank's to solve my problem :3
;;

%include "m.inc"

global _start
section .data
        panjang     equ 30
        maxi        dq 0x60000000
        counter     dq 0
        buffer      times panjang db 0
        sama        dq 0

section .text
_start:

; 2X^2=(n(n+1))

        xor     r9, r9 ;r9=count X
        push    r9
        pop     rdx

.loop:
        mov     rbx, r9
        inc     rbx
        mov     r9, rbx
        imul    rbx, rbx
        shl     rbx, 1
        mov     [sama], rbx	; simpan untuk di cetak

checkpoint:
        inc     rdx
        push    rdx
        pop     rbx
        inc     rbx
        imul    rbx, rdx
        cmp     rbx, [sama]
        jb      checkpoint
        ja      loncati
        mov     rax, rbx
        shr     rax, 1
        rax2ascii buffer, panjang

loncati:
        cmp     r9, [maxi]
        jne     .loop

exit:
        mov     rax, 60
        syscall
