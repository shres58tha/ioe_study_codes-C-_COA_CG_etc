;2065 Chaitra count no of vowels in the entered string and display odd vowels or even vowels
;works
 .model small
 .stack 100h

 .data
   msg1  db  'enter a string : $'
   msg2  db  0dh,0ah,'odd vowels $'
   msg3  db  0dh,0ah,'even vowels $'

   ;the data below structured storage alinged to byte
   ;for int vector 0a  ie colllection of string from keyboard
   para_list label byte    ; start of parameter list and all below are part of list
   max_len db 254          ; max number of input
   actual_len db ?         ; count for the number of the characters entered
   text db 255 dup('$') ; place to keep chars entered max_len +1 to hold terminator'$'

 .code
   print macro msg
     mov ah,09h
     mov dx,offset msg
     int 21h
   print endm

   main proc
     mov ax,@data
     mov ds,ax
     print msg1
     mov ah,0ah
     mov dx,para_list
     int 21h

     mov bx,0000h                 ; counter for vowels
     mov ch,00h
     mov cl,actual_len            ; get text in using macro in included io.h
     mov si,offset text

again:
     mov ah,[si]
     cmp ah,'a'
     jl down                      ; jump if ah is lower than 'a'
     cmp ah,'z'
     jg down                      ; jump if ah is greater than 'a'
     sub ah,20h                   ; change to caps

down:
     cmp ah, 'A'
     je vowel
     cmp ah, 'E'
     je vowel
     cmp ah, 'I'
     je vowel
     cmp ah, 'O'
     je vowel
     cmp ah, 'U'
     je vowel
     jmp next
vowel:
     inc bx
next:
     loop again                   ; uses cx as the decrement counter and loops till zero

     mov ax,bx
     and ax,0001h
     cmp ax,0000h
     jne odd
     print msg3
     jmp done
odd: print msg2
done:
     mov ah, 4ch                  ; return control to dos
     int 21h
 main endp


