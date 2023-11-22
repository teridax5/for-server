format elf64
public print_num_sys
public print_char
public print_line
public print_string
public msg

section '.output_data' writeable
msg db 'Hello, world!', 0xA, 0

section '.output_buffer' writeable
sym rb 1

section '.print_num_sys' executable
print_num_sys:
; |input
; rax = integer
; rbx = integer base
    push rax
    push rcx
    push rdx
    xor rcx, rcx
    .iter1:
        cmp rax, 0
        je .iter2
        xor rdx, rdx
        div rbx
        add rdx, '0'
        cmp rdx, '9'
        jg .letter
        .back:
        push rdx
        inc rcx
        jmp .iter1
    .letter:
        add rdx, 7
        jmp .back
    .iter2:
        cmp rcx, 0
        je .close
        pop rax
        call print_char
        dec rcx
        jmp .iter2
    .close:
        pop rdx
        pop rcx
        pop rax
        ret

section '.print_char' executable
print_char:
    push rax
    push rbx
    push rcx
    push rdx
    mov [sym], al
    mov rax, 4
    mov rbx, 1
    mov rcx, sym
    mov rdx, 1
    int 0x80
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret

section '.print_line' executable
print_line:
    push rax
    mov rax, 0xA
    call print_char
    pop rax
    ret

section '.print_string' executable
print_string:
; |input
; rax = string ptr
    push rax
    push rbx
    xor rbx, rbx
    .next_iter:
        cmp [rax+rbx], byte 0
        je .print_and_close
        inc rbx
        jmp .next_iter
    .print_and_close:
        push rcx
        push rdx
        mov rcx, rax
        mov rax, 4
        mov rdx, rbx
        mov rbx, 1
        int 0x80
        pop rdx
        pop rcx
        pop rbx
        pop rax
        ret
