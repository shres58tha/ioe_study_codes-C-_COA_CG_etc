; WAP(8085) to Add all 8-bit num. at E000H to E00FH
; store 16-bit result at the end of the table.
	   JMP SK
	   LXI H,E000H
	   LXI B,0800H
	   MVI E,0FH

LP:    LDAX B
	   MOV M,A
	   INX H
	   INX B
	   DCR E
	   JNZ LP
	   HLT

SK:
; program

START  LXI H,E000H
	   MVI C,0FH
	   MVI B,00H
	   MOV A,M

LOOP:  INX H
	   ADD M
	   JNC SKIP
	   INR B	; add carry to b

SKIP   DCR C
	   JNZ LOOP
	   INX H
	   MOV M,A	; LSn same as SHLD
	   INX H
	   MOV M,B	; MSn
	   HLT
