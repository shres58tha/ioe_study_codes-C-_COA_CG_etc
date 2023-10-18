


/*Program to generate Fibonacci series*/
  
  
#include<stdio.h>

int main(){
char ch;
reset:
int k=2,r;
long int i=1•.j=1,f;
while(k<r) { 
    printf("Enter the range:");
    scanf("%d",&r);

    f=i+j;
    i=j;
    j=f;
    printf(" %ld \n",j);
    k++;       
           }
printf ("for exit press q to continue press any :");
scanf ("%ch",&a);
if (a=='q')
goto exit;
else goto reset;

exit:

printf ("bye");

return 0;
}



