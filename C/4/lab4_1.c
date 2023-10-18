// program to testif entered no is multiple of 5 or not ,divisible by 7 but not by 11

#include <stdio.h>
//#include<conio.h>
#define block 2 // two blocks of code block = {1 , 2}

#if (block==1)
int main(){
	int num;
	printf("\enter a number");
	scanf ("%d",&num);
	if (num%5)
        if(num%7)
            if (!num%11)
                printf("no is divisible by 5 & 7 but not by 11");
            else
                printf("the no is divisible by 5, 7 & 11");
        else
            printf("no is divisible by 5 but not by 7");
    else
        printf("the no is not divisible by 5");
	return 0;
 }
#endif


#if (block==2)
// compacted into conditional statement
int main(){
	int num;
	printf("\enter a number");
	scanf ("%d",&num);
	 num%5?(num%7?(num%11?puts("divisible by 5, 7 & 11"):printf("divisible by 5 & 7 but not by 11")):printf("divisible by 5 but not by 7")):printf("divisible by 5");
	return 0;
 }

#endif
