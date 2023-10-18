#define block 5// just change value of letter to select corresponding block while comparing


#if (block==1)

//Write a simple program to design a Class to keep the information of three students. For each student, you must get his/her name, rollno and see if s/he is present or absent. The class should contain two functions viz. One for input and one for display.
#include <iostream>
#include <string>   //for string

using namespace std;

class student{
    private: 
        string std_name;
        int roll_no;
        char presence;
    public:
        void input(void){
            cout << " name: " ;
            cin  >> std_name;
            cout << " roll number: ";
            cin  >> roll_no;
            cout << "present (y), absent (n) : ";
            cin  >> presence;
        }   
        void display(void){
            cout << "Student details:\n";
            cout << " Name  :" << std_name << endl
                 << " Roll  :" << roll_no << endl
                 << "Present:" << presence <<endl; 
        }
};

int main(){
    student s1,s2,s3];       //array of objects creation 
    s1.input();
    s2.input();
    s3.input();
    cout << "displaying students info" << endl;
    s1.display();
    s2.display();
    s3.display();
    
return 0;
}

/**************output********

*/

#endif
#if (block== 2)
//// C++ program to calculate the volume of cube, cuboid, and cylinder using class and object.
// USING member function definition outside of the class
#include<iostream>
#include<cmath>
using namespace std;

class cuboid{
    private:
        float length=0.0;
        float width=0.0;
        float height=0.0;
    public:
        // declaration of the methods
        cuboid(float, float, float);
        float volume();
};
//  member function definition
     cuboid::cuboid(float l=0.0, float w=0.0, float h=0.0 ){    //using default values
        length=l;
        width=w;
        height=h;    
    }

    float cuboid::volume(){
        return (length*width*height);
    }
//  end of member function definition of cuboid

class cube{
    private:
        float side=0.0;
    public:
        // declaration of the methods
        cube(float);
        float volume();
};
//  member function definition
  
     cube::cube(float s=0.0){    //using default values
        side=s;
    }
   
    float cube::volume(){
        return (side*side*side);
    }
//  end of member function definition of cube

class cylinder{
    private:
        float radius=0.0;
        float height=0.0;
    public:
        // declaration of the methods
        cylinder(float, float);
        float volume();
};
//  member function definition
     cylinder::cylinder(float r=0.0, float h=0.0){    //using default values
        radius=r;
        height=h;;
    }
    
    float cylinder::volume(){
        return (M_PI*radius*radius*height);
    }
//  end of member function definition of cylinder

int main(){
    cuboid box(20,15,10);         // side of cube set using constructor 
    cube   cubic_box(5);             // sides of the cuboid
    cylinder cyldr ( 1, 1);        // parameterized constructor call
    
    cout<<"\nVolume of cuboid is   "<<box.volume()<<endl;
    cout<<"\n Volume of cube is    "<<cubic_box.volume()<<endl;
    cout<<"\nVolume of cylinder is "<<cyldr.volume() <<endl;
    cout <<endl;
return 0;
}
/* OUTPUT
Volume of cuboid is   3000

 Volume of cube is    125

Volume of cylinder is 3.14159
*/
#endif
#if (block== 3)

// constructors

#include <iostream>
using namespace std;

class complex{
      private:
           float real;
           float img;
      public:
          complex (){real=0.0; img=0.0;}                    // default constructor
          complex (float r){real= r; img=0.0;}             // parameterized constructor 
          complex (float r , float i){real= r; img=i;}     // parameterized overload constructor  
          void display (){
              cout << real <<" "<<showpos << img << noshowpos << endl;
          }
};
      
int main(){

      complex num1;             // object construction by use of default constructor
      complex num2(5.5);        // parameterized constructor 
      complex num3(54, -8.8);   // overloaded parameterized constructor
      complex num4=num3;        // default copy constructor auto generated
      cout << "num1 : "; 
      num1.display();
      cout << "num2 : ";
      num2.display();
      cout << "num3 : ";
      num3.display();
      cout << "num4 : ";
      num4.display();
return 0;
}
/* OUTPUT
num1 : 0 +0
num2 : 5.5 +0
num3 : 54 -8.8
num4 : 54 -8.8
*/

#endif
#if (block== 4)

// Illustrate an example of using this pointer
#include <iostream>
using namespace std;

class complex{
      private:
           float real;
           float img;
      public:
         complex (float r=0.0 , float i=0.0){real= r; img=i;}     // constructor  
          void display (){
              cout << real <<" "<<showpos << img <<"i"<< noshowpos << endl;
          }
          complex add(complex num){
              complex ret_num;
              ret_num.real=this->real + num.real;
              ret_num.img =this->img  + num.img ;
              return ret_num;
        }
};
      
int main(){

      complex num1(10,10);            
      complex num2(5.5);        
      complex num3;  
      cout << "num1 : "; 
      num1.display();
      cout << "num2 : ";
      num2.display();
      num3=num1.add(num2);
      cout << "num3 : ";
      num3.display();
      
return 0;
}
/* OUTPUT
num1 : 10 +10i
num2 : 5.5 +0i
num3 : 15.5 +10i

*/
#endif
#if (block== 5)
// friend function
#include <iostream>    
using namespace std; 

class item1{
    private:
        float price;
    public:
        item1(float p=0.0){price=p;}
        friend void showprice (item1);
};
class item2{
    private:
        float price;
    public:
        item2(float p=0.0){price=p;}
        friend void showprice (item2);
};
//  member function definition
  
void showprice(item1 x){
        cout<<x.price<<endl;
    }    
void showprice(item2 x){                //overloaded friend function
        cout<<x.price<<endl;
    }    
// driver code
int main(){    
    item1 a(100);    
    item2 b(200);
    showprice(a);           //calling friend function
    showprice(b);
return 0;    
}  
/*
100
200
*/
#endif




