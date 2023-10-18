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
    void normalize();               // for normalization
    Distance operator+(Distance);   // member function declaration
    friend Distance operator-(Distance, Distance);  // friend function declaration
   
};
void Distance::normalize(){
    if (feet >0){                           // normalize Distance Class must be used after every + -
            if (inch < 0){ inch += 12; feet--;}
            else if (inch >=12){inch -=12 ;feet++;}
        }
    else{
            if (inch > 0){ inch -=12; feet++; }
            else if(inch <=-12){inch +=12;feet--;}
        }     
}
Distance Distance::operator+(Distance d){       // member binary operator taking one argument only
    Distance ret;
    ret.inch = inch + d.inch;
    ret.feet = feet + d.feet;     // handle carry and normalize
    ret.normalize();
return ret;
}
Distance operator-(Distance d1,  Distance d2){ // friend binary operator taking two arguments
    Distance ret;
    ret.inch= d1.inch - d2.inch;
    ret.feet= d1.feet - d2.feet;
    ret.normalize();
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
class pol_ordinate;
class rect_ordinate{
private:
    float x,y;
public:
    rect_ordinate(float a=0, float b=0):x(a),y(b){}
    rect_ordinate(pol_ordinate p);          //parameterized constructor type conversion
    void setx(float a){ x=a;}
    void sety(float b){ y=b;}
    float getx(){ return x;}
    float gety(){ return y;}
    friend ostream& operator <<(ostream& cout, rect_ordinate);
    operator pol_ordinate();                // source type conversion
    rect_ordinate operator+(rect_ordinate); // operator + overloaded
};

class pol_ordinate{
    float r,a;                              //angle in degrees
public:
    pol_ordinate(float m=0, float n=0):r(m),a(n){}
    void setr(float m){ r=m;}
    void seta(float n){ a=n;}
    float getr(){ return r; }
    float geta(){ return a; }
    pol_ordinate operator + (pol_ordinate);
    // << overloaded with normal function
};

// Member functions definitions
rect_ordinate::rect_ordinate(pol_ordinate p){   //parameterized constructor type conversion
        x=p.getr() * cos(p.geta() * M_PI/180);  //
        y=p.getr() * sin(p.geta() * M_PI/180);
}

rect_ordinate::operator pol_ordinate(){         // source type conversion
    pol_ordinate ret;
    ret.setr ( sqrt(x*x + y*y) );               // this-> implied no controversy 
    ret.seta ( atan(y/x)* 180/ M_PI );
    return ret;
}
//return_type scopeResolver::keyWord  OP( arguments )
rect_ordinate rect_ordinate::operator + (rect_ordinate p){  // add rect_ordinate points
    rect_ordinate ret;
    ret.x = x + p.x ;                           // addition of point in rect_ordinate
    ret.y = y + p.y ;
    return ret;
}

ostream& operator << ( ostream& cout, rect_ordinate p){  // friend function for rect_ordinate <<
    cout << "("<< p.x <<" , "<< p.y <<")";
    return cout;
}

ostream& operator<< ( ostream& cout, pol_ordinate p){   // normal function for pol_ordinate <<
    cout << "("<< p.getr() <<" , "<< p.geta()<<")";
    return cout;
}

pol_ordinate pol_ordinate::operator + (pol_ordinate p){ // add pol_ordinate points
    rect_ordinate point1(*this), point2(p);             //using type conversion to rect_ordinate
    return pol_ordinate(point1+point2);                 // return pol_ordinate type after type conversing sum of added rect_ordinate points
}

//driver
int main(){
    pol_ordinate point1(1,0), point2(1,360), point_sum;
    point_sum = point1 + point2;
    cout << " sum of  pol points " << point1 << " + " << point2 << " is " << point_sum << endl;
}

/* output* 
 sum of  pol points (1 , 0) + (1 , 360) is (2 , -7.01671e-15)
 */
#endif
