#include<stdio.h>
#define fabs(a) ((a) ? (a) :-(a))
#define f1(y,z) ( ( 17 -(y) + 2*(z)   )/20 )
#define f2(x,z) ( ( -18 -3*(x) + (z)  )/20 )
#define f3(x,y) ( ( 25 -2*(x) + 3*(y) )/20 )
int main(){
    float x,x0=0.0,y,y0=0.0,z,z0=0.0,err=.000001;
    printf("Enter tolerance : ");
    scanf("%f",&err);
    printf("Enter the initial values of x0, y0 ,z0 : ");
    scanf("%f%f%f",&x0,&y0,&z0);
    do{
        x=x0; y=y0; z=z0;
        x0 = f1(y,z);
        y0 = f2(x,z);
        z0 = f3(x,y);
    }while( fabs(x-x0)>err || fabs(y-y0)>err || fabs(z-z0)> err );
    printf("\nSolution:\nx=%f\ny=%f\nz=%f\n",x0,y0,z0 ); //Display
    return(0);
}
