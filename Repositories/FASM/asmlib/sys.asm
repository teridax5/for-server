format elf64
public exit

section '.exit' executable
exit:
    xor rax, rax
    inc rax
    xor rbx, rbx
    int 0x80
