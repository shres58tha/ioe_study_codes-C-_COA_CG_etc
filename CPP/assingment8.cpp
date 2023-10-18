#define block 1 
/*
An abstract class is a class in which there is a declaration but no definition for a member function by having the member function declaration assigned to zero. Abstract class cannot be used as a parameter type, a function return type, or the type of an explicit conversion, nor to declare an object of an abstract class. It can be used to declare pointers and references to an abstract class.
It's a way of forcing a contract between the class designer and the users of that class that the virtual functions that are declared in the abstracted class need to be implemented by the one who derives a class from abstract class by inheritance. 

Example: 
class abstract_polygon {
private: 
double length;
double height;
public:
//Non Abstract Member Function
void set_height( double x) { height=x;} 
double get_height() {return height;} 
void set_length(double x) {length = x;} 
double get_length() {return length;}

//Pure virtual function
virtual double area() = 0; // Pure virtual function makes this class Abstract class.
    void NonAbstractMemberFunction2();
};
Here the class abstract_polygon is an abstract class because it contains the member area() which is a pure virtual function as it is set equal to zero. Because of this this class cannot be instantiated and the derived class is forced to make an appropriate function area() suitable to its own type.

RTTI ( Run-time Type Identification ) is a standard way for a program to determine the type of object during runtime allowing the runtime polymorphism by allowing programs that use pointers or references to base classes to retrieve or access derived types object’s instances/members.

RTTI is provided through two operators:
The typeid operator, which returns the actual type of the object referred to by a pointer (or a reference).
The dynamic_cast operator, which safely converts from a pointer (or reference) to a base type to a pointer (or reference) to a derived type.


The dynamic_cast Operator  (keyword is dynamic_cast) converts an object into a more specific object or derived object.
The need for dynamic_cast generally arises because of desire to perform derived class operation on a derived class object, but only a pointer or reference-to-base is available.

Example:
*/
// Explain abstract class with example. Explain how dynamic cast and typeid operators are used to achieve RTTI. [IOE Back, 2074]
//Answer:
 * 
# if block ==1
/*
An abstract class is a class in which there is a declaration but no definition for a member function by having the member function declaration assigned to zero. Abstract class cannot be used as a parameter type, a function return type, or the type of an explicit conversion, nor to declare an object of an abstract class. It can be used to declare pointers and references to an abstract class.
It's a way of forcing a contract between the class designer and the users of that class that the virtual functions that are declared in the abstracted class need to be implemented by the one who derives a class from abstract class by inheritance. 

Example: 
class abstract_polygon {
private: 
double length;
double height;
public:
//Non Abstract Member Function
void set_height( double x) { height=x;} 
double get_height() {return height;} 
void set_length(double x) {length = x;} 
double get_length() {return length;}

//Pure virtual function
virtual double area() = 0; // Pure virtual function makes this class Abstract class.
    void NonAbstractMemberFunction2();
};
Here the class abstract_polygon is an abstract class because it contains the member area() which is a pure virtual function as it is set equal to zero. Because of this this class cannot be instantiated and the derived class is forced to make an appropriate function area() suitable to its own type.

RTTI ( Run-time Type Identification ) is a standard way for a program to determine the type of object during runtime allowing the runtime polymorphism by allowing programs that use pointers or references to base classes to retrieve or access derived types object’s instances/members.

RTTI is provided through two operators:
The typeid operator, which returns the actual type of the object referred to by a pointer (or a reference).
The dynamic_cast operator, which safely converts from a pointer (or reference) to a base type to a pointer (or reference) to a derived type.


The dynamic_cast Operator  (keyword is dynamic_cast) converts an object into a more specific object or derived object.
The need for dynamic_cast generally arises because of desire to perform derived class operation on a derived class object, but only a pointer or reference-to-base is available.

Example:
*/
#include <iostream>
using namespace std;

class polygon {
private: 
double length;
double height;
public:
//Non Abstract Member Function
void set_height( double x)      { height=x;     } 
    double get_height()         {return height; } 
    void set_length(double x)   {length = x;    } 
    double get_length()         {return length; }

    void display_area()  {
        cout << "polygon area is :"<< length * height<<endl;
    }
};

class parallelogram : public polygon {
public:
    parallelogram(double b, double h){
        set_length(b);
        set_height(h);
    }
    
    void display_area () {
        cout << "parallelogram area is :"<< get_length()*get_height()<<endl;
    }
};

int main(){
    polygon *p0= new parallelogram( 10.9, 9.9);  // conversion from the derived to base type pointer cast not necessary as the parallelogram type is also a polygon type. since  it is derived
    p0->display_area();    // works
    
    polygon base;
    base.set_height(11.1);
    base.set_length(8.9);
    
    parallelogram *p1;
    p0=&base;               // getting the address of the base class polygon in the pointer p0
   // p1= dynamic_cast<parallelogram *>(p1);  // dyanmic_cast of the base  type object pointer to the derived class parallelogram type pointer
    if(p1){
      //  p1->display_area();
    }else
        cout << "Cannot cast" << endl;
    
    return 0;
}

/*output:



*/
#endif

//What do you mean by pure virtual function and where is it used? Illustrate an example. [2073 Back]

#if block == 2
/*
Pure virtual function is a function that is declared in the base abstract class in such a way that it is compulsory to be defined in all the derived classes. The base class becomes abstract due to the declaration of pure virtual function in it due to which it cannot be instantiated and the base class just becomes an abstract class. If it is not defined in the derived class then the derived class also becomes abstract .
Syntax:

virtual<func_type><func_name>() =0;

    = 0; part makes the virtual function a pure virtual function which disallows the definition of this function in the base class. All derived class must redefine pure virtual function of base class otherwise derived class also becomes abstract just like base class.

#include<iostream> 
using namespace std; 
  
class Base { 
   int x; 
public: 
    virtual void display() = 0; 
}; 
  
// This class inherits from Base and implements fun() 
class Derived: public Base { 
public: 
    void display() { cout << x<<endl; } 
}; 
  
int main(void) 
{ 
    Derived d; 
    d.display(); 
    return 0; 
}

*/
#endif
#if block == 3
/*Illustrate with an example (hint: multipath inheritance)*/


#endif

