// program to check the given number is armstrong or not
// defination of armstromng no is sum of nth power of all the digits digit is equal to that of the number where n is number digits in that number
#include <stdio.h>
#include <math.h>

int pw (int digit, int n){
    int ret_val=1;
    //printf ("\n in pw funct digit    %d   n %d", digit, n);
    for (;n;n--) ret_val*=digit; // raise power of the digit n times till n becomes 0

    //printf ("\n ret_val   %d", ret_val);
return (ret_val); // needs to be last line in the function.
}


int main()
{
    int num, temp, digit, i, sum=0, n=0 ; // n gives no of digits in number so is initialized to zero

    printf("Enter a number : "); // Input number from user
    scanf("%d", &num);
    temp=num;  // initiliaze temp to perserve value of numb
    while (temp){
    temp/=10; // reduce the val by 10 times
    n++;
    } // run loop until temp is 0
                //printf("n  %d",n);
    temp=num;   //reset value of the temp back to number
    for (i=1;i<=n;i++){
    digit=temp%10;
                //printf ("\n digit %d",digit);
    temp/=10;   // extract the digits 7
    sum+=pw(digit,n); // accumulate the powers of sum here
                //printf("  sum %d   \n ",sum);
    }
   if (sum==num) printf("the entered no is armstrong \n");
   else printf("the entered no is not armstrong \n");

return 0;
}
