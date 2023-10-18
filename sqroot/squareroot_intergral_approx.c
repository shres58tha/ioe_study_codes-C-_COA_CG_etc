//squareroot just the intergral part approximation
#include<stdio.h>
#define debug 1 // set 1 for debug; 0 for normal
int sR(int n){
    int x=n, y=1;
    #if (debug==1)
    int i=1;
    #endif
    while (x>y) { //NR ~~ bisection method  here
        y = n / x;
        x = (x + y)/2;
        #if (debug==1)
        printf("%d\tx %d \t y %d \n",i++,x,y); // counter for no of loop
        #endif
    }
    return x;
}

int main(){
    int num;
    printf("\n enter a num  ");
    scanf("%d",&num);
    printf("\n integral sq root of %d is : %d \n",num, sR(num));
    printf("\n");
    return 0;
    getchar();
}
