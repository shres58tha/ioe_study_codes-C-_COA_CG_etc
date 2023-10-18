#include<stdio.h>
//write to perform to reverse the number entered by the user and display the result
int main(){
    int a;
    printf("enter a number :");
    scanf("%d", &a);
    while(a){
    	printf("%d",a%10);
     a/=10;
	} 
	printf("\n");
    return 0;
}
