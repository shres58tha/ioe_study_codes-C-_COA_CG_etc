 /*
Inheritance examples: 
Base class Rectangle
Derived class Square with base class Rectangle
Derived class Cuboid with base class Rectangle
Derived class Cube with base class Cuboid
*/

#include <iostream>
using namespace std;

/*
Base class Rectangle
*/
class Rectangle {  
    
public:

  /*
    Static data members have to be initialized when declared.
    Static data memebers are usually declared constexpr (constant), 
    because the values should not be changed (Principle of Least Privilege)
  */
   static constexpr double ZERO = 0.0;

/*
overloading: same class, same name, different parameters (none)
"default" constructor - constructor with no arguments
*/

   Rectangle(){ 
      setLength(ZERO);
      setWidth(ZERO);
   }
/*
overloading: same class, same name, different parameters (two)
*/
   Rectangle(double length2, double width2){ 
      setLength(length2);
      setWidth(width2);
   }
   //returns name of class
   char const * name() const{
      return "Rectangle";
   }
   //set function
   void setLength(double length2){
   //error checking for negative numbers
      if(length2 < ZERO){
         length2 = -length2;
      }
      length = length2; 
   }
   //set function
   void setWidth(double width2){
   //error checking for negative numbers
      if(width2 < ZERO){
         width2 = -width2;
      }
      width = width2;
   }
   //get function
   double getLength() const{
      return length;
   }
   //get function
   double getWidth() const{
      return width;
   }
   //Calculate area of Rectangle
   double area() const{ 
      return length * width; 
   }
   
   /*
    Friend Function Definition for operator<< for output with cout<<
   */
   friend ostream &operator<<(ostream &output, const Rectangle & rect){
      output<<rect.name()<<" with length = "<<rect.length<<", width = "<<rect.width<<", area = "<<rect.area();
      return output;
   }

protected: //note this is "protected" and not "private"  
   double length;
   double width;
   
}; //end of class Rectangle

/****************************************************************/

/*
Derived class Square with base class Rectangle.
Syntax for 1st line of class definition:
class DerivedClass: public BaseClass
*/
class Square: public Rectangle{
public:

   //overloaded "default" constructor
   Square(): Rectangle(ZERO, ZERO){ 
       /*data members initialized in base
       class Rectangle, so no code here*/
   }  

/*
Constructor for derived class Square.
Because Square is a derived class of Rectangle,
we can use this syntax to call the base class's constructor:
DerivedClass(datatypes parameters): BaseClass(parameters){ ... }
*/
   Square(double side): Rectangle(side,side){ 
       /*data members initialized in base
       class Rectangle, so no code here*/
   }  
   /*
   returns name of class
   overrides Rectangle's name() function
   */
   char const * name() const{
      return "Square";
   }
   //new set function
   void setSide(double side){
      /*
      use Rectangle's setLength() and setWidth() functions, 
      to set both length and width to same value
      */
      Rectangle::setLength(side); 
      Rectangle::setWidth(side);
   }
   //override Rectangle's set function for proper Square behavior
   void setLength(double length2){
      setSide(length2);
   }
   //override Rectangle's set function for proper Square behavior
   void setWidth(double width2){
      setSide(width2);
   }   
   //get function
   double getSide() const{
      //use Rectangle's getLength() function
      return getLength();
   }
   
  /*
    Friend Function Definition for operator<< for output with cout<<
   */
   friend ostream &operator<<(ostream &output, const Square & square){
   //function area() calls Rectangle's function area()
      output<<square.name()<<" with side = "<<square.length<<", area = "<<square.area();
      return output;
   }   

//no new data members - length and height are store in base class Rectangle
}; //end of class Square

/****************************************************************/

/*
Inheritance example: Derived class Cuboid with base class Rectangle.

Cuboid is short for "Rectangular Cuboid".
A Rectangular Cuboid is basically a box.
A Rectangular Cuboid is also called rectangular parallelepiped or orthogonal parallelepiped, 
a three-dimensional figure formed by six parallelograms.
By the way, parallelepipeds are a subclass of the prismatoids, 
a polyhedron where all vertices lie in two parallel planes. 
*/
class Cuboid: public Rectangle{
public:

   //overloaded "default" constructor
   Cuboid(): Rectangle(ZERO, ZERO){ 
      setHeight(ZERO);
   }
/*
Constructor for class Cuboid, which is a Rectangular Cuboid.
Because Cuboid is a derived class of Rectangle,
we can use this syntax to call the base class's constructor:
DerivedClass(parameters): BaseClass(parameters){ ... }
*/
   Cuboid(double length2, double width2, double height2): Rectangle(length2, width2){ 
      setHeight(height2);
   }
   //returns name of class
   char const * name() const{
      return "Rectangular Cuboid";
   }
   //set function
   void setHeight(double height2){
      //error checking for negative numbers
      if(height2 < ZERO){
         height2 = -height2;
      }
      height = height2;
   }
   //get function
   double getHeight() const{
      return height;
   }
   /*
   Override Rectangle's area() function, 
   so it returns the surface area of the Rectangular Cuboid.
   */
   double area() const{
      return 2 * (length * width + height * length + height * width);
   }
   
