;WAP 8085 to transfer 8-bit number table1 to
;table2 setting bit D5, if the number < 80H
;else transfer number by resetting bit D6. ,

START:	LXI H,8010H	; scr data table
		LXI D,8020H	; destination table
		MVI C,0AH	; counter 10 dec

LOOP:	MOV A,M
		CPI 80H
		JC SETD6
		ORI 20H		;SET D5 ORing
		JMP SKIP
SETD6:	ANI BEH		;RESET D6 ORing

SKIP:	STAX D
		INX D
		INX H
		DCR C
		JNZ LOOP
		HLT
