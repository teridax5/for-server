format elf64
public fibonacci
public factorial
public gcd

section '.factorial' executable
; |input
; rax=number
; |output
; rax=number
factorial:
    push rbx
    mov rbx, rax
    mov rax, 1
    .next_iter:
        cmp rbx, 0
        je .close
        mul rbx
        dec rbx
        jmp .next_iter
    .close:
        pop rbx
        ret

section '.fibonacci' executable
; |input
; rax=index
; |output
; rax=fib[index]
fibonacci:
    push rbx
    push rcx
    xor rbx, rbx
    xor rcx, rcx
    inc rcx
    .next_iter:
        cmp rax, 0
        je .close
        push rcx
        add rcx, rbx
        pop rbx
        dec rax
        jmp .next_iter
    .close:
        mov rax, rbx
        pop rcx
        pop rbx
        ret

section '.gcd' executable
gcd:
; |input
; rax = integer
; rbx = integer
; |output
; rax = number
    push rdx
    .iter:
        cmp rbx, 0
        je .close
        xor rdx, rdx
        div rbx
        push rdx
        mov rax, rbx
        pop rbx
        jmp .iter
    .close:
        pop rdx
        ret
