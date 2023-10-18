
// global data structures
#ifndef MY_HUMAN_H        // include guard
#define MY_HUMAN_H
#include "input_.h"

#include <string>
#include <iomanip>
#include <vector>


class Human{
protected:
        std::string name;
        std::string address;
        std::vector <unsigned long int> contact_number;
        std::vector <std::string> email;
public:
        void input_name           ( ) ;
        void input_address        ( ) ;
        void input_contact_number ( ) ;
        void input_email          ( ) ;
        void input_data           ( ) ;
        void show_data            ( ) ;
        std::string get_name           ( ) ;// need to implement this get required for searching
        std::string get_address        ( ) ;//
    //  std::string get_contact_number ( ) ;// wont implement these
    //  std::string get_email          ( ) ;// wont implement these

};
//#include "human_.cpp"

#endif //MY_INSTITUTE_H
