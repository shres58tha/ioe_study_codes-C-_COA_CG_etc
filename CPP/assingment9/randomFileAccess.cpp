/*
WAP for transaction processing that write and read object randomly to and from a random access file so that user can add, update, delete and display the account information (account number, lastname, firstname, totalbalance)  [IoE, New Back, 2066]

*/
#include <iostream>
#include <fstream>
#include <string>
#define MAXLN 25
using namespace std;

class data{
private:
    int acc_num;
    char lt_name[MAXLN], ft_name[MAXLN];
    float tot_bal=0.0;
public:
    int get_acc_num ( ) { return acc_num; }
    char* get_lt_name ( ) { return lt_name; }
    char *get_ft_name ( ) { return ft_name; }
    float get_tot_bal ( ) { return tot_bal; }
    void set_acc_num ( ) { 
        cout << "Enter the account number :";
        cin  >> acc_num;
    }
    void set_lt_name ( ) { 
        cout << "2Enter the last name :";
        cin  >> lt_name;
    }
    void set_ft_name ( ) {  
        cout << "Enter the first name :";
        cin  >> ft_name;
    }
    void set_tot_bal ( ) { 
        cout << "Enter the total balance :";
        cin  >>tot_bal;
    }
    
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
    };
   
    void update (){
        int choice1;
        cout << "select option number for editing\n";
        cout << " 1 => first name = "<< ft_name<< "\n"
             << " 2 => last name  = "<< lt_name<< "\n"
             << " 3 => acc. num.  = "<< acc_num<< "\n"
             << " 4 => total bal. = "<< tot_bal<< "\n"
             << " 0 => exit submenu "<< endl;
             
        cout << "Enter the choice "<< endl;
        cin  >> choice1;
        
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
            default:
                cout<< "invalid selection nothing to edit"<<endl;
                break;
        }
        
    }
};

