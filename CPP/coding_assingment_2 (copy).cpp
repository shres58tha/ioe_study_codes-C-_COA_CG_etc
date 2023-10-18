// coded by umesh.076bei029@acem.edu.np 18th sept 2020
// Class for creating student  objects
/*
 * Attempt all the questions.
Define Class and Object. Write a simple program to design a Class to keep the information of three students. For each student, you must get his/her name, rollno and see if s/he is present or absent. The class should contain two functions viz. One for input and one for display.

Write down the syntax for defining a member function outside of the class. In the previous assignment, you wrote a program for calculating volume of a cube, cuboid and cylinder. Now, write the same program using Class and Object. Make sure the member functions definition are outside of the class.

What do you mean by a Constructor and write about its importance? Discuss about the types of constructors. Write a program that illustrates class/object concept, constructor overloading (default and parameterized) and one of the constructor functions should have default argument(s).

What is a this pointer ? Write down its significance. Illustrate an example of using this pointer.

What do you mean friend function ? Write a program to illustrate the friend function in action.

*/
#define block 5 // just change value of letter to select corresponding block while comparing

#if block == 1 
/*
Define Class and Object. Write a simple program to design a Class to keep the information of three students. For each student, you must get his/her name, rollno and see if s/he is present or absent. The class should contain two functions viz. One for input and one for display.
*/
/******************Answer*********
 *Class is defined as a user defined type that can be used as conveniently similar to the build in data type. In C++ Class forms the basis of the OOP. A class encompasses data and function that operate on the data into single functional entry, instances of which is known as the Object. 
 * Class declaration is syntactically similar to the structure in C, the difference being that while structure only contains a group of data that goes together and which is accessible all over the scope freely, whereas the Class encompasses the data and the methods (or functions) that are used to modify and access the data in the Class. In Class the data are generally hidden from access directly from the functions / methods not the member of that particular class hence preventing or reducing undesirable change in the data.This process is binding the data and the function which operate on it into tight capsule is also known as encapsulation.
*/
// Generalized and possible error handled
// bit complicated due to this same function will go towards project too.
#include<iostream>
#include <string>   //for string
#include <iomanip>  //for setw()



using namespace std;

class Student{
    private: 
        string std_name;
        int roll_no;
        bool presence;
    public:
        Student (){                                             //default constructor
        }
    Student (string name, int roll, bool attend  ){             //build student by arguments
        std_name=name;
        roll_no=roll;
        presence=attend;
        }
    void input(){                                               // enter student data one by one
        int bad_input=0; // a huge number hoping that long wrong input wont be put this long
        
        cout << "Enter the name of the student : " ;
        getline(cin,std_name);                                  // does not leave dangling anything in the input stream
        //cout << (cin.peek())<< "ghnbn\n"                      // debug line
                                                                // big issues in the input better to  use getline                 everywhere but need to use boost library for easy conversion as there are ambiguities here how to convert characters got from getline to numbers
                                                                // and use library conversion in memory then accept or reject input
        
        do {                  // get input for the roll with error checking
            bad_input=0;
            cin.clear();                                        //clear input error state if set
            cout << "Enter the student's roll no : ";
            cin>>roll_no;                                        // just pops type data from stream 
            //cout << cin.fail() <<  endl;     // debug line    // either '\n' or others characters remain in input stream
            
            if (cin.fail()){
                bad_input=1;                                      // if cin is not in error
                cin.clear();                                      // before doing anything to input buffer need to clear buffer error
                cin.ignore(1000000,'\n');                         // ignore 1000000 ie huge no of input buffer of till '|n'  which ever comes first 
             
                //cout << cin.fail() <<"qwerty"<<  endl;          // debug line
            }
            else if( cin.peek() == EOF|| cin.peek() == '\n'){     
                                                                 // invalid data as the the input stream not empty  case where number is followed by some ascii characters.
                bad_input=0;                                     // all ok 
                                                                 // following code has to be executed for successful removal so
                cin.ignore();                                   
                                                                 // remove the ascii 10 '\n' from in stream for the next scanning of getline  as cin leaves '\n' dangling in buffer.
                }
                //cout << cin.fail() <<"ASDFGHJ"<<  endl; 
            else{                                               // re-handled here if no is followed by some dangling ascii 
                bad_input=1;
                cin.clear(); 
                cin.ignore(1000000,'\n');                       // works only  after cin error is cleared
                //cout << cin.fail() <<"zxcvbnm"<<  endl;       // debug line
            }
        }while(bad_input);   // works as it should
        
           
        char ch;
        bad_input=0;
        do {                // get input for the presence with error checking
    
            cout << "Enter y for presence and n for absence : ";
            cin>>ch;                                             // just pops one character from stream 
                                                                 // either '\n' or others characters remain in input stream
            ch =tolower(ch);                                     // lib function to change the char to lower
            //cout << (cin.peek());                              // debug line  peek the next character without popping the cin stream
            //if (cin.peek() == EOF|| cin.peek() == '\n' ){      // actually  EOF causes problem and is redunctant.
            if ( cin.peek() == '\n' ){  
                bad_input=0;    // all ok
                cin.ignore();   // remove the ascii 10 from in stream for the next scanning of getline.
             }
             else{
                 bad_input=1;
                 cout <<endl<< "Error : ";
                 cin.ignore(1000000, '\n');                     // clear to new line is ok here as on looping cin ignores white space
                 cin.clear();
            }
            
            if (ch == 'y' )
                presence=1;
            else if (ch == 'n')
                presence=0;
            else{
                bad_input=1;
                cin.clear();
                cout <<endl<< "Error : ";
            }

        }while (bad_input ==1) ;
    }
    
    
    void display(){         // displays the data in the object
        cout << endl;
        cout << setw(12) << "NAME : " << std_name <<endl;
        cout << setw(12) << "Roll No. : " << roll_no<< endl;
        cout << setw(12) << "present : "<<(presence ? "YES" : "NO") << endl;
    } 
};


