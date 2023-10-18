//program to check leap year or not

#include <stdio.h>
//#include<conio.h>
int main(){
	int year;
	printf ("enter the year:");
	scanf ("%d",&year);
	if (year%400==0||(year%4==0 &&year%100!=0))   // rem this statement
	printf ("\n\t the year %d is a leap year",year);
	else
	printf("\n\t the year %d is not a  leap year",year);
	return 0;
}



