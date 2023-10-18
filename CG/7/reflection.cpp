//Reflection
#include<conio.h>
#include<graphics.h>
#include<math.h>
int main(){
    
    int gd=DETECT, gm;
    float x1, y1, x2, y2,maxx,maxy, mx,my;
    printf ("Enter two points (x1, y1) & (x2, y2):");
    scanf (" %f %f %f %f", &x1, &y1, &x2, &y2);
    
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    maxx=getmaxx();
    maxy=getmaxy();
    mx=(x1+x2)/2;  // center point of rectangle for label
    my=(y1+y2)/2;
    
    setcolor(WHITE);
    line( maxx / 2, 0, maxx / 2, maxy);
    line( 0, maxy / 2, maxx, maxy / 2);
    
    setcolor(RED);
    rectangle(x1, y1, x2, y2);
    outtextxy(mx,my,"original");
        
    setcolor(BLUE);
    rectangle( x1, maxy -y1, x2, maxy- y2);
    outtextxy(mx,maxy-my," x axis reflected");
    
    setcolor(GREEN);
    rectangle(maxx- x1, y1, maxx- x2, y2);
    outtextxy(maxx-mx,my ," y axis reflected");
    
    setcolor(CYAN);
    rectangle(maxx- x1, maxy -y1, maxx- x2, maxy- y2);
    outtextxy(maxx- mx, maxy -my," center reflected");
    
    getch();
    closegraph();
    return 0;
}

//Enter two points of (x1, y1) & (x2, y2):100 150 250 250