//driver coded

int main(){
    Student s1( "umesh shrestha" , 29, 1);
    Student s2, s3;
    cout << " enter student's data \n" << endl;
    s2.input();
    s3.input();
    cout << "\ndisplay students : \n" << endl;
    s1.display();
    s2.display();
    s3.display();
return 0;
}

/*******************OUTPUT*****************

enter student's data

Enter the name of the student : umesh krishna shrestha
Enter the student's roll no : i do not know
Enter the student's roll no : 29      
Enter y for presence and n for absence : what

Error : 
Error : Enter y for presence and n for absence : y
Enter the name of the student : papila ghising
Enter the student's roll no : 11
Enter y for presence and n for absence : y

display students :

     NAME : umesh shrestha
 Roll No. : 29
  present : YES

     NAME : umesh krishna shrestha
 Roll No. : 29
  present : YES

     NAME : papila ghising
 Roll No. : 11
  present : YES

 
 */


#endif
#if block==2

/*
Write down the syntax for defining a member function outside of the class. In the previous assignment, you wrote a program for calculating volume of a cube, cuboid and cylinder. Now, write the same program using Class and Object. Make sure the member functions definition are outside of the class.
*/

/***ANSWER*
 * The syntax for defining the member function outside of the Class is as follows;
   The declaration of the member function is done inside the Class to indicate that such a function will be defined elsewhere. 
   The member functions is then defined outside the Class using the scope resolution operator :: 
   the general pattern of some arbitrary function will look like
   
   class class_name{
            private: 
                // data......
            public:
                return_type member_func( parameters or arguments);  // decleration 
   }
    
    // member function defination
    
    return_type class_name::member_func ( parameters or arguments ){
        //function body code here
    }

*/ 
// C++ program to calculate the volume of cube, cuboid, and cylinder using class and object.
// USING member function definition outside of the class
 
#include<iostream>
#include<cmath>
using namespace std;

class cuboid{
    private:
        float lenght=0.0;
        float width=0.0;
        float height=0.0;
    public:
        // declaration of the methods
        cuboid(float, float, float);
        void set_side();
        void display();
        float volume();
};
//  member function definition
  
     cuboid::cuboid(float l=0.0, float w=0.0, float h=0.0 ){    //using default values
        lenght=l;
        width=w;
        height=h;    
    }
    void cuboid::set_side(){
        cout << "length :";
        cin  >> lenght;
        cout << "width :";
        cin  >> width;
        cout << "height :";
        cin  >> height;
    } 
     
    void cuboid::display(){
        cout << "The parameters of cuboid are:"<< endl;
        cout << "length :="<<  lenght << endl;
        cout << " width :="<<  width  << endl;
        cout << "height :="<<  height << endl;
        cout << endl;
    }
    float cuboid::volume(){
        return (lenght*width*height);
    }
    
