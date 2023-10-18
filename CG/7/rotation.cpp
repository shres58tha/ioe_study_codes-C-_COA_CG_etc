//rotation
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
int main(){
    
    int gd=DETECT, r, gm;
    float x1, y1, x2, y2, x3,y3,x4,y4, d, a, t;
    printf ("Enter two points of (x1, y1) & (x2, y2):");
    scanf (" %f %f %f %f", &x1, &y1, &x2, &y2);
    printf("Enter the degree of rotation: ");
    scanf("%f", &a);
    
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setcolor(RED);
    line(x1, y1, x2, y2);
    outtextxy(x1,y1,"original");
    
    t = a*3.14/180;  //radian conversion
    x3=x1*cos(t)-y1*sin(t);                            
    y3=y1*cos(t)+y1*sin(t);
    x4=x2*cos(t)-y2*sin(t);
    y4=y2*cos(t)+y2*sin(t);
    
    setcolor(BLUE);
    line(x3, y3, x4, y4);
    outtextxy(x3,y3,"rotated");
    
    getch();
    closegraph();
    return 0;
}

/*output
Enter diagnols points of rectangle (x1, y1) & (x2, y2):10 10 20 100
Enter searingg factor (shx) :5
*/
