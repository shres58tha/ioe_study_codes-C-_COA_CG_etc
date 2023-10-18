//Reflection
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main(){

	int gd=DETECT, r, gm;
	float x1, y1, x2, y2, x3,y3,x4,y4;
	printf ("Enter two points of (x1, y1) & (x2, y2):");
	scanf (" %f %f %f %f", &x1, &y1, &x2, &y2);
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	setcolor(WHITE);
	line( getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
	line( 0, getmaxy() / 2, getmaxx(), getmaxy() / 2);

	setcolor(RED);
	rectangle(x1, y1, x2, y2);
	outtextxy(x1,y1,"original");

	x3= x1;
	y3= getmaxy() - y1;
	x4= x2;
	y4= getmaxy() - y2;

	setcolor(BLUE);
	rectangle(x3, y3, x4, y4);
	outtextxy(x3,y3," x axis reflected");

	setcolor(GREEN);
	rectangle(getmaxx()- x1, y1, getmaxx()- x2, y2);
	outtextxy(getmaxx()- x1, y1," y axis reflected");

	setcolor(CYAN);
	rectangle(getmaxx()- x1, getmaxy() -y1, getmaxx()- x2, getmaxy()- y2);
	outtextxy(getmaxx()- x1, getmaxy() -y1," center reflected");

	getch();
	closegraph();
	return 0;
}
