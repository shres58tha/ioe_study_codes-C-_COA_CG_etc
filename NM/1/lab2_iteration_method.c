#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// fixed point iteration method
//// function (cos(x) -(x)*exp(x))
//#define gfunc(x) cos(x)/exp(x)
//#define dgfunc(x) (-sin(x)-cos(x))/exp(x)

//x**x-4*x-10
//#define gfunc(x) sqrt(4*x+10)
//#define dgfunc(x)

//x*x=7
#define gfunc(x) ((x)+7/(x))/2
//#define dgfunc(x) (-sin(x)-cos(x))/exp(x)


int main(){
    float x1 , x2 ,  val , dval, e;
    int i=0;
    printf("guess ");
	scanf("%f", &x1);
    printf("enter error tolerance ");
	scanf("%f",&e);

    do {
        i++;
        val=gfunc(x1);
//        dval=dgfunc(x1);
/*
        if ( fabs(dval)>=1){
            printf("NO solution at the guessed value") ;
            return 0;
        }
*/
        x2= gfunc(x1);
        if (fabs((x2-x1)/x2)<e)
            break;
        x1=x2;
    }while(i<200);

    if (i<200){
        printf("\n the root to the function is %f \n", x2);
        printf("\n steps taken %d \n",i);
    }
    else {
        printf("iteration method failed to converge in 200 steps\n");
    }
    return 0;
}



