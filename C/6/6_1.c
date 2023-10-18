// program to intialize no in array 10 and then print  all the elements
#include<stdio.h>

 int main(){
    float num[10],sum=0,avg;  // array initization
    int i;
    for (i=0;i<10;i++){
    printf("enter the %d number :",i+1);
    scanf ("%f",&num[i]);
    }
    for (i=0;i<10;i++){
    printf(" %f\t",num[i]);
    }
    printf("\n");
return 0;
}
