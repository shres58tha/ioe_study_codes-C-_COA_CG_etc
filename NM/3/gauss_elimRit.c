#include<stdio.h>
#include<stdlib.h>
void display_aug( float array[][100], int row , int col){
    printf("\n augumented matrix \n");
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            printf(" %7.3f ", array[i][j]);
        }
        printf("\n");
    }
    return ;
}
int main(){
    float sum,a[100][100],x[100];
    int n,row,op,col;
    printf("Enter number of unknown :");
    scanf("%d",&n);
    for(row=1;row<=n;row++){
        for(col=1;col<=n+1;col++){
            printf("The matrix[%d][%d]:",row,col);
            scanf("%f",&a[row][col]);
        }
    }
    display_aug(a,n,n+1);
    //gauss elimination
    for(op=1;op<=n-1;op++){
        if(a[op][op]==0){
            printf("\ndivide by zero\n");
            exit(0);
        }
        for(row=op+1;row<=n;row++){
            for(col=op+1;col<=n+1;col++){
                a[row][col]=a[row][col]-(a[row][op]/a[op][op])*a[op][col];
            }
        }
        display_aug(a,n,n+1);
    }
    //bck subst
    x[n]=a[n][n+1]/a[n][n];
    for(row=n-1;row>=1;row--){
        sum= 0;
        for(col =row+1;col<=n;col++){
            sum =sum + a[row][col]*x[col];
        }
        x[row]=1/a[row][row]*(a[row][n+1]-sum);
    }
    //display result
    printf("\nSolution:\n");
    for(row=1;row<=n;row++){
        printf("x[%d]=  %7.3f \n",row,x[row]);
    }
    return 0;
}
