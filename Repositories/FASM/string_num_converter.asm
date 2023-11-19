format elf64
public _start

section '.data' writeable
    strnum db "571332", 0
    _buffer.size equ 20

section '.buffer' writeable
    bss_char rb 1
    _buffer rb _buffer.size

section '._start' executable
_start:
    mov rax, strnum
    call string_to_number
    ;mov rax, 571
    mov rbx, _buffer
    mov rcx, _buffer.size
    call number_to_string
    mov rax, _buffer
    call print_func
    call print_line
    call exit


section '.string_to_number' executable
; |input
; rax = string
; |output
; rax = number
string_to_number:
    push rbx
    push rcx
    push rdx
    xor rbx, rbx
    xor rcx, rcx
    .next_iter:
        cmp [rax+rbx], byte 0
        je .nullify
        mov cl, [rax+rbx]
        sub cl, '0'
        push rcx
        xor rcx, rcx
        inc rbx
        jmp .next_iter
    .nullify:
        xor rax, rax
        inc rcx
    .next_step:
        cmp rbx, 0
        je .close
        pop rdx
        imul rdx, rcx
        imul rcx, 10
        add rax, rdx
        dec rbx
        jmp .next_step
    .close:
        pop rdx
        pop rcx
        pop rbx
        ret

section '.number_to_string' executable
; |input:
; rax = number
; rbx=_buffer
; rcx=_buffer.size
number_to_string:
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    mov rsi, rcx
    dec rsi
    xor rcx, rcx
    .next_iter:
        push rbx
        mov rbx, 10
        xor rdx, rdx
        div rbx
        pop rbx
        add rdx, '0'
        push rdx
        inc rcx
        cmp rax, 0
        je .next_step
        je .to_string
        jmp .next_iter
    .next_step:
        mov rdx, rcx
        xor rcx, rcx
    .to_string:
        cmp rcx, rsi
        je .pop_iter
        cmp rcx, rdx
        je .null_char
        pop rax
        mov [rbx+rcx], rax
        inc rcx
        jmp .to_string
    .null_char:
        mov rsi, rdx
    .pop_iter:
        cmp rcx, rdx
        je .close
        pop rax
        inc rcx
        jmp .pop_iter
    .close:
        mov [rbx+rsi], byte 0
        pop rsi
        pop rdx
        pop rcx
        pop rbx
        pop rax
        ret

; |input:
; rax=char
section '.print_char' executable
print_char:
    ;push rax
    ;mov rax, 1 ; write
    ;mov rdi, 1 ; stdout
    ;mov rsi, rsp ; rsp -> stack[-1], rdi == rcx
    ;mov rdx, 1 ; length
    ;syscall

    ;pop rax
    push rax
    push rbx
    push rcx
    push rdx
    mov [bss_char], al

    mov rax, 4
    mov rbx, 1
    mov rcx, bss_char
    mov rdx, 1
    int 0x80

    pop rdx
    pop rcx
    pop rdx
    pop rax
    ret

section '.print_func' executable
print_func:
    push rax
    push rbx
    push rcx
    push rdx
    mov rcx, rax
    call length_string
    mov rax, 4
    mov rbx, 1
    int 0x80
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret

; |input
; rax -> msg[0]
; |output
; rdx = length
section '.length_string' executable
length_string:
    xor rdx, rdx
    call .next_iter
    .next_iter:
        cmp [rax+rdx], byte 0
        je .close
        inc rdx
        jmp .next_iter
    .close:
        ret

section '.print_line' executable
print_line:
    push rax
    mov rax, 0xA
    call print_char
    pop rax
    ret

section '.exit' executable
exit:
    xor rax, rax
    inc rax
    xor rbx, rbx
    int 0x80
