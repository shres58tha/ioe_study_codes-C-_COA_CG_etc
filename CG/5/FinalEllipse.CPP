#include <conio.h> 
#include <stdio.h> 
#include <graphics.h> 
#define sq(x) ((x)*(x))

void putpoint(float xc, float yc, float x, float y) {
  putpixel(xc + x, yc + y, RED);
  putpixel(xc - x, yc + y, RED);
  putpixel(xc + x, yc - y, RED);
  putpixel(xc - x, yc - y, RED);
}
void drawEllipse(float xc, float yc, float rx, float ry) {
  float x = 0, y = ry, pk;
  //region 1
  pk = sq(ry) - sq(rx) * ry + (sq(rx)) / 4;
  while ( x * sq(ry) < y * sq(rx)) {  //(2 * x * sq(ry)) < (2 * y * sq(rx)))
    if (pk <= 0) {
      x = x + 1;
      pk = pk + (2 * sq(ry) * x) + sq(ry);
    } else {
      x = x + 1;
      y = y - 1;
      pk = pk + (2 * sq(ry) * x) - (2 * sq(rx) * y) + sq(ry);
    }
    putpoint(xc, yc, x, y);
  }
  //region 2
  pk = (sq(x+0.5) * sq(ry)) + (sq(y-1) * sq(rx)) - (sq(rx) * sq(ry));
  while (y >= 0) {
    if (pk > 0) {
      y = y - 1;
      pk = pk - (2 * sq(rx) * y) + (sq(rx));
    } else {
      x = x + 1;
      y = y - 1;
      pk = pk + (2 * sq(ry) * x) - (2 * sq(rx) * y) + (sq(rx));
    }
    putpoint(xc, yc, x, y);
  }
  ///* 
  line(xc + rx, yc, xc - rx, yc);
  line(xc, yc + ry, xc, yc - ry);
  outtextxy(xc + (1.2 * rx), yc - (1.2 * ry), " ( x , y ) ");
  outtextxy(xc - (1.2 * rx), yc + (1.2 * ry), " (-x ,-y ) ");
  outtextxy(xc + (1.2 * rx), yc + (1.2 * ry), " ( x ,-y ) ");
  outtextxy(xc - (1.2 * rx), yc - (1.2 * ry), " (-x , y ) ");
  //*/
}
int main() {
  int gd = DETECT, gm;
  float xc, yc, rx, ry;
  clrscr();
  initgraph( &gd, &gm, "C:\\turboc3\\BGI");
  printf("Mid point ellipse drawing algorithm\n");
  printf("Enter Center for ellipse ( xc , yc ) : ");
  scanf(" %f %f", &xc, &yc);
  printf("Enter x-radius and y-radius rx & ry : ");
  scanf(" %f %f", &rx, &ry);
  drawEllipse(xc, yc, rx, ry);
  getch();
  closegraph();
  return 0;
}
