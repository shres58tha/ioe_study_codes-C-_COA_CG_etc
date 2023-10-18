#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x, float y)
{
	return(3*x*x+1+0*y);
}
int main()
{
	float x,y,h,n,xp,m1,m2,m3,m4;
	int i;
	printf(" enter the initial value of x and y\n");
	scanf("%f %f",&x,&y);
	printf(" enter the step size and value of xp");
	scanf("%f %f",&h,&xp);
	n=(xp-x)/h;
	for(i=1;i<=n;i++)
	{
		m1=f(x,y);
		m2=f(x+h/2,y+h/2*m1);
		m3=f(x+h/2,y+h/2*m2);
		m4=f(x+h,y+h*m1);
		y=y+(h*(m1+2*m2+2*m3+m4)/6);
		x=x+h;
	}
	printf(" for x=%f,y=%f",x,y);
	getch();
	return(0);
}
