//program to swap two numbers with or with out using 3rd variable just remove // before the comment to activate corrosponding block
#include<stdio.h>
//#inlude<conio.h>


///* // without using third variable
int main(){
	int a, b;
	printf(" \n\nEnter two number please :");
	scanf("%d %d",&a,&b);
	printf ("\n the two no are %d and %d in order", a,b);

	a=a+b;   // for eg let a=7 b=5 then a has 7+5 after this step
	b=a-b;	 //here after b has 7+5-5 ie the value of a and a still has 7+5
	a=a-b;	 //here after a has 7+5-7 ie the value if b and a holds the value of b ie swaped


	printf ("\n after swapping without using third variable");
	printf ("\n the two no are %d and %d in rev. order", a,b);
	printf ("\n\n\n");
}
//*/

/* //using  third variable
int main(){
	int a, b,temp;
	printf(" \n\nEnter two number please :");
	scanf("%d %d",&a,&b);
	printf ("\n the two no are %d and %d in order", a,b);
	temp=a;
	a=b;
	b=temp;
	printf ("\n the two no are %d and %d in rev. order", a,b);
	printf ("\n\n\n");
}
//*/
