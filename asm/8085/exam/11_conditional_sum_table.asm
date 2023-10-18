; WAP(8085)to add all the numbers > 44H & < 77H
; from 10 bytes data at C050H and reject others.
; Store the result at the end of the table.
; 	   jmp sk
	   LXI H,C050H
	   LXI B,0800H
	   MVI D,0AH	; dec 10

LP:	   LDAX B
	   MOV M,A
	   INX H
	   INX B
	   DCR D
	   JNZ LP
; mem initiliazed

SK:	   NOP
; program

START: LXI H,C050H	; scr
	   MVI C,0AH
	   MVI B,00H	; sum

LOOP:  MOV A,M
	   CPI 44H		; a<44h sets C
	   JNC SKIP
	   CPI 77H		; a <77h sets C
	   JC SKIP
	   ADD B
	   MOV B,A

SKIP:  INX H
	   DCR C
	   JNZ LOOP
	   MOV M,B
	   HLT
