/*Write a program having Polygon as an abstract class with length and height as its data members. Create derived class Rectangle and Triangle. Make Area() as pure virtual function and redefined it in derived class to calculate respective area. [IoE, 2072, Regular]
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
    double get_height()         {return height;  } 
    void set_length(double x)   {length = x;     } 
    double get_length()         {return length;  }

    virtual void display_area()=0;  //pure virtual function
};

class rectangle : public polygon {
public:
    rectangle(double b, double h){  // parameterized constructor
        set_length(b);
        set_height(h);
    }
    
    void display_area () {// definition of pure virtual function
        cout << "rectangle area is :"<< get_length()*get_height()<<endl;
    }
};


class triangle : public polygon {
public:
    triangle(double b, double h){
        set_length(b);
        set_height(h);
    }
    
    void display_area () {
        cout << "Triangle area is :"<< 0.5*get_length()*get_height()<<endl;
    }
};
int main(){
    polygon *p;
    rectangle  r( 10, 5.5);  
    triangle   t(10,5.5);
    
    p=&r;
    p->display_area();
    p=&t;
    p->display_area();
    
    return 0;
}

/*output:
rectangle area is :55
Triangle area is :27.5
*/
