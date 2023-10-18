#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
   {
   return(1+x*x*x);
   }
int main ()
{
	float a,b,h,I;
	printf("entert the lower and upper limit");
	scanf("%f %f",&a,&b);
	h=b-a;
	I=(h/2)*(f(a)+f(b));
	printf("required integration =%f",I);
	getch();
	return(0);
}

