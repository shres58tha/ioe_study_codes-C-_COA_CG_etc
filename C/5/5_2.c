// program to check entered number is prime or not using function
#include<stdio.h>
#include <stdlib.h>
//#include<math.h>

#define block 1  // just change value of letter to select corrosponding block while comparing
#if (block==1)
///* using if else statement
float prime_check( int num){
    for(int i=1;i<num/2;i++){
    if (num%i==0) return 0;
    }
    return 1;

}

int main(){
    int num;
	printf(" \n\n Enter a number :");
	scanf("%d",&num);
	prime_check(num) ? printf("not prime") : printf("is prime");
	printf ("\n\n\n");

}
#endif



#if (block==2)



#endif
