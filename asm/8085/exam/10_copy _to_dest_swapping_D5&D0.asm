; WAP(8085) to swap bit D5 and D0 of 10 numbers
; at 8000H and store the corresponding result
; at 9000H
	;  JMP SK   ; comment uncomment to auto intialize
	   LXI H,8000H
	   LXI B,0800H
	   MVI D,0A		; dec 10

LP:	   LDAX B
	   MOV M,A
	   INX H
	   INX B
	   DCR D
	   JNZ LP
; mem initiliazed

SK:
; program

START: LXI H,8000H	; scr
	   LXI D,9000H	; dest
	   MVI C,0A

LOOP:  MOV A,M
	   ANI 21H
	   CPI 21H
	   JZ DONE
; swap
	   XRI 21H

DONE:  LDAX D
	   INX H
	   INX D
	   DCR C
	   JNZ LOOP
	   HLT
