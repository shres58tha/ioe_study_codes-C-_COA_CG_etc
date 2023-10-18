#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define round ( x ) ( ( int ) ( ( x ) +.5 ) )
#define abs ( x ) ( ( x>0 ) ? ( x ) : ( ( x ) * ( -1 ) ) ) 
void lineDDA ( int x1, int y1, int x2, int y2 ) {
	int d_x, d_y, step ;
	float x_incr, y_incr ;
	d_x = x2-x1 ;
	d_y = y2-y1 ;
	step = ( abs ( d_x ) > = abs ( d_y ) ) ? abs ( d_x ) : abs ( d_y ) ;
	x_incr = d_x / ( float ) step ;
	y_incr = d_y / ( float ) step ;
	printf ( "step%d dx%f dy%f", step, x_incr, y_incr ) ;
	for ( int i = 0 ; i<step ; i++ ) {
		putpixel ( round ( x1 ) , round ( y1 ) , RED ) ;
		x1+ = x_incr ;
		y1+ = y_incr ;
	}
return ;
}
int main ( ) {
	int x1, y1, x2, y2, gdriver = DETECT, gmode ;
	clrscr ( ) ;
	printf ( "Enter two points of ( x1, y1 ) & ( x2, y2 ) :" ) ;
	scanf ( "%d %d %d %d", &x1, &y1, &x2, &y2 ) ;
	initgraph ( &gdriver, &gmode, "C:\\turboc3\\bgi" ) ;
	lineDDA ( x1, y1, x2, y2 ) ;
	getch ( ) ;
	closegraph ( ) ;
	return 0 ;
}
