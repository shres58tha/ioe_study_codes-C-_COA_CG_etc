; WAP(8085) to Transfer the 20 bytes
; from memory location 7500H to
; memory location starting at 9050H
; in reverse order.
	   LXI H,0800H
	   LXI D,7500H
	   MVI C,14H	; dec 20

LP:	   MOV A,M
	   STAX D
	   INX H
	   INX D
	   DCR C
	   JNZ LP
; mem initiliazed
; program

START: LXI H,7500H	; scr
	   LXI B,9050H	; destination
	   MVI D,14	; dec 20 counter
	   MOV A,C
	   ADD D
	   MOV C,A	; points to end of dest.

LOOP:  MOV A,M
	   STAX B
	   INX H
	   DCX B
	   DCR D
	   JNZ LOOP
	   HLT
