#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// secant method
#define func(x) (cos(x) -(x)*exp(x))

int main(){
    float x1 , x2 , x3, val1 , val2, val3,e;
    int i=0;
    printf("1st guess ");
	scanf("%f", &x1);
    printf("2nd guess ");
	scanf("%f", &x2);
    printf("enter error tolerance ");
	scanf("%f",&e);

    val1=func(x1);
    val2=func(x2);
    do {
        i++;
        x3= x2 - (x2-x1)/(val2-val1)*val2;
        val3=func(x3);
        x1=x2;
        x2=x3;
        val1=val2;
        val2=val3;
        if (fabs((x2-x1)/x2)<e)
            break;
    }while(i<200);

    if (i<200){
        printf("\n the root to the function is %f \n", x2);
        printf("\n steps taken %d \n",i);
    }
    else {
        printf("secant method failed to converge in 200 steps\n");
    }
    return 0;
}



