; 2072 magh 8086 code to read a string apd display each word in a separate line in the center of the screen.
; done finally working perfectly as intended
      .model small
      .stack 100h

       .data
            count db 00h   ;count intialized to 0
            prompt db 'enter a string:','$'
            msg1 db 'press any key .....','$'
            tmp db 50 dup('$')         ; initialize 50 bytes array for char to null
            row db 24                  ;setting screen size  row 24 chars     normally 25X80
            col db 79                  ;setting screen size  col 79 chars
            end_str db '$'

            ;the data below structured storage alinged to byte
            ;for int vector 0a  ie colllection of string from keyboard
            para_list label byte    ; start of parameter list and all below are part of list
            max_len db 254          ; max number of input
            actual_len db ?         ; count for the number of the characters entered
            charBuf db 255 dup('$') ; place to keep chars entered max_len +1 to hold terminator'$'

       .code
        main proc
            save_stack macro        ; macro to save entire stack
                ;push
            endm


            print macro msg       ; macro defination for printing msg
                push ax
                mov dx, offset msg
                mov ah,09h
                int 21h              ; dos int service
                pop ax              ; return the state of registers
                pop dx
            endm

            nextline macro          ; prints nextline
                push dx             ; save state of registers accessed in macro
                push ax
                mov ah,02h
                mov dl,0dh          ; line feed
                int 21h
                mov dl,0ah          ; next line
                int 21h             ; dos int service
                pop ax              ; return the state of registers
                pop dx
            endm

            space macro             ;print space
                push dx             ; save state of registers accessed in macro
                push ax
                mov dl,09h          ; space
                mov ah,02h          ; setting for char print int vector
                int 21h             ; dos int service
                pop ax              ; return the state of registers
                pop dx
            endm

            inp_str macro str
                push dx             ; save state of registers accessed in macro
                push ax
                mov ah,0ah          ; int vector for request keyboard input of string
                lea dx,para_list    ; parameter list for collectng input from keyboard
                int 21h             ; dos int service
                pop ax              ; return the state of registers
                pop dx
            endm

            setwindow macro
                push dx             ; save state of registers accessed in macro
                push ax
                push cx
                mov ax,0600h        ; select whole screen display area  06 scroll up
                mov bh,0fh          ; black background and white foreground
                mov cx,0000h        ; ch=00h clear screen bring cursor to 00 00
                mov dh,row          ; set row
                mov dl,col          ; set col
                int 10h             ; dos int service for setting screen
                pop cx
                pop ax              ; return the state of registers
                pop dx
            endm

            crlscr macro
                push ax             ; save state of registers accessed in macro
                mov ax,0003h        ; mode colour txt
                mov bh,0fh          ; black background and white foreground
                mov cx,0000h        ; start scan line
                mov dh,row          ; set row
                mov dl,col          ; set col
                int 10              ; dos int service for setting screen
                pop ax              ; return the state of registers
            endm

            setmode macro
                push ax
                mov ax,0003h        ; color txt mode
                int 10h
                pop ax
            endm

            disp_center macro msg
                push dx             ; save state of registers accessed in macro
                push ax
                push cx
                push bx

                mov bl,actual_len
                mov si,offset msg   ; get address of msg in si
                mov dh,12           ; row/2
                mov dl,40           ; col/2
   nxtdis:      mov bh,00h          ; int vector parameter
                mov ah,02h          ; set cursor
                int 10h             ; dos int service for setting cursor using anove parmeters
                mov cx,1            ; cx contains no characters to display at a time
                mov ah,0ah          ; int 10h vector cor displaying character at cursor
                mov al,[si]         ; get char to display
                mov bh,00h          ; on page 0
                int 10h             ; dos int service call
                inc si              ; next char
                inc dl              ; increase line col no for next char
                dec bl              ; dec count of remaininf char to be proccessed
                jz done             ; done when all chars are processed
                mov al,[si]         ; get next char
                cmp al,' '          ; compare with white space
                jnz nxtdis          ; loop
                inc dh              ; point to next row
                mov dl,40           ; center of the coulums  col/2
                inc si
                dec bl              ; dec count of remaininf char to be proccessed
                jnz nxtdis          ; done when all chars are processed
           done:
                pop bx
                pop cx
                pop ax
                pop dx

            endm


                mov ax,@data
                mov ds,ax
                mov es,ax

                print prompt
                inp_str para_list
                setmode
                setwindow

                disp_center charBuf
                nextline
                print msg1
                mov ah,1            ;wait for key press
                int 21h
           xyz:
                mov ax,4c00h        ; exit to os gracefully
                int 21h

           main endp



