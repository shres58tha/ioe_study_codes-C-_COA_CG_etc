;There are two tables with 20 data with starting address 9000H and 9020H
;wap(8085) to add the elements of first table with the content of second
;and store sum and carry into the third and fourth table indexing 9040H
;and 9060H respectively.

START:	LXI H,9000H	; use L as increment counter
		MVI E,00H	; for sum

NEXT:	MVI D,00H	; for carry
	 	MOV B,H		; calcuating BC= HL+20
	 	MOV A,L		; calculate 2nd data loc
	 	ADI 20H		; put it in function call
	 	MOV C,A		; address complete
	 	LDAX B		; A <- [BC]
	 	ADD M
	 	MOV E,A		; E=sum
	 	JNC SKIP	; skip if carry is not set
	 	MVI D,01H	; set carry

SKIP:	MOV A,C		; calculate carry save loc
	 	ADI 20H		; put it in function call
	 	MOV C,A		; address complete
	 	MOV A,D		; put carry in A
	 	STAX B		; save carry in [BC]
	 	MOV A,C		; calculate carry save loc
	 	ADI 20H		; put it in function call
	 	MOV C,A		; address complete
	 	MOV A,E		; put sum in A
	 	STAX B		; save carry in [BC]
	 	INX H
	 	MOV A,L		; get l in accumulator
	 	CPI 14		; sets flag Z if equal
	 	JNZ NEXT	; jmp if flag Z not set
	 	HLT
