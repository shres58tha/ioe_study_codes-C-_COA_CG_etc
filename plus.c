#include <stdio.h>
int fun1(){
    printf(" 1st one");
    return 1;
}
int fun2(){
    printf(" 2nd one");
    return 1;
}
int main() {
    printf(" : %d\n",fun1()+fun2());
return 0;
}
