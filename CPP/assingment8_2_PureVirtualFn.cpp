/*
What do you mean by pure virtual function and where is it used? Illustrate an example. [2073 Back]
Answer:
	Pure virtual function is a function that is declared in the base abstract class in such a way that it is compulsory to be defined in all the derived classes. The base class becomes abstract due to the declaration of pure virtual function in it due to which it cannot be instantiated and the base class just becomes an abstract class. If it is not defined in the derived class then the derived class also becomes abstract .
Syntax:

virtual<func_type><func_name>() =0;

    = 0; part makes the virtual function a pure virtual function which disallows the definition of this function in the base class. All derived class must redefine pure virtual function of base class otherwise derived class also becomes abstract just like base class.

*/

#include<iostream> 
using namespace std; 
  
class Base { 
   int x; 
public:
    void set_x(int a){ x=a;}
    int get_x(){return x;}
    virtual void display() = 0;  // pure virtual function
}; 
  
// This class inherits from Base and implements fun() 
class Derived: public Base { 
public: 
    void display() { cout << get_x()<<endl; } 
}; 
  
int main(void) 
{
    Base *b;
    Derived d;
    d.set_x(5) ;
    b=&d;
    b->display(); 
return 0; 
}


/*output 
5
*/
