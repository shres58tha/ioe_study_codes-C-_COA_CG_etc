; 2071 magh 8086 code to read a read a string & display only alphabetic char in clear screen
; works
      .model small
      .stack 100h

       .data
            count db 00h   ;count intialized to 0
            prompt db 'enter a string:','$'
            msg1 db 'press any key .....','$'

            ;the data below structured storage alinged to byte
            ;for int vector 0a  ie colllection of string from keyboard
            para_list label byte    ; start of parameter list and all below are part of list
            max_len db 254          ; max number of input
            actual_len db ?         ; count for the number of the characters entered
            charBuf db 255 dup('$') ; place to keep chars entered max_len +1 to hold terminator'$'

       .code
        main proc
            print macro msg       ; macro defination for printing msg
                push ax
                mov dx, offset msg
                mov ah,09h
                int 21h              ; dos int service
                pop ax              ; return the state of registers
                pop dx
            endm

            input macro pra_lst
                push dx             ; save state of registers accessed in macro
                push ax
                mov ah,0ah          ; int vector for request keyboard input of string
                lea dx,pra_lst      ; parameter list for collectng input from keyboard
                int 21h             ; dos int service
                pop ax              ; return the state of registers
                pop dx
            endm

            mov ax,@data
            mov ds,ax
            print prompt
            input para_list

            ; A= 65  41h
            ; Z= 90  5Ah
            ; a= 97  61h
            ; z= 122 7Ah

            mov cl,actual_len        ;putting total no of chars in cl
            mov ch,00                ; setting cx
            mov si,offset charBuf
      next: mov al,[si]
            cmp al,65
            jb notalpha
            cmp al,91
            jb  alpha
            cmp al,97
            jb notalpha
            cmp al,122
            jb alpha
            jmp notalpha

     alpha: mov dl,al
            call putch
  notalpha: inc si
            loop next

            mov ax,4c00h
            int 21h
         main endp

         putch proc
            mov ah,2h
            int 21h
            ret
         putch endp

        end main
