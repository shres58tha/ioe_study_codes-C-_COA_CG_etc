// program to transpose  matrix

#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int main(){
    int mat1[100][100], mat2[100][100];\
    int n,m;

    printf(" enter row m and column n of matrix");
    scanf ("%d %d",&m,&n);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
        printf ("enter the postion mat1[[%d][%d]",i,j);
        scanf("%d"&mat1[i][j]);
        }
    }


    scanf()
