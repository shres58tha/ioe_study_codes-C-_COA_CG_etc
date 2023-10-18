 // print the pattern
 /*      
    N
   eee
  PPPPP
 aaaaaaa
LLLLLLLLL

*/
 
 
 
#include <stdio.h>
int main (){
    
    char arr[]="NEPAL";
    for (int i=0;i<5;i++){
        for (int j=0; j<5-i;j++)
        putchar (' ');
        for (int k=0;k<=2*i;k++){
                if (i%2==0) 
                    putchar(arr[i]);
                else 
                    putchar(arr[i]+32);
        }
        putchar('\n');
    }
    putchar('\n');
    return 0;
}
