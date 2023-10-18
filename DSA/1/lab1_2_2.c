#include<stdio.h>
//write to perform addition subtraction division and multiplication usng functions
float add( float x,  float y){
	return( x+y);
}
float sub( float x,  float y){
	return( x-y);
}
float mul( float x,  float y){
	return( x*y);
}
float div( float x,  float y){
	return( x/y);
}

int main(){
    float a,b;
    printf("enter two number ");
    scanf("%f %f", &a,&b);
    printf("the result of addition %f \n" ,add(a,b));
    printf("the result of subtraction %f\n" ,sub(a,b));
    printf("the result of multipication %f\n" ,mul(a,b));
    printf("the result of division %f\n" ,div(a,b));

    return 0;
}
