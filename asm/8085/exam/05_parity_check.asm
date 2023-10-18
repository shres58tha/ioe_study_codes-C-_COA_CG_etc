; WAP(8085) to check a hex numb.at 6000H
; for odd or even parity. If the parity is even
; store data EEH at 6001H otherwise store 00H
	   LXI H,6000H
	   MVI M,0FH
; mem initiliazed
; program

START: LXI H,6000H	; scr
	   MOV A,M
	   ADI 00H		; add 0 to set flags
	   JPE EVEN
	   MVI A,00H	; odd parity
	   JMP SKIP

EVEN:  MVI A,EE	; even parity

SKIP:  INX H
	   MOV M,A
	   HLT
