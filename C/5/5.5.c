// program to cfind the factorial of a number using recursive function
#include<stdio.h>
#include <stdlib.h>
//#include<math.h>

#define block 1 // just change value of letter to select corrosponding block while comparing

#if (block==1)

 long long int fac( int n){
        //  if(num >524287) {printf("mem overflow max decimal no = 524287 \n"); exit (1);}
        while (n){
        if (n==0) return 1;
        else return (n*fac(n-1));
        }
}

int main(){
    int num;
    //long long int  bin_num=0;
	printf(" \n\n Enter a number to find factorial:");
	scanf("%d",&num);
	printf("\n factorial of %d is  %lld \n",num,fac(num));  // ask how to print more than 512 dec equivalent
	printf ("\n\n");

}
#endif

//*/

#if (block==2) // refined
l
}
#endif
//*/

#if (block==3) // alternative logic


#endif
