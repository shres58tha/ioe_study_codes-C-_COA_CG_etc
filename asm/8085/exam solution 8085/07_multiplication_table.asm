; WAP 8085 to generate multiplication table
; number stored at 8230H
; store the generated table starting at 8231H.
; For example, if location 8230H has 05H
; then store 05H at8231H, OAH at8232H and so on.

START:	LXI H,8230H	; source data then dest table
		MVI C,10H		; counter
		MVI A,00H		; initialize for sum
		MOV B,M			; b is counter for add loop
		MVI D,04H		; counting for 4 bitsift
		MOV E,M			; use for gen table

LOOP:	ADD E			; generate multiply
		INX H
		MOV M,A			; save data in mul table
		DCR C			; dec counter
		JNZ LOOP
		HLT
