format elf64 executable
entry _start

msg db "Hello, World!", 0xA, 0

_start:
    mov rax, msg
    call print_func
    call exit

; |input
; rax -> msg[0]
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

exit:
    xor rax, rax
    inc rax
    xor rbx, rbx
    int 0x80
