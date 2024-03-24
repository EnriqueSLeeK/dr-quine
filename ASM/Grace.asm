extern printf
section .text
global main
main:

mov rax, 2
mov rdi, name
mov rsi, 64
mov rdx, 0664q
syscall


mov rax, 3 ; Close
syscall

ret

section .rodata
name: db "Grace_kid.asm", 0
m: db "bau bau", 10, 0
