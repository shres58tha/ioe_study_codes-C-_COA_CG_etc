 
#include <stdio.h>
#define MAX 5
int main (){
    
    int number[MAX]={2,3,5,4,10};
    int i,sum=0;
    float average;
    for (i=0;i<MAX; i+=1){
        
        printf ("Number %d=%3.2d\n",i,number[i]);
        sum+=*number+i;
    };
    average=(float)sum/MAX;
    printf("%06.2f\n",average);
    return 1;
    
}
