; WAP 8085 to count no. of -ve element in a data block
; block containing 16 bytes of data
; store the count at the end of the block
; if the count is greater than 8
; otherwise store 0.
; assuming tables start at A000H and A010H
; counter used
		LXI H,A000H	; table 1
		MVI C,00H	; count neg nos
		MVI B,0F	; count down

NEXT:	MOV A,M
		RAR			; get MSB in carry
		JNC SKIP
		; count neg nos
		INR C

SKIP:	INX H
		DCR B
		JNZ NEXT
		MOV A,C
		CPI 08H
		JNC JU
		MVI A,00H

JU:		MOV M,A
		HLT
