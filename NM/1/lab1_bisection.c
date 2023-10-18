#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*bisection method
 * objectives
 * theory wiht the  graph
 * algorithm
 * flow chart
 */
 
/* final report 
 * program code with results steps and error
 * manual calculations results steps and error
 */
  
/*
float func(float x){
    return (cos(x)-x*exp(x));
}
//*/
/*
float func(float x){
    return (x*x-4*x-10);
}//*/
///*
float func(float x){
    return (4*sin(x)-exp(x));
}
//*/

int main(){
    float x1 , x2 , x0, val1 , val2, val0,e=0.0001;
    int i=0;
    //printf("turncation error "); scanf("%f",&e);
    printf("initial lower bound ");
	scanf("%f", &x1);
    printf("initial upper bound ");
	scanf("%f", &x2);
    printf("enter error tolerance "); 
	scanf("%f",&e);
	
    float lb=x1;
    float ub=x2;
    val1=func(x1);
    val2=func(x2);
 
    if (val1*val2>0) {
		printf("failure\ninterval (%f , %f) \n val1:%f ,val2:%f\n",x1,x2,val1,val2);
		exit(0);
	}	
		
    do {
        i++;
        x0=(x1+x2)/2;
        
        val0=func(x0);
        
        if (val1*val0<0){
            x2=x0;
            val2=val0;
        }
        else {
            x1=x0;
            val1=val0;
        }
             
        if (fabs(x1-x2)<e) break;
        
    }while(i<150);
    
    printf("\n the root to the function in interval (%f ,%f) is %f \n", lb, ub, x0);
    printf("\n septs taken %d \n",i);
    
    return 0;
}



