#include <iostream>

using namespace std;

void input_( string str, string *p){  // input string to string pointer
        do{
            if (cin.fail()){cin.clear(); while (cin.ignore(100000000,'\n'));}
            cout << str ;      // prompt 
            getline(cin,*p);   // does not leave dangling anything in the input stream
        }while(cin.fail() || p->empty());
}

// using template for the number type
void input_( string str, int *p){  // input int to int pointer
        int error;
        do {                  // get input  with error checking
            error=0;
            if (cin.fail()){ cin.clear();  cin.ignore(100000000,'\n');}
            cout << str;
            cin>>*p;   
            if (cin.peek()!='\n') {cin.ignore(100000000,'\n');error=1;}
            else cin.ignore();
        }while(cin.fail()||error );
}
    
void input_( string str, float *p){  // input float to float pointer
        int error;
        do {                  // get input  with error checking
            error=0;
            if (cin.fail()){ cin.clear();  cin.ignore(100000000,'\n');}
            cout << str;
            cin>>*p;   
            if (cin.peek()!='\n') {cin.ignore(100000000,'\n');error=1;}
            else cin.ignore();
        }while(cin.fail()||error );
}

void input_( string str, double *p){  // input double to double pointer
        int error;
        do {                  // get input  with error checking
            error=0;
            if (cin.fail()){ cin.clear();  cin.ignore(100000000,'\n');}
            cout << str;
            cin>>*p;   
            if (cin.peek()!='\n') {cin.ignore(100000000,'\n');error=1;}
            else cin.ignore();
        }while(cin.fail()||error );
}

void input_( string str, bool *p){  // input bool to bool pointer 
        int error;
        do {                  // get input  with error checking
            error=0;
            if (cin.fail()){ cin.clear();  cin.ignore(100000000,'\n');}
            cout << str;
            cin>>*p;   
            if (cin.peek()!='\n') {cin.ignore(100000000,'\n');error=1;}
            else cin.ignore();
        }while(cin.fail()||error );
}

void input_yn_( bool *p){  // input bool to bool pointer 
        char ch;
        int bad_input;
        do {           // get input  with error checking
            bad_input=0;
            if (cin.fail()){ cin.clear();  cin.ignore(100000000,'\n');}
            cout << "Enter y for true and n for false : ";
            cin>>ch;    
            ch =tolower(ch);                                     
            if ( cin.peek() == '\n' ){
                cin.ignore();    // remove the '/n' from in stream for the next scanning
                if (ch == 'y') *p=1;
                else if (ch == 'n') *p=0;
                else bad_input=1;
            }
            else
                bad_input=1;
                
        }while(bad_input);
}
