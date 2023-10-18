// program to check oddess or eveness of the entered number
// two alternate blocks can be switched on off using or removing // just in front of /*
#include<stdio.h>

#define block 2  // just change value of letter to select corrosponding block while comparing
//#include<conio.h>

#if (block==1)
///* using if else statement
int main(){
	int a;
	printf("\n\t\t\tusing if...else statement operator\n");
	printf(" \n\nEnter a number please :");
	scanf("%d",&a);

	if (a%2==0) // checks odd or eveness here using for loop
			printf ("the number is even");
	else
			printf ("the no is odd");

	printf ("\n\n\n");

}
#endif

//*/

#if (block==2)

///*  // using conditional operator
int main(){
	int a;
	printf("\n\t\t\tusing conditional operator\n");
	printf(" \n\nEnter a number please :");
	scanf("%d",&a);

	(a%2==0)?printf ("it is even"):printf("it is odd"); // conditional operator case ? statement : statement ;     // only one terminator required
	printf ("\n\n\n");
	return 0;

}
#endif
//*/

///*  // using conditioinal operator
