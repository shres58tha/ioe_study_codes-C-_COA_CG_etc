#include<stdio.h>
#include <conio.h>
#include<graphics.h>

int main ()
{
	int gdriver=DETECT,gmode;
	int x2, y2,x1,y1;
	printf ("Enter value of (x1,y1) & (x2,y2):");
	scanf ("%d %d %d %d",&x1,&y1, &x2,&y2);
	clrscr();
	initgraph(&gdriver,&gmode,"C:\\turboc3\\bgi");
	printf(" point %d %d %d %d \n",x1,y1, x2,y2);
	line(x1,y1,x2,y2);
	getch();
	closegraph();
    return 0;
}



