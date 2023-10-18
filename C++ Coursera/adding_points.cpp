 
#include <iostream>
using namespace std;

class cmplxPoint{
public:
    cmplxPoint(double a=0.0, double b=0.0) {x = a; y = b;}
    double getx() {return x;}
    void setx(double z) {x = z;}
    double gety() {return y;}
    void sety(double z) {y = z;}
    cmplxPoint conj() { cmplxPoint c(x,-y); return c;}
    double abs(){ return (x*x-y*y);}
private:
    double x, y;
};

cmplxPoint operator+(cmplxPoint &a, cmplxPoint &b) {
    cmplxPoint c(a.getx()+b.getx(), a.gety()+b.gety());
    return c;
}

cmplxPoint operator-(cmplxPoint &a, cmplxPoint &b) {
    cmplxPoint c(a.getx()-b.getx(), a.gety()-b.gety());
    return c;
}

cmplxPoint operator*(cmplxPoint &a, cmplxPoint &b) {
    cmplxPoint c( (a.getx()*b.getx()-a.gety()*b.gety() ), ( a.getx()*b.gety()+a.gety()*b.getx() ) );
    return c;
}

cmplxPoint operator/(cmplxPoint &a, cmplxPoint &b) {
    cmplxPoint b_conj=b.conj();
    cmplxPoint temp=a*b_conj;
    cmplxPoint c(temp.getx()/b.abs(), temp.gety()/b.abs()); 
    return c;
}
ostream& operator<<(ostream& out, cmplxPoint &p) {
    cout <<  "( " << p.getx() << ", " << p.gety() << " )";
    return cout;
}

int main() {
    cmplxPoint a(0, 8);
    cmplxPoint b(0, 2);
    cmplxPoint c;
    cout << "a = " << a << ", b = " << b << endl;
    c = a / b;
    cout << "div = " << c << endl;
    // cout << "div =" << c=(a/b) << endl;   // issue here here << is overloaded- why not sure
    c=a.conj();
	cout << "a.conj " << c << endl;
	cout << "a.abs " << a.abs()<<endl;
}