int main(){
    int choice, flag=1;
    data record;
    // filename record.dat
    cout<<"Account record system\n";
    do {
        cout<<"\n|\tselect from the menu\t|\n"
             << "|\t____________________\t|\n"  
             << "|\t1 => Add new record \t|\n"
             << "|\t2 => Update  record \t|\n"
             << "|\t3 => Delete  record \t|\n"
             << "|\t4 => Display record \t|\n"
             << "|\t0 => exit           \t|\n"
             <<endl;
        cin >> choice;
        
        switch(choice){
            
            case 1:
            {
                ofstream outfile("record.dat", ios::binary|ios::app); // open in an append mode
                record.add();   // add new record
                outfile.write(reinterpret_cast<char*> (&record), sizeof (record) );
                outfile.close();
                break;
            }
            case 2:
            {
                ifstream ifile("record.dat", ios::binary); // open in out mode
                int count, index=0;
                
                if (!ifile){ cout<<" error! opening file, may be non-existence \n";  break;}
                ifile.seekg(0,ios::end);
                count=ifile.tellg()/sizeof(record);
                ifile.seekg(0,ios::beg);// calling twice failed always why??
        
                while(!ifile.eof()){
                    if ( (bool) ( ifile.read(reinterpret_cast <char*>(&record),sizeof (record)) )>0 ){
                        cout <<endl
                        <<"index :"<<++index<<endl
                        <<"======================================"<<endl;
                        record.display();
                        }
                }
                ifile.close(); // why this closing is needed for using seekg() 2nd time 
                
                cout<< "select the index number to edit"<<endl;
                cin>>index;
                --index; //displayed index starts form 1
                
                ifile.open("record.dat", ios::binary);  //reopen file for reading the selected record from file
                ifile.seekg(index*sizeof(record),ios::beg);  // get the editing data in record                
                ifile.read(reinterpret_cast<char*>(&record),sizeof(record)); //data in record
                ifile.close();
                
                // editing here
                ofstream ofile ("record.dat", ios::binary|ios::in); // open in out mode not to overwrite
                ofile.seekp(index*sizeof(record),ios::beg);  // set the pointer to the location
                
                record.update();  // update record object
                
                ofile.write(reinterpret_cast<char*>(&record),sizeof(record)); // write updated record
                ofile.close();
                
                break;
            }
            case 3:  //delete the record
                // temp file = temp.dat
            {
                ifstream infile("record.dat", ios::binary); // open in out mode
                int count, index=0;
                
                if (!infile){ cout<<" error! opening file, may be non-existence \n";  break;}
                infile.seekg(0,ios::end);
                count=infile.tellg()/sizeof(record);
                infile.seekg(0,ios::beg);   // calling twice failed always why??
        
                while(!infile.eof()){
                    if ( (bool) ( infile.read(reinterpret_cast <char*>(&record),sizeof (record)) )>0 ){
                        cout <<endl
                        <<"index :"<<++index<<endl
                        <<"======================================"<<endl;
                        record.display();
                        }
                }
                infile.close();
                
                cout<< "select the index number to delete"<<endl;
                cin>>index;
                --index;
                
                infile.open("record.dat", ios::binary);  //reopen file for reading 
                infile.seekg(0,ios::beg);  // set get pointer to start
            
                ofstream tmpfile("temp.dat", ios::binary);  // opening temporary file
                for (int i=0; i<count;++i){
                    infile.read(reinterpret_cast<char*>(&record),sizeof(record));
                    record.display();
                    if(i==index)
                        continue;  // skip copying the record that is to be deleted
                    tmpfile.write(reinterpret_cast<char*>(&record),sizeof(record));
                }
                infile.close();
                tmpfile.close();
                rename ("record.dat", "record.bak");  // keeps backup in record.bak
                if (rename ("temp.dat","record.dat"))
                    cout << "delete operation not successful original in record.bak";
                else 
                    remove("record.bak");
        
                break;
            }
            case 4:  //display
            {  // this can be put in a function as this code is repeated 2 times above
                ifstream infile("record.dat", ios::binary); // open only binary mode
                int index=0;
                int count=infile.tellg()/sizeof(record);
                if (!infile){ cout<<" error! opening file, may be non-existence \n";  break;}
                while(!infile.eof()){
                   if ( (bool)(infile.read(reinterpret_cast <char*>(&record),sizeof (record)))>0){
                    cout <<endl
                    <<" index :"<<++index<<endl
                    <<"======================================"<<endl;  
                    // note the index starts form 1 not from 0
                    record.display();
                    }
                }
    
                break;
            }
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


/*OUTPUT**
Account record system

|       select from the menu    |
|       ____________________    |
|       1 => Add new record     |
|       2 => Update  record     |
|       3 => Delete  record     |
|       4 => Display record     |
|       0 => exit               |

1
Enter the first name :1
2Enter the last name :1
Enter the account number :1
Enter the total balance :1

|       select from the menu    |
|       ____________________    |
|       1 => Add new record     |
|       2 => Update  record     |
|       3 => Delete  record     |
|       4 => Display record     |
|       0 => exit               |

1
Enter the first name :2
2Enter the last name :2
Enter the account number :2
Enter the total balance :2

|       select from the menu    |
|       ____________________    |
|       1 => Add new record     |
|       2 => Update  record     |
|       3 => Delete  record     |
|       4 => Display record     |
|       0 => exit               |

3

1
======================================
first name: 1
last name : 1
acc. num. : 1
tot. bal. : 1

2
======================================
first name: 2
last name : 2
acc. num. : 2
tot. bal. : 2
select the index number to delete
3
first name: 1
last name : 1
acc. num. : 1
tot. bal. : 1
first name: 2
last name : 2
acc. num. : 2
tot. bal. : 2

|       select from the menu    |
|       ____________________    |
|       1 => Add new record     |
|       2 => Update  record     |
|       3 => Delete  record     |
|       4 => Display record     |
|       0 => exit               |

3

1
======================================
first name: 1
last name : 1
acc. num. : 1
tot. bal. : 1

2
======================================
first name: 2
last name : 2
acc. num. : 2
tot. bal. : 2
select the index number to delete
2
first name: 1
last name : 1
acc. num. : 1
tot. bal. : 1
first name: 2
last name : 2
acc. num. : 2
tot. bal. : 2

|       select from the menu    |
|       ____________________    |
|       1 => Add new record     |
|       2 => Update  record     |
|       3 => Delete  record     |
|       4 => Display record     |
|       0 => exit               |

4

1
======================================
first name: 1
last name : 1
acc. num. : 1
tot. bal. : 1

|       select from the menu    |
|       ____________________    |
|       1 => Add new record     |
|       2 => Update  record     |
|       3 => Delete  record     |
|       4 => Display record     |
|       0 => exit               |

2

1
======================================
first name: 1
last name : 1
acc. num. : 1
tot. bal. : 1
select the index number to edit
1
select option number for editing
 1 => first name = 1
 2 => last name  = 1
 3 => acc. num.  = 1
 4 => total bal. = 1
 0 => exit submenu 
Enter the choice 
5
invalid selection nothing to edit

|       select from the menu    |
|       ____________________    |
|       1 => Add new record     |
|       2 => Update  record     |
|       3 => Delete  record     |
|       4 => Display record     |
|       0 => exit               |

50000
invalid selection nothing to edit

|       select from the menu    |
|       ____________________    |
|       1 => Add new record     |
|       2 => Update  record     |
|       3 => Delete  record     |
|       4 => Display record     |
|       0 => exit               |

2

1
======================================
first name: 1
last name : 1
acc. num. : 1
tot. bal. : 1
select the index number to edit
1
select option number for editing
 1 => first name = 1
 2 => last name  = 1
 3 => acc. num.  = 1
 4 => total bal. = 1
 0 => exit submenu 
Enter the choice 
4
Enter the total balance :5000

|       select from the menu    |
|       ____________________    |
|       1 => Add new record     |
|       2 => Update  record     |
|       3 => Delete  record     |
|       4 => Display record     |
|       0 => exit               |

4

1
======================================
first name: 1
last name : 1
acc. num. : 1
tot. bal. : 5000

|       select from the menu    |
|       ____________________    |
|       1 => Add new record     |
|       2 => Update  record     |
|       3 => Delete  record     |
|       4 => Display record     |
|       0 => exit               |




*/
