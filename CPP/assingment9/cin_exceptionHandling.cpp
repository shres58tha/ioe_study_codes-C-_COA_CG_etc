 
#include <iostream>
#include <exception>
#include <limits>


using namespace std;

int main()
{
	int x;
    bool err_flag=0;  // 0 all ok

	// make failbit to throw exception
	cin.exceptions(ios::failbit);
do{
	try {
        err_flag=0;  //reset err_flag
		cin >> x;
		cout << "input = " << x << endl;
        
		
	}
	catch(ios_base::failure &fb) {
        cout<< "ios::failbit"<< ios::failbit <<endl;
		cout << "Exception:" << fb.what() << endl;
		cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
        err_flag=1;  // flag set
	}
}while(err_flag);
	return 0;
}

/*
 * // ios::exceptions
#include <iostream>     // std::cerr
#include <fstream>      // std::ifstream

int main () {
  std::ifstream file;
  file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
  try {
    file.open ("test.txt");
    while (!file.eof()) file.get();
    file.close();
  }
  catch (std::ifstream::failure e) {
    std::cerr << "Exception opening/reading/closing file\n";
  }

  return 0;
}
*/
