// program to calculate simple intrest for given data
#include <stdio.h>
int main(){
     float P = 4000, T=2, R=5.5, I=0; // declaration and  initialization of variable. area always initialize to 0
     I = P*T*R/100;  // formula for simple intrest
     printf("\n \t area = %f \n", I); // formatting and printing value of area using %d specifier
return 0;
}
