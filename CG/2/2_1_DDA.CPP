#include<stdio.h>
#include<conio.h>
#include<graphics.h>
//#include<math.h>
#define round(x) ( (int) ( (x) +.5 ) )
#define abs(x) ( (x>0) ? (x) : ( (x)*(-1)))
/*int abs( int a){
    if (a<0)
        return -a;
    else 
        return a;
}*/
//error due to floating point need floating point calc
int  main(){
    int gdriver=DETECT,gmode, x1, y1, x2, y2, d_x, d_y,i ;
    float x,y, x_incr, y_incr, step;
    clrscr();
    printf("Enter two points of (x1,y1) & (x2,y2):");
    scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
    d_x=x2-x1;
    d_y=y2-y1;
    if (abs(d_x) >= abs(d_y)) 
        step=abs(d_x) ;
    else 
        step=abs(d_y);
    x_incr=d_x/step;
    y_incr=d_y/step;
    printf( "\n dx %d  dy %d  step%f \nx_incr%f y_incr%f\n ",d_x, d_y,step,x_incr,y_incr);
    x=x1;y=y1;
    initgraph(&gdriver,&gmode, "C:\\turboc3\\bgi");
    for (i=0; i<=step ;i++){
        printf( "x %d  y %d  step%d \n ",round(x), round(y),i);
        putpixel(round(x), round(y),RED);
        x = x + x_incr;
        y = y + y_incr;
        
        
    }
    getch();
    closegraph();
    return 0;
}
