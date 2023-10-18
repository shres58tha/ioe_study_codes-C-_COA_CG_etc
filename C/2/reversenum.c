// program to print the num inreverse (any no of digits)

#include<stdio.h>
//#include<conio.h>
// #include<math.h> // not needed

int main(){
	int a=0, b=0,rev =0 ,rem=0;
	printf(" \n\nEnter number please :");
	scanf("%d",&a);
	b=a;
	while (b>0){
        rem=b%10;// these two lines are used to extract digits from the number sequentiallu
        b=b/10; // these two lines are used to extract digits from the number sequentiallu
        rev =rev*10+rem; // rev those digits in invreasing power of 10 radix
    }
	printf("the entered no is %d reverse of it  is %d",a,rev);
	return 0;

}
