//Scaling
#include<conio.h>
#include<graphics.h>
int main(){
    int gd=DETECT, gm;
    int x1, y1, x2, y2, x3,y3,x4,y4,sx,sy;
    clrscr();
    printf ("Enter two points (x1, y1) & (x2, y2):");
    scanf (" %d %d %d %d", &x1, &y1, &x2, &y2);
    printf ("Enter scaling (sx, sy) :");
    scanf (" %d %d", &sx, &sy);
    
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    
    setcolor(RED);
    line(x1, y1, x2, y2);
    //rectangle(x1, y1, x2, y2);
    outtextxy(x1,y1,"original");
    
    x3=x1*sx;             //scaling               
    y3=y1*sy;
    x4=x2*sx;
    y4=y2*sy;
    
    setcolor(BLUE);
    line(x3, y3, x4, y4);
    //rectangle(x3, y3, x4, y4);
    outtextxy(x3,y3,"scaled");
    
    getch();
    closegraph();
    return 0;
}

/* output
Enter two points of (x1, y1) & (x2, y2):10 10 120 170
Enter scaling (sx, sy) :2 3
*/
