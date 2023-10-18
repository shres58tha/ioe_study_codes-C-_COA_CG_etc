; WAP(8085) to cal. num. of ones upper nibble
; of a byte at 8050H .
; Store the count in memory location 8040H.
; program

START  LXI H,8050H
	   MVI B,00H	; ones counter
	   MOV A,M
	   MVI C,04h	; mo of bits in upper nibble

LOOP:  RLC
	   JNC SKIP
	   INR B

SKIP:  DCR C
	   JNZ LOOP
	   LXI H,8040h
	   MOV M,B
	   HLT
