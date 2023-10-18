#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x,float y)
   {
   return(3*x*x*x+1+0*y);
   }
int main()
{
float x,y,y1,h,n,xp;
int i;
printf("enter the initial value x and y \n");
scanf("%f %f",&x,&y);
printf("enter step size & value of xp");
scanf("%f %f",&h,&xp);
n=(xp-x)/h;
 for(i=1;i<=n;i++)
   {
    y1=y+h*f(x,y);
   	x=x+h;
   	y=y1;
    }
printf("for x=%f,y=%f",x,y1);
getch();
return (0);
}
