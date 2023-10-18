#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main ()
{
	int gdriver=DETECT,gmode;
	int x2, y2,x1,y1;
	initgraph(&gdriver,&gmode, "C:\\turboc3\\bgi");
	clrscr();
	printf ("Enter value of (x1,y1) & (x2,y2):");
	scanf ("%d %d %d %d",&x1,&x2, &x2,y2);
	line(x1,y1,x2,y2);
	getch();
}



