/*
 * C Program to Print Armstrong Number from 1 to 1000
 */
/*
#include <stdio.h>
 
main()
{
    int number, temp, digit1, digit2, digit3;
 
    printf("Print all Armstrong numbers between 1 and 1000:\n");
    number = 001;
    while (number <= 900)
    {
        digit1 = number - ((number / 10) * 10);
        digit2 = (number / 10) - ((number / 100) * 10);
        digit3 = (number / 100) - ((number / 1000) * 10);
        temp = (digit1 * digit1 * digit1) + (digit2 * digit2 * digit2) + (digit3 * digit3 * digit3);
        if (temp == number)
        {
            printf("\n Armstrong no is:%d", temp);
        }
        number++;
    }
}

*/


#include <stdio.h>
//#include <math.h>
int power(int num, int n){
    int pwnum=1;
    for (int i=1;i<=n;i++){
        pwnum*=num;
    }
    return pwnum;
}

int main(){

    int num, orig_num, n=0, rem, val=0;
 
    printf("check if entered number is armstrong: Enter an integer  :");
    scanf("%d",&num);
    orig_num=num;
    
    while (num) {
         num/= 10;
        n++;
    }
    //printf ("\n n:%d",n);  // debuged for value of n

    num=orig_num;

    while (num){
        rem=num%10;
        num/=10;
        val+= power(rem,n);
        //printf("\n val :%d\n",val); //debug line for checking val value
        if (val>orig_num) break;
        }

    if (val==orig_num)
        printf ("\nThe given number is armstrong");
    else 
        printf("\nThe given number is not armstrong");

    printf ("\n\n");
return 0;
}