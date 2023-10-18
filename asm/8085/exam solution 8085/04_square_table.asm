; WAP(8085) to find the square of ten 8-bit numbers
; which are < 0FH, from table at location C090H.
; Store the result from the end of table

START:	LXI H,C090H	; source table
		LXI D,C09AH	; destination table
		MVI C,0AH	; counter

NEXT:	MVI A,00H	; initialize to zero
		MOV B,M		; counter loop to M

LOOP:	ADD M		; square loop A + [HL]
		DCR B		; tracks added loop
		JNZ LOOP	; end of square loop
		STAX D		; result saved in [DE]
		INX H		; HL+1
		INX D		; DE+1
		DCR C		; c-1
		JNZ NEXT	; jmp if flag Z not set
		HLT
