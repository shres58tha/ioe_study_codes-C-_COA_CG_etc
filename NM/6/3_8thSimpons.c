//simpson 3/8 rule
#include<stdio.h>
# define f(x) (1 + (x)*(x)*(x) )
float sim_simpson3_8(float a, float b) {          //simple
    float I=0.0, h;
    h=(b-a)/3;
    I=3*h/8*(f(a)+ 3* f(a + h) + 3* f(a + 2*h) +f(b));
    return I;
}
float com_simpson3_8(float a, float b,int n) {    //composite n should be multiple of 2
    float  h,I, sum_3=0.0, sum_not_3=0.0;
    if (n%3!=0) {                                 //not multiple of 3
        printf("\nn must be multiple of 3\n");
        return 0 ;
    }
    h=(b-a)/n;
    for(int i=1;i<=n-1;i++) {
        if (i%3==0)                               // multiple of 3
            sum_3 = sum_3 + 2 * f(a + i*h);
        else
            sum_not_3 = sum_not_3 + 3 * f(a + i*h);
    }
    I=3*h/8*( f(a) + sum_not_3 + sum_3 + f(b) );
    return I;
}
int main() {                                        //driver
    float a,b;
    int i,n=1;
    printf("\nlower(a) & upper(b) limit of integration :");
    scanf("%f%f",&a,&b);
    printf("\nsimple simpson 3/8 rule I=%f\n",sim_simpson3_8(a,b));
    while(n>0) {
        if (n%3!=0)
            printf("\nn must be multiple of 3");
        else
            printf("complex simpson 3/8 rule I(n=%d): %f\n", n,com_simpson3_8(a,b,n) );
        printf("\nEnter no. of sub intervals n (0 to exit): ");
        scanf("%d",&n);
    }
}
