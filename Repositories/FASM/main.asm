format elf64
public _start

include "asmlib/stdin.inc"
include "asmlib/stdout.inc"
include "asmlib/sys.inc"
include "asmlib/fmt.inc"
include "asmlib/mth.inc"

section '.data' writeable
num db '4321', 0

section '.entry' executable
_start:
    mov rax, buffer
    mov rbx, 2048
    call read_from_stdin
    mov rax, 95
    mov rbx, 8
    call print_num_sys
    call print_line
    call print_char
    call print_line
    mov rax, msg
    call print_string
    mov rax, 1234
    call int_to_string
    call print_string
    call print_line
    mov rax, num
    call string_to_int
    mov rbx, 10
    call print_num_sys
    call print_line
    mov rax, 10
    call factorial
    mov rbx, 10
    call print_num_sys
    call print_line
    mov rax, 10
    call fibonacci
    mov rbx, 10
    call print_num_sys
    call print_line
    mov rax, 231
    mov rbx, 77
    call gcd
    mov rbx, 10
    call print_num_sys
    call print_line
    call exit
