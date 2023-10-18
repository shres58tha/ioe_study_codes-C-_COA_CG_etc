 
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define sz 5
int main (){
    
    int xyz;
    printf("enter xyz:0");scanf("%d",&xyz);
    
    int *n[xyz];
    
    for (int i=0;i<xyz; i+=1){
        
        printf ("pointer %d = %p \n",i,n[i]);
        
    }
    for (int i=0;i<xyz;i++){
        n[i]=(int *)malloc(sizeof(int)*sz);
        *n[i]=i;
    }
    for (int i=0;i<xyz; i+=1){
        
        printf ("pointer %d = %p \n",*n[i],n[i]);
        
    }
   
    return 1;
    
}
