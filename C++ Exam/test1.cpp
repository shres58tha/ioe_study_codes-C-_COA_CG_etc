#include<iostream>
using namespace std;

class Number{
private:
    int i;
public:
    Number (int n=0):i(n){}  //parameterized constructor
    int get_i(){ 
        return i;
    }
    void set_i(int a){
        i=a;        
    }
    void operator +=(int x);      
    
};
void Number::operator +=(int x){          
    i+=x;
}
// driver
int main(){
    Number x(5);
    x+=5;
    cout << endl<<"x :"<< x.get_i()<<endl;
    cout << "x +=5 :" << x.get_i()<<endl;
    return 0;
}
