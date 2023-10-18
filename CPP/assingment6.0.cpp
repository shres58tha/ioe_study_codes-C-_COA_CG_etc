 // coded by umesh.076bei029@acem.edu.np 2nd Oct 2020

#define block 5  // choices 2,3,4,5 Q no 1 ans  has no code

/*Q No 1
 * What do you mean by Operator Overloading. Write down the general syntax of an operator being overloaded.
 * Answer*/
/*
Operator overloading is a concept in C++ which provide the new definition for the operator that are defined by the language. It is a type of polymorphism in which an operator is overloaded to give user defined meaning to it, performing operation on user-defined data type. For example '+' operator can be overloaded to perform addition on various data types, objects type, and even to add   Strings (i.e. concatenation) etc.

Almost any operator can be overloaded in C++. However there are few operator which can not be overloaded. Operator that are not overloaded are follows

scope operator  ::
sizeof ( )
member selector  .
member pointer selector  *
ternary operator  ?:


For example let Distance be a class with data type feet and inch, then + operator can be overloaded to provide the native like addition of two objects D1 and D2 which are obj instances of the class Distance by overloading operator '+'. 
However, operator overloading for fundamental data types like int,float,char etc are not allowed.
SYNTAX FOR OPERATOR OVERLOADING:

Operator Overloading Syntax

Member function:
 return_type class_name::Operator Op ( argument list){  //Op = operator symbol being overloaded Like:+,<,>,-,*,++,etc
 //Function body
 }
//unary takes no arguments while binary takes one argument.
 
Non member function
 return_type Operator Op ( argument list)
 {
 // function body
 }
 // no of argument equal to anary of the operator that is unary takes one while binary takes two.
 
*/

/*Q No 2
 * What is the difference between using member function and friend function when overloading an operator? Illustrate with examples.*/
/* Answer**
    The difference between the member function and the friend function is as follows
*Member function has one less argument in the function definition than the anary of the operator while the friend function has same number of the arguments as the anary of the operator.
* When the operator is overloaded as a member function it is called by the object itself. but in case of the friend member overloading of operator it cannot be called by the object but is called as a independent function with the specific arguments passed to it.
for example;

// member function general format
 class class_name {
 
    private: 
        //.............
    public:
        return_type operator op_symbol (argument);
 };
return_type operator op_symbol ( argument){
    //body of function
}

// friend function general format 
class class_name {
 
    private: 
        //.............
    public:
        friend return_type operator op_symbol (arg, arg);
 };
return_type operator op_symbol ( [arg], [arg]){
    //body of function
}
 */

/*code*/
#if  block == 2
#include <iostream>
using namespace std;

class C1{
private:
    int num;
public:
    C1(int n=0):num(n){}
    void show(){
        cout << num;
    }
    // member function declaration
    C1 operator+(C1);
    
    // friend function declaration
    friend C1 operator-(C1, C1);
};

C1 C1::operator+(C1 n){       // member binary operator taking one argument only
return C1( num + n.num);
}
C1 operator-(C1 n1,  C1 n2){ // friend binary operator taking two arguments
return C1 (n1.num -n2.num);
}

// driver
int main (){
    C1 num1(1), num2(2), num3;
    num3=num1+num2;
    cout << endl<< " addition of "; num1.show(); cout << " and "; num2.show(); 
    cout << ": "; num3.show();
    num3=num1-num2;
    cout << endl<< " subtraction of "; num1.show(); cout << " and "; num2.show(); 
    cout << ": "; num3.show();
    cout << endl;
    
}
/* output*
 
 addition of 1 and 2: 3
 subtraction of 1 and 2: -1

 */

#endif


/* Q No 3
 * Overload the operator == to compare two objects of a class if they are equivalent.
 */
#if block == 3
#include <iostream>
using namespace std;

