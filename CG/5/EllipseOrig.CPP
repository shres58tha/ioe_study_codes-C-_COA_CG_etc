#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#define sq(x) ((x) * (x))
void putpoint(float xc, float yc, float x, float y){
    putpixel(xc+x, yc+y, RED);
    putpixel(xc-x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
}
void drawEllipse(float xc, float yc, float rx, float ry ){
    float x = 0, y = ry, pk;
    float ry2 = sq(ry), rx2 = sq(rx);
    //region 1
    pk = ry2-rx2 * (ry-0.25); // pk = (ry * ry)-(rx * rx * ry)+((rx * rx)/4);
    while( x * ry2 < y * rx2 ){
        x += 1;
        pk += (2 * ry2 * x) + ry2; 
        if(pk > 0){
            y -= 1;
            pk -= (2 * rx2 * y);
        }
        putpoint(xc, yc, x, y);
    }
    //region 2
    pk = sq(x+0.5) * ry2 + sq(y-1) * rx2 - rx2 * ry2;
    while(y >= 0){
        y -= 1;
        pk -= (2 * rx2 * y)+rx2;
        if(pk <= 0){
            x += 1;
            pk += (2 * ry2 * x);
        }
        putpoint(xc, yc, x, y);
    }
    // draw axis and pre float text
    line(xc+rx, yc, xc-rx, yc);
    line(xc, yc+ry, xc, yc-ry);
    outtextxy(xc+(1.2 * rx), yc-(1.2 * ry), "( x, y)");
    outtextxy(xc-(1.2 * rx), yc+(1.2 * ry), "(-x,-y)");
    outtextxy(xc+(1.2 * rx), yc+(1.2 * ry), "( x,-y)");
    outtextxy(xc-(1.2 * rx), yc-(1.2 * ry), "(-x, y)");
    
}
int main(){
    int gd = DETECT, gm;
    float xc, yc, rx, ry;
    clrscr();
    printf("Mid point ellipse drawing algorithm\n");
    printf("Enter Center for ellipse (xc, yc) : ");
    scanf(" %f %f", &xc, &yc);
    printf("Enter x-radius and y-radius xr & xy : ");
    scanf(" %f %f", &rx, &ry);
    initgraph(&gd, &gm, "C:\\turboc3\\BGI");
    drawEllipse(xc, yc, rx, ry);
    getch();
    closegraph();
    return 0;
}
