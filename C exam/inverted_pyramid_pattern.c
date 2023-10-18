 
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
        for (int j=0; j<=i;j++)
        printf (" ");
        for (int k=2*(5-i)-1;k>0;k--)
            putchar(arr[i]);
        
        putchar('\n');
        }
    putchar('\n');

    return 0;
    
}
