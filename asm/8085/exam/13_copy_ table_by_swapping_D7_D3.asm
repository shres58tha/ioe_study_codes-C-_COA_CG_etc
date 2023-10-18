; WAP(8085)to transfer 20 bytes in a table
; to another table interchanging D7 and D3 bits
; of each byte.
	   JMP SK
	   LXI H,5000H
	   LXI D,0800H
	   MVI C,14H	; deci 20

XYZ:  LDAX D
	   MOV M,A
	   INX H
	   INX D
	   DCR C
	   JNZ XYZ

SK:    NOP
; program

START: LXI H,5000H
	   LXI D,5050H
	   MVI C,14H

LOOP:  MOV A,M
	   ANI 84H
	   CPI 84H	; d7=1 d3=1
	   JZ SKIP
	   CPI 00H	; d7=0 d3=0
	   JZ SKIP
	   MOV A,M
	   XRI 84H	; exchange as D7 != D3
	   JMP CONTD

SKIP:  MOV A,M

CONTD: STAX D
	   INX H
	   INX D
	   DCR C
	   JNZ LOOP
	   HLT
