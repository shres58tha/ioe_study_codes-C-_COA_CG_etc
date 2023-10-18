
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

    virtual void display_area()  {
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
    polygon *p0= new parallelogram( 10.9, 9.9);  // conversion from the derived to base type pointer cast not necessary as the parallelogram type is also a polygon type. since  it is derived from base 
    p0->display_area();    // works
    
    parallelogram p(11.1,8.9);
    parallelogram *p2;
    p0=&p;               // getting address of derived class in the base class pointer
    p2= dynamic_cast<parallelogram *>(p0);  // dyanmic_cast of the base  type object pointer to the derived class parallelogram type pointer works only in case of polymorphic code

    if(p0){
        p0->display_area();
    }else
        cout << "Cannot cast" << endl;
    
    return 0;
}

/*output
parallelogram area is :107.91
parallelogram area is :98.79
*/
