
#include <iostream>                                         // standard input output stream 
#include <vector>                                           // vector header
#include <ctime> //including the c time.h 

using namespace std; 
 
int main()
{
int how_many = 100;
srand(rand()*time(0));  // Initialize random number generator.

cout << "Print " << how_many
<< " random integers." << endl;
for (int i = 0; i < how_many; ++i)
cout << rand() << '\t';
cout << endl;
} 
