// program to print the num in reverse (any no of digits)

#include<stdio.h>
//#include<conio.h>
// #include<math.h> // not needed

int main(){
	int a=0, b=0,sum =0 ,rem=0;
	printf(" \n\nEnter number please :");
	scanf("%d",&a);
	b=a;
	while (b>0){
        rem=b%10;// these two lines are used to extract digits from the number sequentially from left
        b=b/10; // these two lines are used to extract digits from the number sequentially from left
        sum =sum*10+rem; // sum those digits in increasing power of 10 radix
        }
	printf("the entered no is %d reverse of it  is %d \n",a,sum);
	return 0;

}
