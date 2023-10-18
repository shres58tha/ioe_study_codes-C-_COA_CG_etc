//Runge- Kutta 2
#include<stdio.h>
#define f(x,y) ( ( (y)*(y)-(x)*(x) )/( (y)*(y)+(x)*(x) ) ) 
int main() {
    float x,xf,y,h,m1,m2;
    printf("Enter intial val  (x,y) :");
    scanf("%f%f",&x,&y);
    printf("Enter xf :");
    scanf("%f",&xf);
    printf("Enter step h :");
    scanf("%f",&h);
    printf("xf =%f; yf = %f \n",x,y);
    while(x<xf) {
        m1=h*f(x, y);                             //euler slope
        m2=h*f(x+h,y+m1);                         //modif1ied
        y=y+(m1+m2)/2;
        x=x+h;
        printf("xf =%f; yf = %f \n",x,y);
    }
    return 0;
}
