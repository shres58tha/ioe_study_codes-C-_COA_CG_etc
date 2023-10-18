#include<stdio.h>
#define MAX 100
int main(){
    float x[MAX],y[MAX],sumx=0,sumx2=0,sumy=0,sumyx=0,a,b;
    int i,n;
    printf("Enter no of data points: ");
    scanf("%d",&n);
    
    printf("Enter the values:\n");
    for(i=0;i<n;i++){
        printf("Enter x[%d] and y[%d]: ",i,i);
        scanf("%f%f",&x[i],&y[i]);
        
        sumx=sumx+x[i];
        sumx2=sumx2+x[i]*x[i];
        sumy=sumy+y[i];
        sumyx=sumyx+y[i]*x[i];
    }
    //for y=a+bx; sumy  = a*n    + b*sumx   eq i
    //            sumxy = a*sumx + b*sumx2  eq ii
    b=(n*sumyx-sumy*sumx)/(n*sumx2-sumx*sumx);
    a=(sumy-b*sumx)/n;       // back subst value of b in eq 1
    
    printf("\nthe fitted linear eqn is\n\t\ty = %f + %f x\n",a,b);
  
}
