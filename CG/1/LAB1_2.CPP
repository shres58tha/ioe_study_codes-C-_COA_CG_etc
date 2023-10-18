#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main ()
{
	int gdriver=DETECT,gmode;
	int x2, y2,x1,y1;
	printf ("Enter diagnols points of (x1,y1) & (x2,y2):");
	scanf ("%d %d %d %d",&x1,&y1, &x2,&y2);
	//printf(" coordinate %d %d %d %d \n",x1,y1, x2,y2);
	//printf(" max x =%d : max y =%d \n",getmaxx(),getmaxy() );
	initgraph(&gdriver,&gmode, "C:\\turboc3\\bgi");
	setcolor(BLUE);
	rectangle(x1,y1,x2,y2);
	setbkcolor(RED);
	getch();
	closegraph();
}



