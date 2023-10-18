#include<stdio.h>
#include<math.h>
#define SIZE 100
int main(){
    float A[SIZE+2][SIZE+2],X[SIZE+2], err, Z[SIZE+2],E[SIZE+2], Zmax,Emax,temp;
    int A_size, step=0;
    printf("Enter number of variables : ");
    scanf("%d", &A_size);
    //Reading  Matrix
    for(int row=1;row<=A_size;row++){
        for(int col=1;col<=A_size;col++){
            printf("A[%d][%d] = ",row,col);
            scanf("%f", &A[row][col]);
        }
    } 
    // read initial gguess vector X[i]
    for(int row=1; row<=A_size;row++){ 
        printf("X[%d] = ",row);
        scanf("%f", &X[row]);
    }    
    //read stopping criterion
    printf("stopping criterion : ");
    scanf("%f", &err);
    //loop
    do{
        step++;\
        //solving power method
        for(int i=1;i<=A_size;i++){
            Z[i]=0.0;
            // matrix multipication Z=A*X
            for(int j=1;j<=A_size;j++){
                Z[i]=Z[i]+ A[i][j]*X[j]; 
            }
        }
        //extracting abs max val
        Zmax=fabs(Z[1]);
        for (int i=2; i<=A_size;i++){ 
            temp=fabs(Z[i]);
            if(temp>Zmax)
                Zmax=temp;
        }       
        //normalizing
        for( int i=1; i<=A_size; i++){ 
            Z[i]=Z[i]/Zmax;
        }        
        // Display 
        printf("\nSTEP:%d\nEigen Value = %f\nEigen Vector\n[ ",step, Zmax);
        for(int i=1;i<=A_size;i++){ 
            printf("%f\t", Z[i]);
        }
        printf(" ]T\n");        
        //calculation of error
        for (int i=1; i<=A_size;i++){ 
            E[i]=0;
            E[i]= fabs(Z[i])-fabs(X[i]);
        }
        //extracting abs max val
        Emax=fabs(E[1]);
        for (int i=2; i<=A_size;i++){ 
            float temp=fabs(E[i]);
            if(temp > E[i])
                Emax=temp;
        }        
        printf("Emax=%f\n",Emax); 
        // Replacing eigen vector
        for(int i=1; i<=A_size;i++){ 
            X[i]=Z[i];
        }
    }while(Emax>err);    
    // Displaying Solution
    printf("\nSolution:\n Eigen Value: %f\n Eigen Vector\n",Zmax); 
    for(int i=1;i<=A_size;i++){
        printf("x[%d] = %7.6f\n",i, Z[i]);
    }
    return(0);
}
