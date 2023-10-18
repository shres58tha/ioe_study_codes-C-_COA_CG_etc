#include <iostream>
#include "human_.h" 
#include "tempus_.h"
using namespace std;
/*
int main(){
    Human college;
    college.input_data();
    cout <<endl;
    college.show_data();   
    
return 0;    
}
//*/

// c++ program to demonstrate 
// example of localtime() function. 
  
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    time_t time_ptr; 
    time_ptr = time(NULL); 
  
    // Get the localtime 
    tm* tm_local = localtime(&time_ptr); 
  
    cout << "Current local time is = "
         << tm_local->tm_hour << ":"
         << tm_local->tm_min << ":"
         << tm_local->tm_sec; 
  
         
    Tempus current_d;
    Tempus temp_d;            //temp_ name used somewhere i guess in ctime may be
    temp_d.set_date();
    current_d.current_date(); // local time should be better in the loop
std::time_t t=std::time (NULL);   // can be used as time stamp


    return 0; 
} 
