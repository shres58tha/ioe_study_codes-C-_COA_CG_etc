#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void putpix(int x, int y, int xc,  int yc ){
    putpixel ( xc + x, yc + y, RED);
    putpixel ( xc + x, yc - y, RED);
    putpixel ( xc - x, yc + y, RED);
    putpixel ( xc - x, yc - y, RED);
    putpixel ( xc + y, yc + x, RED);
    putpixel ( xc + y, yc - x, RED);
    putpixel ( xc - y, yc + x, RED);
    putpixel ( xc - y, yc - x, RED);
}
void circleDraw(int xc, int yc, int r ){
    int x=0,y=r,pk=1-r; // intiliaze calculating variables
    while (x<=y){
	putpix(x,y,xc,yc);
	if (pk>0)       // if pk>0
	    pk-=2*--y;  // decrement y then pk by 2y
	pk+=2*++x+1;    // increment x then pk ==> pk=pk+2x+1 / pk=pk+2x-2y+1
    }
}
int main(){
    int xc,yc,r, gdriver=DETECT,gmode;
    clrscr();
    printf("enter the center (xc, yc) and radius r:");
    scanf("%d %d %d", &xc , &yc, &r);
    initgraph(&gdriver,&gmode,"C:\\turboc3\\BGI");
    circleDraw(xc,yc,r);
    getch();
    closegraph();
    return 0;
}
