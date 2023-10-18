; 15 bytes of data stored in memory location 5060H
; Add higher nibble and lower nibble of
; corresponding data and store the result in
; memory location starting from 8070H.

		LXI H,0800H				; mem initiliazer
		LXI B,5060H
		MVI E,0E

LOOP:	MOV A,M
		STAX B
		INX H
		INX B
		DCR E
		JNZ LOOP  				; mem initiliazer

START:	LXI H,5060H				; scr
		LXI D,8070H
		MVI C,0E				; 07 BCD

RE:		MOV A,M
		ANI F0H
		RLC
		RLC
		RLC
		RLC
		MOV B,A
		MOV A,M
		ANI 0FH
		ADD B
		STAX D
		INX H
		INX D
		DCR C
		JNZ RE
		HLT
