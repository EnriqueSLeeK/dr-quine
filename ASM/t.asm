          global    main         ; entry point for c-compiler
          extern    printf       ; will be borrowed from c-library
                                 ; printf(char* format, data)
                                 ; printf(rdi, rsi)

          section   .text
main:   
          ; lea       rdi, [rel message]   ; the format is the message!
          ;                                ; no need for rsi
          ;                  ; printf("Hellow world!");
          ;          ; or (alternative):
          ; lea       rdi, [rel fmts]
          ; lea       rsi, [rel message]
          ;                  ; printf("%s", "Hellow world!");
              
          ; mov       al, 0        ; no SSE regs used
          ; call      printf

          lea       rdi, [rel fmti]
          push 3
          push 4
          push fmti
          mov       al, 0
          call      printf
          add rsp, 24


          ; mov       rax, 0x3C    ; system call for exit
          ; xor       rdi, rdi     ; exit code 0
          ; syscall                ; invoke operating system to exit

          section   .data
message:  db        "Hello, World!",10,0; don't forget to terminate
   fmti:  db        "%d %d!!!!",10,0    ; format for printing int
   fmts:  db        "%s!!!!!!!!!!!!!!!!!!!!",0       ; format fpr printing string
