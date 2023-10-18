
// global data structures
#ifndef MY_FACULTY_H        // include guard
#define MY_FACULTY_H
#include "input_.h"

#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Faculty{
protected:
        string faculty_name;
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
//#include "faculty_.cpp"
#endif //MY_FACULTY_H
