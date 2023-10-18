; 10 8-bit data are stored at C000H to C009H.
; Transfer these data to D050H only if data's
; D6 is set & D2 is reset
; otherwise store 00H at dest. table
	  ;JMP SK
	   LXI H,C000
	   LXI B,0800H
	   MVI D,0A	; dec 10H

LP:	   LDAX B
	   MOV M,A
	   INX H
	   INX B
	   DCR D
	   JNZ LP
; mem initiliazed

SK:    NOP
; program

START: LXI H,C000	; scr
	   LXI D,D050	; dest
	   MVI C,0A	; dec 10H

LOOP:  MOV A,M
	   ANI 22H
	   CPI 20H
	   JNZ SKIP
	   MOV A,M
	   JMP CONT

SKIP:  MVI A,00H

CONT:  INX H
	   INX D
	   STAX D
	   DCR C
	   JNZ LOOP
	   HLT
