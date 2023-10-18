; wap(8085) to convert and copy Lowercase ASCII
; codes To upper from memory location 9050H->90A0H
; if any otherwise copy as they are.
; Assume there are 50 codes in the source memory.
; [Note: ASCII Code for A:65...Z=90, a:97...2:122]

		LXI H,9050H
		LXI D,90A0H
		MVI C,32H	; dec 50 characters

NEXT:	MOV A,M
		CPI 61H		; ascii of a=61H
		JC SKIP		; A < (a)
		CPI 7BH		; ascii of z=7AH cmp 7ah +01h
		JNC SKIP	; A < (z+1)
		SBI 20H		; (a-A) = 20h

SKIP:	STAX D
		INX H
		INX D
		DCR C
		JNZ NEXT
		HLT
