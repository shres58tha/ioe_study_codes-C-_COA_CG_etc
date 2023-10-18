 //shearing along x-axis
#include<conio.h>
#include<graphics.h>
int main(){
    int gd=DETECT, gm;
    int x1, y1, x2, y2, x3,y3,x4,y4,shx;
    clrscr();
    printf ("Enter diagnol points of rectangle (x1, y1) & (x2, y2):");
    scanf (" %d %d %d %d", &x1, &y1, &x2, &y2);
    printf ("Enter searingg factor (shx) :");
    scanf (" %d", &shx);
    
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");
    
    setcolor(RED);
    rectangle(x1, y1, x2, y2);
    outtextxy(x1,y1,"original");
    
    x3=x1+shx*y1;             // shearing x axis                
    y3=y1;
    x4=x2+shx*y2;
    y4=y2;
    
    setcolor(BLUE);
    rectangle(x3, y3, x4, y4);
    outtextxy(x3,y3,"sheared");
    
    getch();
    closegraph();
    return 0;
}
/*
Enter diagnol points of rectangle (x1, y1) & (x2, y2):20 20 40 40 
Enter searingg factor (shx) :3
*/
