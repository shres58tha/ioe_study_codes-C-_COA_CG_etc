/* wap a friend function to compare data member of two different class and display the largest one*/
#include <iostream>
using namespace std;
class A;
class B;
int max( A , B);
class A{
    int num;
public:
    A(int x):num(x){}
     friend int max( A, B);
};
class B{
    int num;
public:
    B(int x):num(x){}
          friend int max( A, B);
};
int max( A a, B b){  return ( a.num > b.num ? a.num : b.num );  }
int main(){
    A a(5);
    B b(6);
    cout << " the max num is "<< max ( a, b )<<endl;
    
}