   //calculate volume
   double volume() const{
      return length * width * height;
   }
   
  /*
    Function Definition for operator<< for output with cout<<
   */
   friend ostream &operator<<(ostream &output, const Cuboid & cubo){
      output<<cubo.name()<<" with length = "<<cubo.length<<", width = "<<cubo.width<<", height = "<<cubo.height<<", surface area = "<<cubo.area()<<", volume = "<<cubo.volume();
      return output;
   }   

/*
Note this is "protected" and not "private", 
just in case we have another derived class.
*/
protected:   
   double height; //new data member, in addition to length and width
   
}; //end of class Cuboid


/****************************************************************/

/*
Inheritance example: Derived class Cube with base class Cuboid.

A Cube is a Rectangular Cuboid with all equal sides
The Cube inherits the Rectangle's length and width, and also inherits the Cuboid's height, and all member functions
We have to override the set() member functions to keep equal values for the length, width and height (see example program: inheritance.cpp)
*/
class Cube: public Cuboid{
public:

   //overloaded "default" constructor
   Cube(): Cuboid(ZERO, ZERO, ZERO){ 
   //all data members are initialized in base class Cuboid
   }
/*
Constructor for class Cube, which is a Rectangular Cuboid with all equal sides.
Because Cube is a derived class of Cuboid,
we can use this syntax to call the base class's constructor:
DerivedClass(parameters): BaseClass(parameters){ ... }
*/
   Cube(double side): Cuboid(side, side, side){ 
   //all data members are initialized in base class Cuboid
   }
   //returns name of class
   char const * name() const{
      return "Cube";
   }
   /*
   All set functions must keep equal values 
   for the length, width and height 
   */
   void setSide(double side){
      /*
   need to call base class set methods,
   to set length, width, and height to same value
      */
      Rectangle::setLength(side);
      Rectangle::setWidth(side);
      Cuboid::setHeight(side);
   }
   //override Rectangle's setLength() function
   void setLength(double length2){
      setSide(length2);
   }
   //override Rectangle's setLength() function
   void setWidth(double width2){
      setSide(width2);
   }
   //override Cuboid's setLength() function
   void setHeight(double height2){
      setSide(height2);
   }
   
  /*
    Function Definition for operator<< for output with cout<<
   */
   friend ostream &operator<<(ostream &output, const Cube & cube){
      output<<cube.name()<<" with length = "<<cube.length<<", width = "<<cube.width<<", height = "<<cube.height<<", surface area = "<<cube.area()<<", volume = "<<cube.volume();
      return output;
   }   

/*
No new data members
*/ 
}; //end of class Cube



/****************************************************************/

//driver function main() to test classes
int main(){
   //Rectangle test
   Rectangle rect1;
   cout<<rect1<<endl; 
   rect1.setLength(3);
   rect1.setWidth(4);
   cout<<rect1<<endl;
   Rectangle rect2(20,30);
   cout<<rect2<<endl;
   double length = rect2.getLength();
   double width = rect2.getWidth();
   cout<<"length = "<<length<<endl;
   cout<<"width = "<<width<<endl<<endl;

   
   //Square test

   Square square1(-2);
   cout<<square1<<endl;
   Square square2; 
   square2.setSide(5);
   cout<<square2<<endl;
   square2.setLength(9);
   cout<<square2<<endl;
   double side = square2.getSide();
   cout<<"side = "<<side<<endl<<endl;
   
   //Cuboid test
   Cuboid cubo1;
   cout<<cubo1<<endl;
   Cuboid cubo2(-3, -4, -5);
   cout<<cubo2<<endl; 
   cubo2.setHeight(10);
   cout<<cubo2<<endl;
   double height = cubo2.getHeight();
   cout<<"height = "<<height<<endl<<endl;
   
   //Cube test
   Cube cube1;
   cout<<cube1<<endl; 
   Cube cube2(-2);
   cout<<cube2<<endl;
   cube2.setSide(5);
   cout<<cube2<<endl;
   cube2.setHeight(9);
   cout<<cube2<<endl;
   height = cube2.getHeight();
   cout<<"height = "<<height<<endl<<endl;
   

   
   return 0;
}

/*
Rectangle with length = 0, width = 0, area = 0
Rectangle with length = 3, width = 4, area = 12
Rectangle with length = 3, width = 4, area = 12

Square with side = 2, area = 4
Square with side = 5, area = 25
Square with side = 9, area = 81

Rectangular Cuboid with length = 0, width = 0, height = 0, area = 0, area = 0
Rectangular Cuboid with length = 3, width = 4, height = 5, area = 94, area = 60
Rectangular Cuboid with length = 3, width = 4, height = 10, area = 164, area = 120

Cube with length = 0, width = 0, height = 0, area = 0, area = 0
Cube with length = 2, width = 2, height = 2, area = 24, area = 8
Cube with length = 5, width = 5, height = 5, area = 150, area = 125
Cube with length = 9, width = 9, height = 9, area = 486, area = 729

*/
