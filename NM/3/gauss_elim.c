#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define   SIZE   100


void display_aug( float array[SIZE][SIZE+1], int row , int col){
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
	 float a[SIZE][SIZE+1], x[SIZE], ratio;
	 int i,j,k,n;
	 // input matrix size
	 printf("Enter number of unknowns: ");
	 scanf("%d", &n);
	 // input Augmented Matrix
	 for(i=1;i<=n;i++){ //row
		  for(j=1;j<=n+1;j++){  //col
			   printf("a[%d][%d] = ",i,j);
			   scanf("%f", &a[i][j]);
		  }
	 }
	// Applying Gauss Elimination
	 for(i=1;i<=n-1;i++){  // select R1
		  if(a[i][i] == 0.0){
			   printf("Mathematical Error!");
			   exit(0);
		  }
		  for(j=i+1;j<=n;j++){ // R2 select
			   ratio = a[j][i]/a[i][i];
			   for(k=1;k<=n+1;k++){ // OPERATING R2--> R2-A21/A11*R2 //
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
			   display_aug(a,n,n+1);
		  }
	 }
	 // Back Subsitution
	 x[n] = a[n][n+1]/a[n][n];

	 for(i=n-1;i>=1;i--){
		  x[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++){
		  		x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }
	 // Displaying Solution
	 printf("\nSolution:\n");
	 for(i=1;i<=n;i++){
	  	printf("x[%d] = %0.3f\n",i, x[i]);
	 }

	 return(0);
}
