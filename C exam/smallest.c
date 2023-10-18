 
#include <stdio.h>

int main (){
    
    int a,b,c, min;
    printf("\nenter 3 int : ");
    scanf ("%d %d %d",&a,&b,&c);
    min=a<b?a:b;
    min=min<c?min:c;
    printf("smallest: %d\n",min);
    
    return 0;
      
}
