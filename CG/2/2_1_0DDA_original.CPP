#include<stdio.h>
#include<conio.h>
#include<graphics.h> 
#define round(x ) ( (int ) ( x ) +.5 )
#define abs(x ) ( (x>0 ) ? x : ( x * (-1 ) ) )
int main( ){
    int gdriver=DETECT,gmode;
    int x1,y1,x2,y2,d_x,d_y,step;
    float x_incr, y_incr;
    clrscr( );
    printf ("Enter two points of (x1,y1 ) & (x2,y2 ):" );
    scanf ("%d %d %d %d",&x1,&y1, &x2,&y2 );
    d_x=x2-x1;
    d_y=y2-y1;
    printf("diff %d %d \n",d_x,d_y );
    step= ( absl(d_x ) >= absl(d_y ) ) ? absl(d_x ) : absl(d_y );
    x_incr=d_x/(float )step;
    y_incr=d_y/(float )step;
    printf("%d %f %f",step,x_incr,y_incr );
    getch( );
    initgraph(&gdriver,&gmode, "C:\\turboc3\\bgi" );
    for ( int i=0; i<step ;i++ ){
        putpixel( round(x1 ), round(y1 ),RED );
        x1+=x_incr;
        y1+=y_incr;
    }
    getch( );
    closegraph( );
    return 0;
}
