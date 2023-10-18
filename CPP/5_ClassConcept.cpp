//  simple C++ program using the concept of Class and Objects (Optional Question) 

#include <iostream> 
using namespace std;
                    
class Rectangle {           // class declaration
   protected:
      double lenght;
      double width;
   public:
      //Rectangle(){lenght  = 0; width = 0;}   //causes error
      Rectangle(double l=0, double w =0) {lenght  = l; width = w;}  //constructor  
      
      void setLength(double l) {
         lenght = l;
      }  
      void setWidth(double w) {
         width = w;
      }
      double getArea() { 
         return ( lenght * width); 
      }
      
      ~Rectangle(){                            //destructor
          cout<< "instance of Rectangle destroyed\n";
    }   
  
};

class Cuboid: public Rectangle {             // Derived class
   protected:
      double height; 
   public:
      Cuboid(){lenght=0; width=0; height=0;}          // constructor
      Cuboid(double l=0, double w=0, double h=0){lenght=l; width=w; height=h;}  //constructor
      void setHeight(double h) {
         height = h;
      }
     double getVolume() { 
         return ( lenght * width * height); 
      }
      ~Cuboid(){                            //destructor
          cout<< "instance of Cuboid destroyed\n";
    }                        
     
};

int main(void) {
{
    Cuboid Cub(1,1,1);
    cout << "Total Vol: " << Cub.getVolume() << endl;
}
   Cuboid Cub(2,2,2);
    cout << "Total Vol: " << Cub.getVolume() << endl;
 /*
   Cub.setLength(5);
   Cub.setWidth(5);
   Cub.setHeight(7);
*/
   Rectangle s;
   cout << "Total Vol: " << s.getArea() << endl;

   return 0;
}

/********OUTPUT*************




*****************************/
