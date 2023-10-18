; 2068 Bhadra read string count no of vowels consonants numerals and other characters and display the count.
; does not work from book can be done as a part solution to the no 19 and 17
; fake answer in the book

      .model small
      .stack 100h

       .data
            s1 db 'enter a string :$'
            vowl db 'AEIOUaeiou$'

            para_list label byte    ; start of parameter list and all below are part of list
            mxchar db 99
            nchar db ?
            s2 db 100 dup('$')

            s3 db 10,13,'Num. of vowels are : $'

            count dw ?

       .code

        main proc
              mov ax,@data          ;inititalize stack
              mov ds,ax
              mov es,ax

              mov cx,0000h          ; counter
              mov cl,10h

              lea dx,s1             ;msg
              mov ah,09h
              int 21h

              lea dx,para_list
              mov ah,0ah
              int 21h

              lea dx,s2
              xor cl,cl             ; resetting couter a
              cld

       loop1: mov ah,01h
              cmp al,0dh
              jz endinpt
              stosb
              inc cl
              jmp loop1

     endinpt: mov bl,cl
              cmp cl,00h
              jnz jump1
              xor ax,ax
              jmp pr

      jump1:  cld
              lea si,s2
       next:  mov cx,000bh
              lodsb
              lea di,vowl
              repne scasb
              cmp cx,00
              inc cl

      novowl: dec bl
              jnz next
              mov dl,0ah
              mov ah,02h
              int 21h
              mov ax,cx
         pr:  mov bx,000ah
              xor cx,cx
       print: xor dx,dx
              div bx
              push dx
              inc cx
              inc cx
              cmp ax,0000h
              jne print
              lea dx,s3
              mov ah, 09h
              int 21h
      display:pop dx
              add dl,30h
              mov ah,02h
              int 21h
              loop display
              mov ax,4c00h
              int 21h
        main endp
        end main




