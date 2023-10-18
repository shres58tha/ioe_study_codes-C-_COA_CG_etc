; WAP on 8085 to calculate the number of ones
; in the upper nibble of ten 8-bit numbers
; stored in a table.
; Store the count of ones in a location just
; after the table

START:	LXI H,C000H	; source table
		MVI C,0AH	; counter
		MVI B,00H	; counter 1 in higher nibble

LOOP:	MOV A,M		; initialize to zero
		MVI D,04H	; counting for 4 bit shift

NIBBLE:	RLC
		JNC SKIP	; jump on carry not set
		INR B		; 1 found

SKIP:	DCR D
		JNZ NIBBLE	; loop again to shifter
		INX H		; point to next no
		DCR C		; dec counter
		JNZ LOOP
		MOV A,B		; mov 1 counter in a
		MOV M,A		; result saved M
		HLT
