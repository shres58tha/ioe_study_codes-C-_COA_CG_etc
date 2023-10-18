// program to intialize no in array 8 and then print sum and avg of all the elements
#include<stdio.h>
#include <stdlib.h>
//#include<math.h>

#define block 1 // just change value of letter to select corrosponding block while comparing

#if (block==1)

 int main(){
    float num[8],sum=0,avg;  // array initization
    int i;
    for (i=0;i<8;i++){
    printf("enter the %d number :",i+1);
    scanf ("%f",&num[i]);
    }
    for (i=0;i<8;i++) sum+=num[i];
    printf("the sum is %f and avg is %f",sum,sum/8);
    printf("\n");
return 0;
}


#endif



#if (block==2) // refined

#endif


#if (block==3) // alternative logic


#endif
