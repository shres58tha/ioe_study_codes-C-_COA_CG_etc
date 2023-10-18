//simple trapezoid
#include<stdio.h>
#define f(x) ( 1 + (x)*(x)*(x) )
int main(){
    float a,b,h,n,I;
    printf("\n lower(a) & upper(b) limit of integration :");
    scanf("%f%f",&a,&b);
    h=b-a;
    I=h/2*(f(a)+f(b));
    printf("I = %f\n",I);
    return 0;
}
