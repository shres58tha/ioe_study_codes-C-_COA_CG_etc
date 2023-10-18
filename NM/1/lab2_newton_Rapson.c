#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// newton rapson method
#define func(x) (cos(x) -(x)*exp(x))
#define dfunc(x) (-sin(x)-(x)*exp(x) -exp(x) )

int main(){
    float x1 , x2 ,  val , dval, e;
    int i=0;
    printf("guess ");
	scanf("%f", &x1);
    printf("enter error tolerance ");
	scanf("%f",&e);

    do {
        i++;
        val=func(x1);
        dval=dfunc(x1);
        x2= x1 - val/dval;
        if (fabs((x2-x1)/x2)<e)
            break;
        x1=x2;
    }while(i<200);

    if (i<200){
        printf("\n the root to the function is %f \n", x2);
        printf("\n steps taken %d \n",i);
    }
    else {
        printf("Newton Rapson method failed to converge in 200 steps\n");
    }
    return 0;
}



