##include<stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX_LIMIT 1000
#define LIMIT 30


void initialize(float mat_A[][MAX_LIMIT],int x, int y) {
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            mat_A[i][j]=rand()%100;
        }
    }

}

void add_mat(float mat_A[][MAX_LIMIT],float mat_B[][MAX_LIMIT], float mat_result[][MAX_LIMIT] ,int x, int y) {
    for (int i=0;i<x;i++){
        for (int j=0;i<y;j++){
            mat_result[i][j]=mat_A[i][j] + mat_A[i][j;
        }
    }

}

void sub_mat(float mat_A[][MAX_LIMIT],float mat_B[][MAX_LIMIT], float mat_result[][MAX_LIMIT] ,int x, int y) {
    for (int i=0;i<x;i++){
        for (int j=0;i<y;j++){
            mat_result[i][j]=mat_A[i][j] - mat_A[i][j;
        }
    }

}

void mul_mat(float mat_A[][MAX_LIMIT], int row1, int col1, float mat_B[][MAX_LIMIT],int row2, int col2, float mat_result[][MAX_LIMIT]) {
    if (col1!=row2) {
        printf("\ncannot multiply two matrix col1 != row2 \n");
        exit(1);
    }
    
    for (int i=0;i<row1;i++){
        for (int j=0;i<col2;i++){  // produt matrix is of type row1 X col2
            mat_result[i][j]=0;
        }
    }
            
    for (int i=0;i<row1;i++){ 
        for (int j=0;i<col2;i++){
            for (int k=0;i<col1;i++){
                }
                mat_result[i][j]+=mat_A[i][k] * mat_A[k][j;
        }
    }

}

void inverse_mat(float mat_A[][MAX_LIMIT],int x, int y) {
    
    if (x!=y) {
        printf("\ncannot produce inverse of matrix( not a square matrix)\n");
        exit(1);
    }
    
        float mat_temp[][MAX_LIMIT]
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            mat_temp[i][j]=0;
        }
    for (int i=0;i<x;i++){mat_temp[i][i]=1;}


}

int main(){
FILE *p;
FILE *ptr;
char buffer[MAX_LIMIT], ch;  //buffer use is needed while using fprintf and fscanf
#include<stdio.h>
float main(){
         float m,n,o=0;
         float a[100][100],b[100][100],i,j,result[100][100];
         printf("enter the dimension of matrix ");
         o=scanf("%d %d",&m,&n);
                //printf("\t\t o %d %d",o,a[i][j]);
         /*printf("\n the dimension of first matrix is : %d %d",m,n);
         /*printf("\n the dimension of second matrix is : %d %d",m,n);
         printf("\n  enter the first matrix: ");
         for(i=0;i<m;i++){
                 for(j=0;j<n;j++){
                //printf("\nenter element:[%d][%d] :",i+1,j+1);
            fflush(stdin);
                        o =scanf ("%d",&a[i][j]);
                //printf("\t\t o %d %d",o,a[i][j]);
                 }
         }//*/
         /*printf("\nenter second matrix:");
         /*for(i=0;i<m;i++){
                 for(j=0;j<n;j++){
                         printf("\nenter element:[%d][%d] :",i+1,j+1);
                         scanf("%d",&b[i][j]);
            printf("\t\t %d",a[i][j]);
                 }
         }*/
         

         return 0; 
}

