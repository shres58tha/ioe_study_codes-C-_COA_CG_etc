/*(A simple method to find hcf and lcm using recursion*/

#include <stdio.h>

// just change value of letter to select corrosponding block while comparing
#define block 1 // recursive
#if (block==1)

int hcf(int a, int b){
    if (b==0)
        return a;
    else {
        //printf( "a=%d  b=%d  b mod a=%d \n",a,b,a%b);
        return hcf(b,a%b);
    }
    
}

void main(){
    int a,b,h;
    printf("\nenter a numbers to find hcf and lcm: ");
    scanf("%d %d",&a,&b);
    
    h=hcf(a,b);
    printf("the hcf is %d and lcm is %d \n",h,a*b/h);
    
}
#endif



#if (block==2) // simple

#endif

