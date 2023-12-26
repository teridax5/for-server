format elf64
public read_from_stdin
public buffer

section '.input_buffer' writeable
buffer rb 2048

section '.read_from_stdin' executable
read_from_stdin:
; |input
; rax = buffer ptrr
; rbx = buffer len
    push rax
    push rbx
    push rcx
    push rdx
    mov rcx, rax
    mov rdx, rbx
    mov rax, 3
    mov rbx, 2
    int 0x80
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret
