// useage : input_ ( string to be desplayed for prompt, pointer to data to be saved)
// input_ overloaded
// failed to put it in another file as not sure how to declare template class in h file
// global functions

#ifndef MY_INPUT_H // include guard
#define MY_INPUT_H

#include <iostream>
#include <string>   //for string
#include <iomanip>
#include <cstring>

#define MAX_CH 25
#define MAX_ENTRY 2000

#if defined(__linux__) // any linux distribution
#define CLR "clear"
#elif defined(_WIN32) // any windows system
#define CLR "cls"
#endif

#define PAUSED ({cout <<"press any key" << endl;getchar();})
using namespace std;

template< class T_NUM>
void input_( std::string str, T_NUM *p) { // get input  with error checking
    int error;
    do {
        error=0;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000000,'\n');
        }
        std::cout << str;
        std::cin>>*p;
        if (std::cin.peek()!='\n') {
            std::cin.ignore(100000000,'\n');
            error=1;
        } else std::cin.ignore();
    } while(std::cin.fail()||error );
}

void input_( std::string str, std::string *p) { // input string to string pointer  // template overloaded
    do {
        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.ignore(100000000,'\n'));
        }
        std::cout << str ;      // prompt
        while ( std::cin.peek() == '\n') std::cin.ignore();
        std::getline(std::cin,*p);   // does not leave dangling anything in the input stream
    } while(std::cin.fail() || p->empty());
}

void input_( std::string str, char *p, unsigned int max_char) {
    std::string temp;
    input_( str, &temp);
    if (temp.length() >=max_char) {
        std::cout<<"buffer overflow error the entered text will be truncated"<<std::endl;
    }
    strncpy( p, temp.c_str(), max_char);
    //strcpy(char_array, s.c_str());
}

void input_( bool *p) {  // template overloaded
    char ch;
    int bad_input;
    do {           // get input  with error checking
        bad_input=0;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100000000,'\n');
        }
        std::cout << "Enter 'y' for true and 'n' for false : ";
        std::cin>>ch;
        ch =std::tolower(ch);
        if ( std::cin.peek() != '\n' ) {
            std::cin.ignore(100000, '\n');
            bad_input=1;
        } else
            std::cin.ignore();// remove the '/n' from in stream for the next scanning
        if (ch == 'y') *p=1;
        else if (ch == 'n') *p=0;
        else bad_input=1;

    } while(bad_input);
}

void input_choice( std::string str, int *p, int n) { // get choice val from 0 to n
    int temp;
    do {
        input_( str, &temp);
    } while(temp <0 || temp>=n );
    *p=temp;
}

#endif /* MY_INPUT_H */
