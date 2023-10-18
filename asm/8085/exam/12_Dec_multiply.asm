; WAP(8085)to mult. two deci. numbers 34 & 7
; store the answer in memory location 8100H.
; jmp sk
; program

START: MVI B,34H	; BCD notation
	   MVI C,07H	; BCD notation
	   MVI A,00H	; sum
	   MVI D,00H	; carry check
	   DCR C
	   CALL MUL
	   LXI H,8100H
	   MOV M,A
	   HLT

MUL:   MOV A,E
	   ADD B
	   DAA
	   JNC SKIP
	   INR D

SKIP:  MOV E,A
	   MOV A,D
	   ADI 00H
	   DAA
	   MOV D,A
	   MOV A,C
	   SBI 01H
	   ADI 00H
	   DAA
	   MOV C,A
	   CPI 00H
	   JNZ MUL
	   RET
