#/* bash header rendering c/c++ code run with gcc/g++/tcc;
#!/bin/bash
clear;echo $'\n'Executing $0 $'\n    using BASH header\n';
rm -f a.out;echo $'preparing...';g++ -Wall "$0";#gcc "$0";
#tcc -run "$0" #interprate mode code umesh.acem@gmail.com;
if(($? != 0));then echo $'\n.ERROR COMPILATION.\n';exit;fi
echo executing...$'\n';./a.out "$@"; #cli argument handled
rm -f a.out;echo;read -t 5 -p 'press any key or wait 5 s.'
echo $'\n';exit 0; ********C/C++ code below here*********/
//Command line arguments in C/C++
//usage bash-C++.cpp arguments here 
#include <iostream> 
using namespace std; 
int main(int argc, char** argv){ 
    if (argc<2){
        cout<<"Usage: bash-C++.cpp arguments here .....\n";
        return 0;
    }      
    cout<<"You have entered "<<argc-1<<" arguments:"<<"\n"; 
    cout<<"the arguments entered are :\n";     
    for (int i = 1; i < argc; ++i)  //skipping 0th argument
        cout << argv[i] << " "; 
    cout <<endl;
    return 0; 
} 
