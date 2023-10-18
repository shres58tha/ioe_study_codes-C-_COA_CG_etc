/*Illustrate with an example (hint: multipath inheritance)*/

#include <iostream>
using namespace std;
class One{
protected:    
    int a;
public:
    One(int x=0):a(x){}
    int geta(){return a;}
};
class Two : virtual public One{ // only one copy as it is declared virtual
protected:   
    int b;
public:
    Two(int x=0, int y=0):One(x),b(y){}
    int getb(){return b;}
    
};
class Three : virtual public One{ // only one copy as it is declared virtual
protected:   
    int c;
public:
    Three(int x=0, int y=0):One(x),c(y){}
    int getc(){return c;}

};

class Four : public Two, public Three {
protected:   
    int d;
public:
    Four(int w=0,int x=0, int y=0, int z=0):One (w),Two(w,x),Three(w,y),d(z){}
    int getd(){return d;}
};

int main(){
    Four obj( 1, 2, 3, 4) ;    

    cout<< "\n A from Two  : "<< obj.Two::geta();
    cout<< "\n A from Three  : "<< obj.Three::geta();

    cout<< "\n A : "<< obj.geta();       // only one copy as it is declared virtual 
    cout<< "\n B : "<< obj.getb();
    cout<< "\n C : "<< obj.getc();
    cout<< "\n D : "<< obj.getd()<<endl;
return 0;
}
/*
Output :

*/
/*
#include<iostream>
using namespace std;

class One{
protected:    
    int a;
public:
    One( int i=0): a(i){     //parameterized constructor
        cout<< "One constructor"<<endl;
    }
    int geta(){return a;}
    ~One(){
        cout<< "One destructor"<<endl;
    }
};

class Two:public One{     //Two derived from One
//initialize Two then Three; invoked classB->classA
protected:   
    int b;
public:
    Two ( int i=0, int j=0): One(i),b(j){                 //parameterized constructor
        cout<< "Two constructor"<<endl;
    }
    int getb(){return b;}
    ~Two(){
        cout<< "Two destructor"<<endl;
    }
};

class Three :public Two{    // Three derived from classB which is derived from One
//initialize One then Two then Three; invoked classC->classB->classA
protected:   
    int c;
public:
    Three ( int i=0, int j=0, int k=0):Two(i,j) ,c(k){      //parameterized constructor
        cout<< "Three constructor"<<endl;
    }
    int getc(){return c;}
    ~Three(){
        cout<< "Three destructor"<<endl;
    }
};

int main(){
    Three obj(10,20,30);

    cout<< "\n A : "<< obj.geta();      // calling inherited member function from One    
    cout<< "\n B : "<< obj.getb();      // calling inherited member function from Two
    cout<< "\n C : "<< obj.getc();      // calling member function from own class Three
    cout<<endl;
return 0;
}
/*Output
One constructor
Two constructor
Three constructor

 A : 10
 B : 20
 C : 30
Three destructor
Two destructor
One destructor
*/
