#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void putpix(float x, float y, int xc,  int yc ){
    putpixel ( xc + x, yc + y, RED);
    putpixel ( xc + x, yc - y, RED);
    putpixel ( xc - x, yc + y, RED);
    putpixel ( xc - x, yc - y, RED);
}
void ellipseDraw(int xc, int yc, int a, int b ){
    float x=0,y=b; // intiliaze calculating variables
    float pk;
    int a2=a*a, b2=b*b;
    //region 1
    pk=b2-a2*(b+0.25) ;
    printf("TAKAR TAK !     %f\n",pk);
    while ((2*b2*x)<=(2*a2*y)){
        putpix(x,y,xc,yc);
        if (pk<=0){
            x+=1;
            pk+=(2*x+1)*b2; // pk=pk+2*b*b*x+b*b;
            //	printf("HEE HAA !  =%d    %f\n",x,pk);
        }
        else {
            x+=1;
            y-=1;
            pk+=(2*x+1)*b2 - 2*a2*y;  // pk=pk+2*b*b*x -2*a*a*y + b*b;
            //	printf("NEEEEH !        %f\n",pk);
            
        }
    }// end while
    ///*//region 2
    pk=b2*(x+0.5)*(x+0.5) + a2*(y-1)*(y-1) -a2*b2;  // pk=b2*(x+1/2)^2 + a2*(y-1)^2 -a2*b2;
    //printf("TAKAR TAK!     %f\n",pk);
    while (y>=0.0){
        putpix(x,y,xc,yc);
        y-=1;
        if (pk>0.0){
            pk+=a2-2*a2*y; // pk=pk-2*b*b*a+b*b;
            //	printf("HEE HAA!  =%d    %f\n",x,pk);
        }
        else {
            x+=1;
            pk+=2*b2*x-(2*y - 1)*a2;  // pk=  pk + 2*b*b*x- 2*a*a*y + a*a;
            //printf("NEEEEH!        %f\n",pk);
        }
    }// end while */
    putpix(x,y,xc,yc);
    
}
int main(){
    int xc,yc,a,b, gdriver=DETECT,gmode;
    clrscr();
    /*
     *	printf("enter the center (xc, yc) and radius a and b:");
     *	scanf("%d %d %d %d", &xc , &yc, &a, &b);
     */
    xc=400;yc=300; a=150;b=100;
    initgraph(&gdriver,&gmode,"C:\\turboc3\\BGI");
    ellipseDraw(xc,yc,a,b);
    getch();
    closegraph();
    return 0;
}
