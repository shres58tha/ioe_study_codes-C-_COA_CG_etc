//simpson 1/3 rule
#include<stdio.h>
#define f(x) (1 + (x)*(x)*(x) )
float sim_simpson1_3(float a, float b) {          //simple
    float I=0.0, h;
    h=(b-a)/2;
    I=(h/3)*(f(a)+4*f((a+b)/2)+f(b));
    return I;
}
float com_simpson1_3(float a, float b,int n) {    //composite n should be multiple of 2
    float  h,I, sumeven=0.0, sumodd=0.0;
    if (n%2==1) {                                 //odd
        printf("\nn must be even\n");
        return 0 ;
    }
    h=(b-a)/n;
    for(int i=1;i<n;i++) {
        if (i%2==1)                               // odd
            sumodd = sumodd + 4 * f(a + i*h);
        else
            sumeven = sumeven + 2 * f(a + i*h);
    }
    I=h/3*(f(a)+sumodd + sumeven + f(b));
    return I;
}
int main() {                                      //driver
    float a,b;
    int n=1;
    printf("\nlower(a) & upper(b) limit of integration :");
    scanf("%f%f",&a,&b);
    printf("\nsimple simpson 1/3 rule I=%f\n",sim_simpson1_3(a,b));
    while(n>0) {
        if (n%2==1)
            printf("\nn must be even");
        else
            printf("complex simpson 1/3 rule I(n=%d): %f\n", n,com_simpson1_3(a,b,n) );
        printf("\nEnter no. of sub intervals n (0 to exit): ");
        scanf("%d",&n);
    }
}
