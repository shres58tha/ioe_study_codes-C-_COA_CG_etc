#include<stdio.h>
#include<conio.h>
#include<graphics.h>
/*circle)*/
int main ()
{
	int gdriver=DETECT,gmode;
	int x, y, radius;
	printf ("Enter center points of (x,y):");
	scanf ("%d %d",&x,&y);
	printf(" enter radius ");
	scanf("%d",&radius);
	initgraph(&gdriver,&gmode, "C:\\turboc3\\bgi");
	setcolor(RED);
	circle(x,y,radius);
	getch();
	closegraph();
}



