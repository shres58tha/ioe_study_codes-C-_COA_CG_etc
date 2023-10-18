//composite trapezoid 
#include<stdio.h>
#define f(x) ( 1 + (x)*(x)*(x) )
int main(){
    float a, b, I=0.0, h, k=0.0;
    int i, n=1;
    printf("\n lower(a) & upper(b) limit of integration :");
    scanf("%f%f",&a,&b);
    do{//
        I=0.0;//
        k=0.0;//
        h = (b - a)/n;
        for(i=1; i<= n-1; i++)
            k=k+ 2*f(a + i*h);
        I=h/2*(f(a)+f(b)+k);
        printf("\nI(n=%d) is: %f\n",n, I); 
        printf("Enter number of sub intervals {0 for exit}: ");
        scanf("%d", &n);
    }while(n!=0);//
    return 0;
}
