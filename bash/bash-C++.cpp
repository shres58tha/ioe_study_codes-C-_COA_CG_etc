#/*header making c/c++ code bash exeutable with gcc/g++/tcc
#!/bin/bash
clear;echo HI! from bash$'\n'doing $0 -> a.out; rm -f a.out   
g++ -Wall "$0"; #gcc "$0";#interperator mode;#tcc -run "$0"
if (($? != 0));then echo $'\n..ERROR COMPILATION..\n'; exit
fi;read -t 2 -p 'running c excutable in 2 s..'; echo; clear
echo executing...$'\n\t....\n\t....\n';#coded by shres58tha
./a.out "$@" #cli argument handled    #umesh.acem@gmail.com
rm -f a.out;echo;read -t 5 -p 'press any key or wait 5 s..'
echo $'\n\n';exit 0; *******C/C++ code below here**********/
//Command line arguments in C/C++ 
//usage bash-C++.cpp arguments here 
#include <iostream> 
using namespace std; 
int main(int argc, char** argv){ 
    if (argc<2){
        cout<<"Usage: bash-C++.cpp arguments here ... ..\n";
        return 0;
    }      
    cout << "You have entered " << argc 
         << " arguments:" << "\n"; 
    cout <<"the arguments entered are :\n";     
    for (int i = 1; i < argc; ++i)  //skipping 0th argument
        cout << argv[i] << " "; 
    cout <<endl;
    return 0; 
} 
