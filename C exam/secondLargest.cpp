//display 2nd largest number in list
#include <stdio.h>
int main (){
int a[]={44,66,99,100,33,220,55};
int x , y;
x=a[0];y=a[1]; 
if (a[0] >a[1] ){
 x=a[1] ; 
 y=a[0];
 } 

for ( int i = 2; i < 7; i++) {
                if (y < a[i]) {
                x=y;
                y = a[i];
                }
                else if (x<a[i])
                    x=a[i];
            }
        
       printf ("%d",x);
}
