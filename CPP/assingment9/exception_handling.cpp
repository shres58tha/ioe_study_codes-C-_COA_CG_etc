/*
 What are the advantages of Exception Handling over Conventional Error Handling mechanism? Explain the constructs for Exception Handling in C++ with an example. Write a meaningful program illustrating the use of both Exception with argument and Exception Specification for function. [IoE, Regular 2068]
*/
// answer
 /*
Exceptions are the errors that occur at the run time. They are caused by wide range of the exceptional circumstances suchh as running out of the memory, not being able to open the file, trying of initialize the object with impossible values, out of bounds index in the vector and arrays, division by zero, etc etc.
Exception handling provides a way of transferring control and information to function caller that has expressed the willingness to handle exception of given type when the function itself cannot cope with the problem.
Exceptions of any types can be thrown and caught and thus resolved.

Traditionally, error handling was done by adding a piece of code in the program module for validating input data and prevent run time errors in the module.The exception handling is intended to to support error handling in programs composed of independently developed components. The notation of the exception handling is that when abnormal situation arise the program should terminate and should take necessary measure before the program termination throwing exception which allows user to find information ar the throw point that should be useful in the diagnosing of the error. 

The advantages of the exception handling over the traditional error correction are:

traditional  handling
 
 the error that is generated in the function need to be handled locally
 of the error is nor handled then the termination of whole program results
 the locally generated resolution is not visible to the user of the function
 even if error is successfully handle locally the only way to notify user the occurrence of the error is by to return some value which might be very cryptic.
 the function that terminates itself by calling function exit(); and abort(); when abnormal situation arise has no way to know what the calling function is doing and is the very bad way of resolving abnormal condition.
 the function may return a value indicating error but there is no universally accepted values and what the function intended to say to the calling remains vague.
 even if there is possibility to indicate error by return some value say normally the program returns only +ve value hence -ve return indicates some error. but this requires all the instances of the function be included in if ..... else statements to catch the neg return ie to catch the error.


exceptional throwing

the exceptional method uses three construct  try, throw, and catch to detect and resolve the errors.
any type can be thrown as exception when error is detected but use of object provides more information.
in this mechanism the control is transferred along with the value of exception from a point of the exception in the program to appropriate handle by the try block, ie the code of function generating exception should reside in the try block, Th block of code that is labeled by keyword catch the type of exception that it is  made to handles and takes the control doing whatever is necessary to resolve the situation. there can be may catch block handling different types of error.
*/
#include<iostream>
using namespace std;
class Divide
{
	private:
		int *x;
		int *y;
	public:
		Divide()
		{
			x = new int();
			y = new int();
			cout<<"Enter two numbers: ";
			cin>>*x>>*y;
			try
			{
				if(*y == 0)
				{
					throw *x;
				}
			}
			catch(int)
			{
				delete x;
				delete y;
				cout<<"Second number cannot be zero!"<<endl;
				throw;
			}
		}
		~Divide()
		{
			try
			{
				delete x;
				delete y;
			}
			catch(...)
			{
				cout<<"Error while deallocating memory"<<endl;
			}
		}
		float division()
		{
			return (float)*x / *y;
		}
};
int main()
{
	try
	{
		Divide d;
		float res = d.division();
		cout<<"Result of division is: "<<res<<endl;
		
	}
	catch(...)
	{
		cout<<"Unkown exception!"<<endl;
	}
	return 0;
}
 
// Input and output for the above program is as follows:
 
//Enter two numbers: 5 0
//Second number cannot be zero!
//Unkown exception!

