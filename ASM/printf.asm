
global main
extern printf
section .text
main:
        lea rdi, [rel fmt2]
        lea rsi, [rel m]

        mov al, 0
        call printf

        mov rax, 0x3C
        xor rdi, rdi
        syscall


section .data
m: db "this is something meh", 10, 0
fmt1: db "%d\n", 23, 0
fmt2: db "%s!!!\n", 0
