; WAP 8085 to add corresponding data form two
; table if the data from the first table is
; smaller than the second table else
; subtract data of second table from
; the first table.
; assuming tables start at A000H and A010H

; counter used

		LXI SP,FFFFH	; stack at max limit of mem
		LXI H,A000H	; table 1
		XTHL		; 2
		LXI H,A010H	; table 2
		LXI D,A020H	; destination table
		MVI C,0FH

NEXT:	MOV B,M	; 2
		XTHL	; 1
		MOV A,M
		CMP B	; A<B sets Carry
		JZ SUM
; diff
		MOV B,M	; 1
		XTHL	; 2
		MOV A,M	; 2
		SUB B
		JMP STORE

SUM:	ADD B
		XTHL	; 2

STORE:	STAX D
		INX D
		INX H	; 2
		XTHL	; 1
		INX H	; 1
		XTHL	; 2
		DCR C
		JNZ NEXT
		HLT
