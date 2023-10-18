// input header file
#include <iostream>
#include <string>   //for string
#include <iomanip>  //for setw()

using namespace std;

void input_( string str, string *p){  // input string to string pointer
        do{
            if (cin.fail()){cin.clear(); while (cin.ignore(100000000,'\n'));}
            cout << str ;      // prompt 
            getline(cin,*p);   // does not leave dangling anything in the input stream
        }while(cin.fail() || p->empty());
}

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
        
        do {                  // get input with  error checking
            if (cin.fail())cin.clear();
            while (cin.peek()!=EOF){ cin.ignore();}
            cout << str;
            cin>>*p;    
        }while(cin.fail());
}

void input_( string str, double *p){  // input double to double pointer
        
        do {                  // get input  with error checking
            if (cin.fail())cin.clear();
            while (cin.peek() == EOF){ cin.ignore();}
            cout << str;
            cin>>*p;    
        }while(cin.fail());
}

void input_( string str, bool *p){  // input bool to bool pointer 
        
        do {                  // get input  with error checking
            if (cin.fail())cin.clear();
            while (cin.peek() == EOF){ cin.ignore();}
            cout << str;
            cin>>*p;    //0 or 1 only
        }while(cin.fail());
}

void input_yn_( bool *p){  // input bool to bool pointer 
        char ch;
        int bad_input=0;
        do {                  // get input  with error checking
            if (cin.fail())cin.clear();
            while (cin.peek() == EOF){ cin.ignore();}
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

/*test above in driver*/
class Student{
    private: 
        string std_name;
        int roll_no;
        bool presence;
        float due;      // not implemented yet
        float discount; //not implemented yet
        float paid_amount; // not implemented
        int  paid_till_month; //not implemented
//<inherit time >          // year of the enrollment
                            // structure for month variable enum listing names of the months from the jan = 1  to dec =12
                            //quaterly information etc.
//<inherit group> 
        /*total fee for the course
         entry year
         libary due:
         laboratory due:
         tution fee:
         transportation fees;
         misc fees;
         etc adn all the description of the fees
         */
        
        
    public:
        Student (){                                             //default constructor
        }
        Student (string name, int roll, bool attend  ){             //build student by arguments
            std_name=name;
            roll_no=roll;
            presence=attend;
            }
        void input();
        void display();
};

void Student::input(){
        input_("Enter the name of student: ", &std_name);
        input_( "Enter the roll no: ",  &roll_no);
        //input_bool_yn( &presence);
}
void Student::display(){         // displays the data in the object
        cout << endl;
        cout << setw(12) << "NAME : " << std_name <<endl;
        cout << setw(12) << "Roll No. : " << roll_no<< endl;
        cout << setw(12) << "present : "<<(presence ? "YES" : "NO") << endl;
} 



//driver coded

int main(){
    Student s1( "umesh shrestha" , 29, 1);
    Student s2, s3;
    cout << " enter student's data \n" << endl;
    s1.input();
    s2.input();
    s3.input();
    cout << "\ndisplay students : \n" << endl;
    s1.display();
    s2.display();
    s3.display();
return 0;
} 
