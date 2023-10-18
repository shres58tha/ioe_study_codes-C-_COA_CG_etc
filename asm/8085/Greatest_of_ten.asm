; Save greatest no of table of 10 num at 4500H
; to 4510H
	   JMP SK
	   LXI H,4500H
	   LXI D,0800H
	   MVI C,0A		; deci 20

XYZ:   LDAX D
	   MOV M,A
	   INX H
	   INX D
	   DCR C
	   JNZ XYZ

SK:	   MVI C,0A
	   LXI H,4500H
	   MOV A,M

LOOP:  CMP M	; loop will go on until c!=0
	   JNC SKIP
	   MOV A,M

SKIP:  INX H
	   DCR C
	   JNZ LOOP
	   STA 4510H
	   HLT
