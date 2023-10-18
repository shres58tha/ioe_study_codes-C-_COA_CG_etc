/*
 * C Program to Print Armstrong Number from 1 to 1000
 */
#include <stdio.h>
 
#define block 2  // just change value of letter to select corrosponding block while comparing
//#include<conio.h>
#if (block==1)
///* using if else statement
int main()
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
printf("\n");
return 0;
}

#endif

//*/

#if (block==2)
/*

/**
 * C program to print Armstrong numbers from 1 to n
 */

#include <stdio.h>
#include <math.h>

int main()
{
    int num, lastDigit, digits, sum, i, end;

    /* Input upper limit from user */
    printf("Enter upper limit: ");
    scanf("%d", &end);

    printf("Armstrong number between 1 to %d are: \n", end);

    for(i=1; i<=end; i++)
    {
        sum = 0;

        /* Copy the value of num for processing */
        num = i;

        /* Find total digits in num */
        digits = (int) log10(num) + 1;

        /* Calculate sum of power of digits */
        while(num > 0)
        {
            /* Extract last digit */
            lastDigit = num % 10;

            // Find sum of power of digits
            // Use ceil() function to overcome any rounding errors by pow()
            sum = sum + ceil(pow(lastDigit, digits));

            /* Remove the last digit */
            num = num / 10;
        }

        /* Check for Armstrong number */
        if(i == sum)
        {
            printf("%d, ", i);
        }

    }

    return 0;
}

        #endif
//*/

///*  // using conditioinal operator
