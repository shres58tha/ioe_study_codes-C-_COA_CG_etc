//translation
#include<conio.h>
#include<graphics.h>

int main(){
    int gd=DETECT, gm;
    int x1, y1, x2, y2, x3,y3,x4,y4,tx,ty;
    clrscr();
    printf ("Enter two points of (x1, y1) & (x2, y2):");
    scanf (" %d %d %d %d", &x1, &y1, &x2, &y2);
    printf ("Enter translation (tx, ty) :");
    scanf (" %d %d", &tx, &ty);
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    setcolor(RED);
    line(x1, y1, x2, y2);
    outtextxy(x1,y1,"original");
    x3=x1+tx;                             //tP()
    y3=y1+ty;
    x4=x2+tx;
    y4=y2+ty;
    setcolor(BLUE);
    line(x3, y3, x4, y4);
    outtextxy(x3,y3,"translated");
    getch();
    closegraph();
    return 0;
}
