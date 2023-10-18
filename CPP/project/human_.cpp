// functios defination for Human object 
#include "human_.h"
using namespace std;

void Human::input_name ( ){ 
    input_("Enter the Institute Name :", &name); 
}
        
void Human::input_address ( ){ 
        input_("Enter the address :", &address);  
}
        
void Human::input_contact_number( ) {
    unsigned long int temp;
    while (1){
        std::cout<< "Enter 0 if no more numbers"<<std::endl;
        input_("Enter the contact number :", &temp);
        if (temp == 0) break;
        contact_number.push_back(temp); 
    }
}

void Human::input_email ( ) { 
    std::string temp;
        while (1){
            std::cout<< "Enter 0 if no more email addresses"<<std::endl;
            input_("Enter the email address :", &temp);
            if (temp == "0") break;
            email.push_back(temp);            
        }
}
        
void Human::input_data ( ) {
    std::cout << "Enter Institute information"<<std::endl;
    input_name();
    input_address();
    input_contact_number();
    input_email();
}
    
void Human::show_data ( ) {
    std::cout <<std::setw(14)<<"Name :"<< name<<std::endl;
    std::cout <<std::setw(14)<<"Address :"<< address<<std::endl;   
    for(unsigned long int x: contact_number ) 
        std::cout<<std::setw(14)<<"Contact No.:"<< x<<std::endl;
    for( std::string x: email ) 
        std::cout<<std::setw(14)<<"email :"<< x<<std::endl; 
}

string Human::get_name ( ) { return (name);}
string Human::get_address ( ) { return (address);}

        

    
        
    

