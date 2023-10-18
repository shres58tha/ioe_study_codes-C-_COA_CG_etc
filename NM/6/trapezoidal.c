//trapezoid rule
#include<stdio.h>
# define f(x) (1 + (x)*(x)*(x) )
float sim_trapez(float a,float b) {  //simple
    float I,h=b-a;
    I=h/2*(f(a)+f(b));
    return I;
}
float com_trapez(float a,float b,int n) { //composite
    float I, h=(b-a)/n, k=0.0;
    for(int i=1; i<= n-1; i++)
        k=k+ 2*f(a + i*h);
    I=h/2*(f(a)+f(b)+k);
    return I;
}
int main() {                                //driver
    float a,b;
    int i,n=1;
    printf("\nlower(a) & upper(b) limit of integration :");
    scanf("%f%f",&a,&b);
    printf("simple trapezoid method I= %f\n",sim_trapez(a,b));
    while(n>0){
        printf("complex trapezoid method I(n=%d): %f\n", n, com_trapez(a,b,n));
        printf("\nEnter number of sub intervals(0 to exit): ");
        scanf("%d",&n);
    }
    return 0;
}
