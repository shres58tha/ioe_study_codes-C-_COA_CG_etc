#include<stdio.h>
#include<conio.h>
#include<graphics.h>
/* house */
void main ()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode, "C:\\turboc3\\bgi");
	setcolor(GREEN);
	line(120,40,520,40);
	line(120,440,520,440);
	line(120,40,120,440);
	line(520,40,520,440);
	setcolor(WHITE);
	circle(220,140,50);
	circle(420,140,50);
	setcolor(RED);
	rectangle(270,300,370,440);
	getch();
	closegraph();
}



