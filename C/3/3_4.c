#include <stdio.h>
//#include<conio.h>
int main(){
	float a,b;
	int ch=0;
	//printf("enter the operator");
	//scanf (" %c",&ch);
	printf ("enter the numbers seperated by operator eg (2+3):");
	scanf("%f %c %f", &a,&ch,&b);
	//printf ("a %f b %c c %f", a,ch,b);
	switch (ch){
	case '+':
		printf ("the result is = %f", a+b);
		break;
	case '-':
		printf ("the result is = %f", a-b);
		break;
	case '*':
		printf ("the result is = %f", a*b);
		break;
	case '/':
		printf ("the result is = %f", a/b);
		break;
	case '%':
		printf ("the result is (after dropping .decima part) = %f", (int)a%(int)b);  // typecasting needed as modulus operator cant work with floating point type
		break;
		default:
		printf("unknown error");
	}
	return 0;

}


