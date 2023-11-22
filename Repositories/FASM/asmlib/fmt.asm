format elf64
public int_to_string
public int_buffer
public string_to_int

section '.num_buffer' writeable
int_buffer rb 21

section '.int_to_string' executable
int_to_string:
; |input
; rax = integer
; |output
; rax = string ptr
    push rbx
    push rcx
    push rdx
    mov rbx, 10
    xor rcx, rcx
    .iter1:
        cmp rax, 0
        je .nullify
        xor rdx, rdx
        div rbx
        add rdx, '0'
        push rdx
        inc rcx
        jmp .iter1
    .nullify:
        xor rax, rax
        xor rdx, rdx
    .iter2:
        cmp rcx, 0
        je .close
        pop rdx
        mov [int_buffer+rax], dl
        inc rax
        dec rcx
        jmp .iter2
    .close:
        mov [int_buffer+rax], byte 0
        pop rdx
        pop rcx
        pop rbx
        mov rax, int_buffer
        ret

section '.string_to_int' executable
string_to_int:
; |input
; rax = string ptr
; |output
; rax = integer
    push rbx
    push rcx
    push rdx
    xor rbx, rbx
    xor rcx, rcx
    .iter1:
        cmp [rax+rbx], byte 0
        je .prepare
        mov cl, [rax+rbx]
        sub rcx, '0'
        push rcx
        inc rbx
        jmp .iter1
    .prepare:
        mov rcx, 1
        xor rax, rax
    .iter2:
        cmp rbx, 0
        je .close
        pop rdx
        imul rdx, rcx
        add rax, rdx
        imul rcx, 10
        dec rbx
        jmp .iter2
    .close:
        pop rdx
        pop rcx
        pop rbx
        ret
