// WAP for transaction processing that write and read object randomly to and from a random access file so that user can add, update, delete and display the account information (account number, last name, firstname, totalbalance)
 
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
 
class Acc_Record{
private:
    int account_number;
    char first_name[20];
    char last_name[20];
    int total_balance;
 
public:
    int get_account_number() { return account_number; }
    void input_record();
    void add_record();
    void display_record();
    void delete_record();
};
 
void Acc_Record ::input_record(){
    cout << "\nEnter client records\n";
    cout << "Enter account number: ";
    cin >> account_number;
    cin.ignore();
    cout << "Enter first name: ";
    cin >> first_name;
    cin.ignore();
    cout << "Enter last name: ";
    cin >> last_name;
    cout << "Enter total_balance: ";
    cin >> total_balance;
    //we should not allow to enter the total balance, but the quesion says so.
}
 
void Acc_Record ::add_record(){
    ofstream outfile;
    input_record();
    outfile.open("record.dat", ios::app);
    outfile.write((char *)this, sizeof(*this));
    outfile.close();
}
 
void Acc_Record::display_record(){
    cout << "\n\nAccount number:\t" << account_number << endl;
    cout << "First name:\t" << first_name << endl;
    cout << "Last name:\t" << last_name << endl;
    cout << "Total Balance\t" << total_balance << endl
         << endl;
}
 
void display_all_records(){
    Acc_Record temp;
    ifstream infile;
    infile.open("record.dat");
    cout << "Acc_Record records are as follows\n";
    while (infile.read((char *)&temp, sizeof(temp)))
    {
        temp.display_record();
    }
    infile.close();
}
 
void modify_record(){
    int location, acc; //to store the location where we found the acc no.
    //bool record_found = false;
    Acc_Record client, temp_client;
    cout << "Enter the account number: ";
    cin >> acc;
 
    ifstream infile;
    ofstream outfile;
    infile.open("record.dat");
    outfile.open("record.dat", ios::app);
    while (infile.read((char *)&client, sizeof(client)))
    {
        if (client.get_account_number() == acc)
        {
            location = (int)infile.tellg() - sizeof(client);
            outfile.seekp(location, ios::beg);
            temp_client.input_record();
            temp_client.add_record();
            cout << "The record is updated.\n";
		break;
        }
    }
    infile.close();
    outfile.close();
}
 
void delete_record(){
    int location, acc; //to store the location where we found the acc no.
    //bool record_found = false;
    Acc_Record client;
    cout << "Enter the account number: ";
    cin >> acc;
 
    ifstream infile, infile_from_temp;
    ofstream outfile_to_temp, outfile;
    infile.open("record.dat");
    outfile_to_temp.open("temp.dat", ios::out);
    //we are opening ofstream in ios::out because we want to create a new txt file where we will write all the records except that to be deleted.
    //later we will write that in the original file and then delete the temporary file.
 
    while (infile.read((char *)&client, sizeof(client)))
    {
        if (client.get_account_number() != acc)
        {
            outfile_to_temp.write((char *)&client, sizeof(client));
        }
    }
    outfile_to_temp.close();
    infile.close();
 
    infile_from_temp.open("temp.dat");
    outfile.open("record.dat", ios::out);
 
    while (infile_from_temp.read((char *)&client, sizeof(client)))
    {
        outfile.write((char *)&client, sizeof(client));
    }
    cout << "Deleted sucessfully\n";
    infile_from_temp.close();
    outfile.close();
 
    remove("temp.dat");
}
 
int main(){
    Acc_Record client;
    int choice;
 
    while (1){
        cout << endl;
        cout << "--------MENU-------" << endl;
        cout << "1. Add Account Record" << endl;
        cout << "2. Modify Account Record" << endl;
        cout << "3. Delete Account Record" << endl;
        cout << "4. Display Account Records" << endl;
        cout << "5. Exit\n"<<endl;
 
        cout << "Enter a choice: ";
        cin >> choice;
 
        switch (choice)
        {
        case 1:
            client.add_record();
            break;
        case 2:
            modify_record();
            break;
        case 3:
            delete_record();
            break;
        case 4:
            display_all_records();
            break;
        case 5:
            cout << "\nExiting from the program.....\n\n";
            exit(0);
        default:
            cout << "Wrong choice, please try again.\n\n";
        }
    }
 
    return 0;
}
