; WAP 8085 to transfer eight-bit numbers from
; 9080H to 9090H if if bit D5 is 1 & D3 is 0,
; Otherwise transfer data by changing bit D2 & D0
; 1->0 or 0->1
; Assume there are ten numbers.
; assuming tables start at A000H and A010H
; counter used

		LXI H,9080H	; scr
		LXI D,9090H	; dest
		MVI C,0AH	; count down

NEXT:	MOV A,M
		ANI 28H		; mask for D5 & D3
		CPI 20H		; check for D5=1, D3=0
		JNZ CHANGE
		MOV A,M
		JMP STORE

CHANGE:	MOV A,M		; data flip
		XRI 44H		; flip D2 & D6

STORE:	STAX D
		INX H
		INX D
		DCR C
		JNZ NEXT
		HLT
