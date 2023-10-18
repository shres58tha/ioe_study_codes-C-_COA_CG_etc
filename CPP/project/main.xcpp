#include <iostream>
#include <string>   //for string
#include <iomanip>  //for setw()
#include "input_.h"
using namespace std;

/*test above in driver*/
class Student{
    private: 
        string std_name;
        int roll_no;
        bool presence,val;
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
        input_("enter Due: ", &due);
        input_("enter 1 for true and 0 for false: " , &presence);
        input_(&val);
}
void Student::display(){         // displays the data in the object
        cout << endl;
        cout << setw(12) << "NAME : " << std_name <<endl;
        cout << setw(12) << "Roll No. : " << roll_no<< endl;
        cout << setw(12) << "Due: "<<due << endl;
        cout << setw(12) << "present : "<<(presence ? "YES" : "NO") << endl;
        cout << setw(12) << "val: " << val<<endl;
} 

//driver coded
int main(){
    Student s1("umesh shrestha" , 29, 1);
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
