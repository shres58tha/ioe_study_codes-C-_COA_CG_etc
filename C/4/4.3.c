
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

#if (block==3)

// A tail recursive function to
// calculate n th fibnacci number
//int fib(int n, int a=0, int b=1) //equally valid
int fib(int n, int a , int b)
{
//printf("\na=%d", a);
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fib(n - 1, b, a + b);
}

// Driver Code
int main()
{
    int num, fib_num;
    int a = 0, b = 1; // if alternate call is done no need to declare these here
    printf("\n enter number of terms : ");
    scanf ("%d",&num);
    for (int i=0;i<num;i++){
        fib_num=fib(i,a,b);  //  fib_num=fib(i); //alternate form
        if ((float)fib_num<0)  {printf("\n int. overflow, program exited"); break;} // upgraded to make checking overflow feaseable
        printf("\n term %d :%d",i,fib_num);
        //if (fib_num>=1836311903)  {printf("\nint. overflow, program exited"); break;}
    }
    printf("\n");
}

#endif

