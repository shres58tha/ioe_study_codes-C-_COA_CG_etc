// composite simpson rule 3/8 // n should be multiple of 3
#include<stdio.h>
float f(float x) { return ( 1 + x*x*x );}
int main(){
    float lower, upper, I=0.0, h, sum_not_3=0.0, sum_3=0.0;
    int i, n;
    printf("\n lower & upper limit of integration :");
    scanf("%f%f",&lower,&upper);
    printf("Enter number of sub intervals (multiple of 3): ");
    scanf("%d", &n);
    h=(upper-lower)/n;
    for(i=1;i<=n-1;i++){
        if (i%3==0){// multiple of 3
            sum_3 = sum_3 + 2 * f(lower + i*h);
        }
        else{
            sum_not_3 = sum_not_3 + 3 * f(lower + i*h);
        }
    }
    I=3*h/8*( f(lower) + sum_not_3 + sum_3 + f(upper) );
    printf("\nI= %f\n",I);
    return 0;
}
