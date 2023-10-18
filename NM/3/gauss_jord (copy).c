#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
void display_aug( float array[SIZE][SIZE+1], int row , int col){
    printf("\n augumented matrix \n");
    for(int i=1;i<=row;i++){
        for(int  row=1; row<=col; row++){
            printf(" %7.3f ", array[i][ row]);
        }
        printf("\n");
    }
    return ;
} 
int main(){
    float a[SIZE][SIZE+1], x[SIZE], ratio;
    int i, row,k,n;
    printf("Enter number of unknowns: "); 
    scanf("%d", &n);
    printf("Enter coefficients of Augmented Matrix:\n");
    for(i=1;i<=n;i++){  //row
        for( row=1; row<=n+1; row++){ //col
            printf("a[%d][%d] = ",i, row);
            scanf("%f", &a[i][ row]);
        }
    }
    // Applying Gauss Jordan Elimination
    for(i=1;i<=n;i++){  // R1
        if(a[i][i] == 0.0){
            printf(" Error:DIV by ZERO!");
            exit(0);
        }
        for( row=1; row<=n; row++){ // select R2  opreate all rows
            if(i!= row) {
                ratio = a[ row][i]/a[i][i];
                for(k=1;k<=n+1;k++){ // OPERATING R2--> R2-A21/A11*R2 opreate all rows
                    a[ row][k] = a[ row][k] - ratio*a[i][k];
                }
                printf("\noperating  op %d ; row %d ", i,  row);
                display_aug(a,n,n+1);
            }
        }
    }
    // Obtaining Solution
    for(i=1;i<=n;i++){
        x[i] = a[i][n+1]/a[i][i];
        a[i][n+1]=x[i];   // for putting aug matrix in proper form
        a[i][i]=1;        // for putting aug matrix in proper form
        printf("\nobtaining soln op %d ; row %d ", i, i);
        display_aug(a,n,n+1);
    }
    // Displaying Solution
    printf("\nSolution:\n");
    for(i=1;i<=n;i++) {
        printf("x[%d] = %7.3f\n",i, x[i]);
    }
    return(0);
}
