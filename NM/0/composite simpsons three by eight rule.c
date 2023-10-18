#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
   {
   return(1+x*x*x);
   }
int main ()
{
	float a,b,h,I,I1=0,I2=0;
	int i,n,j;
	printf("entert the lower and upper limit");
	scanf("%f %f",&a,&b);
	printf("enter no of strips");
	scanf("%d",&h);
	h=(b-a)/n;
	for(i=0;i<n;i++)
	{
		if(i%3==0)
		I1=I1+f(a+i*h);
		else
		I2=I2+f(a+i*h);
	}
	I=((3*h/8)*(f(a)+3*I2+2*I1+f(b)));
	printf("required integration =%f",I);
	getch();
	return(0);
}

