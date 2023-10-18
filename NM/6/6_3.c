 //simpson 1/3 rule
 #include<stdio.h>
 float f(float x){
     return ( 1 + x*x*x );
 }
 int main(){
     float lower, upper, I=0.0, h, k=0.0;
     int i, n;
     printf("\nlower & upper limit of integration :");
     scanf ("%f%f",&lower,&upper);
     h=(upper-lower)/2;
     
     I=(h/3)*(f(lower)+4*f((lower+upper)/2)+f(upper));
     printf("\nI= %f\n",I);
     return 0;
     
 }


