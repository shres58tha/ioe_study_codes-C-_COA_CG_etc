#include<stdio.h>

int main(){
    float a,b;
    printf("enter two number ");
    scanf("%f %f", &a,&b);
    printf("the remainders is %d \n", (int)a % (int)b );
    return 0;
}
