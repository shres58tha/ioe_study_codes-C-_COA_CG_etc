#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    float a[10][10],x[10],c[10],d=0,temp;
    int n,i,j;
    printf("Enter the order of matrix ? ");
    scanf("%d",&n);
    printf("\nCoefficients of matrix ");
    for(i=0;i<n;i++)    {
        for(j=0;j<n;j++){
            printf("%d %d :",i,j);
            scanf("%f",&a[i][j]);
        }
    }
    printf("Enter your starting vector ? ");
    for(i=0;i<n;i++)
    scanf("%f",&x[i]);
    do    {
        for(i=0;i<n;i++){
            c[i]=0;
            for(j=0;j<n;j++)
                c[i]+=a[i][j]*x[j];
        }
        for(i=0;i<n;i++)
            x[i]=c[i];
        temp=d;
        d=0;
        for(i=0;i<n;i++){
            if(fabs(x[i])>fabs(d))
                d=x[i];
        }
        for(i=0;i<n;i++)
            x[i]/=d;
    }while(fabs(d-temp)>0.00001);
    printf("Eigen value is : %f\n",d);
    printf("Eigenvector is: ");
    for(i=0;i<n;i++)
        printf("\n%f",x[i]);
    return 0;
}
