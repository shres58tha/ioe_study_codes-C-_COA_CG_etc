; 2070 magh find the largest and smallest numbers of an array having 16 numbers.
; put it in minval and maxval variables
;  works

      .model small
      .stack 100h

       .data
            array db 95,2,5,8,4,3,2,8,7,5,5,3,7,5,1,4
            minval db ?
            maxval db ?
            temp db ?   ; for monitoring [bx]

       .code

        start:
              mov ax,@data          ;inititalize stack
              mov ds,ax

              mov cx,0000h          ; counter
              mov cl,10h

              lea bx,array   ;load effective address of array
              mov al,[bx]    ;al to contain lowest number ptr auto incremnted
              mov ah,al      ;ah to contain highest number  referencing

       check1:
              mov dl,[bx]
              mov temp,dl
              cmp al,[bx]    ;sets carry if al is < [bx] al thus contain largest num.
              jnc check2     ;if al !< [bx]
              mov al,[bx]    ;swap




       check2:cmp ah,[bx]    ;sets carry if al is < [bx] al thus contain smallest num.
              jc check3      ;if al < [bx]
              mov ah,[bx]    ;swap
       check3:inc bx         ;increament bx to point to next number in array
              loop check1

              mov maxval,al    ; largest num
              mov minval,ah    ; smallest num

              mov ah,4ch
              int 21h
        code ends
        end start



