/* wap to find area of circle , rectangle and square using function overloading*/

#include <iostream>
#define PI 3.14

using namespace std;

double area ( double r){  // circle double arg
    return PI*r*r; 
}

float area ( float s){   // square float arg
    return s*s ;
}

float area ( float l, float b){   // rectangle 2 arg type float
    return l*b ;
}
int main(){
    cout <<" area of circle : "<< area( 2.0)<<endl;              // defaults to double
    cout <<" area of the square :"<< area( 2.0f)<< endl;         // explicity defined to float here
    cout <<" area of the rectangle :"<< area ( 1.0, 3.0)<<endl;  // implicit conversion to float here
    
}
