format elf64
public _start

msg db "Hello, World!", 0xA,  0
len = $-msg

_start:
    mov rax, 4
    mov rbx, 1
    mov rcx, msg
    mov rdx, len
    int 0x80
    call exit

exit:
    xor rax, rax
    inc rax
    xor rbx, rbx
    int 0x80
