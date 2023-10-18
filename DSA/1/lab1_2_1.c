#include<stdio.h>
//write to perform addition subtraction division and multiplication usng functions
void add(const float *x,const float *y){printf(" the sum is %f\n", *x+*y);}

void sub( float x,  float y){printf(" the diff is %f\n", x-y);}
void mul( float x,  float y){printf(" the product is %f\n", x*y);}
void div( float x,  float y){printf(" the result is %f\n", x/y);}

int main(){
    float a,b;
    printf("enter two number ");
    scanf("%f %f", &a,&b);
    add(&a,&b);
    sub(a,b);
    mul(a,b);
    div(a,b);
    return 0;
}
