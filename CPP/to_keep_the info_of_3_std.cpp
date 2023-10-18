// rite a simple program to design a Class to keep the information of three students. For each student, you must get his/her name, rollno and see if s/he is present or absent. The class should contain two functions viz. One for input and one for display..
#include<iostream>
#include <string>   //for string
#include <iomanip>  //for setw()



using namespace std;

class Student{
    private: 
        string std_name;
        int roll_no;
        bool presence;
    public:
        Student (){                                             //default constructor
        }
    Student (string name, int roll, bool attend  ){             //build student by arguments
        std_name=name;
        roll_no=roll;
        presence=attend;
        }
    void input(){                                               // enter student data one by one
        int bad_input=0; // a huge number hoping that long wrong input wont be put this long
        
        cout << "Enter the name of the student : " ;
        getline(cin,std_name);                                  // does not leave dangling anything in the input stream
        //cout << (cin.peek())<< "ghnbn\n"                      // debug line
                                                                // big issues in the input better to  use getline                 everywhere but need to use boost library for easy conversion as there are ambiguities here how to convert characters got from getline to numbers
                                                                // and use library conversion in memory then accept or reject input
        
        do {                  // get input for the roll with error checking
            bad_input=0;
            cin.clear();                                        //clear input error state if set
            cout << "Enter the student's roll no : ";
            cin>>roll_no;                                        // just pops type data from stream 
            //cout << cin.fail() <<  endl;     // debug line    // either '\n' or others characters remain in input stream
            
            if (cin.fail()){
                bad_input=1;                                      // if cin is not in error
                cin.clear();                                      // before doing anything to input buffer need to clear buffer error
                cin.ignore(1000000,'\n');                         // ignore 1000000 ie huge no of input buffer of till '|n'  which ever comes first 
             
                //cout << cin.fail() <<"qwerty"<<  endl;          // debug line
            }
            else if( cin.peek() == EOF|| cin.peek() == '\n'){     
                                                                 // invalid data as the the input stream not empty  case where number is followed by some ascii characters.
                bad_input=0;                                     // all ok 
                                                                 // following code has to be executed for successful removal so
                cin.ignore();                                   
                                                                 // remove the ascii 10 '\n' from in stream for the next scanning of getline  as cin leaves '\n' dangling in buffer.
                }
                //cout << cin.fail() <<"ASDFGHJ"<<  endl; 
            else{                                               // re-handled here if no is followed by some dangling ascii 
                bad_input=1;
                cin.clear(); 
                cin.ignore(1000000,'\n');                       // works only  after cin error is cleared
                //cout << cin.fail() <<"zxcvbnm"<<  endl;       // debug line
            }
        }while(bad_input);   // works as it should
        
           
        char ch;
        bad_input=0;
        do {                // get input for the presence with error checking
    
            cout << "Enter y for presence and n for absence : ";
            cin>>ch;                                             // just pops one character from stream 
                                                                 // either '\n' or others characters remain in input stream
            ch =tolower(ch);                                     // lib function to change the char to lower
            //cout << (cin.peek());                              // debug line  peek the next character without popping the cin stream
            //if (cin.peek() == EOF|| cin.peek() == '\n' ){      // actually  EOF causes problem and is redunctant.
            if ( cin.peek() == '\n' ){  
                bad_input=0;    // all ok
                cin.ignore();   // remove the ascii 10 from in stream for the next scanning of getline.
             }
             else{
                 bad_input=1;
                 cout <<endl<< "Error : ";
                 cin.ignore(1000000, '\n');                     // clear to new line is ok here as on looping cin ignores white space
                 cin.clear();
            }
            
            if (ch == 'y' )
                presence=1;
            else if (ch == 'n')
                presence=0;
            else{
                bad_input=1;
                cin.clear();
                cout <<endl<< "Error : ";
            }

        }while (bad_input ==1) ;
    }
    
    
    void display(){         // displays the data in the object
        cout << endl;
        cout << setw(12) << "NAME : " << std_name <<endl;
        cout << setw(12) << "Roll No. : " << roll_no<< endl;
        cout << setw(12) << "present : "<<(presence ? "YES" : "NO") << endl;
    } 
};


//driver coded

int main(){
    Student s1( "umesh shrestha" , 29, 1);
    Student s2, s3;
    cout << " enter student's data \n" << endl;
    s2.input();
    s3.input();
    cout << "\ndisplay students : \n" << endl;
    s1.display();
    s2.display();
    s3.display();
return 0;
} 
