 
#include <iostream>
#include <climits>
using namespace std;

class counter{
      private:
           int count;
           int max_value;
      public:
          counter (){count=0;max_value=INT_MAX;}              // default constructor
          counter (int i){                                    // parameterized constructor if default parameters are used generate call to counter() ambiguous
              count=i;
              max_value=INT_MAX;
          }
            
          counter(int i , int m){ 
              count=1; 
              max_value=m;
              
          }
          counter(counter &c){                                  //parameterized copy constructor
              count=c.count; 
              max_value=c.max_value;
              
          }
          void display (){
              cout << "count :" << count <<endl<< "max_value :"<<max_value<<endl<<endl;
          }
};
      
int main(){

      counter c1;            // object construction by use of default constructor
      counter c2(1);         // parameterized constructor 
      counter c3(1,100);     // overloaded parameterized constructor
      counter c4=c1;         // default copy constructor auto generated
      counter c5(c3);        // overloaded parameterized copy constructor
      cout << "c1"<<endl; 
      c1.display();
      cout << "c2"<<endl;
      c2.display();
      cout << "c3"<<endl;
      c3.display();
      cout << "c4"<<endl;
      c4.display();
      cout << "c5"<<endl;
      c5.display();
return 1;
}

/*  ****************OUTPUT*******************
c1
count :0
max_value :2147483647

c2
count :1
max_value :2147483647

c3
count :1
max_value :100

c4
count :0
max_value :2147483647

c5
count :1
max_value :100

************************************/
