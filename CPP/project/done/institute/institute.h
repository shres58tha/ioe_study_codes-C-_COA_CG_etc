 
// global data structures
#ifndef MY_INSTITUTE_H        // include guard
#define MY_INSTITUTE_H
#include "input_.h"

#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class institute {
protected:
        string name;
        string address;
        vector <unsigned long int> contact_number;
        vector <string> email;
public: 
        void input_name           ( ) ;        
        void input_address        ( ) ;        
        void input_contact_number ( ) ;
        void input_email          ( ) ; 
        void input_data           ( ) ;
        void show_data            ( ) ;
};

#endif //MY_INSTITUTE_H
