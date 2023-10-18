 
/* read 3 num x y z and evaluate r=z/(x-y) with exception handling*/
#include <iostream>
#define ROW 3
#define COL 3
using namespace std;


int main(){
    float x, y, z ;
    cout <<"enter x , y, z :"<<endl; cin>>x>>y>>z;
    cout <<"evaluating r=z/(x-y) : ";
    try {
        if (x == y){
            if (z!=0)
                throw "infinity";
            else 
                throw "indeterminate";
        }
        else 
            cout <<z/(x-y)<<endl;
    }
    catch(char const * str){
    cout<<str<<endl;
    }
    
return 0;
}
