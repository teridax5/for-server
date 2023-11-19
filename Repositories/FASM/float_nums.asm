format elf64
public _start

float_num db '9.23', 0xA, 0

_start:
    mov rax, float_num
    call print_float
    call exit

print_float:
    mov rcx, rax
    mov rdx, 5
    mov rax, 4
    mov rbx, 1
    int 0x80
    ret

exit:
    xor rax, rax
    inc rax
    xor rbx, rbx
    int 0x80
