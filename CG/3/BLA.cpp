#include<stdio.h>
#include<graphics.h>
#define abs(x) ( (x)>0 ? (x) : ( (x)*(-1) ) )
#define plot(x, y) ( printf ("\n%d %d", x, y))
void LineBLA(int x0, int y0, int x1, int y1){
    int dx, dy, lx, ly, err, e2;
    dx =  abs(x1-x0);
    dy = -abs(y1-y0);    // for making it into addition later on
    lx = x0<x1 ? 1 : -1; // increment | decrement  
    ly = y0<y1 ? 1 : -1;
    err = dx+dy;         // error value e_xy new val constructed in place of pk= dx - dy
    plot(x0, y0);        
    while(x0 != x1 || y0 != y1){ // loop // (!(x0 == x1 && y0 == y1)
        e2 = 2*err;      // pk +dy
        if (e2 >= dy){   //   e_xy+e_x > 0 same as pk>0
            // (err += dy) & (x0 += lx) ;  // can be done () needed as the precedence of assingment operator is the least
            err += dy;
            x0  += lx;
        }
        if (e2 <= dx) {  // e_xy+e_y < 0 same as pk<=0
            err += dx; 
            y0  += ly; 
        } 
        plot(x0, y0);
    } 
}
int main(){
    LineBLA(1, 1, 5, 4);
    printf("\n");
    return 0;
}
