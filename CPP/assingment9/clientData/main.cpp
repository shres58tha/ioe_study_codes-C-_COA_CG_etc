//main.cpp
// Creating a randomly accessed file.
#include "client.h"
using std::cerr;
using std::endl;
using std::ios;

#include  <iostream>
#include <fstream>
using std::ofstream;

// #include <cstring>
 using std::exit; // exit function prototype

 int main()
 {
 ofstream outCredit( "credit.dat", ios::binary );

 // exit program if ofstream could not open file
 if ( !outCredit )
 {
 cerr << "File could not be opened." << endl;
 exit (0);
 } // end if

 ClientData blankClient; // constructor zeros out each data member

 // outputblank records to file
 for ( int i = 0; i < 0; i++ )
 outCredit.write( reinterpret_cast< const char * >( &blankClient ),
  sizeof( ClientData ) ); 

 return 0;
 } // end main
