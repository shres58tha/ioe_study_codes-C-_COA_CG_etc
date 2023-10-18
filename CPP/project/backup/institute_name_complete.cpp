// class for institute object 
#include "institute_name.h"

using namespace std;
class institute {
protected:
        string name;
        string address;
        vector <unsigned long int> contact_number;
        vector <string> email;
public: 
        void input_name ( )  { input_("Enter the Institute Name :", &name); }
        
        void input_address ( )  { input_("Enter the address :", &address);  }
        
        void input_contact_number( )  {
            unsigned long int temp;
            while (1){
                cout<< "Enter 0 if no more numbers"<<endl;
                input_("Enter the contact number :", &temp);
                if (temp == 0) break;
                contact_number.push_back(temp); 
            }
        }
        
        void input_email ( )   {
            string temp;
            while (1){
                cout<< "Enter 0 if no more email addresses"<<endl;
                input_("Enter the email address :", &temp);
                if (temp == "0") break;
                email.push_back(temp);            
            }
        }
        
        void input_data ( ) {
            cout << "Enter Institute information"<<endl;
            input_name();
            input_address();
            input_contact_number();
            input_email();
        }
    
        void show_data ( )    {
        cout <<setw(14)<<"Name :"<< name<<endl;
        cout <<setw(14)<<"Address :"<< address<<endl;   
        for(unsigned long int x: contact_number ) 
            cout<<setw(14)<<"Contact No.:"<< x<<endl;
        for( string x: email ) 
            cout<<setw(14)<<"email :"<< x<<endl;
        }
        
};
    

