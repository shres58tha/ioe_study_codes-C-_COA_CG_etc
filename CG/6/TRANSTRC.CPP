#include<conio.h>
#include<graphics.h>
#include<stdio.h>
typedef struct {
    int x;
    int y;    
}Point;
Point getPoint(char *s ){
    Point p;
    printf ("Enter %s (x, y):",s);
	scanf ( "%d%d",&p.x,&p.y);
    return p;
}
void lineP(Point p, Point r){
    line(p.x, p.y, r.x, r.y);
}
Point translateP(Point p, Point t){
    Point q;
    q.x=p.x+t.x;
    q.y=p.y+t.y;
    return q;
}
int main(){
    int gd=DETECT, gm;
    Point a, b, t , c,d;
    clrscr();
    a=getPoint("start point");
    b=getPoint("end point");
    t =getPoint("translation vector");
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    setcolor(RED);
    lineP(a,b);
    outtextxy(a.x,a.y,"original");
    c=translateP(a,t);
    d=translateP(b,t);
    setcolor(BLUE);
    lineP(c,d);
    outtextxy(c.x,c.y,"translated");
    getch();
    closegraph();
    return 0;
}
