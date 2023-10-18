
#define block 3

#if block==1

// complex number calculator
#include <iostream>
using namespace std;

class Complex{
private:    
    double real , imaginary;  
    
public:
    Complex(double x=0.0, double y=0.0) {
        real = x; imaginary = y;
    }              
    
    void show();
    Complex add(Complex);
    Complex sub(Complex);
    Complex mul(Complex);

};
//definition of member functions 
void Complex::show(){
    if (imaginary > 0)
        cout << real << " + i"<< imaginary<< endl;
    if (imaginary <0 )
        cout << real << " - i"<< -imaginary<< endl;
    if (imaginary == 0)
        cout << real << endl;
}
Complex Complex::add(Complex num){         //Complex add
     Complex return_value;
     return_value.real= real+num.real;
     return_value.imaginary = imaginary+num.imaginary ;
     return return_value;
}
Complex Complex::sub(Complex num){         //sub Complex
     Complex return_value( real - num.real, imaginary - num.imaginary );
     return return_value;
}
Complex Complex::mul(Complex num){         //multiply Complex
     Complex return_value;
     return_value.real= real*num.real-imaginary*num.imaginary;
     return_value.imaginary = real*num.imaginary +imaginary*num.real;
     return return_value;
}

int main() {
    Complex num1(1, 2);
    Complex num2(3, 4);
    Complex result;
    cout << "num1 "; num1.show();
    cout << "num2 "; num2.show();
    cout << "num1 add num2" << endl;
    result=num1.add(num2);
    result.show();
    cout << "num1 sub num2" << endl;
    result=num1.sub(num2);
    result.show();
    cout << "num1 mul num2" << endl;
    result=num1.mul(num2);
    result.show();
}

/*****************output*************
num1 1 + i2 
num2 3 + i4 
num1 add num2 
4 + i6 
num1 sub num2 
-2 - i2 
num1 mul num2 
-5 + i10
***************************************/



#endif
#if block == 2

//program to add and subtract Tme. 

#include <iostream>
using namespace std;
class Tme{
private:
        int hour=0;
        int minutes=0;
        int second=0;
       
public:
        Tme( int h=0, int m=0, int s=0){
            hour=h; minutes=m; second=s;
        }
        void show ();
        Tme add (Tme);
        Tme sub (Tme);
        
};

void Tme::show (){
            cout<< "HH:MM:SS = ";
                cout<<hour<<":"<< minutes <<":"<< second <<endl;
    }

Tme Tme::add (Tme t){
    Tme return_value;
    int carry;
    
    return_value.second=this->second+t.second;
    if (return_value.second>=60){                   
        carry=return_value.second/60;              
        return_value.second=return_value.second%60;
    }
    return_value.minutes=this->minutes+t.minutes+carry;
    carry=0;                                
    if (return_value.minutes>=60){
        carry=return_value.minutes/60;
        return_value.minutes=return_value.minutes%60;
    }
    return_value.hour=this->hour+t.hour+carry;
    carry=0;                               
return return_value;
}

Tme Tme::sub (Tme t){
    Tme return_value;
    int flag_borrow=0;
    
    return_value.second=this->second-t.second;
    if (return_value.second < 0 ){
        return_value.second+=60;
        flag_borrow=1;
    }                               
    return_value.minutes=this->minutes- flag_borrow -t.minutes;
    flag_borrow=0;                      
    if (return_value.minutes < 0 ){
        return_value.minutes+=60;
        flag_borrow=1;
    }                                   
    return_value.hour=this->hour - flag_borrow -t.hour;
    flag_borrow=0;                     
return return_value;
}
    

int main(){

        Tme Tme1(1, 23, 45);
        Tme Tme2(1, 11, 11);
        Tme Tme_diff, Tme_sum;
        
        Tme_sum =Tme1.add(Tme2);
        Tme_diff=Tme1.sub(Tme2);
        
        cout<<("Tme 1 = ");Tme1.show();
        cout<<("Tme 2 = ");Tme2.show();
        cout<<("Tme_sum = "); Tme_sum.show();
        cout<<("Tme_diff= ");Tme_diff.show();
;
        
return 0;

}
/*
Tme 1 = HH:MM:SS = 1:23:45
Tme 2 = HH:MM:SS = 1:11:11
Tme_sum = HH:MM:SS = 2:34:56
Tme_diff= HH:MM:SS = 0:12:34

*/
#endif
#if block ==3
//counts the number of objects in memory using static data and static function. .

#include <iostream> 
using namespace std; 
class count_obj { 
private:
    static int count;   
    
public: 
    count_obj() { 
        count++;              
        cout << "Objects created   "<< endl;
    }
    ~count_obj(){ 
        count--;                
        cout << " Objects destroyed "<< endl;  
    } 
    static void show(){ 
        cout << "count of obj in memory:" << count<< endl; 
    }
}; 

int count_obj::count;    

int main(){ 
    count_obj o1, o2; 
    count_obj::show();     
    count_obj o3;
    count_obj::show();    
return 0; 
}
/*
 
*/
#endif
