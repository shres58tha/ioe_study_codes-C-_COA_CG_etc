#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main ()
{
	int gdriver=DETECT,gmode;
	int x2, y2,x1,y1;
	initgraph(&gdriver,&gmode, "C:\\turboc3\\bgi");
	printf ("Enter diagnols points of (x1,y1) & (x2,y2):");
	scanf ("%d %d %d %d",&x1,&y1, &x2,&y2);
	printf(" hello %d %d %d %d",x1,y1, x2,y2);
	setcolor(BLUE);
	rectangle(x1,y1,x2,y2);
	setbkcolor(RED);
	getch();
	closegraph();
}



