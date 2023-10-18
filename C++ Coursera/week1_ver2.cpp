// program to find total sum of 1 < 40 via function call by use of vector 

#include <iostream>                                         // standard input output stream 
#include <vector>                                           // vector header

using namespace std;                                        // using standard namespace
const int  N=40;                                            // equivalent to C define #define n 40
template <class Ret_, class Data_>                          // To create generic class
inline Ret_ sum(Data_ *p, int n, vector<Data_> &d)          //function call using vector no change to vector here

{
    *p = 0;
    for(int i: d)                                           // one staement for loop
        *p = *p + i;
}

int main()
{
    int accum = 0;
    vector<int> data;                                       // declaration of vector (variable size arrray)

    for(int i=1; i<N;i++)                                   
        data.push_back(i);

    sum<void,int>(&accum, N, data);                         // calling of the funtion by reference
    cout << "sum is "<< accum <<endl;                       //std::cout but std:: namespace specifier can be dropped out
    return 0;
}
