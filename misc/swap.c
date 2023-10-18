#include <stdio.h>
void swap(int*, int*);

int main(){
    int a, b;
    printf ("enter 1st number :");
    scanf("%d",&a);
    printf ("enter 2nd number :");
    scanf("%d",&b);
    printf(" the numbers are \n a=%d \n b=%d\n",a,b);
    printf("calling swap function");
    swap(&a,&b);
    printf(" the numbers are \n a=%d \n b=%d\n",a,b);

return 0;
}

void swap (int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
