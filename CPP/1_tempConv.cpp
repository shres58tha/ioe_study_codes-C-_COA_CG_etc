// C++ program that will ask for a temperature in Fahrenheit and display it in Celcius

#include<iostream>
using namespace std;
int main(){  
    float f,c;
    cout<<"Fahrenheit  to Celsius conversion \nEnter FAHRENHEIT : ";
    cin>>f;
    c = (f-32)*5/9;
    cout<<"\nCELSIUS DEGREE = "<<c << endl;
} 

/*OUTPUT*****************
$ ./a.out 
Fahrenheit  to Celsius conversion 
Enter FAHRENHEIT : -40

CELSIUS DEGREE = -40
**************************/
