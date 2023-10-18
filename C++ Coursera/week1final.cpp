
// program to find total sum of 1 < 40 via function call by use of vector 

#include <iostream>                                         // standard input output stream 
#include <vector>                                           // vector header

using namespace std;                                        // using standard namespace
const int  N=40;                                            // equivalent to C define #define n 40
template <class Data_>                                      // To create generic class
inline Data_ sum(vector<Data_> &dim)                          //function call using vector no change to vector here
{
    Data_ val = 0;
    for(int i: dim)                                           // one statement for loop
        val += i;
    return val;
}

int main()
{
    int accum = 0;
    vector<int> data;                                       // declaration of vector (variable size arrray)
    
    for(int i=1; i<N;i++)                                   
        data.push_back(i);
    
    accum = sum<int>(data);                                 // calling of the funtion by reference
    cout << "sum is "<< accum <<endl;                       //std::cout but std:: namespace specifier can be dropped out
    return 0;
}
