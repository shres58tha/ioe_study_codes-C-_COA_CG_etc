; WALP8085 to divide as [9070H]/[9071H]
; store rem-> [9072H] & quotient-> [9073H]

START:	LXI H,9070H	; scr data table
		LDA 9071H	; load accumlator direct
		MOV D,A		; div in d
		MVI B,00H	; quotient
		MOV A,M


LOOP:	SUB D		; subtract until (A is -ve)
		JC NEG		; borrow true
		INR B		;
		JMP LOOP

NEG:	ADD D		; fix it make A +ve
		MOV C,A		; remainder
		STA 9072H
		MOV A,B
		STA 9073H
		HLT
