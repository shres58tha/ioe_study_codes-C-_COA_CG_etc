// program to calculate area of ellipse
#include <stdio.h>
#define pi 3.14159265358979 //  can use 22/7 or 355/113 later is better approximation
int main(){
     int minor = 4, major=6; // declaration and  initialization of variable. area always initialize to 0
     float area; // Area declared as float as it is in decimal form
     area = pi*minor*major;  // formula for area of ellipse given the radius
     printf("\n \t area = %f \n", area); // formatting and printing value of area using %d specifier
return 0;
}
