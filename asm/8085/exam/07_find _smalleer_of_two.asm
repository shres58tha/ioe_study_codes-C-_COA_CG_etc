; WAP(8085) to find the smaller of two numbers
; at 7101H & 7102H. Store the result at 7103H.
	   LXI H,7101H
	   MVI M,08H
	   INX H
	   MVI M,07H
; mem initiliazed
; program

START: LXI H,7101H	; scr
	   MOV B,M	; save data
	   INX H
	   MOV A,M
	   CMP B
	   JC SMALL	; a<b ; a is small do nothing
	   MOV A,B	; b is small

SMALL: INX H
	   MOV M,A
	   HLT
