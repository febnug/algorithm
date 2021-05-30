%macro exit64 0
    mov     rax, 60
    xor     rdi, rdi
    syscall
%endmacro

%macro printf 2
;input rsi=offset of message, rdx=message.len
    push    rax
    push    rdx
    push    rsi
    push    rdi
    mov     rsi, %1
    mov     rdx, %2
    mov     rax, 1
    mov     rdi, rax
    syscall
    pop     rdi 
    pop     rsi
    pop     rdx
    pop     rax
%endmacro

%macro scanf 2
;input rsi=offset of buffer rdx=buffer.len
    push    rax
    push    rdx
    push    rsi
    push    rdi
    mov     rsi, %1
    mov     rdx, %2
    mov     rax, 0
    mov     rdi, rax
    syscall
    pop     rdi
    pop     rsi
    pop     rdx
    pop     rax
%endmacro

%macro reg2stack 0
pushf
push rax
push rbx
push rcx
push rdx
push rsi
push rdi
push rbp
push rsp
%endmacro
%macro stack2reg 0
pop rsp
pop rbp
pop rdi
pop rsi
pop rdx
pop rcx
pop rbx
pop rax
popf
%endmacro
%macro ech0 2
mov rsi,%1
mov rdx,%2
%%ulangbuf:
cmp byte [rsi],0
jnz %%tampilin
inc rsi 
dec rdx
jmp %%ulangbuf
%%tampilin:
mov rax,1
mov rdi,rax
syscall
%endmacro

%macro rax2ascii 2
mov rsi,%1
add rsi,%2
dec rsi
mov byte [rsi],10
mov rdi,10
%%val2strg:
xor rdx,rdx
div rdi
add dl,30h
dec rsi
mov byte [rsi],dl
and rax,rax
jnz %%val2strg
ech0 %1,%2
%endmacro

%macro rax2div 2
mov rsi,%1
add rsi,%2
dec rsi
mov byte [rsi],"."
mov rdi,10
%%val2str:
xor rdx,rdx
div rdi
add dl,30h
dec rsi
mov byte [rsi],dl
and rax,rax
jnz %%val2str
ech0 %1,%2
%endmacro

%macro rax2str 2
mov rsi,%1
add rsi,%2
mov rdi,10
%%val2str:
xor rdx,rdx
div rdi
add dl,30h
dec rsi
mov byte [rsi],dl
and rax,rax
jnz %%val2str
ech0 %1,%2
%endmacro

%macro rax2nul 2
mov rsi,%1
add rsi,%2
dec rsi
mov byte [rsi],10
mov rdi,10
%%val2str3:
xor rdx,rdx
div rdi
add dl,30h
dec rsi
mov byte [rsi],dl
and rax,rax
jnz %%val2str3
ech0 %1,%2
%endmacro
%macro clearbuf 2
push rcx
push rax
push rdi
cld
mov ax,ds
mov es,ax
mov rcx,%2
lea rdi,[%1]
xor rax,rax
rep stosb
pop rdi
pop rax
pop rcx
%endmacro
