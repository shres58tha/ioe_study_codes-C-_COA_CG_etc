#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
	return(x*x-4);
}
float df(float x)
{
	return(2*x);
}
int main()
{
	float a,x1,e;
	int count=0;
	printf("enter initial guess");
	scanf("%f",&a);

		do{
		x1=a-(f(a)/df(a));
		e=fabs(x1-a);
		a=x1;
		count++;
		printf(" \n no.of iterations -->%d, root=%f",count,x1);
		}
		while(e>0.0001);
		printf(" \n no 0f iterations=%d\n",count);
	
	getch();
	return(0);
}
