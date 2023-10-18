;wap(8085) to transfer 20 bytes of data in a table to another table by
interchanging D1 and D4 bits of each byte.

START:	   LXI H,C000H
		   LXI B,C050H
		   MVI D,14H	 ;20 dec down counter

NEXT:	   MOV A,M		 ;load from mem
		   ANI 10H		 ;0001 0000
		   RRC
		   RRC
		   RRC
		   MOV E,A		 ;D4 in D1 position
		   MOV A,M		 ;load from mem
		   ANI 01H		 ;get D1 in D1 position
		   CMP B
		   MOV A,M		 ;flags remain unaffected
		   JNC SKIP
		   JZ SKIP
		   XRI 21		 ;0001 0010

SKIP:	   STAX B
		   INX H
		   INX B
		   DCR D
		   JNZ NEXT
		   MOV A,E
		   MOV M,A
		   HLT
