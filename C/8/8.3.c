// find biggest number among three number uding pointer
#include <stdio.h>
int main (){
    int num[3];
    int *max;
    printf ("enter numbers :");
    for (int i=0;i<=2; i++)
        scanf ("%d",&num[i]);
    max = &num[0];
     for (int i=0;i<=2; i++){
         if (*max < num[i]) max=&num[i];
    }
         
         printf (" max  %d \n", *max);
         
}
