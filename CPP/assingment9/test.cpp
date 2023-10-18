 /*
#include <iostream>
using namespace std;

template<class T>
T  sum(T *arr , int b){
    T ret = 0;
    int i;
    for(i = 0; i <b ; i++){
        ret+=arr[i];
   } 
    return ret;
}
int main(){
    int ar[10] = {1 , 2, 3,4,5,6,7,8};
    float average = sum(ar, 10)/10.0;
    cout<<"The sum is  : "<< sum<int>(ar ,10) <<endl;
   cout<<"The average is :"<<average<<endl;
    
}
*/
 /*
#include <string>
#include <iostream>
#include <cmath>
 
using namespace std;
int square_root(int); //Function prototype

int main ()
{
    int num = 0;

    cout << "Enter an integer  to find the square root of: ";
 cin  >> num;
    double num2 = num;
    double result;
    try {
        result=square_root(num );
        cout<<"square root is : "<< result <<endl;
    }
    catch (const char * str){
        cout<< str<<endl;
    }
    catch (...){
        cout<< "unknown error"<<endl;
    }

}
//Square root function
int square_root (int data)

{

    double dSqrt = sqrt((double)data); 
    if ( (dSqrt * dSqrt - data) != 0)
    { throw "Error: There is no perfect square for this number.\n"; }

    else
    { return dSqrt; } //Returns the square root

}
*/
 
 /*
 // exception_specification.cpp
// compile with: /EHs
#include <stdio.h>

void handler() {
   printf("in handler\n");
}

void f1(void) throw(int) {
   printf("About to throw 1\n");
   if (1)
      throw 1;
}

void f5(void) throw() {
   try {
      f1();
   }
   catch(...) {
      handler();
    }
}

// invalid, doesn't handle the int exception thrown from f1()
// void f3(void) throw() {
//   f1();
// }

void __declspec(nothrow) f2(void) {
   try {
      f1();
   }
   catch(int) {
      handler();
    }
}

// only valid if compiled without /EHc
// /EHc means assume extern "C" functions don't throw exceptions
extern "C" void f4(void);
void f4(void) {
   f1();
}

int main() {
   f2();

   try {
      f4();
   }
   catch(...) {
      printf("Caught exception from f4\n");
   }
   f5();
}
*/
// redirecting cout's output thrrough its stream buffer
#include <iostream>     // std::streambuf, std::cout
#include <fstream>      // std::ofstream

int main () {
  std::streambuf *psbuf, *backup;
  std::ofstream filestr;
  filestr.open ("test.txt");

  backup = std::cout.rdbuf();     // back up cout's streambuf

  psbuf = filestr.rdbuf();        // get file's streambuf
  std::cout.rdbuf(psbuf);         // assign streambuf to cout

  std::cout << "This is written to the file funny ya";

  std::cout.rdbuf(backup);        // restore cout's original streambuf

  filestr.close();

  return 0;
}
