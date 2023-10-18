#include <stdio.h>
//#include<conio.h>
int main(){
	char ch;
	printf ("enter a  character please:");
	scanf ("%c",&ch);
	if (ch>='a'&&ch<='z')
		printf("\nchanged into CAPITAL %c",ch-('a'-'A')); //ascii value of a=97 and that of A is 65 diff is 32
	else if (ch>='A'&&ch<='Z')
		printf ("\nchanged to small %c",ch+('a'-'A')); //
	else 
		printf ("\nentered digit is not an alphabet");

	printf ("\n\n");
	return 1;
}


