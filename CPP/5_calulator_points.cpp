//  simple C++ program using the concept of Class and Objects (Optional Question) 
//redo it with multiple way of operator overloading and see the effect
#include <iostream>
using namespace std;

class cmplxPoint{
public:
    cmplxPoint(double a=0.0, double b=0.0) {x = a; y = b;}  //constructor  // parameterized constructor with default value
    //cmplxPoint(const cmplxPoint &p2) {x = p2.x; y = p2.y; } //copy constructor //const keyword is essential for copy constructor
    // looks like copy constructor is applied by default without above code too as error in above code fails to compile at line 39
    // same with the default constructur otherwise line 66 cmplxPoint c; would generate error. 
    
    
    double getx() {return x;}                               // gets value of real part
    void setx(double z) {x = z;}                            // sets value of real part
    double gety() {return y;}                               // gets value of img part
    void sety(double z) {y = z;}                            // sets value of img part    
    cmplxPoint conj() { cmplxPoint c(x,-y); return c;}      // returns the conjugate of point
    double abs(){ return (x*x-y*y);}                        // returns abs value of point
private:    
    double x, y;                                            // saved complxpoint
};
//global operator overloading cannot access private data directly
cmplxPoint operator+(cmplxPoint &a, cmplxPoint &b) {        // adds complxpoint
    cmplxPoint c(a.getx()+b.getx(), a.gety()+b.gety());
    return c;
}

cmplxPoint operator-(cmplxPoint &a, cmplxPoint &b) {        // subtracts complxpoint
    cmplxPoint c(a.getx()-b.getx(), a.gety()-b.gety());
    return c;
}

cmplxPoint operator*(cmplxPoint &a, cmplxPoint &b) {        // multiply complxpoint 
    cmplxPoint c( (a.getx()*b.getx()-a.gety()*b.gety() ), ( a.getx()*b.gety()+a.gety()*b.getx() ) );
    return c;
}

cmplxPoint operator/(cmplxPoint &a, cmplxPoint &b) {        // divide complxpoint           
    cmplxPoint b_conj=b.conj();
    cmplxPoint temp=a*b_conj;                               // member function return failed to be used as native eval expression, need to be catched on some object variable ???? 
    cmplxPoint c(temp.getx()/b.abs(), temp.gety()/b.abs()); 
    return c;
}
ostream& operator<<(ostream& cout, cmplxPoint &p) {          // display out for complxpoint       
    cout <<  "( " << p.getx() << ", " << p.gety() << " )";   // cout or out can be interchanged
    return cout;
}

istream& operator>>(istream& cin, cmplxPoint &p) {          // display out for complxpoint       
    double temp;
    cout << "(real part)"; 
    cin>> temp; p.setx(temp);
    cout << "(img part )"; 
    cin>> temp; p.sety(temp);  
    return cin;
}

int main() {
    cmplxPoint a(0, 8);
    cmplxPoint b(0, 2);
    cmplxPoint p1(10, 15);  // Normal constructor is called here 
    cmplxPoint p2 = p1;     // Copy constructor is called here  eqv. complxpoint p2(p1);
    cout << "Normal constructor p1 "<<p1<<endl;
    cout << "copy constructor   p2 "<<p2<<endl;
    cmplxPoint c;
    cout << "a = " << a << ", b = " << b << endl;
    c = a/b;
    cout << "div = " << c << endl;
    //cout << "div = " <<a/b << endl;   // issue here here << is overloaded but cant use a/b why not sure
    c=a.conj();
	cout << "a.conj " << c << endl;
	cout << "a.abs " << a.abs()<<endl;\
	cout<< " enter a cmplxPoint"<<endl ;
    cin>>b;
    c = a + b;                      // need this step here due next step failing to
    cout << "sum is " << c <<endl;               // issue cannot evaluate the complxpoint  expression    // problem noticecd might be solvable now
}

/*****************output*************
$ ./a.out 
a = ( 0, 8 ), b = ( 0, 2 )
div = ( -4, -0 )
div =( -4, -0 )
a.conj ( 0, -8 )
a.abs -64
***************************************/
