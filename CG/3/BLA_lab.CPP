#include<stdio.h>
#include<conio.h>
#include<graphics.h>
//#include<math.h>
#define abs(x) ( (x)>0 ? (x) : ( (x)*(-1) ) )

void lineBLA(int x1, int y1, int x2, int y2){
    int dx, dy, lx, ly, pk, i;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    lx=(x2>x1)?1:-1 ;
    ly= (y2>y1)?1:1 ;
    putpixel(x1, y1, RED);
    if (dx>dy){
        pk=2*dy-dx;
        for (i=0;i<dx;i++){
            if (pk<0){
                x1+=lx;
                //y1=y1;
                pk+=2*dy;
            }
            else {
                x1+=lx;
                y1+=ly;
                y1+=2*dy-2*dx;
            }
            putpixel(x1, y1, RED);
        }
    }
    else{
        pk=2*dx-dy;
        for (i=0;i<dy;i++){
            if (pk<0){
                y1+=ly;
                //x1=x1;
                pk+=2*dx;
            }
            else {
                x1+=lx;
                y1+=ly;
                pk+=2*dx-2*dy;
            }
            putpixel(x1, y1, RED);
        }
    }
    return ;
}
int main(){
    int gdriver=DETECT, gmode;
    int x1, y1, x2, y2;
    clrscr();
    printf ("Enter two points of (x1, y1) & (x2, y2):");
    scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
    initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
    lineBLA(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}
