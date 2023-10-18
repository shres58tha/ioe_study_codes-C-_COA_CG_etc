//RungeKutta 4
 #include<stdio.h>
 #define f(x,y) ( ( (y)*(y)-(x)*(x) )/( (y)*(y)+(x)*(x) ) ) 
 int main() {
     int n;
     float x,xf,y,h,m1,m2,m3,m4;
     printf("Enter intial val  (x,y) :");
     scanf("%f%f",&x,&y);
     printf("Enter xf :");
     scanf("%f",&xf);
     printf("Enter step h :");
     scanf("%f",&h);
     n=(xf-x)/h;
     printf("xf =%f; yf = %f \n",x,y);
     for(int i=0;i<n;i++){
         m1=h*f(x,y);      
         m2=h*f(x+h/2,y+m1/2);  
         m3=h*f(x+h/2,y+m2/2);
         m4=h*f(x+h,y+m3);
         y=y+(m1+2*m2+2*m3+m4)/6;
         x=x+h; 
         printf("xf =%f; yf = %f \n",x,y);
     }
     return 0;
 }
