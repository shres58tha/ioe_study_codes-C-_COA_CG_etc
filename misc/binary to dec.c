#include<stdio.h>
//#include<conio.h>
/*
int rvrs (int n){ // funtion reverses a number
int temp=0;
while (n>0){temp =temp*10+n%10; n/=10;}
return (temp);
}//*/

/*
int countdigit(int n){
    for (i=0;n;i++)n/=10;
    return i;
}//*/

int main(){
int dec=0;
int rem, i = 1;
long long bin=0, b ;
    printf("\n Enter number please : ");
    scanf("%Ld",&bin);
    //printf("%Ld",bin);
    b=bin;
    while (b) { //while b is true that is not zero
        rem = (int)(b % 10);        // get the remainder of 2 either 1 or 0
        b/= 10;              // reduce no by 10
        dec += rem * i;     // input value of the rem in bin each iteration multiply rem by i so it goes to the higherfile:///home/shr/Desktop/c%20practicle/decimal%20to%20binary.c
        i *= 2;            // increment i by 10 so next rem go to higer radix
       printf(" Remainder = %d, Quotient = %d\n",rem,b);
    }
	printf("\decimal equivalent %d\n",dec);
return 0;

}
