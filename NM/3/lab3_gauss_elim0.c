#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define   SIZE   100

int main(){
	 float a[SIZE][SIZE], x[SIZE], ratio;
	 int i,j,k,n,sum;

     printf("Enter number of variables : ");
	 scanf("%d", &n);
	 //Reading Augmented Matrix
	 for(i=1;i<=n;i++){
            for(j=1;j<=n+1;j++){
                    printf("a[%d][%d] = ",i,j);
                    scanf("%f", &a[i][j]);
		  }
	 }
	 //solving aug. matrix by gauss elimination
	 for(k=1;k<=n-1;k++){

		  for(i=k+1;i<=n;k++){

			   ratio = a[i][k]/a[k][k];

			   for(j=k+1; k<=n+1; j++){
			  		a[i][j] = a[i][j] - ratio*a[k][j];
			   }
		  }
	 }
	// Back Subsitution
     x[n] = a[n][n+1]/a[n][n];
	 for(k=n-1;k>=1;k--){
		  sum =0;
          for(j=k+1;j<=n;j++){
		  		sum = sum + a[k][j]*x[j];
		  }
		  x[k] =1/(a[k][k])*(a[k][n+1]-sum);
	 }

	 // Displaying Solution
	 printf("\nSolution:\n");
	 for(k=1;k<=n;k++){
	  	printf("x[%d] = %0.3f\n",i, x[k]);
	 }
return(0);
}
