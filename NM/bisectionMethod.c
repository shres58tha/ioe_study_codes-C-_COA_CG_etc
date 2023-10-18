#include <stdio.h>
#include <stdlib.h>

float func(float x){
    return (x*x-5*x+6);
}
float method(float x1,float x2){
    return ((x1+x2)/2); // bisection method
}
int driver(){
    float x1 , x2 , x0, val1 , val2, val0,e=0.0001;
    int i=0;
    //printf("turncation error "); scanf("%f",&e);
    printf("initial lower bound ");scanf("%f", &x1);
    printf("initial upper bound ");scanf("%f", &x2);
    float lb=x1;
    float ub=x2;
    val1=func(x1);
    val2=func(x2);
    if (val1==0) {printf(" root to the the function is %f \n",x1); exit(0);}
    if (val2==0) {printf(" root to the the function is %f \n",x2); exit(0);}
    if (val1*val2>0) {printf("failure\ninterval (%f , %f) \n val1:%f ,val2:%f\n",x1,x2,val1,val2); exit(0);}
    printf("\ninterval (%f , %f) \n val1:%f ,val2:%f\n\n",x1,x2,val1,val2);
    do {
        i++;
        printf("step %3d  x1 =%f    x2 =%f  f(x1)= %f   f(x2)= %f \n", i, x1,x2,val1,val2);
        x0=method(x1,x2);
        val0=func(x0);
        printf("x0 =%f  f(x0)= %f\t\t",x0,val0);
        if (val1*val0<0){
            x2=x0;
            printf("f(x1)*f(x0)<0=TRUE  :-> x2=x0\n\n");
            val2=val0;
        }
        else {
            x1=x0;
            printf("f(x1)*f(x0)<0=FALSE :-> x1=x0\n\n");
            val1=val0;
        }
        if (val1==0){ x2=x1; break;}
        if (val2==0){ x1=x2; break;}
    }while(i<150);
    printf(" the root to the function in interval (%f ,%f) is %f \n", lb, ub, (x1+x2)/2);
    
    return 0;
}

int main(){
    driver();
    return 0;
}

