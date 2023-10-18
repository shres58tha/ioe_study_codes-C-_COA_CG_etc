 
#include<iostream>
#include<string>
using namespace std;

class Detail{
	protected:
	string name,address;
	string phone;
	string email;
	public:
	void Detail_input(string n,string a,string p,string e){
		name=n;address=a;phone=p;email=e;
	}
	void displayD(){
		cout<<"PERSONAL DETAIL"<<endl;
		cout<<"Name:	"<<name<<endl;
		cout<<"Address:	"<<address<<endl;
		cout<<"phone:	"<<phone<<endl;
		cout<<"E-mail:	"<<email<<endl;
	}
};
class Fee{
	protected:
	float total_pay;
	float pay,due;
	public:
	 void Fee_input(float t,float p){
		total_pay=t;
		pay=p;
		due=total_pay-pay;
	}
	void displayF(){
		cout<<"FEE DETAIL"<<endl;
		cout<<"your total fee is:	"<<this->total_pay<<endl;
		cout<<"you pay:	"<<pay<<endl;
		cout<<"your due amount is:	"<<due<<endl;
	}
};
class Student: public Detail,public Fee {
  public:
	void display(){
		cout<<"Student detail"<<endl;
	}
};
int main(){
	Student s;
	char ch;
	int code;
	int student=5040;
	int teacher=2034;
	s.Detail_input("Ram","KTM","+977014327","ram@gamil.com");
	s.Fee_input(500000.00,50000.00);
	
	cout<<"		Enter for login"<<endl<<"1.student"<<endl<<"2.teacher"<<endl;
	ch= getchar();
	switch(ch){
		case '1':
			cout<<"Enter password for login: ";
			cin>>code;
			if(student ==code){
				s.display();
     cout<<endl;
				s.displayD();
     cout<<endl;
				s.displayF();
			}
			else{
				cout<<"Invalid login";
			}
			break;
		case '2':
			cout<<"Enter password for login: ";
			cin>>code;
			if(teacher ==code){
				s.display();
				s.displayD();
				s.displayF();
			}
			else{
				cout<<"Invalid login";
			}
			break;
        default:
					cout<<"Invalid choice";
		}
	}
