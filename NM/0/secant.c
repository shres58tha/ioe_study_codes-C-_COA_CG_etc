#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
	return(x*x-4*x-10);
}
int main()
{
	float a,b,c;
	int count=0;
	printf("enter initial guess");
	scanf("%f %f",&a,&b);

		do{
		c=b-((b-a)/(f(b)-f(a)))*f(b);
		a=b;
		b=c;
		count++;
		printf(" \n no.of iterations -->%d, root=%f",count,c);
		}
		while(fabs(b-a)>0.00001);
		printf("\n the  required solution is =%f \n",c);
		printf(" \n no 0f iterations=%d\n",count);
	
	getch();
	return(0);
}
