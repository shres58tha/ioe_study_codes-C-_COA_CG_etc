; 2073 bhadra find the largest and smallest numbers of an array having 10 numbers.
; Display the found numbers in the clear screen
      .model small
      .stack 100h

       .data
            array db 5,2,5,8,4,3,2,8,6,9
            msg1 db "smallest number in array: ",'$'
            msg2 db "largest number in array: ",'$'
            small db ?
            large db ?

       .code

        start:
              mov ax,@data          ;inititalize stack
              mov ds,ax

              mov cx,0000h          ; counter
              mov cl,0Ah

              lea bx,array   ;load effective address of array
              mov al,[bx]    ;al to contain lowest number ptr auto incremnted
              mov ah,al      ;ah to contain highest number  referencing

       check1:cmp al,[bx]    ;sets carry if al is < [bx] al thus contain largest num.
              jnc check2     ;if al !< [bx]
              mov al,[bx]    ;swap

       check2:cmp ah,[bx]    ;sets carry if al is < [bx] al thus contain smallest num.
              jc check3      ;if al < [bx]
              mov ah,[bx]    ;swap
       check3:inc bx         ;increament bx to point to next number in array
              loop check1

              mov large,al    ; largest num
              mov small,ah    ; smallest num

              mov ax,0600h    ;06 to scroll & 00 for fullj screen
              mov bh,0fh      ;attribute 7 for background and 1 for foreground
              mov cx,0000h    ;starting coordinates
              mov dx,184fh    ;ending coordinates
              int 10h         ;for video display

              lea dx, msg1    ; load & display the msg
              mov ah, 09h
              int 21h

              mov dx,0000h
              mov dl,small
              add dl,30h
              mov ah,02h
              int 21h

              mov ah, 02h
              mov dl, 0ah       ; line feed + new line
              int 21h
              mov dl,0dh
              int 21h

              lea dx, msg2       ; load & display the msg
              mov ah, 09h
              int 21h

              mov dx,0000h
              mov dl,large
              add dl,30h
              mov ah,02h
              int 21h


              mov dl, 0ah       ; line feed + new line
              mov ah, 02h
              int 21h
              mov dl,0dh
              int 21h

              mov ah,4ch
              int 21h
        code ends
        end start



