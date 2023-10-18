/*
 * What do you understand by function template? Write down the syntax and use of the function template. WAP that will find the sum and average of elements in an array using function templates. [IOE, New Back, 2066]
 
*/
/*answer
 * 
A template is a method of declaring the function for a group of data types at once using the placeholder symbols known as a template parameter type. It is akin  to a simple instructions to the compiler on how to generate function and classes of the given type data akin to some blue print. It is a simple and yet very powerful tool in C++. The simple idea is to pass data type as a parameter so that need to write the same code for different data types is avoided. 

C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always be replaced by keyword ‘class’.

Templates work by expanding at compiler time same as the marcos but are more powerful the macros. The difference being, compiler does type checking on template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class.

syntax:

template <typename T>      //  here T is the template parameter on which other data types are cast into
T myMax(T x, T y) 
{ 
   return (x > y)? x: y; 
} 
*/

// source code
#include <iostream>
using namespace std;
template <typename T>
double average ( T * pointer, int array_size){
    T ret_value=0;
    int i=0;
    for( i=0; i< array_size; ++i){
        ret_value+= pointer[i];
    } 
    return (( (double)ret_value)/array_size);
}

int main(){
    int array1[10]={1,2,3,5,8,0,5,6,5,9};
    float array2[10]={1.1,5.4,99.2,5,6,78.2558,5556,25.002,0.111,10};
    
    cout << " average of int array1 is " <<average <int>( array1, 10)<<endl;
    cout << " average of float array2 is " <<average(array2, 10)<<endl;     // putting  <float> is optional as it is gotten by matching the data type of the passed argument.
    
}


/* output is 
 average of int array1 is 4.4
 average of float array2 is 578.607
 */
 
