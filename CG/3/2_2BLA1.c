#include<iostream>
#include<stdio.h> 
#include<graphics.h> 
void lineBLA(int x1, int y1, int x2, int y2){ 
    int dx, dy, p, x, y; 
    dx=x2-x1; 
    dy=y2-y1; 
    x=x1; 
    y=y1; 
    p=2*dy-dx; 
    while(x<x2) { 
        if(p>=0) { 
            putpixel(x,y,7); 
            y+=1; 
            p=p+2*dy-2*dx; 
        } 
        else { 
            putpixel(x,y,7); 
            p=p+2*dy;} 
            x+=1; 
    } 
} 
int main() { 
    int gdriver=DETECT, gmode, error, x1, y1, x2, y2; 
    
    printf("Enter co-ordinates of 1st point (x1,y1) and 2nd point (x2,y2) : "); 
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2); 
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi"); 
    lineBLA(x1, y1, x2, y2); 
    getch();
    return 0; 
} 
