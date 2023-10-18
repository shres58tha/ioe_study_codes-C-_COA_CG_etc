// add two point in polar system here angle is measured in degrees.
#define block 1
#if block ==  1
#include <iostream>
#include <cmath>
using namespace std;
class rect;

class polar{
private:
  double radius,angle;                 // angle in degrees
public:
    friend class rect;                 // for accessing radius and angle directly from class rect
    polar(double r=0, double a=0): radius(r), angle(a){}    // constructor
    friend ostream& operator<< ( ostream& cout, polar p);   // display polar << overload
    polar operator + (polar point);                         // polar point adder
};

class rect {
private:
    double x,y;
public:
    rect (double x1=0, double y1=0): x(x1), y(y1){}         // constructor
    rect (polar p){                                         // constructor type conversion
        x=p.radius*cos(p.angle * M_PI/180);                 // for radian  x=r*cos(a)
        y=p.radius*sin(p.angle * M_PI/180);                 // for radian  y=r*sin(a)
    }
    operator polar(){                                       // member type conversion
        return polar (sqrt(x*x + y*y), atan(y/x)*180/M_PI); // for radian a=atan(y/x)
    }
    rect operator + (rect point ){                          // add rect points
        return rect( x + point.x , y + point.y);  
    }
};

// definition
ostream& operator<<( ostream& cout, polar p){   // normal function for pol_ordinate <<
    cout << "("<< p.radius <<" , "<< p.angle <<")";
    return cout;
}
// this need to be after rect class as it assess members function of class rect
polar polar::operator + (polar point){ 
    return polar( rect(*this) + rect(point) );  // double type conversion
}

int main(){
 polar point1(10,0), point2(10,120), sum;
 sum= point1 + point2;
 cout<<"\npoint1 ="<< point1 <<"\npoint2 ="<<point2<<endl;
 cout<<"\n   sum ="<< sum << endl;
}
/* output* 
 point1 =(10 , 0)
 point2 =(10 , 120)

    sum =(10 , 60)
 */
#endif

#if block == 2
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
