 
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
class User{
	private:
		char acc_num[20];
		char last_name[20],first_name[20];
		float total_balance;
	public:		
		void read_data(){
			cout<<"Enter account numbr: ";
			cin>>acc_num;
			cout<<"Enter last name: ";
			cin>>last_name;
			cout<<"Enter first name: ";
			cin>>first_name;
			cout<<"Enter total balance: ";
			cin>>total_balance;
		}
		void display_data(){ 
			cout<<"Account numbr: "<<acc_num<<endl;
			cout<<"firt name: "<<first_name<<endl;
			cout<<"last name: "<<last_name<<endl;
			cout<<"Total balance: "<<total_balance<<endl<<endl;
		}
};
void addfile(){
	User u;
	ofstream outfile("user.txt",ios::binary | ios::app);
	u.read_data();
	outfile.write(reinterpret_cast<char*>(&u),sizeof(u));
}
void readfile(){
	User u;
	int ch;
	ifstream infile("user.txt",ios::binary);
	system("cls");
	cout<<"==============================\n"
	    <<"|  Enter choice for show      |\n"
	    <<"|_____________________________|\n"
	    <<"| 1.show all record           |\n"
	    <<"| 2.show one record           |\n"
	    <<"|_____________________________|\n";
	    cin>>ch;
	    if(ch==1){
	    	if(!infile){
	    		cout<<"file not found store data first !"<<endl;
			}
			while(!infile.eof()){
				if(infile.read(reinterpret_cast<char*>(&u),sizeof(u))>0){
					u.display_data();
				}
			}
		}
		if(ch==2){
			int n,count;
			if(!infile){
	    	cout<<"file not found store data first !"<<endl;
			}
			infile.seekg(0,ios::end);
			count=infile.tellg()/sizeof(u); 
			cout<<"There are: "<<count<<" record int the file\t";
			cout<<"Enter record number: ";
			cin>>n;
			infile.seekg((n-1) *sizeof(&u));
			infile.read(reinterpret_cast<char*>(&u),sizeof(u));
			u.display_data();
		}
		if(ch>2){
			cout<<"Invalid choice";
			readfile();
		}
	}
void updatedata(){ 
		User u;
		int ch;
		int count,n;
		fstream infile("user.txt",ios::in|ios::binary|ios::out);
		if(!infile){
	    	cout<<"file not found store data first !"<<endl;
		}
		infile.seekg(0,ios::end);
		count=infile.tellg()/sizeof(u);
		cout<<"There are"<<count<<" record int the file";
		cout<<"Enter record number to be modify: ";
		cin>>n;
		infile.seekg((n-1)*sizeof(&u));
		infile.read(reinterpret_cast<char*>(&u),sizeof(u));
		u.display_data();
		infile.close();
		infile.open("user.txt",ios::out|ios::in|ios::binary);
		infile.seekp((n-1)*sizeof(&u));
		cout<<"Enter data to modify"<<endl;
		u.read_data();
		infile.write(reinterpret_cast<char*>(&u),sizeof(u));
	}
void deletedata(){
	User u;
	int n;
	cout<<"enter the index num to be deleted :  ";
	cin>>n;
	n--;
	ifstream infile("user.txt",ios::binary);
	ofstream outfile("temp.txt",ios::binary);
	int i=0;
	while(!infile.eof()){
		infile.read(reinterpret_cast<char*>(&u),sizeof(u));
		if(i==n) continue;
		outfile.write(reinterpret_cast<char*>(&u),sizeof(u));
		i++;
	}
	getchar();
		remove("user.txt");
	rename("temp.txt","user.txt");
	
	}
int main(){
	User u;
	int choice;
	cout<<"\t\tTransaction record system"<<endl;
	while(true){
		cout<<"===========================================\n"
		    <<"|     Enter choice for below operation     |\n"
		    <<"|__________________________________________|\n"
		    <<"|  1.write record to file                  |\n"
		    <<"|  2.show record from file                 |\n"
		    <<"|  3.update record                         |\n"
		    <<"|  4.delete record from file               |\n"
		    <<"|  5.exit from program                     |\n"
		    <<"|__________________________________________|\n";
		    cin>>choice;
		    switch(choice){
		    	case 1:
		    		addfile();
		    		break;
		    	case 2:
					readfile();
					break;
				case 3:
					updatedata();
					break;
				case 4:
					deletedata();
					break;
				case 5:
					exit(0);
					break;
				default:
					cout<<"\nChoice not available";
					exit(0);
			}	
		}
	return 0;
}
