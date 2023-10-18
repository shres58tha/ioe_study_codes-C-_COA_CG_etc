// simple simpson rule 3/8 // n should be multiple of 3
#include<stdio.h>
#define f(x) ( 1 + (x)*(x)*(x) )
int main(){
    float lower, upper, I=0.0, h, sumeven=0.0, sumodd=0.0;
    printf("\n lower & upper limit of integration :");
    scanf("%f%f",&lower,&upper);
    
    h=(upper-lower)/3;
    
    I=3*h/8*(f(lower)+ 3* f(lower + h) + 3* f(lower + 2*h) +f(upper));
    printf("\nI= %f\n",I);
    return 0;
}
