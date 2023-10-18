/*
 * Write a program such that a class (Class1) becomes a friend of another (Class2). Make sure you access the contents of Class2 using at least two member functions of Class1.
*/
#include <iostream>

using namespace std;

class Class1;
class Class2 {
private:
    int num;
public:
            
    Class2 (int n=0): num(n){}
    int get_num(){
        return num;
    }
    void set_num(int n){
        this->num=n;
        cout<<n<<endl;
    }
    void display(){
        cout << get_num();
    }
    friend Class1;
};

class Class1{
public:
    void input(Class2 &n){
         int t;
         cout << "enter a num :";
         cin>>t;
         n.set_num(t);
    }
    void display(Class2 n){
        cout << n.get_num();
    }
};

int main(){
 Class2 num;
 Class1 n;
n.input(num);
num.display();
n.display(num);
}
