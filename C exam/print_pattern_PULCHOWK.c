 
 // print alternatively in the pattern
#include <stdio.h>
int main (){
    
    char arr[]="PULCHOWK";
    for (int i=0;arr[i]!='\0';i++){
        for (int j=0; j<=i;j++){  
             if (i%2==0)
                 putchar(arr[j]);
             else if (j%2==0) 
                    putchar(arr[j]);
                else 
                    putchar(arr[j]+32);
        }
        putchar('\n');
    }
    
}
