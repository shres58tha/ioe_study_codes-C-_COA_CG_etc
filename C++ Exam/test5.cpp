/*
What is DMA ? Implement a program that illustrates DMA in action using user defined class. Also overload few member functions.
*/
/*
Answer
DMA full form is the Dynamic memory allocation, which is the method of dynamically allocating the memory in the run time by use of key words new and delete. new takes type of object or data type for which new memory need to be dynamically allocated and returns the pointer to the just allocated space of the memory in a pointer to type of the object or data. delete frees the allocated space and takes pointer to the memory to be freed.
*/
#include <iostream>

using namespace std;

class Num {
private:
    int num;
    double n;
public:
    Num(){num=0;n=0;}
    Num (int x): num(x){}
    Num (double x): n(x){}
      
    void set(int x){  num=x; }
    void set(double x){ n=x; }

    int get_int(){ return num;}
    double get_double(){ return n;}
};

int main(){
 Num  *p;
 p=new Num(10);
 cout << p->get_int()<<endl;
 
 p->set(5.01);
 cout << p->get_double()<<endl;
 delete (p);
 
return 0;
}
