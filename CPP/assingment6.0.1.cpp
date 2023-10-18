1.What do you mean by Operator Overloading. Write down the general syntax of an operator being overloaded.
  In C++, we can change the way operators work for user-defined types like objects and structures. This is known as operator overloading.
 For example,We have created three objects c1,c2 and result from a class named complex that represents complex number.Since operator overloading allows us to change how operator works,we can redefine how the + operator works and use it to add the complex numbers of c1 and c2 by writing result=c1+c2 ;
instead of result=c1addnumbers(c2);
This makes code easy and intuitive.
But we cannot use operrator overloading for fundamental datatypes like int ,char ,float…
To overload an operator, we use a special operator function 
Class className{
………….
           public
                 returntype operator symbol (arguments){
                  …………..
                 }
………….
};
 Here returntype is the return type of the function,operator is the keyword,symbol is the operator we want to overload andarguments  is the argument passed to the functions.

2.What is the difference between using member function and friend function when overloading an operator? Illustrate with examples.
When overloading member function has no argument for urinary and one argument for binary operators but friend function has one argument  for urinary and two for binary operators.
The friend function takes one argument more than member function because the invoking object appears as an explicit parameter to the friend function whereas in member function it is passed as an implicit parameter.
Example member function general format
class class_name
 { 
  private: 
  .............
  public:
       return_type operator op_symbol (argument);
 };
return_type operator op_symbol ( argument){
    body of function
}

 friend function general format 
class class_name {
 
    private: 
        .............
    public:
        friend return_type operator op_symbol (arg, arg);
 };
return_type operator op_symbol ( [arg], [arg]){
    body of function
}


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
     C1 operator+(C1);
    friend C1 operator-(C1, C1);
};

C1 C1::operator+(C1 n){      
return C1( num + n.num);
}
C1 operator-(C1 n1,  C1 n2){ 
return C1 (n1.num -n2.num);
}
int main (){
    C1 num1(1), num2(2), num3;
    num3=num1+num2;
    cout <<  "num1="; num1.show(); 
    cout<< "\nnum2="; num2.show(); 
    cout <<"\n sum="; num3.show();
    num3=num1-num2;
    out <<  "num1="; num1.show(); 
    cout<< "\nnum2="; num2.show(); 
    cout <<"\ndiff="; num3.show();
}

 output
 num1=1 
 num2=2
 sum =3
 num1=1 
 num2=2
 sum =-1

3.Overload the operator == to compare two objects of a class if they are equivalent.
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
int main (){
    C1 num1(2), num2(2);
    if (num1==num2)
        cout << "equal";
    else
        cout << "not equal";
}

 Output
equal

4.Overload the operator + using Friend Function to add two objects of class Distance(feet, inches). The relation between inches and feet is 12 inches = 1 feet.

#include <iostream>
using namespace std;
class Distance{
private:
    int feet, inch;
public:
    Distance( int f=0,int i=0):feet(f),inch(i){}
    void display(){
        cout << "feet =" << feet<< "; inch =" << inch ;
    }
    friend Distance operator+(Distance,Distance);
};

Distance operator+(Distance d1, Distance d2){ 
    Distance sum;
    sum.inch = d1.inch + d2.inch;             
    sum.feet = d1.feet + d2.feet;
    if  (sum.inch >12){
        sum.inch=sum.inch-12;
        sum.feet=sum.feet+1;
    }
        
return ret;
}
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
 output
 1 feet 
 2 inch + 3 feet 4 inch : 4 feet 6 inch 



5.Design a class Polar which describes a point in the plane using polar coordinates (radius and angle). Use the overloaded + operator to add two objects of Polar.
Note that we can’t add polar values of two points directly. This requires first the conversion of points into rectangular coordinates, and then adding the corresponding rectangular coordinates and finally converting the results back into polar coordinates.
You might need to use the following trigonometric formulae.
x = r * cos(a)
y = r * sin(a)
a = atan(y/x)
r = sqrt(x*x + y*y)

Where x, y are components of a rectangular coordinate system and r(radius) and a(angle) are components of polar coordinates system.

#include<iostream>
#include<cmath>
using namespace std;
class Rect;
class Polar
{
	float r,a;                         
public:
	Polar(float a1=0,float r1=0){
        a=a1;
		r=r1;
	}

	void putData(){
		cout<<"\nPolar Data";
		cout<<"\nA="<<a<<", R="<<r<<"";
	}

	float geta(){
		return a;
	}

	float getr(){
		return r;
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
		//x = r * cos(a);
		//y = r * sin(a);
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
		return Polar( atan(x/y) , sqrt(x*x+y*y) );
	}
};

int main()
{
    float pa,pr;

	//cout<<"Enter Polar-1: A,R:";
	//cin>>pa>>pr;
	//Polar p1(pa,pr);
	Polar p1(2,3);

	//cout<<"Enter Polar-2: A,R:";
	//cin>>pa>>pr;
	Polar p2(4,5);

	Polar p3;
	Rect r1,r2,r3;

	r1=p1;
	r2=p2;

	r3=r1+r2;
	p3=r3;

	r3.putData();
	p3.putData();

	return 0;
}

output

Rect Data
x=7.98601, y=0.453251
Polar Data
A=1.5141, R=7.99886
 
 
 
 
