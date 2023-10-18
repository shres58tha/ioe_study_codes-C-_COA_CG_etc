// simple calculator using function and case
#include<stdio.h>
#include <stdlib.h>
#include<math.h>

#define block 1  // just change value of letter to select corrosponding block while comparing
#if (block==1)
///* using if else statement
float fun_calc( float num1, char opt, float num2){


    switch (opt){
	case '+':
		return(num1+num2);
		break;
	case '-':
		return(num1-num2);
		break;
	case '*':
		return(num1*num2);
		break;
	case '/':
		return(num1/num2);
		break;
    case '^':
		return(pow(num1,num2));
		break;
    case '#':
        num2=1/num2;
        return(pow(num1,num2));
		break;
	case '%':
		return((int)num1%(int)num2);
		break;
    default:
		printf("unknown error\n\n");
		exit(0);
		}
}
int main(){
	float num1, num2;
	char opt;
    printf("\n   valid operators + - * / %% ^ power # rooth ");
	printf(" \n\n Enter two number seperated by operator eg (2 + 3) please :");
	scanf("%f %c %f",&num1, &opt, &num2);
	printf ("\n the result of expression %f %c %f is: %f",num1, opt, num2,fun_calc(num1,opt,num2));
	printf ("\n\n\n");
}
#endif


#if (block==2)


#endif
