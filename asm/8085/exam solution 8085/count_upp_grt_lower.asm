;WAP for 8085 to count the numbers for which
;upper nibble is higher than the lower nibble
;and store the count at the end of table with
;5O bytes data starting from C050

start: 	LXI H,C050h	; scr data tablE
       	MVI C,32H	; counter 50 dec
        MVI D,00H	; count u_nibble>l_nibble
LOOP:	MOV A,M
		ANI f0h
        RRC
        RRC
        RRC
        RRC
        MOV B,A		; B= upper nibble
        MOV A,M
        ANI 0FH		; A = lower nibble
        CMP B		; sets if A<B
        JNC SKIP
        INR D
SKIP:   INX H
        DCR C
        JNZ LOOP
        MOV M,D		; SAVE TO MEM COUNT D
        HLT
