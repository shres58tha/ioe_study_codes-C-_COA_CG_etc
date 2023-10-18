 
 // print alternatively in the pattern
#include <stdio.h>
int main (){
    
    char arr[]="PULCHOWK";
    for (int i=0;i<8;i++){
        for (int j=0; j<=80-i;j++) 
            putchar(' ');
                 
        for (int k=7-i; k<8;k++)
            putchar(arr[k]);
             
        putchar('\n');
    }
    
}
