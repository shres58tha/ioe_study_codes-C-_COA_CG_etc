// program to swap two numbers by reference method
#include<stdio.h>

void swp_num( int *a,  int *b) {
        int t;
        t=*a;
        *a=*b;
        *b=t;
    
} //swap values of two numbers using pointer

int main(){
    int a, b;
    printf("\nenter two numbers :");
    scanf("%d %d",&a,&b);
    printf("\t\tcalling swp_num(a,b)\n");
    swp_num(&a,&b);
    printf("\nnumbers are now :%d %d \n\n",a,b);
return 0;
}
