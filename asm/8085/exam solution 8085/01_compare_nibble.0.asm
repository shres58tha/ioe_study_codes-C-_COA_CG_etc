;wap(8085) to count the numbers for which upper nibble is higher than the
;lower nibble, store count at end of table of 50 bytes located at C050H

START:	   LXI H,C050H
           MVI D,32H    ;50 dec counter
           MVI E,00H    ;counter inc if higher nibble > lower

NEXT:	   MOV A,M      ;load from mem
           ANI F0H
           RLC
           RLC
           RLC
           RLC
           MOV B,A	 	;higher nibble
           MOV A,M	 	;load from mem
           ANI 0F	 	;lower nibble
           CMP B
           JZ SKIP
           JNC SKIP
           INR E

SKIP:	   INX H
           DCR D
           JNZ NEXT
           MOV M,E
           HLT
