#define block 2
#if block==1 
/*Illustrate with an example (hint: multipath inheritance)*/
;/*
#define Virtual 1  ;1 yes 0 no
#include <iostream>
using namespace std;
class One{
protected:    
    int a;
public:
    One(int x=0):a(x){cout<< "One constructor"<<endl;}
    void set_a(int x){a=x;}
    int get_a(){return a;}
    ~One(){
        cout<< "One destructor"<<endl;
    }
};
class Two : 
            #if Virtual==1 
            virtual 
            #endif
                    public One{ ; only one copy as it is declared virtual
protected:   
    int b;
public:
    Two(int x=0, int y=0):One(x),b(y){cout<< "Two constructor"<<endl;}
    void set_b(int x){b=x;}
    int get_b(){return b;}
    ~Two(){
        cout<< "Two destructor"<<endl;
    }
};
class Three : 
            #if Virtual==1 
            virtual 
            #endif
            public One{ ; only one copy as it is declared virtual
protected:   
    int c;
public:
    Three(int x=0, int y=0):One(x),c(y){cout<< "Three constructor"<<endl;}
    void set_c(int x){c=x;}
    int get_c(){return c;}
    ~Three(){
        cout<< "Three destructor"<<endl;
    }
};
class Four : public Two, public Three {  ; check removing virtual keyword
protected:   
    int d;
public:
    ;/*
    Four(int w=0,int x=0, int y=0, int z=0):Two(w,x),Three(w,y),d(z){  ; fails with virtual'
       cout<< "Four constructor"<<endl;
   } ;2 base class inherited, can be resolved by scope:: of derived class Two, Three  */
    /*
    Four(int w=0,int x=0, int y=0, int z=0):One (w),Two(w,x),Three(w,y),d(z){ ; fails in normal
        cout<< "Four constructor"<<endl;
    }  ;One act as direct inheritance and the call from Two & Three suppressed */
    void set_d(int x){d=x;}
    int get_d(){return d;}
    ~Four(){
        cout<< "Four destructor"<<endl;
    }
};

int main(){
    Four obj( 1, 2, 3, 4) ;   
    
    /*
    obj.ClassB::set_a (10);       
    obj.ClassC::set_a (100);      

    obj.set_a (100);
    obj.set_b (20);
    obj.set_c (30);
    obj.set_d(40);
    */
    cout<< "\n A from Two  : "<< obj.Two::get_a();
    cout<< "\n A from Three  : "<< obj.Three::get_a();
    #if Virtual==1 
    cout<< "\n A : "<< obj.get_a();; only one copy as is declared virtual fails on normal call 
    #endif
    
    cout<< "\n B : "<< obj.get_b();
    cout<< "\n C : "<< obj.get_c();
    cout<< "\n D : "<< obj.get_d()<<endl;
return 0;
};*/
/*
Output :
 A from Two  : 1
 A from Three  : 1
 A : 1
 B : 2
 C : 3
 D : 4

*/
#endif
#if block==2

#include<iostream>
using namespace std;

class One{
protected:    
    int a;
public:
    One( int i=0): a(i){     //parameterized constructor
        cout<< "One constructor"<<endl;
    }
    int get_a(){return a;}
    ~One(){
        cout<< "One destructor"<<endl;
    }
};

class Two:public One{     //Two derived from One
;initialize Two then Three; invoked classB->classA
protected:   
    int b;
public:
    Two ( int i=0, int j=0): One(i),b(j){                 //parameterized constructor
        cout<< "Two constructor"<<endl;
    }
    int get_b(){return b;}
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
    int get_c(){return c;}
    ~Three(){
        cout<< "Three destructor"<<endl;
    }
};

int main(){
    Three obj(10,20,30);

    cout<< "\n A : "<< obj.get_a();      // calling inherited member function from One    
    cout<< "\n B : "<< obj.get_b();      // calling inherited member function from Two
    cout<< "\n C : "<< obj.get_c();      // calling member function from own class Three
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
#endif
