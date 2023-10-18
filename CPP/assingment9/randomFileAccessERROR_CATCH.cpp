/*
* WAP for transaction processing that write and read object randomly to and from a random access file so that user can add, update, delete and display the account information (account number, lastname, firstname, totalbalance) [IoE, New Back, 2066]
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include "input_.h"
#define MAXLN 25
#if defined(__linux__) // any linux distribution
#define CLR "clear"
#elif defined(_WIN32) // any windows system
#define CLR "cls"
#endif
#define PAUSED ({cout <<"press any key" << endl;getchar();})
using namespace std;
class data{
private:
    int acc_num;
    char lt_name[MAXLN], ft_name[MAXLN];
    float tot_bal=0.0;
public:
    int   get_acc_num ( ) { return acc_num; }
    char* get_lt_name ( ) { return lt_name; }
    char* get_ft_name ( ) { return ft_name; }
    float get_tot_bal ( ) { return tot_bal; }
    
    void set_acc_num ( ) { input_("Enter the acc. num.  :", &acc_num);}
    void set_lt_name ( ) { input_("Enter the  last name :", lt_name, MAXLN);}
    void set_ft_name ( ) { input_("Enter the first name :", ft_name, MAXLN);}
    void set_tot_bal ( ) { input_("Enter the total bal. :", &tot_bal) ;}
    
    void add ( ) { 
        set_ft_name();
        set_lt_name();
        set_acc_num();
        set_tot_bal();
    }
    void display(){
        cout<< "first name: "<<ft_name<<endl;
        cout<< "last name : "<<lt_name<<endl;
        cout<< "acc. num. : "<<acc_num<<endl;
        cout<< "tot. bal. : "<<tot_bal<<endl;
    }
    void update (){
        int choice1;
        
        do{ 
            system(CLR);
            cout <<" select option number for editing\n"
                 <<" 1 => first name =c "<< ft_name<<"\n"
                 <<" 2 => last name  = "<< lt_name<<"\n"
                 <<" 3 => acc. num.  = "<< acc_num<<"\n"
                 <<" 4 => total bal. = "<< tot_bal<<"\n"
                 <<" 0 => exit submenu "<< endl;
            input_("Enter the choice ",&choice1);
        }while( choice1<0 || choice1 > 4);
        switch (choice1){
            case 1:
                set_ft_name();
                break;
            case 2:
                set_lt_name();
                break;
            case 3:
                set_acc_num();
                break;
            case 4:
                set_tot_bal();
                break;
            case 0:
                break;
        }
    }
    void add_record( ) {
        ofstream outfile("record.dat", ios::binary|ios::app); // open in an append mode
        add(); // add new *this
        outfile.write(reinterpret_cast<char*> (this), sizeof (*this) );
        if ( !outfile.fail() ) cout<<"\n2record add sucessful"<<endl;
        outfile.close();
        
    }
    int display_record( ){ 
        system(CLR);
        ifstream infile("record.dat", ios::binary); // open only binary mode
        int index=0;
        if (!infile){ cout<<" error! opening file, may be non-existence\n"; return index;}
        while(!infile.eof()){
            if ( (bool)(infile.read(reinterpret_cast <char*>(this),sizeof (*this)))>0){
                cout <<endl
                <<" index :"<<++index<<endl
                <<"======================================"<<endl; 
                // note the index starts form 1 not from 0
                this->display();
            }
        }
        infile.close();
        return index;
    }
    void update_record( ){
        
        int index=0;
        int count=display_record();
        if (!count ){ cout<<" No records to edit"<<endl; return; }  // file has no rec return
        
        ifstream ifile("record.dat", ios::binary);//reopen file for reading selected *this
        if (!ifile){ cout<<" error! opening file, may be non-existence\n"; return;}
        
        do{    // surprising result if the index is out of bound
               //all in between index will have null and will not occupy space in default compressed drives like ntfs and ext but on fat should fail badly
            
            cout<<"\nindex range 1 to "<<count<<endl;
            input_("select the index number to edit : ", &index);
        }while( index <1 || index > count);
        --index; //displayed index starts form 1
        
        ifile.seekg(index*sizeof(*this),ios::beg); // get the editing data in *this 
        ifile.read(reinterpret_cast<char*>(this),sizeof(*this)); //data in *this
        ifile.close();
        
        // editing here
        ofstream ofile ("record.dat", ios::binary|ios::in); // open in out mode not to overwrite
        ofile.seekp(index*sizeof(*this),ios::beg); // set the pointer to the location
        
        this->update(); // update *this object
        
        ofile.write(reinterpret_cast<char*>(this),sizeof(*this)); // write updated *this
        ofile.close();
    }
    void delete_record( ){
        int index;
        int count=display_record();
        if (!count ){
            cout<<" No records to delete"<<endl;
            return;
        }
        
        do{    // surprising result if the index is out of bound
               //all in between index will have null and will not occupy space in default compressed drives like ntfs and ext but on fat should fail badly
            
            cout<<"\nindex range 1 to "<<count<<endl;
            input_("select the index number to delete :", &index);
        }while( index <1 || index > count);
        --index;
        
        ifstream infile("record.dat", ios::binary); //reopen file for reading 
        infile.seekg(0,ios::beg); // set get pointer to start
        
        ofstream ofile("temp.dat", ios::binary); // opening temporary file
        for (int i=0;i<count;++i){  
            infile.read(reinterpret_cast<char*>(this),sizeof(*this));
            //this->display(); debug line
            if(i==index)  continue; // skip copying the *this that is to be deleted
            ofile.write(reinterpret_cast<char*>(this),sizeof(*this));
        }
        infile.close();
        ofile.close();
        
        infile.open("record.dat",ios::binary);
        ofile.open ("record.bak",ios::binary);
        ofile<<infile.rdbuf(); // save data file backup
        ofile.close();
        infile.close();
        
        infile.open("temp.dat",ios::binary);
        ofile.open("record.dat",ios::binary);
        ofile << infile.rdbuf();
        remove("temp.dat");
    }
};
int main(){
    int choice, flag=1;
    data record;
    // filename record.dat
    cout<<"\n\tAccount record system\n";
    
    do {
        cout<<"\n|\tselect from the menu\t|\n"
        << "|\t____________________\t|\n" 
        << "|\t1 => Add new record \t|\n"
        << "|\t2 => Update record  \t|\n"
        << "|\t3 => Delete record  \t|\n"
        << "|\t4 => Display record \t|\n"
        << "|\t5 => Search record  \t|\n"
        << "|\t0 => exit           \t|\n"
        <<endl;
        
        cin >> choice;
        cin.ignore();
        switch(choice){
            case 1:
                record.add_record();
                break;
            case 2:
                record.update_record();
                break;
            case 3: //delete the *this
                record.delete_record();
                break;
            case 4: //display
                record.display_record();
                break;
            case 0:
                flag= 0;
                break;
            default:
                cout<< "invalid selection nothing to edit"<<endl;
                break;
        }
    }while (flag);
    return 0;
}
