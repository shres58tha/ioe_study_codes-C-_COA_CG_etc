//squareroot just the intergral part approximation
#include<stdio.h>
int sR(int n)   //square root by bisection method
    {
        float x = (float)n;
        float y = 1;
        x=x/2;.
        /* e decides the accuracy level*/
        float e = 0.1;
        while (x - y > e) {
            x = (x + y) / 2;
            y = n / x;
        }
        return (int)x;
    }
int main(){
int num;
printf("\n enter a num  ");
scanf("%d",&num);
printf("\n integral sq root of %d is %d: ",num, sR(num));
printf("\n");
return 0;


}
