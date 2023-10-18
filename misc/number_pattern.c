#include <stdio.h>

int main(void) {
    int  num , row, col, sp;
    num=5;
    for (row=0; row<=num;row++){  // gives no of row
        for (sp=row;sp>=1;sp--)
        printf("  ");  // gives spaces before number
        
        for (col=1;col<=num-row;col++) // gives no of col
                printf("%d ",col);  // print no increasing
            
        for (col=num-row-1;col>=1;col--) // gives no of col
                printf("%d ",col);   // print no decreasing
            
        printf("\n"); //new line
        }
    
  return 0;
}
