; WAP(8085)to mult. two deci. numbers 34 & 7
; store the answer in memory location 8100H.
; jmp sk
; program

START: MVI B,22H	; BCD notation
	   MVI C,07H	; BCD notation
	   MVI A,00H	; sum
	   MVI D,00H	; carry check
	   CALL MUL
	   LXI H,8100H
	   MOV M,A
	   HLT

MUL:   ADD B
	   JNC SKIP
	   INR D
SKIP:  MOV E,A
	   DCR C
	   JNZ MUL
	   RET
