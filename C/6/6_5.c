// program to initialize square matrix and sort each row so that  the min no is in diagonal elements
#include<stdio.h>
#include <stdlib.h>
//#include<math.h>

#define block 1 // just change value of letter to select corrosponding block while comparing

#if (block==1)
int main(){
    int num[100][100],min;  // max list size 100
    int n, i, j;
    printf("enter the size of square matrix");
    scanf("%d",&n);
    printf(" \n enter the numbers for %d square matrix : \n",n);
    for (i=0; i<n; i++){
        for (j=0;j<n;j++){
            printf("enter a num for pos %d %d: ", i, j);
            scanf ("%d",&num[i][j]);
            }
        }
        
    min=num[0][0];
    for (i=0; i<n; i++){        // finding the min no in the matrix
        for (j=0; j<n;j++){  
            if (min>num[i][i])
            min=num[i][i];
            }
        }
    for (i=0; i<n; i++)
          num[i][i]=min;
    printf("pinting matrix with min val in diagonal\n");
    for (i=0; i<n; i++){
        for (j=0;j<n;j++) {
        printf("\t%d",num[i][j]);    
        }
        printf("\n");
    }
    

return 0;
}


#endif



#if (block==2) // refined

#endif


#if (block==3) // alternative logic


#endif
