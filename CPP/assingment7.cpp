# define block 5
# if block ==1
// Example of single inheritance:
#include<iostream>
using namespace std;
class Base{
public:
    Base(){
    cout<<"Base class constructor called"<<endl;
    }
};
class Derived: public Base{
public:
    Derived(){
    cout<<"Derived class constructor called"<<endl;
    }
};
int main(){
    Derived d;
return 0;
}

/*Output:
Base class constructor called
Derived class constructor called
*/
#endif
#if block == 2
/*WAP to define a class named Course. Derive three classes from this class named: Mathematics, Science and Engineering. Then, derive two classes from Science named: Physics and Chemistry. Define data members and member functions as appropriate. Illustrate the concept of member functions overriding in the program. [IOE 2071 Shrawan]
*/
#include <iostream>
using namespace std;

class Course{
public:
    float marks=0;
private:
    float get_marks(){ return marks;}
    void set_marks(float x){marks=x;}
};

class Mathematics:public Course{
public: 
    float get_marks(){ return marks;}       // over ridden 
    void set_marks(float x){marks=x;}
};

class Science:public Course{
public:
    float get_marks(){ return marks;}       // over ridden 
    void set_marks(float x){marks=x;}
};

class Engineering:public Course{
public: 
    float get_marks(){ return marks;}       // over ridden 
    void set_marks(float x){marks=x;}
};

class Physics:public Science{
public:
    float get_marks(){ return marks;}       // over ridden 
    void set_marks(float x){marks=x;}
};
class Chemistry:public Science{
public:
    float get_marks(){ return marks;}       // over ridden 
    void set_marks(float x){marks=x;}
};

/// driver 
int main(){
    Engineering e;
    Physics p;
    e.set_marks(50.0f);
    p.set_marks(55.5f);
    cout<<" Engineering marks = "<<e.get_marks()<<endl;
    cout<<" Physics marks     = "<<p.get_marks()<<endl;
return 0;
}

/*Output
 Engineering marks = 50
 Physics marks     = 55.5
*/ 
#endif
#if block == 3
/*Illustrate with an example (hint: multipath inheritance)*/

#include <iostream>
using namespace std;

class ClassA{
protected:    
    int a;
public:
    void seta(int x){a=x;
        //cout<<a << ";"<<x <<endl;
    }
    int geta(){return a;}
};

class ClassB : virtual public ClassA{ // only one copy as it is declared virtual
protected:   
    int b;
public:
    void setb(int x){b=x;}
    int getb(){return b;}
    
};
class ClassC : virtual public ClassA{ // only one copy as it is declared virtual
protected:   
    int c;
public:
    void setc(int x){c=x;}
    int getc(){return c;}

};

class ClassD : public ClassB, public ClassC {
protected:   
    int d;
public:
    void setd(int x){d=x;}
    int getd(){return d;}
    
};

int main(){
    ClassD obj;

    obj.ClassB::seta (10);       
    obj.ClassC::seta (100);      

    obj.seta (100);
    obj.setb (20);
    obj.setc (30);
    obj.setd (40);

    cout<< "\n A from ClassB  : "<< obj.ClassB::geta();
    cout<< "\n A from ClassC  : "<< obj.ClassC::geta();

    cout<< "\n A : "<< obj.geta();       // only one copy as it is declared virtual 
    cout<< "\n B : "<< obj.getb();
    cout<< "\n C : "<< obj.getc();
    cout<< "\n D : "<< obj.getd()<<endl;
return 0;
}
/*
Output :
 A : 100
 B : 20
 C : 30
 D : 40
*/

#endif
#if block ==4 
/*In case of multiple Inheritance, how are the constructors and destructors invoked ? Illustrate with a detailed example. Your program should contain parameterized constructor functions.
*/
#include<iostream>
using namespace std;

class ClassA{
protected:    
    int a;
public:
    ClassA( int i=0): a(i){
        cout<< "ClassA constructor"<<endl;
    }
    void seta(int x){a=x;}
    int geta(){return a;}
    ~ClassA(){
        cout<< "ClassA destructor"<<endl;
    }
};

class ClassB{ 
protected:   
    int b;
public:
    ClassB ( int i=0): b(i){
        cout<< "ClassB constructor"<<endl;
    }
    void setb(int x){b=x;}
    int getb(){return b;}
    ~ClassB(){
        cout<< "ClassB destructor"<<endl;
    }
};

class ClassC : public ClassA, public ClassB{ // declared in order ClassA, ClassB
protected:   
    int c;
public:
    ClassC ( int i=0, int j=0, int k=0):ClassA(i), ClassB(j) ,c(k){
        cout<< "ClassC constructor"<<endl;
    }
    void setc(int x){c=x;}
    int getc(){return c;}
    ~ClassC(){
        cout<< "ClassC destructor"<<endl;
    }
};

int main(){
    ClassC obj(30,20,10);

    cout<< "\n A : "<< obj.geta();       
    cout<< "\n B : "<< obj.getb();
    cout<< "\n C : "<< obj.getc();
    cout<<endl;
return 0;
}
/*Output
ClassA constructor
ClassB constructor
ClassC constructor

 A : 30
 B : 20
 C : 10
ClassC destructor
ClassB destructor
ClassA destructor
*/
#endif
#if block ==5
/*Illustrate an example of Hierarchical Inheritance*/

#include<iostream>
using namespace std;

class ClassA{
protected:    
    int a;
public:
    ClassA( int i=0): a(i){     //parameterized constructor
        cout<< "ClassA constructor"<<endl;
    }
    void seta(int x){a=x;}
    int geta(){return a;}
    ~ClassA(){
        cout<< "ClassA destructor"<<endl;
    }
};

class ClassB:public ClassA{     //ClassB derived from ClassA
//initialize ClassB then ClassC; invoked classB->classA
protected:   
    int b;
public:
    ClassB ( int i=0, int j=0): ClassA(i),b(j){                 //parameterized constructor
        cout<< "ClassB constructor"<<endl;
    }
    void setb(int x){b=x;}
    int getb(){return b;}
    ~ClassB(){
        cout<< "ClassB destructor"<<endl;
    }
};

class ClassC :public ClassB{    // ClassC derived from classB which is derived from ClassA
//initialize ClassA then ClassB then ClassC; invoked classC->classB->classA
protected:   
    int c;
public:
    ClassC ( int i=0, int j=0, int k=0):ClassB(i,j) ,c(k){      //parameterized constructor
        cout<< "ClassC constructor"<<endl;
    }
    void setc(int x){c=x;}
    int getc(){return c;}
    ~ClassC(){
        cout<< "ClassC destructor"<<endl;
    }
};

int main(){
    ClassC obj(10,20,30);

    cout<< "\n A : "<< obj.geta();      // calling inherited member function from ClassA    
    cout<< "\n B : "<< obj.getb();      // calling inherited member function from ClassB
    cout<< "\n C : "<< obj.getc();      // calling member function from own class ClassC
    cout<<endl;
return 0;
}
/*Output
ClassA constructor
ClassB constructor
ClassC constructor

 A : 10
 B : 20
 C : 30
ClassC destructor
ClassB destructor
ClassA destructor
*/
#endif
