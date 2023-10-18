; WAP(8085) to swap bit D7 and D1 of ten numbers
; at 6050H if any number > 80H and < A0H.
; Otherwise set D6 and reset D3 of the number
; stored.
	   JMP SK
	   LXI H,6050H
	   LXI B,0800H
	   MVI D,0A	; dec 10

LP:	   LDAX B
	   MOV M,A
	   INX H
	   INX B
	   DCR D
	   JNZ LP
; mem initiliazed

SK:
; program

START: LXI H,6050H	; scr
	   MVI C,0AH	; dec 10

LOOP:  MOV A,M
	   CPI 80H	; carry set if a<80h
	   JNC SWAP
	   JMP SET	; set D6 and reset D3

SWAP:  CPI A0H	; carry not set if a<A0h
	   JC SET
; swap
	   ANI 82H
	   CPI 82H
	   JNZ SWP
	   JMP DONE

SWP:   MOV A,M
	   XRI 82H
	   JMP DONE

SET:   ORI 48H	; set both set D6 and reset D3
	   XRI 08H	; flip D3 to reset

DONE:  MOV M,A
	   INX H
	   DCR C
	   JNZ LOOP
	   HLT
