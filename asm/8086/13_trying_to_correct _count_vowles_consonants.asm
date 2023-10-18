; 2068 Bhadra read string count no of vowels consonants numerals and other characters and display the count.
; does not work from book can be done as a part solution to the no 19 and 17

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
              mov cl,nchar  ; code paragraph below is unnecessary due to this line           
              cld        ; resetting direction flag for repne inc di 
                 
              ;might be useful code snippet   
              xor cl,cl             ; clearing cl  for counting characters till newline is found 
       loop1: ;inc cl               ; here might be more sutiable if n/n+1
              stosb                 ; get char from [di] to al
              cmp al,0dh            ; possibly a check for the carriage 
              jz endinpt            ; exit loop if line return is found  
              inc cl                ; cl 0                  n-1/n     
              jmp loop1             ; cl contains the lenght of the 

     endinpt: mov bl,cl             ; useless code
              cmp cl,00h
              jnz jump1
              xor ax,ax
              jmp pr

      jump1:  cld
              lea si,s2
       next:  mov cx,000bh          ; should check for the vowel if any one test ok there should be  flag on
       
              lodsb
              lea di,vowl
              repne scasb
              cmp cx,00
              inc cl
                                    ; bogus looop
                                    ; loop should be for actually counting the vowels
                                   
      novowl: dec bl
              jnz next
              mov dl,0ah
              mov ah,02h
              int 21h
              mov ax,cx
         pr:  mov bx,000ah
              xor cx,cx
       print: xor dx,dx             ; should be for hex to ascii code conversion using stack
              div bx
              push dx                ; counter here for keeping track of pushed byte
              inc cx
              inc cx
              cmp ax,0000h
              jne print
              lea dx,s3
              mov ah, 09h
              int 21h
      display:pop dx
              add dl,30h            ; dispaly counter number of byters by popping the stack
              mov ah,02h
              int 21h
              loop display
              mov ax,4c00h         ; graceful termination of program
              int 21h
        main endp
        end main




