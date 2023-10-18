#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
void display_aug( float array[SIZE][SIZE+1], int row , int col){
    printf("\n augumented matrix \n");
    for(int  i=1;i<=row;i++){
        for(int  row=1; row<=col; row++){
            printf(" %7.3f ", array[i][ row]);
        }
        printf("\n");
    }
    return ;
} 
int main(){
    float a[SIZE][SIZE+1], x[SIZE], ratio;
    int row,col,op,n;
    printf("Enter number of unknowns: "); 
    scanf("%d", &n);
    printf("Enter coefficients of Augmented Matrix:\n");
    for( row=1;row<=n;row++){  //row
        for( col=1; col<=n+1; col++){ //col
            printf("a[%d][%d] = ",row, col);
            scanf("%f", &a[row][ col]);
        }
    }
    // Applying Gauss Jordan Elimination
    for(op=1;op<=n;op++){  // R1
        if(a[op][op] == 0.0){
            printf(" Error:DIV by ZERO!");
            exit(0);
        }
        for(row=1; row<=n; row++){ // select R2  opreate all rows
            if(op!= row) {
                ratio = a[ row][op]/a[op][op];
                for(col=1;col<=n+1;col++){ // OPERATING R2--> R2-A21/A11*R2 opreate all rows
                    a[ row][col] = a[ row][col] - ratio*a[op][col];
                }
                printf("\noperating  op %d ; row %d ", op,  row);
                display_aug(a,n,n+1);
            }
        }
    }
    // Obtaining Solution
    for(row=1;row<=n;row++){
        x[row] = a[row][n+1]/a[row][row];
        a[row][n+1]=x[row];   // for putting aug matrix in proper form
        a[row][row]=1;        // for putting aug matrix in proper form
        printf("\nobtaining soln op %d ; row %d ", row, row);
        display_aug(a,n,n+1);
    }
    // Displaying Solution
    printf("\nSolution:\n");
    for(row=1;row<=n;row++) {
        printf("x[%d] = %7.3f\n",row, x[row]);
    }
    return(0);
}
