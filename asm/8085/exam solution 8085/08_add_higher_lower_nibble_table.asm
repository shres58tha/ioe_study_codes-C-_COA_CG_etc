; WAP 8085, add upper & lower nibble
; of ten 8 bit words stored in table at 8B20H.
; Store results in locations just after table

START:	LXI H,8B20H	; scr data table
		LXI D,8B2AH	; dest table just after scr
		MVI C,0AH	; counter

LOOP:	MOV A,M
		ANI F0H		; get upper nibble
		RRC
		RRC
		RRC
		RRC			; rotate 4 steps
		MOV B,A		; save upper nibble in B
		MOV A,M		; get M for lower nibble
		ANI 0FH		; lower nibble in A
		ADD B		; add upper nibble to
		STAX D		; store at dest table
		INX H		; increment HL
		INX D		; increment DE
		DCR C		; decrement counter
		JNZ LOOP
		HLT