//  end of member function definition of cuboid

class cube{
    private:
        float side=0.0;
    public:
        // declaration of the methods
        cube(float);
        void set_side();
        void display();
        float volume();
};
//  member function definition
  
     cube::cube(float s=0.0){    //using default values
        side=s;
    }
    void cube::set_side(){
        cout << "side :";
        cin  >> side;
    } 
     
    void cube::display(){
        cout << "The parameters of cube are:"<< endl;
        cout << "side :="<<  side << endl;
        cout << endl;
    }
    float cube::volume(){
        return (side*side*side);
    }
//  end of member function definition of cube


class cylinder{
    private:
        float radius=0.0;
        float height=0.0;
    public:
        // declaration of the methods
        cylinder(float, float);
        void set_side();
        void display();
        float volume();
};
//  member function definition
  
     cylinder::cylinder(float r=0.0, float h=0.0){    //using default values
        radius=r;
        height=h;;
    }
    void cylinder::set_side(){
        cout << "radius :";
        cin  >> radius;
        cout << "height :";
        cin  >> height;
    } 
     
    void cylinder::display(){
        cout << "The parameters of cube are:"<< endl;
        cout << "radius :="<<  radius << endl;
        cout << "height :="<<  height << endl;
        cout << endl;
    }
    float cylinder::volume(){
        return (M_PI*radius*radius*height);
    }
//  end of member function definition of cylinder


      
// driver code

int main(){
    cuboid box(20,15,10);         // side of cube set using constructor 
    cube   cubic_box;             // sides of the cuboid
    cylinder cyldr ( 1, 1);        // parameterized constructor call
    
    cout<<"Enter parameters of cube"<<endl;
    cubic_box.set_side();
    
    cout<< " Displaying parameters \n"<< endl;
    
    box.display();
    cubic_box.display();
    cyldr.display();
    
    cout<<"\nVolume of cuboid is   "<<box.volume()<<endl;
    cout<<"\n Volume of cube is    "<<cubic_box.volume()<<endl;
    cout<<"\nVolume of cylinder is "<<cyldr.volume() <<endl;
    cout <<endl;
return 0;
}

/* *************output*******************
 
Enter parameters of cube
side :1
 Displaying parameters 

The parameters of cuboid are:
length :=20
 width :=15
height :=10

The parameters of cube are:
side :=1

The parameters of cube are:
radius :=1
height :=1


Volume of cuboid is   3000

 Volume of cube is    1

Volume of cylinder is 3.14159


*****************************************/

#endif

#if block==3
/*  Question 
What do you mean by a Constructor and write about its importance? Discuss about the types of constructors. Write a program that illustrates class/object concept, constructor overloading (default and parameterized) and one of the constructor functions should have default argument(s).
*/

