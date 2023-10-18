
// here is used to // is used to comment out block of code statement by adding or removing //
// max call n=40 program ran with run time ~ 10 in seconds for 50 it took long time may beout of mem it can allocate
// not an efficient way to generate fibbonacci series but it does demonstrate recursion to fullest extent with its
// limitation as it is very memory intensive n^2 recursive call per n the number
#include <stdio.h>
#define block 3

                    //1 for pure doubly recursive function
                    //2 using for loop  when n=40 took 2s to return value
                    //3 as modified teacher's version with just n recursive call per determination of nth number display in function
                    //4 as shown by teacher with just n recursive call per determination of nth number display in function
#if (block == 1)
double fib(int n){
    if (n==0)return 0;
    else if (n==1) return 1;
    else return (fib(n-1)+fib(n-2));
}
int main() {
    int n;
    printf ("enter an nth term for Fibonacci: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        printf("  %.0f",fib(i));
    printf("\n");
}
 // first complete block of code
#endif
///*    // second block using for loop  when n=40 took 2s to return value
#if (block == 2)
int main() {
    int i, n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return 0;
}
#endif
// third block as modified teacher's version with just n recursive call per determination of nth number display in function
// function disp_fib_series displays fib series using recursion n=40 took ~ 2 s
#if (block == 3)
void disp_fib_series(int n){
    static int n1=0,n2=1;   // need static as it should not be reintialized each disp_fib_series call
                            //all debug lines were there to realize this :(
                            // still has a trouble if disp_fib_series is called again form main :(
    int temp;
    //  printf ("value of n  =%d  n1 =%d  n2=%d \n",n,n1,n2);
        if (n<=0) return;
        else {
            printf ("%d\t",n1);
            temp=n1;    // store value of n1 as it will be changed next step
            n1=n2;      // put value of n2 in n1; where n2 is 2nd term ( n+1)term in series
            //printf ("n1 %d n2 %d\n",n1,n2);
            n2 +=temp;  //increment n2 by original value in n1 3rd term or   (n+2)term in series
            disp_fib_series(n-1);
        }

}



int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    disp_fib_series(n);
    return 0;
}
//*/
#endif


// fourth block as shown by teacher with just n recursive call per determination of nth number display in function

#if (block==4)
// function disp_fib_series displays fib series using recursion n=40 took ~ 2.5 s
void disp_fib_series(int n1, int n2, int n){
// takes n th term, n+1 th term and no of term as aruument
    int temp;
    //  printf ("value of n  =%d  n1 =%d  n2=%d \n",n,n1,n2);
    ///*
        if (n<=0) return;
        else {
            printf ("%d\t",n1);
            temp=n1;    // store value of n1 as it will be changed next step
            n1=n2;      // put value of n2 in n1; where n2 is 2nd term ( n+1)term in series
            //printf ("n1 %d n2 %d\n",n1,n2);
            n2 +=temp;  //increment n2 by original value in n1 3rd term or   (n+2)term in series
            disp_fib_series(n1,n2,n-1); // takes n th term, n+1 th term and no of term as aruument
            // disp_fib_series(n2,n2+n1,n-1); // equivalent code as above
            
        }
        //*/
}

int main() {
    int n1=0,n2=1, n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    disp_fib_series(n1,n2,n);
    return 0;
}
#endif

#if (block==5)
/*C program to print fibonacii series till N terms.*/

//function to print fibonacii series
void getFibonacii(int a,int b, int n)
{
    int sum;
    if(n>0)
    {
        sum=a+b;
        printf("%d ",sum);
        a=b;
        b=sum;
        getFibonacii(a,b,n-1);
    }
}
int main()
{
    int a,b,sum,n;
    int i;

    a=0;        //first term
    b=1;        //second term

    printf("Enter total number of terms: ");
    scanf("%d",&n);

    printf("Fibonacii series is : ");
    //print a and b as first and second terms of series
    printf("%d\t%d\t",a,b);
    //call function with (n-2) terms
    getFibonacii(a,b,n-2);
    printf("\n");
    return 0;
}
#endif