/*
///////////////////////////////////sujit////////////////////////////////////

The major advantage of Exception handling over traditional error handling are as follows:
Separation  from main code : In conventional error handling we use conditions to handle errors within the main code which get mixed with the   normal flow making the code less readable and less maintainable
while in Exception handling we use try catch block for error  handling separating the error handling code separate from the normal main code .
Allows selective trapping of the code through multiple catch statements leads to meaningful error handling and reporting.
Grouping of error types : In C++ , both basic types and objects can be thrown as exceptions . We can create a hierarchy of exception objects, group exceptions in namespaces or classes , categorize them according to types.

The constructs for exception handling in C++ are (Try , Catch , Throw)
• Find the problem (Hit the exception)
• Inform that an error has occurred (Throw the exception)
• Receive the error information(Catch the exception)
• Take corrective actions (Handle the exception)


• The try block is used to preface a block of statements which may generate
exceptions.
• When an exception is detected, it is thrown using throw statement in the try
block.
• A catch block defined by the keyword catch catches the exception thrown by      the  throw statement in the try block and handle it appropriately.
• The catch block that catches an exception must immediately follow the try block
that throws an exception.
 

 One of the advantages of C++ over C is Exception Handling. Exceptions are run-time anomalies or abnormal conditions that a program encounters during its execution. There are two types of exceptions: a)Synchronous, b)Asynchronous(Ex:which are beyond the program’s control, Disc failure etc). C++ provides following specialized keywords for this purpose.
try: represents a block of code that can throw an exception.
catch: represents a block of code that is executed when a particular exception is thrown.
throw: Used to throw an exception. Also used to list the exceptions that a function throws, but doesn’t handle itself.

Why Exception Handling? 
Following are main advantages of exception handling over traditional error handling.

1) Separation of Error Handling code from Normal Code: In traditional error handling codes, there are always if else conditions to handle errors. These conditions and the code to handle errors get mixed up with the normal flow. This makes the code less readable and maintainable. With try catch blocks, the code for error handling becomes separate from the normal flow.

2) Functions/Methods can handle any exceptions they choose: A function can throw many exceptions, but may choose to handle some of them. The other exceptions which are thrown, but not caught can be handled by caller. If the caller chooses not to catch them, then the exceptions are handled by caller of the caller. 
In C++, a function can specify the exceptions that it throws using the throw keyword. The caller of this function must handle the exception in some way (either by specifying it again or catching it)

3) Grouping of Error Types: In C++, both basic types and objects can be thrown as exception. We can create a hierarchy of exception objects, group exceptions in namespaces or classes, categorize them according to types.



Exception Handling in C++

1) Following is a simple example to show exception handling in C++. The output of program explains flow of execution of try/catch blocks. 

filter_none
edit
play_arrow

brightness_4
#include <iostream>
using namespace std;
 
int main()
{
   int x = -1;
 
   // Some code
   cout << "Before try \n";
   try {
      cout << "Inside try \n";
      if (x < 0)
      {
         throw x;
         cout << "After throw (Never executed) \n";
      }
   }
   catch (int x ) {
      cout << "Exception Caught \n";
   }
 
   cout << "After catch (Will be executed) \n";
   return 0;
}
Output: 

Before try
Inside try
Exception Caught
After catch (Will be executed)
2) There is a special catch block called ‘catch all’ catch(…) that can be used to catch all types of exceptions. For example, in the following program, an int is thrown as an exception, but there is no catch block for int, so catch(…) block will be executed. 

filter_none
edit
play_arrow

brightness_4
#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 10;
    }
    catch (char *excp)  {
        cout << "Caught " << excp;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }
    return 0;
}
Output: 

Default Exception
3) Implicit type conversion doesn’t happen for primitive types. For example, in the following program ‘a’ is not implicitly converted to int 

filter_none
edit
play_arrow

brightness_4
#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 'a';
    }
    catch (int x)  {
        cout << "Caught " << x;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }
    return 0;
}
Output: 

Default Exception
4) If an exception is thrown and not caught anywhere, the program terminates abnormally. For example, in the following program, a char is thrown, but there is no catch block to catch a char.  



filter_none
edit
play_arrow

brightness_4
#include <iostream>
using namespace std;
 
int main()
{
    try  {
       throw 'a';
    }
    catch (int x)  {
        cout << "Caught ";
    }
    return 0;
}
Output: 

terminate called after throwing an instance of 'char'

This application has requested the Runtime to terminate it in an 
unusual way. Please contact the application's support team for 
more information.
We can change this abnormal termination behavior by writing our own unexpected function.
5) A derived class exception should be caught before a base class exception. See this for more details.
6) Like Java, C++ library has a standard exception class which is base class for all standard exceptions. All objects thrown by components of the standard library are derived from this class. Therefore, all standard exceptions can be caught by catching this type
7) Unlike Java, in C++, all exceptions are unchecked. Compiler doesn’t check whether an exception is caught or not (See this for details). For example, in C++, it is not necessary to specify all uncaught exceptions in a function declaration. Although it’s a recommended practice to do so. For example, the following program compiles fine, but ideally signature of fun() should list unchecked exceptions. 

filter_none
edit
play_arrow

brightness_4
#include <iostream>
using namespace std;
 
// This function signature is fine by the compiler, but not recommended.
// Ideally, the function should specify all uncaught exceptions and function
// signature should be "void fun(int *ptr, int x) throw (int *, int)"
void fun(int *ptr, int x)
{
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
    // Some functionality 
}
 
int main()
{
    try {
       fun(NULL, 0);
    }
    catch(...) {
        cout << "Caught exception from fun()";
    }
    return 0;
}
Output: 

Caught exception from fun()
A better way to write above code 

filter_none
edit
play_arrow

brightness_4
#include <iostream>
using namespace std;
 
// Here we specify the exceptions that this function 
// throws.
void fun(int *ptr, int x) throw (int *, int)
{
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
    //Some functionality 
}
 
int main()
{
    try {
       fun(NULL, 0);
    }
    catch(...) {
        cout << "Caught exception from fun()";
    }
    return 0;
}
Output: 

Caught exception from fun()
8) In C++, try-catch blocks can be nested. Also, an exception can be re-thrown using “throw; ” 

filter_none
edit
play_arrow

brightness_4
#include <iostream>
using namespace std;
 
int main()
{
    try {
        try {
            throw 20;
        }
        catch (int n) {
            cout << "Handle Partially ";
            throw; // Re-throwing an exception
        }
    }
    catch (int n) {
        cout << "Handle remaining ";
    }
    return 0;
}
Output: 

Handle Partially Handle remaining
A function can also re-throw a function using same “throw; “. A function can handle a part and can ask the caller to handle remaining.
9) When an exception is thrown, all objects created inside the enclosing try block are destructed before the control is transferred to catch block.

filter_none
edit
play_arrow

brightness_4
#include <iostream>
using namespace std;
 
class Test {
public:
    Test() { cout << "Constructor of Test " << endl; }
    ~Test() { cout << "Destructor of Test " << endl; }
};
 
int main()
{
    try {
        Test t1;
        throw 10;
    }
    catch (int i) {
        cout << "Caught " << i << endl;
    }
}
Output: 

Constructor of Test
Destructor of Test
Caught 10



The general syntax is :



try {

.......
throw exception;

...

} catch(type args){

.....

...

}

#include <iostream>
using namespace std;
 
int main()
{
   int x = -1;
 
   cout << "Before try \n";
   try {
      cout << "Inside try \n";
      if (x < 0)
      {
         throw x;
         cout << "After throw (Never executed) \n";
      }
   }
   catch (int x ) {
      cout << "Exception Caught \n";
   }
 
   cout << "After catch (Will be executed) \n";
   return 0;
}

Output :
Before try
Inside try
Exception Caught
After catch (Will be executed)
#include<iostream>
using namespace std;

void result(char x) throw(int, char, double){ // empty throw list and check
    if (x=='q'){
        throw x;
    }else if(x=='a'){
        throw 'r';
    }else if(x=='w'){
        throw 2.7;
    }
}

int main(){
    try{
        result('w');
    }catch(int i){
        cout << "Integer: " << i << endl;
    }catch(char ch){
        cout << "Character: " << ch << endl;
    }catch(double v){
        cout << "Double : " << v << endl;
    }
    
    return 0;
}

Output : 
Double : 2.7

*/