/* ANSWER******************************
 C++ does not auto initialize the variables we declare nor does it initialize the data members in the objects if these data are accessed before proper initialization some garbage value will occur.  For the initialization of the data member some member function need to be declared which can handle the various ways the data member is initialized. If we write a explicit member function to initialize the data member these need to be called right after creating objects.
    
C++ provides a better way to handle this situation. when ever an object is created it automatically executes come default function by the same as the class name while it is created. These special type of functions are known as constructor.

These constructor function can be defined by the programmer and if the programmer doesn't define any, a empty method is automatically generated by the C++. 

Constructors can be overloaded same way as any other functions.

when a constructor is defined by the programmer the C++ doesn't generate the default constructor then it has to be explicitly declared.

    Some  of the constructor are:
    
    Default Constructor:
A constructor which takes no arguments is called Default Constructor. 
  for eg.
      
      class counter{
      private:
           int count;
      public:
          counter(){count=0;}              // this is the default constructor
          counter(int i){ count=i;}        // parameterized constructor
      };
      Here, the default constructor has to be called as
        counter c1;
        as counter c1(); generates error as there is no function in the above class that takes no parameters and returns counter type.
        
        
    Parameterized Constructor:
A constructor which handles arguments are passed to the object at initialization is known as parameterized constructor.
in example above it is the counter(int i){ count i=0;}
parameterized constructor can be defined with the default values so then we do not need to  declare default constructor. for example for above case the code snippet will be
    class counter{
      private:
           int count;
      public:
          counter(int i=0){ count=i;}        // parameterized constructor
      };
      
      calling of the default constructor by
        counter c1();  is ok here as here the default value is used to set counter data to 0.
        call by using
        counter c2;    is ok at run time too
    
    
    Copy Constructor;
The special constructor that the C++ automatically generates, which allows the assignment of the one object to another is called copy constructor, since it copies the values form one object to another.
for eg
    class counter{
        private:
            int count;
        public:
            counter(int i=0){ count=i;}        // parameterized constructor
        };
        
    calling of the default constructor by
        counter c1(5);  // initialization of c1 object by parameterized constructor
        counter c2=c1;  // by use of automatic copy constructor
thus generated copy constructor is default copy constructor generated by c++ compiler.
however this default parameter can be overridden when need arise. The parameter to the construction can be of any data type but an object of its own type, However, the class's own object type can be passed as a reference parameter.
for eg;
    class test(){
    private:
        // ................
    public:
        test(){;}               // default constructor
        test( arguments ){....} // parameterized constructor
        test (test &t){.......} // copy constructor user defined   
    };

here in copy construct the test type object t is reference by use of & ampersand operator.as 

*/

#include <iostream>
#include <climits>
using namespace std;

class counter{
      private:
           int count;
           int max_value;
      public:
          counter (){count=0;max_value=INT_MAX;}              // default constructor
          counter (int i){                                    // parameterized constructor if default parameters are used generate call to counter() ambiguous
              count=i;
              max_value=INT_MAX;
          }
            
          counter(int i , int m){ 
              count=1; 
              max_value=m;
              
          }
          counter(counter &c){                                  //parameterized copy constructor
              count=c.count; 
              max_value=c.max_value;
              
          }
          void display (){
              cout << "count :" << count <<endl<< "max_value :"<<max_value<<endl<<endl;
          }
};
      
int main(){

      counter c1;            // object construction by use of default constructor
      counter c2(1);         // parameterized constructor 
      counter c3(1,100);     // overloaded parameterized constructor
      counter c4=c1;         // default copy constructor auto generated
      counter c5(c3);        // overloaded parameterized copy constructor
      cout << "c1"<<endl; 
      c1.display();
      cout << "c2"<<endl;
      c2.display();
      cout << "c3"<<endl;
      c3.display();
      cout << "c4"<<endl;
      c4.display();
      cout << "c5"<<endl;
      c5.display();
return 1;
}

/*  ****************OUTPUT*******************
c1
count :0
max_value :2147483647

c2
count :1
max_value :2147483647

c3
count :1
max_value :100

c4
count :0
max_value :2147483647

c5
count :1
max_value :100

************************************/
#endif

#if block==4
/*What is a this pointer ? Write down its significance. Illustrate an example of using this pointer*/

/************ANSWER****************
 Every object has an access to its own  address through the pointer known as "this" pointer, which is a pointer to the current instance of the object. An object's "this" pointer is not a part of object itself and sizeof( object) operator does not include it in the result. '"this" pointer is passed into the object by the compiler  as an implicit first argument on every non-static member function call to the object. that is data or member not defined by keyword static.
The "this" pointer used to reference the current object's member data and method. Therefore, inside a member function, this may be used to refer to the invoking object. Friend functions do not have a "this" pointer, because friends are not members of a class. Only member functions have a "this" pointer.
The use of "this" pointer is generally not use that much as for much of the coding it use is redundant and is self implied. But when there are object data member's identifier and local member function declare also have data with same identifier, then use of "this" pointer can be used to resolve the conflict as the  following eg illustrate its use.
        class SomeClass {
            private:
                int x;    // member of object
            public:
                void somefunction(int x);
            };

            void SomeClass::SomeClass(int x) {  // new data x defined;  same name as object's data
                  this->x = x;                  //conflict resolved by use of this pointer to object.
            }
*/
// Illustrate an example of using this pointer

