
START:	   LXI H,C050
	   MVI D,32	// 50 dec counter
	   MVI E,00	// counter ine if higher nibble > lower

NEXT:	   MOV A,M	// load from mem
	   ANI F0
	   RLC
	   RLC
	   RLC
	   RLC
	   MOV B,A	// higher nibble
	   MOV A,M	// load from mem
	   ANI 0F	// lower nibble
	   CMP B
	   JZ SKIP
	   JNC SKIP
	   INR E

SKIP:	   INX H
	   DCR D
	   JNZ NEXT
	   MOV A,E
	   MOV M,A
	   HLT
