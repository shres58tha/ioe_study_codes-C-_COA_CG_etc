#include<stdio.h>
#include<stdlib.h>
int main(){
    float sum,a[100][100],x[100];
    int n,row,op,col;
    printf("Enter number of unknowns :");
    scanf("%d",&n);
    for(row=1;row<=n;row++){
        for(col=1;col<=n+1;col++){
            printf("matrix[%d][%d]:",row,col);
            scanf("%f",&a[row][col]);
        }
    }
    //gauss jordan method
    for(op=1;op<=n;op++){  // R1
        for( row=1; row<=n; row++){ // select R2  opreate all rows
            if(op!= row) {
                float ratio = a[row][op]/a[op][op];
                for( col=1;col<=n+1;col++){ // OPERATING R2--> R2-A21/A11*R2 opreate all rows
                    a[row][col] = a[row][col] - ratio*a[op][col];
                }
            }
        }
    }
    // Obtaining Solution
    for(row=1;row<=n;row++){
        x[row] = a[row][n+1]/a[row][row];
        a[row][n+1]=x[row];   // for putting aug matrix in proper form
        a[row][row]=1;        // for putting aug matrix in proper form
    }
    // Displaying Solution
    printf("\nSolution:\n");
    for(row=1;row<=n;row++) {
        printf("x[%d] = %7.3f\n",row, x[row]);
    }
    return(0);
}

