//C++ program to calculate the Circumference of a Circle given the radius that is requested from the user inline function calculating the circumference 

#include<iostream>
#include<cmath>
using namespace std;
// inline function defination
inline float circum(float r){
    return (2*M_PI*r);
}

// driver code
int main(){  
    float r;
    cout << "enter the radius of the Circle"<< endl;
    cin>>r;
    cout << "the circumference is =" <<circum(r)<< endl;
} 

/**************output************
shr@shr-Aspire-E5-532:~/Desktop/cpract/CPP$ ./a.out 
enter the radius of the Circle
2.5
the circumference is =15.708
***********************************/ 
