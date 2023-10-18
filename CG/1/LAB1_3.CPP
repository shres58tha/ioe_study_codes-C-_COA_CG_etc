#include<stdio.h>
#include<conio.h>
#include<graphics.h>
/* ellipse*/
void main ()
{
	int gdriver=DETECT,gmode;
	int x, y, start_ang, end_ang,x_radius,y_radius;
	printf ("Enter center points of (x,y):");
	scanf ("%d %d",&x,&y);
	printf( "enter start and end angles :");
	scanf("%d %d", &start_ang,&end_ang);
	printf(" enter x_radius & y_radius ");
	scanf("%d %d",&x_radius, &y_radius);
	initgraph(&gdriver,&gmode, "C:\\turboc3\\bgi");
	printf(" max x =%d : max y =%d \n",getmaxx(),getmaxy() );
	setcolor(RED);
	ellipse(x,y,start_ang,end_ang,x_radius,y_radius);
	getch();
	closegraph();
}



