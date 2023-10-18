;2064 paush in the entered string and dis. no of vowels and string - vowel in reverse attribute
;works perfectly
 .model small
 .stack 100h

 .data
   msg1  db  'enter any text : $'
   msg2  db  0dh,0ah,'number of vowels = $'
   msg3  db  0dh,0ah,'string without vowels = $'

   ;the data below structured storage alinged to byte
   ;for int vector 0a  ie colllection of string from keyboard
   para_list label byte    ; start of parameter list and all below are part of list
   maxchar db 254          ; max number of input
   nchars db ?         ; count for the number of the characters entered
   actstr db 255 dup('$') ; place to keep chars entered max_len +1 to hold terminator'$'

   count db ?
   newstr db 255 dup ('$')

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
     mov dx,para_list      ; offset maxchar works too
     int 21h

     mov bx,0000h                 ; counter for vowels
     mov ch,00h
     mov cl,nchars            ; get text in using macro in included io.h
     mov si,offset actstr
     mov di,offset newstr


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
     mov ah,[si]
     mov [di],ah
     inc di
     jmp next
vowel:
     inc bl
next:
     inc si
     loop again                   ; uses cx as the decrement counter and loops till zero

     mov count,bl
     mov bh,70h                    ; reverse attribute
     mov ax,0                      ; clear screen
     mov dx,184fh                  ; row column 25x80
     int 10h

     print msg2
     mov ah,02h
     mov dl,count
     add dl,30h                     ; make ascii char out of number
     int 21h

     print msg3
     print newstr

     mov ax,4c00h
     int 21h
 main endp


