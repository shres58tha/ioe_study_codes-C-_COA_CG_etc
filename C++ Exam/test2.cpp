#include<iostream>
using namespace std;   // Needed for cout


class Room{
    private:
        int price;
    public:
        // Room(){}            //Capitalized
        Room(int p=2500){       //Capitalized     initialized hence upper statement is unnecessary
            this->price=p;
        }
        void display(){
            cout << this->price << endl;  //p
        }
};

int main(){
    Room r;                     //error due to initialized value
    r.display();// spelling
    
    return 0;
}

