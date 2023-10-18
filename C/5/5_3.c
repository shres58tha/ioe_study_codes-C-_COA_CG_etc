// program to check if entered no is palindrome or not using function
#include<stdio.h>
#include <stdlib.h>
//#include<math.h>

#define block 1  // just change value of letter to select corrosponding block while comparing
#if (block==1)

int plndrm( int num){
    int i=0,rev_num=0,org_num;
    org_num=num;                // save value of num for checking it later
   while (num){
    rev_num=rev_num*10+num%10;  // extract digit and set it on rev order in rev_num
    num/=10;
    }
    if (rev_num==org_num) return 1;
    else return 0;

}

int main(){
    int num1,num2,swp=0;
	printf(" \n\n Enter two number :");
	scanf("%d %d",&num1, &num2);
	if (num1>num2){
	swp=num1;printf("swp = %d \n",swp);
	num1=num2;printf("num2 = %d \n",num1);
	num2=swp;printf("swp = %d \n",swp);
	} // swap no so num1 is < num2
	printf("palindrome no in range %d   %d\n",num1,num2);
	for (int i=num1;i<=num2;i++){
	if(plndrm(i))printf("\n%d",i);
	}
	printf ("\n\n\n");

}
#endif



#if (block==2)


}
#endif
