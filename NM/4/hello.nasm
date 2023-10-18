SECTION .data
msg: db "hello world",10
msgLen: equ $ - msg ; the $ sign means the current byte address. That means the address where the next byte would go

SECTION .text

global _start ; "global" means that the symbol can be accessed in other modules. In order to refer to a global symbol from another module, you must use the "extern" keyboard
_start:
    mov eax, 4 ; syscall: write
    mov ebx, 1 ; stdout
    mov ecx, msg
    mov edx, msgLen
    int 0x80 ; call!

    mov eax, 1 ; syscal: exit
    mov ebx, 0 ; return code
    int 0x80
