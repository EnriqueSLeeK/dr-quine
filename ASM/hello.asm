; hi
section .bss:
code: db "; hi%csection .bss:%ccode: db %c%s%c%ccodeLen:equ $-code%csection .text%cglobal _start%c_start:%c; hi%cmov rax, 1%cmov rdi, 1%cmov rsi, code%cmov rdx, codeLen%csyscall%cmov rax, 60%cmov rdi, 0%csyscall%c"
codeLen: equ $-code

section .text
global _start
extern printf

        _start:
                ;hi
                mov rax, 1
                mov rdi, 1
                mov rsi, code
                mov rdx, codeLen
                syscall

                mov rax, 60
                mov rdi, 0
                syscall
