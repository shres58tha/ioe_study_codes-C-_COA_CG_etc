#include<iostream>
#include<cstring>
using namespace std;
template <class T>
T find_max( T a, T b){
    T result;
    if (a>b)
        result= a;
    else 
        result= b;
return result;
}

// for string data
char *find_max( char* a, char * b){
    char *result;
    if (strcmp(a,b)>0)
        result= a;
    else 
        result= b;
return result;
}
int main(){
        int a=5 , b=6;
        cout << "greater is :" << find_max (a,b)<< endl ;
        char s1[]= "hello", s2[]= "hi";
          cout << "greater is :" << find_max (s1,s2)<< endl ;
}
