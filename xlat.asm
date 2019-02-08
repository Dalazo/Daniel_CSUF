;----------------------------------------------------------------
;  Writes "Hello World" to the console using only system calls.
;  Runs on 64-bit linux only.
;       nasm -felf64 hello.asm
;       ld -o hello hello.o
;       ./hello
;----------------------------------------------------------------

    global  _start
    section .text
_start:
    
   
  
    mov    al,  15
    lea	   rbx, [xtable]    ;
    xlat                    ;
    mov     [bval], al      ;
    mov     rax, 1          ; System call for write
    mov     rdi, 1          ; File handle 1 is stdout
    mov     rsi, bval       ; Addres of string to output
    mov    rsi, bval2 
    mov     rdx, 27          ; Size of message in # of bytes
   
    
    syscall                 ; invoke operating system to do the write
    mov     rax, 60         ; System call for exit
    xor     rdi, rdi        ; exit code 0
    syscall                 ; Invoke operating system to do the exit

    section  .data
    
    xtable:  db "0123456789ABCDEF"
    bval2:   db "Here is your conversion: ";
    bval:    db  1,10
   
    