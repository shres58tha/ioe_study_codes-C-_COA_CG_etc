 # include<iostream>
#include<fstream>
#include<string>
 using namespace std;
 
 class Details{
 	char fname[50], lname[50];
 	int accno ;
 	public:
 		void add();
 		void update();
 		void delete1();
 		void display(); 
 		int retacno() const;    //return account number
    int retdeposit() const; //return balance amount
    char rettype() const;   //return type of account   
    	float total_balance;
		 };
 void Details :: add(){
 	cout<<"Enter your first name :" <<endl;
 	cin>>fname;
 	cout<<"Enter your second name : "<<endl;
 	cin>>lname;
 	cout<<"Enter your account number :" <<endl;
 	cin>>accno;
 	cout<<"Enter your balance : " <<endl;
 	cin>>total_balance;
 }
 
 void Details :: display(){
 	cout<<"\n Account No. : "<<accno;
    cout<<"\n First name  : ";
    cout<<fname ;
     cout<<"\n Last  name  : ";
    cout<<lname;
    cout<<"\n Balance Amount : "<<total_balance;
 }
 
 void Details :: update (){
 	cout<<"\nAccount No. : "<<accno;
    cout<<"\nModify First  Name : ";
    cin.ignore();
    cin>>fname;
    cout<<"\nModify Last  Name : ";
    cin.ignore();
    cin>>lname;
    cout<<"\nModify Balance Amount : "; cin>>total_balance;
 }
 int Details::retacno() const
{
    return accno;
}
 
 void write_account();
 void display_sp(int);   //display account details given by user
void modify_account(int);   //modify record of file
void delete_account(int);   //delete record of file
void display_all();     //display all account details

 int main(){
 	 int choice;
    int num;
    //intro();
    do
    {
        cout<<"\n\n\tMAIN MENU";
        cout<<"\n\t 1 NEW ACCOUNT";
        cout<<"\n\t 2. DETAILS LIST";
        cout<<"\n\t 3. DELETE AN ACCOUNT";
        cout<<"\n\t 4. UPDATE AN ACCOUNT";
        cout<<"\n\t 0. EXIT";
        cout<<"\n\t Select Your Option (0-4) "; cin>>choice;
        
        switch(choice)
        {
        case 1:
            write_account();
            break;
        case 2:
            display_all();
            break;
        case 3:
            cout<<"\n\n\tEnter The Account No. : "; cin>>num;
            delete_account(num);
            break;
         case 4:
            cout<<"\n\n\tEnter The Account No. : "; cin>>num;
            modify_account(num);
            break;
            
         default :cout<<"\a";
        }

    }while(choice!=0);
    return 0;
 } 
 
 void write_account()
{
    Details ac;
    ofstream outFile;
    outFile.open("Details.dat",ios::binary|ios::app);
    ac.add();
    outFile.write(reinterpret_cast<char *> (&ac), sizeof(Details));
    outFile.close();
}
 
//      function to modify record of file

 
void modify_account(int n)
{
    bool found=false;
   Details ac;
    fstream File;
    File.open("Details.dat",ios::binary|ios::in|ios::out);
    if(!File)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ac), sizeof(Details));
        if(ac.retacno()==n)
        {
            ac.display();
            cout<<"\n\nEnter The New Details ofDetails"<<endl;
            ac.update();
            int pos=(-1)*static_cast<int>(sizeof(Details));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ac), sizeof(Details));
            cout<<"\n\n\t Record Updated";
            found=true;
          }
    }
    File.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
}
 

//      function to delete record of file

 
 
void delete_account(int n)
{
   Details ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Details.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Details)))
    {
        if(ac.retacno()!=n)
        {
            outFile.write(reinterpret_cast<char *> (&ac), sizeof(Details));
        }
    }
    inFile.close();
    outFile.close();
    remove("Details.dat");
    rename("Temp.dat","Details.dat");
    cout<<"\n\n\tRecord Deleted ..";
}
 

//      function to display allDetailss deposit list

 
void display_all()
{
   Details ac;
    ifstream inFile;
    inFile.open("Details.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    cout<<"\n\n\t\t Details \n\n";
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Details)))
    {
        ac.display();
    }
    inFile.close();
}
