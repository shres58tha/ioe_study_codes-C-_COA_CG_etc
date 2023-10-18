; There are two tables T1, T2
; in memory having ten eight bit data in each.
; WAP(8065) to find the diff. of corresponding
; element of these two tables. Store the result
; of each operation on corresponding element
; of the third table. Remember that
; the resuly should not be negative
; it should be |T1 - T2|.
; assuming tables start at A000H and A010H
; counter used

		LXI H,A000H	; t1
		; use DE as var mem pointer
		; t2 at +10h
		; diff at +20h
		MVI D,A0H	; calculate E later
		MVI C,0AH	; count down
		; working register b

NEXT:	MOV A,M
		MOV B,A
		MOV A,L
		ADI 10H
		MOV E,A		; calc address of t2 element
		LDAX D
		CMP B		; sets carry a if b<m
		JNC XYZ		; jumps when c=0
		LDAX D
		MOV B,A
		MOV A,M
		SUB B
		JMP STORE

XYZ:	LDAX D
		SUB B

STORE:	MOV B,A		; hold the diff
		MOV A,L		; calc add of the dest
		ADI 20H
		MOV E,A		; dest in DE
		MOV A,B		; get diff in a
		STAX D
		INX H
		DCR C
		JNZ NEXT
		HLT
