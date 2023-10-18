#define block 5 // just change value of letter to select corrosponding block while comparing


//Write a C++ program that will ask for a temperature in Fahrenheit and display it in Celcius

#if (block==1)

#include<iostream>
using namespace std;
int main()
{
int F,temp;
float C;
cout<<"enter the temperature in F :"<<endl;
cin>>F;
temp = F-32;
C = temp*5/9;
cout<<"the temperature in C is :"<<C<<endl; 
return 0 ;
}
//enter the temperature in F :-40
//the temperature in C is :-40

#endif
#if (block== 2)
//Write a C++ program to calculate the volume of cube, cuboid, and cylinder using function overloading.


#include <iostream>

using namespace std;
int volume(int a){
    int v;
    v = a*a*a;
    return v;
    
}
int volume(int l, int b, int h){
    int v;
    v = l*b*h;
    return v;
    
}
float volume(int r, int h){
    float v;
    float pi = 3.14;
    v= pi*r*r*h;
    return v;
}
int main()
{
    
  cout<<"the volume of the cube is :"<<volume(1)<<endl;
  cout<<"the volume of the cunoid is:"<<volume(2,3,4)<<endl;
  cout<<"the volume of the cylinder is:"<<volume(6,7)<<endl;
  
    

    return 0;
}


//output:
//the volume of the cube is :1
//the volume of the cunoid is:24
//the volume of the cylinder is:791.28

#endif
#if (block== 3)


//Write a C++ program to calculate the Simple Interest using function. 
//The default time period to calculate the Simple Interest is 1 year. (Hint: Use Default Argument)
#include<iostream>

using namespace std;
float interest(int principal,int rate,int time = 1){
	float interest ;
	interest = (principal*rate*time)/100.0;
	return interest;
}
int main(){
	cout<<"the interst is:"<<interest(1, 2,3)<<endl;
	return 0;
}
//output:
//the interst is:0.06

#endif
#if (block== 4)


//Write a C++ program to calculate the Circumference of a Circle given the radius that is requested from the user. 
//The function that calculates the circumference should be an Inline Function.

#include <iostream>
using namespace std;



inline float circumference(int r){
    float cir;
    float pi = 3.14;
    cir = 2*pi*r;
    return cir;
}
int main(){
    cout<<"the circumference is:"<<circumference (1)<<endl;
    return 0 ;
    
}


//output:
//the circumference is:6.28

 
#endif
#if (block== 5)


//Write a very simple C++ program using the concept of Class and Objects (Optional Question)
#include<iostream>
using namespace std;
class test {
	public:
	void display(){
		cout<<"inside test method"<<endl;
	}
};
int main(){
	test obj;
	obj.display();
	return 0;
}
//output 
//inside test method

#endif






