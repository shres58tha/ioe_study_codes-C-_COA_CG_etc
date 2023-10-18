/*(A simple method to find whether a number is triangular or not in C). using recursion
 * 
 i *nst*ead of using formula n*(n+1)/2,suppose a variable c=0 and add i to it.check whether it is equal to given number.if yes print it’s triangular.if it is not,then value of i becomes equal to given number hence print it is not a triangular number.
 
 Here’s the code.
 */

#include <stdio.h>

// just change value of letter to select corrosponding block while comparing
#define block 1 // recursive
#if (block==1)

int triangular(int n){
    static int i=0;
    int p;
    if (n==0)
        return 1;
    else if (n<0)
        return 0;
    else {
        //i++;
        p=triangular(n- ++i);
        return p;
    }
}

void main(){
    int n,i,c=0;
    printf("\nenter a number to check triangularity : ");
    scanf("%d",&n);
    
    if(triangular(n)==1)
        printf("the number is triangular\n");
    else 
        printf("the number is not triangular\n");
    
}
#endif



#if (block==2) // simple

#endif

/*
void main(){
    int n,i,c=0;
    printf("\n eneter a number to check triangularity : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        c=c+i;
            if(c==n){
            printf("the number is triangular\n");
            break;
            }
        }
    if(i==n){
        printf("the number is not triangular\n");
        }
}
*/
