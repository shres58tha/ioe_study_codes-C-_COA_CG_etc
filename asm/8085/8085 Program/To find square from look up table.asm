// TO FIND SQUARE FROM LOOP-UP TABLE
	   LDA C050
	   ADI 60
	   MOV L,A
	   MVI H,C0
	   MOV A,M
	   STA C051
	   HLT
// First create the look up table->C060=00,C061=01 ,,, C069=81

# ORG C060
# DB 00H,01H,04H,09H,16H,25H,36H,49H,64H,81H


// EXAMPLE-> C050=09
// Answer-> C051=81

# ORG C050
# DB 09H
