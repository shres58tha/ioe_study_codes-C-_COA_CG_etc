/*(A simple method to find whether a number is factorial or not in C). using recursion*/

#include <stdio.h>

// just change value of letter to select corrosponding block while comparing
#define block 1 // recursive
#if (block==1)

int fac_check(float n){
    static int i=0;
    float p;
    if (n==1)
        return 1;
    else if (n<1)
        return 0;
    else {
        i++;
        printf (" i = %d p/i %f   p = %f n=%f\n",i,n/i,p,n);
        p=fac_check(n/i);
        return p;
    }
}

void main(){
    int n,i,c=0;
    printf("\nenter a number to check its factoriality : ");
    scanf("%d",&n);
    
    if(fac_check(n)==1)
        printf("the number is factorial\n");
    else 
        printf("the number is not factorial\n");
    
}
#endif



#if (block==2) // simple

#endif

