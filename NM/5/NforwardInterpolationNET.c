//done final dont touch
#include<stdio.h>
#define MAXN 100
int main(){
    float x[MAXN+1],y[MAXN+1],xp,yp,p,pk;
    int i,j,n;
    printf("enter the value of n :");
    scanf("%d",&n);
    printf("Enter data:\n");
    //getting the values
    for(i=1;i<=n;i++) {
        printf("x[%d],y[%d] ",i,i);
        scanf("%f%f",&x[i],&y[i]);
    }
    printf("\nEnter the value at which to interplot:");
    scanf("%f",&xp);
    p=(xp-x[1])/(x[2]-x[1]);    // p=(xp-x0)/h
    pk=1;
    yp=y[1];                    //interplot started from first position                              
    for(i=1;i<=(n-1);i++){
        for(j=1;j<=(n-i);j++){  // difference table one col at a time
            y[j]=y[j+1]-y[j];   // input data and succesive col destroyed
        }
        pk *= (p-i+1)/i ;       //working out numerator and denominators of coefficient
        yp += pk*y[1];          //summation step y1 always contain next power difference
    }                         
    printf("For the value of x=%6.3f the value is %6.5f\n",xp,yp);
    return 0;
}
