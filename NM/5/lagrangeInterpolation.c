#include<stdio.h>
#define MAXN 100
int main(){
    float x[MAXN], y[MAXN], xp, yp=0, p;
    int n,i,j;
    //Input Section 
    printf("Enter number of data: ");
    scanf(" %d", &n);
    printf("Enter data:\n");
    //getting the values
    for(i=1;i<=n;i++) {
        printf("x[%d],y[%d] ",i,i);
        scanf(" %f %f",&x[i],&y[i]);
    }
    //Lagrange Interpolation 
    char ch='y';
    while(ch=='y'){
        printf("Enter interpolation point: ");
        scanf(" %f",&xp);
        yp=0;
        for(i=1;i<=n;i++){
            p=1;
            for(j=1;j<=n;j++){
                if(i!=j){
                    p = p*(xp - x[j])/(x[i] - x[j]); // doing product (xp-xi)/(xi-xj) where i!=j
                }
            }
            yp = yp + p*y[i];
        }
        printf("Interpolated value at %.3f is %.3f.\n", xp, yp);
        printf("enter y to continue :");
        scanf(" %c",&ch);
    }
}
