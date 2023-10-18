#include<stdio.h>
//#include<conio.h>

int main(){
int a=0,b;
int rem, i = 1;
long long bin=0;
    printf("\n Enter number please : ");
    scanf("%d",&a);
    b=a;
    while (b) { //while b is true that is not zero
        rem = b % 2;        // get the remainder of 2 either 1 or 0
        b/= 2;              // reduce no by 10
        bin += rem * i;     // input value of the rem in bin each iteration multiply rem by i so it goes to the higher value
        i *= 10;            // increment i by 10 so next rem go to higer radix
        printf(" Remainder = %d, Quotient = %d\n",rem,b);

    }
	printf("\n binary equivalent %lld\n",bin); // converts till 512 bu not 1024
return 0;

}
