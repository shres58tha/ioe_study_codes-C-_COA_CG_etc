; WAP 8085 to add all the no. from table of
; 8-bit numbers whose higher nibble > 6
; and store the 16 bit result just after table.
		LXI H,A000H
		MVI C,20H	; 32 dec items
		MVI D,00H	; MS bit of result
		MVI E,00H	; LS bit of result

NEX:	MOV A,M
		CPI 70H		; IF higher nibble less
; 7 sets carry than
		JC SKIP		; do not add
; sum higher nibble >6
		ADD E
		MOV E,A		; accumulate sum in E
		JNC SKIP	; check carry
		INR D		; increase for carry

SKIP:	INX H
		DCR C
		JNZ NEX
		MOV M,D
		INX H
		MOV M,E
		HLT
