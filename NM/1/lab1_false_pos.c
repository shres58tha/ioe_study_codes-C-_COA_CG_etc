#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define func(x) cos(x)-x*exp(x)
//#define func(x) x*x -4*x -10
#define func(x) 4*sin(x)-exp(x)
//*/

int main(){
    float x1 , x2 , x3, val1 , val2, val3,e=0.0001;
    int i=0;
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
        x3= x1-(x2-x1)/(val2-val1)*val1;
        
        val3=func(x3);
               
        if (val1*val3<0){
            x2=x3;
            val2=val3;
        }
        else {
            x1=x3;
            val1=val3;
        }
   
    }while(fabs(val3)>e);
    
    printf("\n the root to the function in interval (%f ,%f) is %f \n", lb, ub, x3);
    printf("\n septs taken %d \n",i);
    
    return 0;
}



