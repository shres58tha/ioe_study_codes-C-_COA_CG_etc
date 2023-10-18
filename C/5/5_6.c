// program to generate fibonnacci no  of the entered number
#include<stdio.h>
#include <stdlib.h>
//#include<math.h>

#define block 1 // just change value of letter to select corrosponding block while comparing

#if (block==1)

 long long int fib(int n, long long int a, long long int  b){   // initialize a and b are intial terms need to provide those in the function call
        if(n>=93) {printf("\n\n mem overflow max term = 93 \n"); exit (1);}
        if (n==0) return a;
        else {
        //printf("\nval of a =%d b = %d",a,b);
        return fib ( (n-1), b, a+b);} // put a=b and b=a+b  ie increment both to next fibonacci no
        }


int main(){
    int num;
    //long long int  bin_num=0;
	printf(" \n\n Enter a number to find factorial:");
	scanf("%d",&num);
	for (int i=0;i<num;i++)
	printf("\n %d term fibonacci =  %lld",i+1,fib(i,0,1));  // provide intial value of a =0 and b=1 for series
	printf("\n");
return 0;
}
#endif



#if (block==2) // refined

#endif


#if (block==3) // alternative logic


#endif
