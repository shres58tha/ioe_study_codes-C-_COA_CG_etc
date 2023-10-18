// coded by umesh.076bei029@acem.edu.np 25th sept 2020

/*
Attempt all the questions (10 marks => 3 + 4 + 3)

Write a program that can perform some operations on two complex numbers such as addition, subtraction, and multiplication. Your class should contain functions such as addition, subtraction and multiplication which computes respective operations and returns the complex object as result of that respective operation. In the main function, you can do something like 
		Result_operation_name = object1.operator_fn_name(object2)
Where all Result_operation_name, object1 and object2 are objects of class Complex


Write a program that can add and subtract two time units. Each time unit consists of HH:MM:SS where respective items refers to Hours, Minutes and Seconds. Create two objects and by calling respective member functions add and subtract, add two time units. Make sure that if seconds sum exceed 60, 1 unit should be transferred to the minute and respectively do the same for minutes as well. For hours if it exceeds 24 leave it. Make sure you utilize the constructor function correctly and member functions should be placed outside of the class.

Write a program that counts the number of objects still active using static data and static function. When an object is created, a static counter should be updated to display the total number of active objects and when an object is destroyed, the same counter value should be dropped by 1 and display the output.

*Let me know if you have any queries regarding the questions.
*/

#define block 3

#if block==1
//Q No. 1 solution

// complex number calculator


#include <iostream>
using namespace std;

class ComplexNum{
private:    
    double real , img;  
    
public:
    ComplexNum(double a=0.0, double b=0.0) {real = a; img = b;}              // parameterized constructor with default value    
    
    // inline core member functions.
    double get_real() {return real;}                                         //gets real part
    void set_real(double num) {real = num;}                                  //sets real part
    double get_img() {return img;}                                           //gets img part
    void set_img(double num) {img = num;}                                    //sets img part    

    void display(){cout<<real<<' '<<showpos<<img<<" i"<<noshowpos<<endl;}    // show ComplexNum
    
    // member function declarations
    ComplexNum add(ComplexNum);
    ComplexNum sub(ComplexNum);
    ComplexNum mul(ComplexNum);
    
};
//definition of member functions 
ComplexNum ComplexNum::add(ComplexNum num){         //ComplexNum add
     ComplexNum ret_val;
     ret_val.real= real+num.real;
     ret_val.img = img+num.img ;
     return ret_val;
}
ComplexNum ComplexNum::sub(ComplexNum num){         //sub ComplexNum
     ComplexNum ret_val( this->real - num.real, this->img - num.img );
     return ret_val;
}
ComplexNum ComplexNum::mul(ComplexNum num){         //multiply ComplexNum
     ComplexNum ret_val;
     ret_val.real= this->real*num.real-this->img*num.img;
     ret_val.img = this->real*num.img +this->img*num.real;
     return ret_val;
}


int main() {
    ComplexNum num1(8, 8);
    ComplexNum num2(2, 2);
    ComplexNum result;
    cout << "num1 "; num1.display();
    cout << "num2 "; num2.display();
    cout << "num1 add num2" << endl;
    result=num1.add(num2);
    result.display();
    cout << "num1 sub num2" << endl;
    result=num1.sub(num2);
    result.display();
    cout << "num1 mul num2" << endl;
    result=num1.mul(num2);
    result.display();
}

/*****************output*************
num1 8 +8 i
num2 2 +2 i
num1 add num2
10 +10 i
num1 sub num2
6 +6 i
num1 mul num2
0 +32 i

***************************************/



#endif
#if block == 2
//Q No. 2 solution
//program that can add and subtract two time units. 

#include <iostream>
#include <iomanip>
using namespace std;
class time_class{
private:
        int hr=0;
        int min=0;
        int sec=0;
       
public:
        time_class( int h=0, int m=0, int s=0){
            if ( h<0 || m<0 || s<0 || s>59 || m>59 ){
                cout<< "Invalid arguments passed";
                exit(1);                                            // 1st error exit
            }
            hr=h; min=m; sec=s;
        }
        void input_time(void);
        void display ();
        time_class add (time_class);
        time_class sub (time_class);
        
};
void  time_class::input_time(void){
            cout<< "Enter hour :";
            cin >> hr;
            if (hr<0){
                cout<< "Invalid input"<<endl;
                exit (1);
            }
            cout<< "Enter min : ";
            cin >> min;
            if (min<0 ||min>59){
                cout<< "Invalid input"<<endl;
                exit (1);
            }
            cout<< "Enter sec : ";
            cin >> sec;
            if (sec<0 ||sec>59){
                cout<< "Invalid input"<<endl;
                exit (1);
            }
        
     }

void time_class::display (){
            cout<< "HH:MM:SS = ";
            if (hr <0 ||min<0||sec<0 ){  // proper formatter for neg values
                cout<< "- " <<"("<<-hr<<":" 
                << setfill('0') << setw(2) << -min <<":"
                << setfill('0') << setw(2) << -sec << ")"<<endl;
            }
            else {
                cout<< " ("<<hr<<":"
                << setfill('0') << setw(2) << min <<":"
                << setfill('0') << setw(2) << sec << ")"<<endl;
            }
    }

