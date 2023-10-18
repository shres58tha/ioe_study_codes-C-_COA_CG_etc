 
 /*
  *  WAP to find the square root of a given number. Check the validity of input number and raise the exception as per the requirement. [IoE, 2072 Regular]
  */
 
 #include <iostream>
 #include <cmath>
 using namespace std;
 
 class sq_root{
 private:
     float number, root;
 public:
     sq_root(float a): number(a){   // throw here
         if ( a < 0 )
             throw " the number cannot be negative ";   // throw char * type 
         else {
              root=sqrt(number);
              if ( (int) root== root)
                  throw ( (int)root) ;  // throw int type
              else
                  throw root;      // throw float type
         }
     }
 };
 int main() {
     float num;
     cout << "enter any number :";
     cin>> num;
     try{   //try here
         sq_root r(num);    // try here
     }
     catch (int result){    // int type throw handled here by proper display
         cout << " the input number " << num << " is a perfect square\n";
         cout << " the root is "<<result<<endl;
         
     }
     catch (float result){ // float type throw handled here with proper display
         cout<<"square root is : "<< result <<endl;
     }
     catch ( char *str){   // string type throw handled here
         cout << str <<endl;
     }
     catch(...)             // default catch all expression 
     {
         cout<<"Unknown exception!"<<endl;
     }
     return 0;
 }
 
 //output
 /*
$ ./a.out 
enter any number :9
 the input number 9 is a perfect square
 the root is 3
$ ./a.out 
enter any number :5
square root is : 2.23607
$ ./a.out 
enter any number :-1
Unknown exception!
$ 

   
   */
