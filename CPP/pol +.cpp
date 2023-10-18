
#include <iostream>
#include <cmath>
#include <boost/regex.h>
using namespace std;
class rect;
class polar{
private:
  double radius,angle;                 // angle in degrees
public:
// constructor
    polar(double r=0, double a=0): radius(r), angle(a){} 
    
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
   
class rect {
private:
    double x,y;
public:
    rect (double x1=0, double y1=0):x(x1), y(y1){}
    rect (polar p){                    // constructor type conversion
        x=p.getx();
        y=p.gety();
    }
    operator polar (){                  // member type conversion
        return polar (sqrt(x*x + y*y), atan(y/x)*180/M_PI);
    }
    rect operator + (rect point );      // add rect points
    friend ostream& operator<< ( ostream& cout, rect p);
};

//definitions

ostream& operator<< ( ostream& cout, rect p){   // normal function for pol_ordinate <<
    cout << "("<< p.x <<" , "<< p.y <<")";
    return cout;
}

rect rect::operator + (rect point){
    return rect( x + point.x , y + point.y);
}

polar polar::operator + (polar point){ 
    /*rect point1(*this), point2( point);
    return polar( point1 + point2);         // return polar point.
    */
    return polar( rect(*this) + rect(point) );  // double type conversion
}
int main(){
 polar point1(10,0), point2(10,120), sum;

 sum= point1 + point2;

 cout<<"\npoint1 ="<< point1 <<"\npoint2 ="<<point2<<endl;
 cout<<"\n   sum = "<< sum << endl;
}

/* output* 
 point1 =(10 , 0)
 point2 =(10 , 120)

    sum = (10 , 60)
 */