#include <iostream>
 
using namespace std;

class cube {
     private:
        double side;                                        // side of a cube
     public:
        cube(double s = 0.0) {                              // Constructor definition
            side = s;
        }
        double Volume() {
            return side*side*side;
        }
        int compare(cube box) {
            return this->Volume() > box.Volume();           // return 1 if true else 0
                                                            // compare by calling object's volume with the cube box object return boolean value 
        }
};

int main(void) {
   cube Box1(8.5);                                           // Declare box1 by parameterized Constructor
   cube Box2(8.5);                                 // Declare box2 by parameterized Constructor

   if(Box1.compare(Box2)) {
      cout << "Box2 is smaller than Box1" <<endl;
   } else {
      cout << "Box2 is equal to or larger than Box1" <<endl;
   }
   
   return 0;
}
/******************OUTPUT***************
by parameterized Constructor
 */
#endif

#if block==5
//What do you mean friend function ? Write a program to illustrate the friend function in action.

/******************ANSWER************* 
A function that has the right to access all private and protected members of the class and is declared inside the class using keyword "friend" and defined outside the class is known as friend function. Even though the prototypes for friend functions appear in the class definition, friends are not member functions of that class. A function or a entire class of the function can be declared as the friend. Using friend function can enhance performance. The most obvious use of the friend function is the stream << or >> operator overloading. as these Operators being a member of 
stram object which is defined by the complier. When we use these as stream operators (rather than binary shift) the first parameter is a stream. Since we do not have access to the stream object (its not ours to modify) these can not be member operators they have to be external to the class. Thus they must either be friends of the class or have access to a public method that will do the streaming.
It is also traditional for these objects to return a reference to a stream object so that chaining stream operations together is possible..
for eg,
    class Y {
        Private:
            int data;                       // private member
            friend std::ostream& operator<<(std::ostream& out, const Y& o);
                                            // the non-member function operator<< will have access to Y's private members
            friend char* X::foo(int);       // members of other classes can be friends too
            friend X::X(char), X::~X();     // constructors and destructors can be friends
};
                                            // friend declaration does not declare a member function
                                            // this operator<< still needs to be defined, as a non-member

std::ostream& operator<<(std::ostream& out, const Y& y)
{
    return out << y.data; // can access private member Y::data
}
   Points to be noted:
    Friendship is not transitive (a friend of your friend is not your friend).
    Friendship is not inherited (your friend's children are not your friends).
    Storage class specifiers are not allowed in friend function declarations. A function that is defined in the friend declaration has external linkage, a function that was previously defined, keeps the linkage it was defined with.
    Access specifiers have no effect on the meaning of friend declarations (they can appear in private: or in public: sections, with no difference).
    A friend class declaration cannot define a new class (friend class X {}; is an error).
    When a local class declares an unqualified function or class as a friend, only functions and classes in the innermost non-class scope are looked up, not the global functions:


*/
//..................CODE.............
// simple program  demonstrating simple instance of friend function
#include <iostream>    
using namespace std; 

class cube{
    private:
        float side=0.0;
    public:
        // declaration of the methods
        cube(float);
        void set_side();
        void display();
        float volume();
        friend  cube expand_twice (cube);
};
//  member function definition
  
     cube::cube(float s=0.0){    //using default values
        side=s;
    }
    void cube::set_side(){
        cout << "side :";
        cin  >> side;
    } 
     
    void cube::display(){
        cout << "The parameters of cube are:"<< endl;
        cout << "side :="<<  side << endl;
        cout << endl;
    }
    float cube::volume(){
        return (side*side*side);
    }
//  end of member function definition of cube

    cube expand_twice(cube c){     // friend function definition
    c.side = 2*c.side;            
                                   //this function has a direct access to private data due to being declared as friend in class cube.
    return c;
    }    
// driver code
int main(){    
    cube a(1), b;    
    a.display();
    b=expand_twice(a);              //calling friend function
    b.display();
return 0;    
}    
/*****************OUTPUT*************
The parameters of cube are:
side :=1

The parameters of cube are:
side :=2

*/ 
#endif
