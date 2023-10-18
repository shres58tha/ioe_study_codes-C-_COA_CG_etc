; WALP8085 Table1 with 16 data
; transfer to Table2 if 1's in num > 3,
; else store FFH in table2.

START:	LXI H,8085H	; scr data table
		LXI D,8095H	; dest table just after scr
		MVI C,08H	; loop counter 8 bit
		MVI B,00H	; count 1

LOOP:	MOV A,M
		MVI C,08H	; loop counter 8 bit
		MVI B,00H

CNT1:	RLC
		JNC SKIP
		INR B

SKIP:	DCR C
		JNZ CNT1
		MOV A,B
		CPI 03H		; sets carry A < 3
		JNC LABEL1	; carry not set jmp
		MVI A,FF
		JMP LABEL2

LABEL1:	MOV A,M

LABEL2:	STAX D		; store at dest table
		INX H		; increment HL
		INX D		; increment DE
		MOV A,L
		CPI 94H		; sets Z if equal
					;l->94h end of table
		JNZ LOOP	; jump if Z not set
		HLT
