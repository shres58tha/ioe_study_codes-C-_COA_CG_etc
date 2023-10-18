#include<stdio.h>
#define fabs(x) ((x) ? (x) :-(x))
#define SIZE 100
int main(){
    float A[SIZE+2][SIZE+2],X[SIZE+2], err, Z[SIZE+2], Zmax=0,Zold=0,temp;
    int A_size;
    printf("Enter number of variables : ");
    scanf("%d", &A_size);
    for(int row=1;row<=A_size;row++){ //Reading Augmented Matrix
        for(int col=1;col<=A_size;col++){
            printf("A[%d][%d] = ",row,col);
            scanf("%f", &A[row][col]);
        }
    }
    for(int row=1; row<=A_size;row++){ // read initial guess vector X[i]
        printf("X[%d] = ",row);
        scanf("%f", &X[row]);
    }
    printf("stopping criterion : "); //read stopping criterion
    scanf("%f", &err);
    do{
        for(int i=1;i<=A_size;i++){ //solving power method
            Z[i]=0.0;
            for(int j=1;j<=A_size;j++){
                Z[i]=Z[i]+ A[i][j]*X[j]; // matrix multipication Z=A*X
            }
        }
        Zold=Zmax;
        Zmax=fabs(Z[1]);
        for (int i=2; i<=A_size;i++){ //extracting abs max val
            temp=fabs(Z[i]);
            if(temp>Zmax)
                Zmax=temp;
        }    
        for( int i=1; i<=A_size; i++){ //normalizing
            Z[i]=Z[i]/Zmax;
        }
        for(int i=1; i<=A_size;i++){ // Replacing eigen vector
            X[i]=Z[i];
        }
    }while(fabs(Zmax-Zold)>err); 
    printf("\nSolution:\nEigen Vector: %f\n",Zmax); // Displaying Solution
    for(int i=1;i<=A_size;i++){ // Displaying Solution
        printf("x[%d] = %7.6f\n",i, Z[i]);
    }
    return(0);
}
