#include<stdio.h>
//write to perform to reverse the number entered by the user and display the result
int main(){
    int a,temp,rev=0, digit;
    printf("enter a number :");
    scanf("%d", &a);
    temp=a;
    while(a!=0){
    	digit=a%10;
    	rev=rev*10+digit;
    	a=a/10;
	} 
    printf("the reverse of %d is %d\n" ,temp, rev);
    return 0;
}
