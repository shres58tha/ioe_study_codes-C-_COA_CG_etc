; WALP8085 to exchange the bits D6 and D2
; of 200 bytes in memory location 8090H.

START:	LXI H,8000H	; scr data table
		MVI C,C8H	; counter 200 dec

LOOP:	MOV A,M
		ANI 40H		; loop counter 8 bit
		RRC
		RRC
		RRC
		RRC
		MOV B,A		; upper nibble
		MOV A,M
		ANI 04H		; lower nibble
		CMP B		; sets z if equal
		JZ CNT		; jmp if z is set
		MOV A,M
		XRI 44H
		MOV M,A

CNT:	INX H
		DCR C
		JNZ LOOP	; jump if Z not set
		HLT
