 // coded by umesh.076bei029@acem.edu.np 2nd Oct 2020

#define block 5 // choices 2,3,4,5 Q no 1 ans  has no code

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

class Distance{
private:
    int feet, inch;
public:
    Distance( int f=0,int i=0):feet(f),inch(i){}
    void show(){
        cout << feet << " feet " << inch <<" inch ";
    }
    // member function declaration
    Distance operator+(Distance);
    
    // friend function declaration
    friend Distance operator-(Distance, Distance);
};

Distance Distance::operator+(Distance d){       // member binary operator taking one argument only
    Distance ret;
    ret.inch = inch + d.inch;
    ret.feet = ret.inch/12 + feet + d.feet;     // handle carry and normalize
    ret.inch %= 12;
return ret;
}
Distance operator-(Distance d1,  Distance d2){ // friend binary operator taking two arguments
    Distance ret;
    ret.inch= d1.inch - d2.inch;
    ret.feet= d1.feet - d2.feet;
    if (ret.feet >0){                           // handle burrow and normalize
            if (ret.inch < 0){
                ret.inch += 12;
                ret.feet--;
            }
        }
    else{
            if (ret.inch > 0){
                ret.inch -=12;
                ret.feet++;
            }
        }    
return ret;
}

// driver
int main (){
    Distance d1(1, 10), d2(2,5), d3;
    d3=d1+d2;
    cout << endl<< " addition of "; d1.show(); cout << "and "; d2.show(); 
    cout << ": "; d3.show();
    d3=d1-d2;
    cout << endl<< " subtraction of "; d1.show(); cout << "and "; d2.show(); 
    cout << ": "; d3.show();
    cout << endl;
    
}
/* output*
 * 
 addition of 1 feet 10 inch and 2 feet 5 inch :4 feet 3 inch 
 subtraction of 1 feet 10 inch and 2 feet 5 inch :0 feet -7 inch 
 */

#endif


/* Q No 3
 * Overload the operator == to compare two objects of a class if they are equivalent.
 */
#if block == 3
#include <iostream>
using namespace std;

class Distance{
private:
    int feet, inch;
public:
    Distance( int f=0,int i=0):feet(f),inch(i){}
    // member function declaration
    bool operator==(Distance);
    friend ostream& operator<<(ostream& cout, Distance &d);
};

bool Distance::operator==(Distance d){      
   return ( feet==d.feet && inch == d.inch );
}

ostream& operator<<(ostream& cout, Distance &d) {          // display out for Distance       
      cout << d.feet << "' " << d.inch <<"\" ";              
      return cout;
}
// driver
int main (){
    Distance d1(1, 10), d2(1,10);
     cout << d1<< "and "<< d2 << " : ";
     if (d1==d2)
        cout <<" equal " << endl;
     else 
         cout <<" not equal"<< endl;
}
/* output*
 * 
 1' 10" and 1' 10"  : equal 
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
    
    // friend function declaration
    friend Distance operator+(Distance,Distance);
    
    // friend function declaration
    friend ostream& operator << (ostream& cout, Distance &d);
};

Distance operator+(Distance d1, Distance d2){ // friend binary operator taking two argument 
    Distance ret;
    ret.inch = d1.inch + d2.inch;             // since friend direct access to private data                      
    ret.feet = ret.inch/12 + d1.feet + d2.feet;
    ret.inch %= 12;
return ret;
}

ostream& operator<<(ostream& cout, Distance &d) { //display out for Distance       
      cout << d.feet << "' " << d.inch <<"\" ";              
      return cout;
}
// driver
int main (){
    Distance d1(1, 10), d2(3,10), d3;
    d3=d1+d2;
    cout << endl<< " addition of "<< d1 << "and "<< d2 << ": "<< d3 << endl;
    
}
/* output*
 * 
 addition of 1' 10" and 3' 10" : 5' 8" 

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
#include <iostream>
#include <cmath>
using namespace std;

class polar{
private:
  double radius,angle;                 // angle in degrees
public:
    polar(double r=0, double a=0): radius(r), angle(a){}       // constructor

//These two function convert this polar object to x and y rectangular coordinates values
    double getx(){ return radius*cos(angle * M_PI/180);  }         
    double gety(){ return radius*sin(angle * M_PI/180);  } 
// display polar
    friend ostream& operator<< ( ostream& cout, polar p);
// polar point adder
    polar operator + (polar point);
};
// definitions of functions
ostream& operator<< ( ostream& cout, polar p){   // normal function for pol_ordinate <<
    cout << "("<< p.radius <<" , "<< p.angle <<")";
    return cout;
}
polar polar::operator + (polar point){ 
    double x,y,r,a;
    x= getx() + point.getx();           // add in form of rectangular coordinate
    y= gety() + point.gety();
    r= sqrt(x*x + y*y);                 //converts x and y to Polar co-ordinate
    a= atan(y/x)*180/M_PI;         
return polar(r,a);                      // return polar point.
}
int main(){
 polar point1(10,0),point2(10,120), sum;

 sum=point1+point2;

 cout<<"\npoint1 ="<< point1 <<"\npoint2 ="<<point2<<endl;
 cout<<"\n   sum = "<< sum << endl;
}

/* output* 
 point1 =(10 , 0)
 point2 =(10 , 120)

    sum = (10 , 60)
 */
#endif
