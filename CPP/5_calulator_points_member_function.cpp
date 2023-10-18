//  simple C++ program using the concept of Class and Objects (Optional Question) 
//redo it with multiple way of operator overloading and see the effect
#include <iostream>
using namespace std;

class cmplxPoint{
        
private:    
    double x, y;                                            // saved complxpoint
public:
    cmplxPoint(double a=0.0, double b=0.0) {x = a; y = b;}  //constructor
    double getx() {return x;}                               // gets value of real part
    double gety() {return y;}                               // gets value of img part
    
    void setx(double z) {x = z;}                            // sets value of real part
    void sety(double z) {y = z;}                            // sets value of img part    
    
    double &setx(){return x;}                               // for assigning directly in cin
    double &sety(){return y;}                               // for assigning directly in cin
    
    cmplxPoint conj() { cmplxPoint c(x,-y); return c;}      // returns the conjugate of point
    double abs(){ return (x*x-y*y);}                        // returns abs value of point

    
    cmplxPoint operator + (cmplxPoint &a) {        // adds complxpoint
        cmplxPoint r ( r.x=x+a.getx(), r.y=y+a.gety() );        // works since it is defined by constructor
        // return ( r.x=x + a.getx(), r.y=y + a.gety() );       //doesnot work as that point is in touple
        //return ((cmplxPoint)(r.x=x+a.getx(),r.y=y+a.gety())); // doesnot work why not sure
        return r;
    }
    
    cmplxPoint operator-(cmplxPoint &a) {        // subtracts complxpoint
        cmplxPoint r;
        r.x= x - a.getx();
        r.y= y - a.gety();
        return r;
    }

    cmplxPoint operator*(cmplxPoint &a) {        // multiply complxpoint 
        cmplxPoint c ( (x*a.getx()-y*a.gety()), (x*a.gety()+y*a.getx() ) );
        return c;
    }

    cmplxPoint operator/(cmplxPoint &z) {        // divide complxpoint           
        cmplxPoint z_conj=z.conj();              //find complement of divident
        cmplxPoint temp(x,y);                    // get current data in complxpoint
        //cout << temp.x<<","<<temp.y<<endl;     // << not overloaded yet
        temp=temp*z_conj;                        // multiply with the complement pus result in  temp
        //cout << temp.x<<","<<temp.y<<endl;
        cmplxPoint c(temp.getx()/z.abs(), temp.gety()/z.abs()); // get the ans be div by the abs value of divident.
        
        return c;
    }
   
    bool operator==(cmplxPoint &a){
         if ((x==a.getx())&&(y==a.gety()))
             return 1;
         else 
             return 0;
        }
       /* bool operator!=(Paragraph const& rhs) const{
            // Define != operator in terms of the == operator
            return !(this->operator==(rhs));
        }*/
       
    friend ostream& operator<<(ostream& cout, cmplxPoint &p);   //not needed actually but for indicationg a vaiation  for future ref      
};

    
// ostream cannot be declared inside the class 
// all that can be done is to make it a global or just friend function
ostream& operator<<(ostream& cout, cmplxPoint &p) {          // display out for complxpoint       
    cout <<  "( " << p.getx() << ", " << p.gety() << " )";   // cout or out can be interchanged
    return cout;
}

istream& operator>>(istream& cin, cmplxPoint &p) {          // in for complxpoint       
    double temp;                                            // not sure why temp is needed                
    cout << "\t(real part):"; cin>> p.setx();//cin>> temp; p.setx(temp);
    cout << "\t(img. part):"; cin>> temp; p.sety(temp);  
    return cin;
}
int main() {
    cmplxPoint a(4, 40);
    cmplxPoint b(10,250);
    cmplxPoint c;
    cout << "a = " << a << ", b = " << b << endl;
    c = a/b;
    cout << "div=" << c << endl;   // issue here here << is overloaded but cant use a/b why not sure
    c=a.conj();
	cout << "a.conj " << c << endl;
	cout << "a.abs " << a.abs()<<endl;\
	cout<< "enter a cmplxPoint b"<<endl ;
    
    cin>>b;
    c = a + b;                      // need this step here due next step failing 
    cout << a <<'+'<< b <<'='<< c <<endl;               // issue cannot evaluate the complxpoint  expression    // problem noticecd might be solvable now
    
    cout<< "a and b are ";
    if (a==b)
        cout << "equal";
    else 
        cout << "not equal";
    
    cout <<endl;
    
}

/*****************output*************
shr@shr-Aspire-E5-532:~/Desktop/cpract/CPP$ ./a.out 
a = ( 4, 0 ), b = ( 2, 0 )
div=( 2, 0 )
a.conj ( 4, -0 )
a.abs 16
enter a cmplxPoint
        (real part):5
        (img. part):5
( 4, 0 )+( 5, 5 )=( 9, 5 )
***************************************/
