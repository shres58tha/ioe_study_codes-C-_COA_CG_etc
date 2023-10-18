// program to testif entered number is multiple of 5 or not ,divisible by 7 but not by 11

#include <stdio.h>
//#include<conio.h>
#define block 2  // two blocks of code block = {1 , 2}

#if (block==1)
int main(){
	int num;
	printf("\n enter a number: ");
	scanf ("%d",&num);
	if (num%5==0)                   // ! takes immediate precedence so notting long expression is bound to creat error
        if(num%7==0)
            if (num%11==0)
                printf("the number is divisible by 5, 7 & 11\n");
            else
                printf("number is divisible by 5 & 7 but not by 11\n");
        else
            printf("number is divisible by 5 but not by 7\n");
    else
        printf("the number is not divisible by 5 \n");
	return 0;
 }
#endif


#if (block==2)
// compacted into conditional statement
int main(){
	int num;
	printf("\n enter a number :");
	scanf ("%d",&num);
	printf(" \n The no is multiple of ");
	 !(num%5)?(num%7==0?(num%11==0?puts("5, 7 & 11"):printf("5 & 7 but not 11")):printf("5 but not 7")):printf("5");
	 // looks like when we put !num%5 its not working so !(num%5) must work
    printf ("\n\n");
	return 0;
 }

#endif