class C1{
private:
    int num;
public:
    C1(int n=0):num(n){}
    void show(){cout << num;}
    bool operator==(C1 n){ return(num==n.num); }
};
// driver
int main (){
    C1 num1(2), num2(2);
    cout << " C1("; num1.show(); cout << ") == C2("; num2.show();cout << ") : "; 
    cout << (num1==num2) << endl;
}
/*output
 C1(2) == C2(2) : 1
*/
#endif

/* QNo 4 Answer
Overload the operator + using Friend Function to add two objects of class Distance(feet, inches). The relation between inches and feet is 12 inches = 1 feet.
*/
#if block == 4
#include <iostream>
using namespace std;

class Distance{
private:
    int feet, inch;
public:
    Distance( int f=0,int i=0):feet(f),inch(i){}
    void show(){
        cout << feet << " feet " << inch <<" inch ";
    }
    // friend function declaration
    friend Distance operator+(Distance,Distance);
};

Distance operator+(Distance d1, Distance d2){ 
    Distance ret;
    ret.inch = d1.inch + d2.inch; 
    ret.feet = d1.feet + d2.feet;
    if (ret.inch >12){
        ret.inch -=12;
        ret.inch ++;
    }  
return ret;
}

// driver
int main (){
    Distance d1(1, 2), d2(3,4), d3;
    d3=d1+d2;
    d1.show(); 
    cout << "+ "; 
    d2.show(); 
    cout << ": "; 
    d3.show();
    cout <<endl;
    
}
/* output*

 1 feet 2 inch + 3 feet 4 inch : 4 feet 6 inch 
 */

#endif

/*
Design a class Polar which describes a point in the plane using polar coordinates (radius and angle). Use the overloaded + operator to add two objects of Polar.
Note that we can’t add polar values of two points directly. This requires first the conversion of points into rectangular coordinates, and then adding the corresponding rectangular coordinates and finally converting the results back into polar coordinates.
You might need to use the following trigonometric formulae.
x = r * cos(a)
y = r * sin(a)
a = atan(y/x)
r = sqrt(x*x + y*y)

Where x, y are components of a rectangular coordinate system and r(radius) and a(angle) are components of polar coordinates system.
*/
#if block== 5
/*
Design a class polar which describes a point in the plane using polar co-ordinates radius and angel. 
A point in polar co-ordinates is show:
X=r*cos(a)
Y=r*sin(a)
A=atan(X/Y)
R=sqrt(X*X+Y*Y)
*/

#include<iostream>
#include<cmath>
using namespace std;
class Rect;
class Polar
{
	float r,a;                         // angle in degrees
public:
	Polar(float r1=0,  float a1=0){
        r=r1;
        a=a1;
	}

	void putData(){
		cout<<"\nPolar Data";
		cout<<"\nR="<<r<<",A="<<a ;
	}
	float getr(){
		return r;
	}
	float geta(){
		return a;
	}
};

class Rect
{
	float x,y;
public:
	Rect(float x1=0,float y1=0){
		x=x1;
		y=y1;
	}

	void putData()	{
		cout<<"\nRect Data";
		cout<<"\nx="<<x<<", y="<<y<<"";
	}

	Rect(Polar p){
		x = p.getr() * cos(3.14*p.geta()/180); //in degrees
		y = p.getr() * sin(3.14*p.geta()/180);
	}

	friend Rect operator+(Rect & r1,Rect & r2){
		Rect r3;
		r3.x=r1.x+r2.x;
		r3.y=r1.y+r2.y;
    return r3;
	}

	operator Polar(){
		return Polar( sqrt(x*x+y*y), atan(x/y)*180/3.14 );
	}
};

int main()
{
	Polar p1(2,3);
	Polar p2(4,5);

	Polar p3;
	Rect r1,r2,r3;

	r1=p1;
	r2=p2;

	r3=r1+r2;
	p3=r3;

	r3.putData();
	p3.putData();
    cout <<endl;
	return 0;
}


/* output* 

Rect Data
x=5.98206, y=0.453066
Polar Data
R=5.99919,A=85.7123
 * */
#endif
