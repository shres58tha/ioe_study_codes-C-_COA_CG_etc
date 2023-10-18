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
	int i,n,j;
	printf("entert the lower and upper limit");
	scanf("%f %f",&a,&b);
	printf("enter the no of strips");
	scanf("%d",&n);
	h=(b-a)/n;
	for(i=1;i<n;i=i+2)
	{
		f3=f3+f(a+i*h);
	}
	for(j=2;j<n;j=j+2)
	{
		f4=f4+f(a+j*h);
	}
	I=(h/3)*(f(a)+(4*f3)+(2*f4)+f(b));
	printf("required integration =%f",I);
	getch();
	return(0);
}