time_class time_class::add (time_class time){
    time_class ret_val;
    int carry;
    
    ret_val.sec=this->sec+time.sec;
    if (ret_val.sec>=60){                   // if carry
        carry=ret_val.sec/60;               //set carry
        ret_val.sec=ret_val.sec%60;
    }
    ret_val.min=this->min+time.min+carry;
    carry=0;                                //reset carry after using
    if (ret_val.min>=60){
        carry=ret_val.min/60;
        ret_val.min=ret_val.min%60;
    }
    ret_val.hr=this->hr+time.hr+carry;
    carry=0;                                //reset carry after using
return ret_val;
}

time_class time_class::sub (time_class time){
    time_class ret_val;
    int flag_borrow=0;
    
    ret_val.sec=this->sec-time.sec;
    if (ret_val.sec < 0 ){
        ret_val.sec+=60;
        flag_borrow=1;
    }                                   // ret_val sec is +ve diff
    ret_val.min=this->min- flag_borrow -time.min;
    flag_borrow=0;                      //reset borrow flag after it is used
    if (ret_val.min < 0 ){
        ret_val.min+=60;
        flag_borrow=1;
    }                                   // ret_val min is +ve diff
    
    ret_val.hr=this->hr - flag_borrow -time.hr;
    flag_borrow=0;                      //reset borrow flag after it is used
    // the result above is mixture of +ve and negative values 
    // hr can be in negative while min and sec are in positive code below normalize it
    if (ret_val.hr < 0 ){               
        
        ret_val.hr = ret_val.hr + 1;                
        ret_val.min= -60 + ret_val.min + 1 ;
        ret_val.sec= -60 + ret_val.sec ;
                                        // fixing for the case
                                        // time 1 = HH:MM:SS = (1:30:50)
                                        // time 2 = HH:MM:SS = (2:30:50)
                                        // time_diff= HH:MM:SS = - (0:59:60)
        if (ret_val.sec==-60){
            ret_val.sec=0;
            ret_val.min -=1;
        }
        if (ret_val.min==-60){
            ret_val.min=0;
            ret_val.hr -=1;
        }
    }    
return ret_val;
}
    

int main(){

        time_class time1(1, 30, 50);
        time_class time2(1, 10, 40);
        time_class time_diff, time_sum;
        
        time_sum =time1.add(time2);
        time_diff=time1.sub(time2);
        
        cout<<("time 1 = ");time1.display();
        cout<<("time 2 = ");time2.display();
        cout<<("time_sum = "); time_sum.display();
        cout<<("time_diff= ");time_diff.display();
;
        
return 0;

}
/***** Output *******
//first run
time 1 = HH:MM:SS =  (1:30:50)
time 2 = HH:MM:SS =  (1:10:40)
time_sum = HH:MM:SS =  (2:41:30)
time_diff= HH:MM:SS =  (0:20:10)


*********************/

#endif
#if block ==3
/* Q No 3 Answer
//counts the number of objects still active using static data and static function. .
*/
//https://en.cppreference.com/w/cpp/language/static
//  class X { static int n; }; // declaration (uses 'static')
//  int X::n = 1;              // definition (does not use 'static')

#include <iostream> 
using namespace std; 
class tracker { 
private:
    static int count;   //declaration only for tracking to no of object created
    
public: 
    tracker() { 
        ++count;              
        cout << " Object created; Objects active in mem   "<<count<< endl;
    }
    ~tracker(){ 
        --count;                
        cout << " Object destroyed; Objects active in mem "<<count<< endl;  
    } 
    static void show_count(){ 
        cout << "count of obj in memory:" << count<< endl; 
    } //These functions work for the class as whole rather than for a particular object of a class.
}; 
//static members are only declared in class declaration, not defined. 
//They must be explicitly defined outside the class using scope resolution operator.
int tracker::count;    // static data in the class needs to defined globally auto initialized to 0

int main(){ 
    tracker t1, t2; 
    tracker::show_count();      // calling member function directly with class name
    {                           // creating  3rd object in limited scope 
    tracker t3; 
    tracker::show_count(); 
    }                           // scope of 3rd object finished
    tracker::show_count();
    tracker t4;
    tracker::show_count();      //note the object destroyed in reverse of creation
return 0; 
}
/* OUTPUT***************
 Object created; Objects active in mem   1
 Object created; Objects active in mem   2
count of obj in memory:2
 Object created; Objects active in mem   3
count of obj in memory:3
 Object destroyed; Objects active in mem 2
count of obj in memory:2
 Object created; Objects active in mem   3
count of obj in memory:3
 Object destroyed; Objects active in mem 2
 Object destroyed; Objects active in mem 1
 Object destroyed; Objects active in mem 0

*/
#endif
