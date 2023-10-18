;2075 bhadra  WAP 8086 asm to read a numberpositive binary number from user
;calculate the factorial in binary format and display it
; working as intended

;page  60,132            ; ???  what does this mean may be the page in the mem segment or display
;title read a single digit decimal number and display fac. in decimal
 .MODEL SMALL
 .STACK 64H

 .DATA
   PROMPT_1  DB  "Enter a Positive SINGLE DIGIT number (0 to 8) :",'$'
   PROMPT_2  DB  0DH,0AH, "The Factorial of the given number is :",'$'
   ILLEGAL   DB  0AH,0DH, "Illegal character. Try again :",'$'
   RESULT DW 0
   FACT DW 1
   NUM DB ?
   TEN DW 10

 .CODE
   MAIN PROC FAR
     MOV AX, @DATA                ; initialize DS
     MOV DS, AX                   ; DS is data stack

     LEA DX, PROMPT_1             ; load and display the string PROMPT_1
     MOV AH, 9                    ; DECI 9  OR 09H IN HEX
     INT 21H

     CALL DECI_INPUT              ; call the procedure DECI_INPUT

     CALL FACTORIAL               ; call the procedure FACTORIAL
     MOV RESULT,AX

     LEA DX, PROMPT_2             ; load and display the string PROMPT_2
     MOV AH, 9
     INT 21H

     CALL DECI_OUTPUT             ; call the procedure DECI_OUTPUT

     MOV AH, 4CH                  ; return control to DOS
     INT 21H
   MAIN ENDP

 ;-------------------------  Procedure Definitions  ------------------------;

 ;----------------------------  DECI_INPUT  ------------------------------;
 DECI_INPUT PROC
   ; this procedure reads single digit number form 1 to 8
   ; input : none
   ; output : store binary number in NUM
   ; uses : MAIN

   JMP @START                   ; jump to label @START

   @ERROR:                      ; jump label
   LEA DX, ILLEGAL              ; load and display the string ILLEGAL
   MOV AH, 9                    ; display interrupt
   INT 21H

   @START:                      ; jump label
   MOV AH, 1                    ; set input function
   INT 21H                      ; read a digit

   CMP AL, 0DH                  ; compare input and CARRY RETURN
   JE @END                      ; jump to label @END if input is CARRY RETURN

   CMP AL, 30H                  ; compare AL with 0
   JL @ERROR                    ; jump to label @ERROR if AL<0

   CMP AL, 38H                  ; compare AL with 8
   JG @ERROR                    ; jump to label @ERROR if AL>1

   SUB AL, 30H                  ; convert ascii to decimal code

   MOV NUM, AL                  ; entered number in NUM

   @END:                        ; jump label

   RET                          ; return control to the calling procedure
 DECI_INPUT ENDP

 ;----------------------------  DECI_OUTPUT  -----------------------------;

 DECI_OUTPUT PROC
   ; this procedure will display a number in DECIMAL form
   ; input : RESULT
   ; output : none
   ; uses : MAIN

   MOV AX, RESULT
   MOV CX,0                       ; initialize loop counter

   @OUTSTAX:                      ; loop label
     MOV DX,0                     ; INITIALIZE DX FOR DIV RESULT
     DIV TEN
     ADD DL, 30H                  ; DECIMAL to ASCII
     PUSH DX                      ; PUSH DX TO STACK
     INC CX                       ; for use by LOOP keyword
     CMP AX, 0
     JNE @OUTSTAX
   @DISPLAY:                      ; DISPLAY NUM from stack
     POP DX
     MOV AH,02H
     INT 21H
     LOOP @DISPLAY                ; HERE loop auto decrements cx and checks for zero
   RET                            ; return control to the calling procedure
 DECI_OUTPUT ENDP

 ;-----------------------------  FACTORIAL  --------------------------------;

 FACTORIAL PROC
   ; this procedure will computes the factorial of a given number
   ; input : BL
   ; output : store the factorial of the number in FACT
   ; uses : MAIN

   MOV AX, 1                      ; set AX=1

   XOR CX, CX                     ; clear CX
   MOV CL, NUM                    ; set CX=BX

   @LOOP:                         ; loop label
   MUL CX                         ; multiply CX with AL i.e. AX=AL*CX
   LOOP @LOOP                     ; jump to label @LOOP if CX!=0

   MOV FACT, AX                   ; set BX=AX

   RET                            ; return control to the calling procedure
 FACTORIAL ENDP

 END MAIN
