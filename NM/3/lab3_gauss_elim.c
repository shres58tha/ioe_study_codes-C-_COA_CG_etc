#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define   SIZE   100
void display_aug( float array[][SIZE+1], int row , int col){
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
    float aug[SIZE][SIZE+1], x[SIZE], ratio;
    int aug_mat_size;
    printf("Enter number of variables : ");
    scanf("%d", &aug_mat_size);
    //Reading Augmented Matrix
      for(int row=1;row<=aug_mat_size;row++){
        for(int col=1;col<=aug_mat_size+1;col++){
            printf("aug[%d][%d] = ",row,col);
            scanf("%f", &aug[row][col]);
        }
    }
    display_aug( aug,  aug_mat_size, aug_mat_size+1);
    //solving aug. matrix by gauss elimination
    for(int op=1;op<=aug_mat_size-1;op++){ //performing R(op+1) = R(op)*a[op,op]/a[row,op
        if(aug[op][op] == 0.0){
            printf(" Error:DIV by ZERO!");
            exit(0);
        }
        for(int row=op+1;row<=aug_mat_size;row++){
            float ratio=aug[row][op]/aug[op][op];
            for(int col =op;col<=aug_mat_size+1;col++){//col=op+1 will ignore or wont make the lower diagnol 0
                aug[row][col]=aug[row][col]- ratio*aug[op][col];
            }
            printf("\niter op %d ; row %d ", op, row);
            display_aug( aug, aug_mat_size, aug_mat_size+1);
        }
    }
    // Back Subsitution
    x[aug_mat_size]=aug[aug_mat_size][aug_mat_size+1]/aug[aug_mat_size][aug_mat_size];
    for(int row=aug_mat_size-1;row>=1;row--){
        int sum= 0;
        for(int col =row+1;col<=aug_mat_size;col++){
            sum =sum + aug[row][col]*x[col];
        }
        x[row]=1/aug[row][row]*(aug[row][aug_mat_size+1]-sum);
    }
    // Displaying Solution
    printf("\nSolution:\n");
    for(int row=1;row<=aug_mat_size;row++){
        printf("x[%d] = %7.3f\n",row, x[row]);
    }
    return(0);
}
