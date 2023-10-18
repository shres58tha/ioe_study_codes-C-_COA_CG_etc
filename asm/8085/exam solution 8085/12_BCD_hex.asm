; WAP 8085 to convert 10 numbers stored at 4350H
; to binary and store the the result at4360H

START:	LXI H,4360H	; scr data table
		LXI D,436AH	; destination table
		MVI C,0AH	; counter 10 dec

LOOP:	MOV A,M
		ANI F0H
		CPI 00H
		JZ STEP
		MOV A,M
        SUI 06H
		JMP SK

STEP:	MOV A,M

SK:		STAX D
		INX D
		INX H
		DCR C
		JNZ LOOP
		HLT
