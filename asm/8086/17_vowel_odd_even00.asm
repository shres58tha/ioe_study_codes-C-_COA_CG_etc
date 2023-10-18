.model small
 .stack 100h

 .data
   prompt_1  db  'enter a string : $'
   prompt_2  db  0dh,0ah,'no. of vowels = $'
   prompt_3  db  0dh,0ah,'no. of consonants = $'

   string        db  50 dup (?)
   c_vowels      db  'AEIOU'
   s_vowels      db  'aeiou'
   c_consonants  db  'BCDFGHJKLMNPQRSTVWXYZ'
   s_consonants  db  'bcdfghjklmnpqrstvwxyz'

 .code
   main proc
     mov ax, @data                ; initialize ds and es
     mov ds, ax
     mov es, ax

     lea dx, prompt_1             ; load and display the string prompt_1
     mov ah, 9
     int 21h

     lea di, string               ; set di=offset address of variable string

     call read_str                ; call the procedure read_str

     xor dx, dx                   ; clear dx
     lea si, string               ; set si=offset address of variable string

     or bx, bx                    ; check bx for 0
     je @exit                     ; jump to label @exit if bx=0

     @count:                      ; jump label
       lodsb                      ; set al=ds:si

       lea di, c_vowels           ; set di=offset address of variable c_vowels
       mov cx, 5                  ; set cx=5

       repne scasb                ; check al is capital vowel or not
       je @increment_vowels       ; jump to label @increment_vowels if al is
                                  ; capital vowel

       lea di, s_vowels           ; set di=offset address of variable s_vowels
       mov cx, 5                  ; set cx=5

       repne scasb                ; check al is small vowel or not
       je @increment_vowels       ; jump to label @increment_vowels if al is
                                  ; small vowel

       lea di, c_consonants       ; set di=offset address of variable
                                  ; c_consonants
       mov cx, 21                 ; set cx=21

       repne scasb                ; check al is capital consonant or not
       je @increment_consonants   ; jump to label @increment_consonants if al
                                  ; is capital consonant

       lea di, s_consonants       ;  set di=offset address of variable
                                  ; s_consonants
       mov cx, 21                 ; set cx=21

       repne scasb                ; check al is small consonant or not
       je @increment_consonants   ; jump to label @increment_consonants if al
                                  ; is small consonants

       jmp @next                  ; otherwise, jump to label @next

       @increment_vowels:         ; jump label
         inc dl                   ; increment dl
         jmp @next                ; jump to label @next

       @increment_consonants:     ; jump label
         inc dh                   ; increment dh

       @next:                     ; jump label
         dec bx                   ; decrement bx
         jne @count               ; jump to label @count while bx!=0

       @exit:                     ; jump label

     mov cx, dx                   ; set cx=dx

     lea dx, prompt_2             ; load and display the string prompt_2
     mov ah, 9
     int 21h

     xor ax, ax                   ; clear ax
     mov al, cl                   ; set al=cl

     call outdec                  ; call the procedure outdec

     lea dx, prompt_3             ; load and display the string prompt_3
     mov ah, 9
     int 21h

     xor ax, ax                   ; clear ax
     mov al, ch                   ; set al=ch

     call outdec                  ; call the procedure outdec

     mov ah, 4ch                  ; return control to dos
     int 21h
   main endp



 ;-------------------------  procedure definitions  ------------------------;




 ;-------------------------------  read_str  -------------------------------;


  read_str proc
    ; this procedure will read a string from user and store it
    ; input : di=offset address of the string variabel
    ; output : bx=number of characters read
    ;        : di=offset address of the string variabel

    push ax                       ; push ax onto the stack
    push di                       ; push di onto the stack

    cld                           ; clear direction flag
    xor bx, bx                    ; clear bx

    @input_loop:                  ; loop label
      mov ah, 1                   ; set input function
      int 21h                     ; read a character

      cmp al, 0dh                 ; compare al with cr
      je @end_input               ; jump to label @end_input if al=cr

      cmp al, 08h                 ; compare al with 08h
      jne @not_backspace          ; jump to label @not_backspace if al!=08h

      cmp bx, 0                   ; compare bx with 0
      je @input_error             ; jump to label @input_error if bx=0

      mov ah, 2                   ; set output function
      mov dl, 20h                 ; set dl=20h
      int 21h                     ; print a character

      mov dl, 08h                 ; set dl=08h
      int 21h                     ; print a character

      dec bx                      ; set bx=bx-1
      dec di                      ; set di=di-1
      jmp @input_loop             ; jump to label @input_loop

      @input_error:               ; jump label
      mov ah, 2                   ; set output function
      mov dl, 07h                 ; set dl=07h
      int 21h                     ; print a character

      mov dl, 20h                 ; set dl=20h
      int 21h                     ; print a character
      jmp @input_loop             ; jump to label @input_loop

      @not_backspace:             ; jump label
      stosb                       ; set es:[di]=al
      inc bx                      ; set bx=bx+1
      jmp @input_loop             ; jump to label @input_loop

    @end_input:                   ; jump label

    pop di                        ; pop a value from stack into di
    pop ax                        ; pop a value from stack into ax

    ret
  read_str endp


 ;--------------------------------  outdec  --------------------------------;


 outdec proc
   ; this procedure will display a decimal number
   ; input : ax
   ; output : none

   push bx                        ; push bx onto the stack
   push cx                        ; push cx onto the stack
   push dx                        ; push dx onto the stack

   cmp ax, 0                      ; compare ax with 0
   jge @start                     ; jump to label @start if ax>=0

   push ax                        ; push ax onto the stack

   mov ah, 2                      ; set output function
   mov dl, "-"                    ; set dl='-'
   int 21h                        ; print the character

   pop ax                         ; pop a value from stack into ax

   neg ax                         ; take 2's complement of ax

   @start:                        ; jump label

   xor cx, cx                     ; clear cx
   mov bx, 10                     ; set bx=10

   @output:                       ; loop label
     xor dx, dx                   ; clear dx
     div bx                       ; divide ax by bx
     push dx                      ; push dx onto the stack
     inc cx                       ; increment cx
     or ax, ax                    ; take or of ax with ax
   jne @output                    ; jump to label @output if zf=0

   mov ah, 2                      ; set output function

   @display:                      ; loop label
     pop dx                       ; pop a value from stack to dx
     or dl, 30h                   ; convert decimal to ascii code
     int 21h                      ; print a character
   loop @display                  ; jump to label @display if cx!=0

   pop dx                         ; pop a value from stack into dx
   pop cx                         ; pop a value from stack into cx
   pop bx                         ; pop a value from stack into bx

   ret                            ; return control to the calling procedure
 outdec endp





 end main
