#include <stdio.h>
void max_min(int num[], int sz){
    int max, min;
    max=num[0];
    min=num[0];
    for (int i=1;i<sz;i++){ // do not need to check 1st element
        if (max<num[i])
            max=num[i];
        
        if (min>num[i])
            min=num[i];
    }
    printf ("\n max = %d \n min= %d \n", max,min);
}


int main(void) {
    int num[100], sz ;
    printf ("enter size of the list n <99 :");
    scanf("%d",&sz);
    for (int i=0; i<sz;i++){  //getting element of matrix
        printf(" enter list %d :  ",i+1);  
        scanf("%d",&num[i]);
    }
    max_min(num,sz);
    
  return 0;
}
