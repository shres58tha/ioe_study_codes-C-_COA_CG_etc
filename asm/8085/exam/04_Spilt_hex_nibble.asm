; WAP(8085) to separate a hexadecimal number
; into two nibbles. The 00H number at 9501H
; LS nibble is to be stored at 9502H
; MS is to be stored in 9503 H memory location.
; Suppose 3AH at 9501 H then LS 0A H at 9502 H
; and 03 H should at 9503 H
	   LXI H,9501H
	   MVI M,3AH
; mem initiliazed
; program

START: LXI H,9501H	; scr
	   MOV B,M	; save number in b
	   MOV A,B
	   ANI 0F	; mask for ls
	   INX H
	   MOV M,A
	   MOV A,B
	   ANI F0H	; mask for ms
	   INX H
	   MOV M,A
	   HLT
