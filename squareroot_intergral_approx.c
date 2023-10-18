//squareroot just the intergral part approximation
#include<stdio.h>
#define debug 0 // set 1 for debug; 0 for normal
int sR(int n)
    {
        float x = (float)n;
        float y = 1;
        #if (debug==1)
        int i=1;
        #endif
    
        /* e decides the accuracy level*/
        float e = .9;
        while (x-y>e ) { //bisection method is used here
            x = (x + y) / 2;
            y = n / x;
            //if ((int)(x*x)==n) break;
            #if (debug==1)
            printf("%d \n",i++); // counter for no of loop
            #endif
        }
        return (int)x;
    }
    
int main(){
    int num;
    printf("\n enter a num  ");
    scanf("%d",&num);
    printf("\n integral sq root of %d is : %d \n",num, sR(num));
    printf("\n");
    return 0;
}
