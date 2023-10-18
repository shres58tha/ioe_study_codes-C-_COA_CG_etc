; 2067 shrawan display multiplication table of single digits in decimal format
; works
      .model small
      .stack 100h

       .data
            num db ?
            msg db "enter single digit num for generating mult. table :",10,13,'$'
            ten db 10
       .code

        main proc
              mov ax,@data          ;inititalize stack
              mov ds,ax

              lea dx,msg   ;msg
              mov ah,09h
              int 21h

              mov ah,07h  ; get a single digit from user without echo
              int 21h
              mov cx,10   ; counter
              mov dl,1    ;initialize increment
              sub al,30h  ; ascii to decimal

     label:   mov ah,0    ; making ax from al and ah
              push ax
              mul dl      ;       ax= al*dl

              push cx
              push dx
              mov bx,0
              mov cx,10



    no_digit: mov dx,0
              div cx
              add dx,30h  ; dx has a remainder
              push dx
              inc bx
              cmp ax,0
              ja no_digit
              mov ah,02
              mov cx,bx

    popping:  pop dx
              int 21h
              loop popping

              mov dl,32
              mov ah,02h
              int 21h

              pop dx
              pop cx

              inc dl
              pop ax
              loop label

              mov ax,4c00h
              int 21h
        main endp
        end main




