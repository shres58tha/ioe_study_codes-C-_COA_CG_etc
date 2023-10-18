#/*header making c/c++ code bash exeutable with gcc/g++/tcc
#!/bin/bash
clear;echo HI! from bash$'\n'doing $0->a.out; rm -f ./a.out   
g++ -Wall "$0"; #gcc "$0";#interperator mode;#tcc -run "$0"
if (($? != 0));then echo ..ERROR COMPILATION..$'\n';exit;fi
read -t 2 -p ' running c excutable in 2 s ...'; echo; clear
echo executing... $'\n\t....\n\t....';./a.out;rm -f ./a.out 
read -t 5 -p 'press any key or wait 5 s.';echo $'\n\n';exit
*******************C/C++ code below here*******************/
#include <stdio.h>
int main(){ 
       printf("hello, world from C.\n "); 
       
return 0
}
