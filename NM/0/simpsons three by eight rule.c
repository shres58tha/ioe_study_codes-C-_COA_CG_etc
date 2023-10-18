#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
   {
   return(1+x*x*x);
   }
int main ()
{
	float a,b,h,I,f3=0,f4=0;
	int i,j;
	printf("entert the lower and upper limit");
	scanf("%f %f",&a,&b);
	h=(b-a)/3;
	I=(h/3)*(f(a)+3*f(a+h)+3*f(a+2*h)+f(b));
	printf("required integration =%f",I);
	getch();
	return(0);
}

