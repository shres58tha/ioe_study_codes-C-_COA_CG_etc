#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
   {
   return(1+x*x*x);
   }
int main ()
{
	float a,b,h,I,f3=0;
	int i,n;
	printf("entert the lower and upper limit");
	scanf("%f %f",&a,&b);
	printf("enter the no of strips");
	scanf("%d",&n);
	h=(b-a)/n;
	for(i=1;i<=n-1;i++)
	{
		f3=f3+f(a+i*h);
	}
	I=(h/2)*(f(a)+ 2*f3+f(b));
	printf("required integration =%f",I);
	getch();
	return(0);
}

