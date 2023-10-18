/*(A simple method to find fib using recursion*/
// just change value of letter to select corrosponding block while comparing
#define block 2 // recursive
#if (block==2) // simple
/*(A simple method to find fib single recursion*/

#include <stdio.h>
int fastfib(int n1, int n2, int n){
    if (n<=1)
        return n1;
    else 
        //printf ("  %d",n2+n1);
        return fastfib(n2,n2+n1,n-1);
}
int fib(int n){
    int a=0, b=1;
    return fastfib(a,b,n);
}

int check_fib1(int n,int i){
    //static int i=0; //avoided static int by using wrapper dummy function 
    int x;
    x=fib(i);
    printf(" x %d",x);
    if (n==x)
        return 1;
    else if (n<x)
        return 0;
    else { 
        i++;
        return check_fib1(n,i);
    }
}

int check_fib(int n){
    return (check_fib1(n,0));
}
void main(){
    int a,h;
    printf("\nenter a numbers to find fibonacci: ");
    scanf("%d",&a);
    h=fib(a);
    printf("\nthe %d fibonacci is %d \n",a,h);
    
    printf("\nenter a numbers to check  fibonaccity: ");
    scanf("%d",&a);
    if (check_fib(a))// -1 needed due to the fibonacci series having two 1
        printf("\nthe number is fibonachhi\n");
    else 
        printf("\nthe number is not fibonachhi\n");
}
#endif



