// C++ program to calculate the Simple Interest using function. The default time period to calculate the Simple Interest is 1 year


#include<iostream>
using namespace std;
//default time t =1  year
float Simple_intrest(float p, float r, int t=1){
    return (p*r*t/100);
}

// driver code
int main(){  
    cout << "calling with p= 100 & r=2.5\nSI=" <<Simple_intrest(100,2.5)<< endl;
    cout << "calling with p= 100, r=2.5 & t=2\nSI=" <<Simple_intrest(100,2.5,2)<< endl;
} 

/**************output************
shr@shr-Aspire-E5-532:~/Desktop/cpract/CPP$ ./a.out 
calling with p= 100 & r=2.5
SI=2.5
calling with p= 100, r=2.5 & t=2
SI=5
***********************************/
