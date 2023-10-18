// program to calculate area of circle
#include <stdio.h>
#define pi 3.14159265358979 //  can use 22/7 or 355/113 later is better approximation
int main(){
     int radius = 5; // declaration and  initialization of variable. area always initialize to 0
     float area; // Area declared as float as it is in decimal form
     area = pi*radius*radius;  // formula for area of circle given the radius
     printf("\n \t area = %f \n", area); // formatting and printing value of area using %d specifier
return 0;
}
