format elf64
public _start

bss_char rb 1

_start:
    mov rax, 27
    mov rbx, 28
    call some_ops
    call exit

some_ops:
    push rax
    push rbx
    push rcx
    push rdx
    xor rcx, rcx
    .next_iter:
        jmp .next_iter
    sub rax, rbx
    pop rdx
    pop rcx
    pop rbx
    pop rax

    ret

print_char:
    push rax
    push rbx
    push rcx
    push rdx
    mov rcx, bss_char
    mov rdx, 1
    mov rax, 4
    mov rbx, 1
    int 0x80
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret

exit:
    xor rax, rax
    inc rax
    xor rbx, rbx
    int 0x80
