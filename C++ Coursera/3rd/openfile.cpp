#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main () {
    int array[4];
    string line;
    ifstream myfile;
    myfile.open ("sampletestdata");
       if ( (myfile.rdstate() & std::ifstream::failbit ) != 0 ){
            std::cerr << "Error opening 'sampletestdata'\n";
        return 0;  
        }
    
while (getline(myfile,line)){
    istringstream ss(line);
    //if (myfile.eof()==true) break;
    int i=0;
        while (ss>> array[i]){
        cout<<array[i]<<" ";
        i++;
        if(i>3) {cout<<endl<<"Error in sampledatatest not a proper format"<<endl;exit(2);}
    }//*/
    
    cout<< endl;
}

myfile.close();

return 0;
}
