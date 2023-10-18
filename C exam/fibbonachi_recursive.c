/*(A simple method to find fib using recursion*/
// just change value of letter to select corrosponding block while comparing
#define block 1 // recursive
#if (block==1)
#include <stdio.h>
int fib(int n){
    if (n==1)
        return 0;
    else if (n==2)
        return 1;
    else
        return fib(n-1)+fib(n-2);
}

void main(){
    int a,h;
    printf("\nenter a numbers to find fibonacci: ");
    scanf("%d",&a);
    h=fib(a);
    printf("the %d fibonacci is %d \n",a,h);
}
#endif

#if (block==2) // simple
/*(A simple method to find fib single recursion*/

#include <stdio.h>
int fastfib(int n1, int n2, int n){
    if (n<=1)
        return n1;
    else 
        printf ("  %d",n2+n1);
        return fastfib(n2,n2+n1,n-1);
}
int fib(int n){
    int a=0, b=1;
    return fastfib(a,b,n);
    }

void main(){
    int a,h;
    printf("\nenter a numbers to find fibonacci: ");
    scanf("%d",&a);
    h=fib(a);
    printf("\nthe %d fibonacci is %d \n",a,h);
}
#endif



#if (block==3) // simple
/*(A simple method to find fib single recursion*/

#include <stdio.h>
int fib(int n){
    static int a=0, b=1;
    int tmp;
    if (n==0)
        return a;
    else {
        tmp=a;
        a=b;
        b=a+b;
        fib(n-1); // using it just as n--  whats the point
    }
    
}

void main(){
    int a,h;
    printf("\nenter a numbers to find fibonacci: ");
    scanf("%d",&a);
    h=fib(a);
    printf("the %d fibonacci is %d \n",a,h);
}
#endif


