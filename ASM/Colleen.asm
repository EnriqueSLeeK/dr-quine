global main
extern printf
section .text
main:
lea rdi, [rel m]
mov rsi, 10 ;nl
mov rdx, 34
mov rcx, m
mov al, 0
call printf
mov rax, 0x3C
xor rdi, rdi
syscall
section .rodata
m: db "global main%1$cextern printf%1$csection .text%1$cmain:%1$clea rdi, [rel m]%1$cmov rsi, 10 ;nl%1$cmov rdx, 34%1$cmov r10, [rel m]%1$cmov al, 0%1$ccall printf%1$ccall printf%1$cmov rax, 0x3C%1$cxor rdi, rdi%1$csyscall%1$csection .data%1$cm: db %2$c%3$s%2$c%1$c", 0
