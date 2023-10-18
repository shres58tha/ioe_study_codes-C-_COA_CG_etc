#include<stdio.h>
//write to perform to factorial using recursion
long f(long n){
	if (n<2)
		return 1;
	else	
		return ( n*f(n-1));
}
int main(){
    long a;
    printf("enter a number :");
    scanf("%ld", &a);
    printf("\nthe factorial of %ld is %ld\n",a,f(a));
    return 0;
}
