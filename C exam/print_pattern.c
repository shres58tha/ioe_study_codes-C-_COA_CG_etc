 
 // print alternatively in the pattern
 /*      
    N
   eee
  PPPPP
 aaaaaaa
LLLLLLLLL

*/
 
 
#include <stdio.h>
int main (){
    
    char arr[]="NePaL";
    for (int i=0;i<5;i++){
        for (int j=0; j<5-i;j++)
        putchar (' ');
        for (int k=0;k<=2*i;k++)
            putchar(arr[i]);
        
        putchar('\n');
        
        }
    putchar('\n');

    return 0;
    
}
