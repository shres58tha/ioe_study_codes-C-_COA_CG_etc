; WAP(8085) to combine two hex nibbles
; stored at 3500H (LSB) and 3501H (MSB)
; locations, to form a byte.
; The byte formed 3502H.
; (Let 09 H is at 3500H & 03H at 3501H
; save result (39H) at 3502H
	   LXI H,3500H
	   MVI M,09H
	   LXI H,3501H
	   MVI M,03H
; mem initiliazed
; program

START:  LXI H,3500H	; lsb
	   MOV B,M
	   INX H
	   MOV A,M	; msb
	   RLC
	   RLC
	   RLC
	   RLC
	   ADD B	; byte in a
	   INX H
	   MOV M,A
	   HLT
	   MVI C,0EH	; 07 BCD

RE:	   MOV A,M
	   ANI F0H
	   RLC
	   RLC
	   RLC
	   RLC
	   MOV B,A
	   MOV A,M
	   ANI 0F
	   ADD B
	   STAX D
	   INX H
	   INX D
	   DCR C
	   JNZ RE
	   HLT
