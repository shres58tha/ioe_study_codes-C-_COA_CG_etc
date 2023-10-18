//Midpoint Ellipse Drawing Code
#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
int xc,yc;
float x,y ;
void disp();
void main()
{
	int gd=DETECT,gm;
	int rx,ry;
	float p1,p2;
	clrscr();
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	printf("Enter the center point");
	scanf("%d%d",&xc,&yc);
	printf("Enter the value for Rx and Ry");
	scanf("%d%d",&rx,&ry);
	x=0;
	y=ry;
	disp();
	p1=(ry*ry)-(rx*rx*ry)+(rx*rx)/4;
	while((2.0*ry*ry*x)<=(2.0*rx*rx*y))
		{	x++;
			if(p1<=0)
			p1=p1+(2.0*ry*ry*x)+(ry*ry);
			else
				{	y--;
					p1=p1+(2.0*ry*ry*x)-(2.0*rx*rx*y)+(ry*ry);
				}
			disp();
		}

	p2=(pow(ry,2)*pow(x+0.5,2))+(pow(rx,2)*pow(y-1,2))-(pow(rx,2)*pow(ry,2));
	printf("x=%f y=%f p2=%f",x,y,p2);
	while((y>0))
		{y--;
			if(p2>0)
				p2=p2+(rx*rx)-(2.0*rx*rx*y);
			else
				{x++;
				p2=p2+(2.0*ry*ry*x)-(2.0*rx*rx*y)+(rx*rx);
				}
		disp();
		}
	getch();
	closegraph();
}
void disp()
{
	delay(50);
	putpixel(xc+x,yc+y,4);
	putpixel(xc-x,yc+y,4);
	putpixel(xc+x,yc-y,4);
	putpixel(xc-x,yc-y,4);
  }
