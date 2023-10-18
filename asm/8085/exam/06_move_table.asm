; 16 data bytes at 9001H to 9010H.
; WAP(8085) to transfer this block of data bytes
; to memory locations 9501H to 9510H.
	   LXI H,0800H
	   LXI B,9001H
	   MVI D,0F		; 16 dec

LP:	   MOV A,M
	   STAX B
	   INX H
	   INX B
	   DCR D
	   JNZ LP
; mem initiliazed
; program

START: LXI H,9001H	; scr
	   LXI D,9501H
	   MVI C,0F		; dec 16

LOOP:  MOV A,M
	   STAX D
	   INX H
	   INX D
	   DCR C
	   JNZ LOOP
	   HLT
