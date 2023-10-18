//read entered no until user enters 0 and display max and min nos
#include <stdio.h>
int main() {
   int max=0,min=0,x;
        do{
        printf("enter numbers sequently (for existing loop enter 0):");
        scanf("%d",&x);
        max=max>x?max:x;
        min=min<x?min:x;
        } while (x);
        printf("/n/n the max. num. is %d  and min. num. is %d",max,min);
   return 0;
}
