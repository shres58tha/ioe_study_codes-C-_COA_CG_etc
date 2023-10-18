#include<stdio.h>
#define fabs(a) ((a>0) ? (a) : (-1*(a)))
#define f1(y,z) ( ( 17 -(y) + 2*(z)   )/20 )
#define f2(x,z) ( ( -18 -3*(x) + (z)  )/20 )
#define f3(x,y) ( ( 25 -2*(x) + 3*(y) )/20 )
int main(){
    float x,x0=0.0,y,y0=0.0,z,z0=0.0,err=.000001;
    int step=0;
    printf("Enter tolerance : ");
    scanf("%f",&err);
    printf("Enter the initial values of y0 ,z0 : ");
    scanf("%f%f",&y0,&z0);
    do{
        x=x0; y=y0; z=z0;
        step++;
        x0 = f1(y,z);
        y0 = f2(x0,z);
        z0 = f3(x0,y0);
        printf("\nstep %d x %9f, y %9f, z %9f ",step,x0,y0,z0);
    }while( fabs(x-x0)>err || fabs(y-y0)>err || fabs(z-z0)> err );
    printf("\nSTEP taken: %d\nSolution:\nx:%9f\ny:%9f\nz:%9f\n",step,x0,y0,z0 ); //Display
    return(0);
}
