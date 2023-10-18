//C++ program to calculate the volume of cube, cuboid, and cylinder using function overloading.
 
#include<iostream>
#include<cmath>
using namespace std;


// function prototypes
float volume(float, float , float );//cuboid
float volume(float);                //cube
float volume(float, float);         //cylinder    

int main(){
    float   a ;         // side of cube  
    float   l,b,h;      // sides of the cuboid
    float   r,h1;       // radius an height of cylinder
    
    cout<<"Enter side of cube:";
    cin>>a;
    cout<<"Enter sides l, b, h of cuboid: ";
    cin>>l >> b >> h;
    cout<<"Enter radius and height of a cylinder:";
    cin>>r>>h1;
    
    cout<<"\nVolume of cube is "<<volume(a);
    cout<<"\nVolume of cuboide is "<<volume(l,b,h);
    cout<<"\nVolume of cylinder is "<<volume(r,h1) <<endl;
    cout <<endl;
    return 0;
}

// function defination
float volume(float a){   //cube
	return (a*a*a); 
}

float volume(float l, float b, float h){   //cuboid
	return l*b*h;
}

float volume(float r, float h1){  //cylinder
	return M_PI*r*r*h1;
}

/* *************outout*******************
 
shr@shr-Aspire-E5-532:~/Desktop/cpract/CPP$ ./a.out 
Enter side of cube:10
Enter sides l, b, h of cuboid: 10 10 10
Enter radius and height of a cylinder:10 10 

Volume of cube is 1000
Volume of cuboide is 1000
Volume of cylinder is 3141.59

shr@shr-Aspire-E5-532:~/Desktop/cpr
*****************************************/
