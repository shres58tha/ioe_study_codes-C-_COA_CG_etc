#include<stdio.h>
int main(){
	int m,n;
	 int a[100][100],b[100][100],i,j,sum[100][100];
	 printf("enter the dimension of matrix");
	 scanf("%d %d",&m,&n);
	 printf("\n the dimension of matrix is:%d %d",m,n);
	 printf("\n  enter the first matrix:");
	 for(i=0;i<m;i++){
	 	for(j=0;j<n;j++){
	 		printf("\nenter element:[%d][%d]",i+1,j+1);
	 		scanf("%d",&a[m][n]);
		 }
	 }
	 printf("\nenter second matrix:");
	 for(i=0;i<m;i++){
	 	for(j=0;j<n;j++){
	 		printf("\nenter element:[%d][%d]",i+1,j+1);
	 		scanf("%d",&b[m][n]);
		 }
	 }
	 for(i=0;i<m;i++){
	 	for(j=0;j<n;j++){
	 		 sum[i][j]=a[i][j]+b[i][j];
		 }
	 }
	 printf("\nthe sum of the matrix is:\n");
	 for(i=0;i<m;i++){
	 	for(j=0;j<n;j++){
	 		printf("%d\t",sum[i][j]);
		 }
		 printf("\n");
	 }

	 return 0;
}