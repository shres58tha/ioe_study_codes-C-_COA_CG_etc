// composite simpson 1/3// n should be multiple of 2
#include<stdio.h>
float f(float x) { return ( 1 + x*x*x );}
int main(){
    float lower, upper, I=0.0, h, sumeven=0.0, sumodd=0.0;
    int i, n;
    printf("\n lower & upper limit of integration :");
    scanf("%f%f",&lower,&upper);
    printf("Enter number of sub intervals (multiple of 2): ");
    scanf("%d", &n);
    h=(upper-lower)/n;
    for(i=1;i<n;i++){
        if (i%2==1){// odd
            sumodd = sumodd + 4 * f(lower + i*h);
        }
        else{
            sumeven = sumeven + 2 * f(lower + i*h);
        }
    }
    I=h/3*(f(lower)+sumodd + sumeven + f(upper));
    printf("\nI= %f\n",I);
    return 0;
}
