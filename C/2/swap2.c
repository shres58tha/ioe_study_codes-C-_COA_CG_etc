#include<stdio.h>
//#include<conio.h>
// #include<math.h> // not needed

int main(){
	int a, b,temp;
	printf(" \n\nEnter two number please :");
	scanf("%d %d",&a,&b);
	printf ("\n the two no are %d and %d in order", a,b);
	temp=a;
	a=b;
	b=temp;
	printf ("\n the two no are %d and %d in order", a,b);
	printf ("\n\n\n");
}
