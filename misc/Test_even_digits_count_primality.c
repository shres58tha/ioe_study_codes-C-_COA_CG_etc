#include <stdio.h>

int prime(int n){
    for (int i=2;i<=n/2;i++ ){
        if (n%i==0)
            return 0;
    }
    return 1;
}
int main()
{
   int num, temp, digit, count=0,flag;
   printf("enter an integer number :");
   scanf("%d",&num);
   temp=num;//temp has the value of num
   while (temp){ // extract digit, if its even 
      digit=temp%10;
      temp/=10;
      if (digit%2==0) 
          count++;
    }
   flag=prime(count);
   if (flag)
        printf ("\n the count of even digits in entered number %d is:%d is prime\n",num, count);
    else
        printf ("\n the count of even digits in entered number %d is:%d is not prime \n",num, count);
    return 0;
}
