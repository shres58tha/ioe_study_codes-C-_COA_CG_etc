/*
Write a conversion program to convert weights in kg to pounds(lbs).
The relationship is 1 kg = 2.2 pounds. (hint: user defined to user defined type conversion).
*/
#include <iostream>

using namespace std;
class Pound {
private:
  float mass;
public:   
  Pound (float m=0): mass(m){}
  float get_mass(){ return mass;}
};

class Kg{
private:
  float mass;
public:       
  Kg(float m=0): mass(m){}
  float get_mass(){ return mass; }
  Kg(Pound p){ mass=2.2*p.get_mass(); }
};

int main(){
 Pound p(5);
 Kg k;
 k=p;
 cout<<"\n mass in kg ="<< k.get_mass() << endl;
}
