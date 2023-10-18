	   MVI A,FF
	   STA 8050
	   MVI A,AA
	   STA 8040

	   LXI H,8050
	   MOV A,M
	   LXI H,8040
	   MOV B,M
	   SUB B
	   LXI H,A560
	   MOV M,A
	   HLT
