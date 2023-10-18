// program to get sum and avg from list of number using pointer arthemetic
#include<stdio.h>
#include <stdlib.h>
#include<time.h> // for random number


#define Sz 50
#define MAX_LIMIT 50
int main(){
time_t t;
srand((unsigned) time(&t));

    int num[MAX_LIMIT];// array
    int ln=MAX_LIMIT;
    float sum=0,avg;
    int *p;



    for( int i = 0 ; i < ln ; i++ )
   {
      num[i] = rand() % 100;
      printf("%d\n", num[i]);
   } // array initialized in normal way
    p=&num[0]; // putting base address of num arrray in int pointer p
    for (int i=0;i<ln;i++) sum+=*(p+i);  // add avlue at address given by pointer *(p+i)  which is equivalent to the p[i]
    avg=sum/ln;
    printf("sum of the array elements is : %.2f \n\t\t avg is :%.3f",sum,avg);

return 0;

}

