#include<stdio.h>
#include<conio.h>
#include<math.h>
float equation(float x)
{
    return (2/(x+1));
}
int main ()
{
    float x0,e,x1;
    int i=0;
    printf("enter x0 ");
    scanf("%f",&x0);
    printf("enter e ");
    scanf("%f",&e);
    do 
    {
        if (i!=0)
            x0=x1;
        x1=equation(x0);
        i++;
    }	
    while (fabs(x1-x0)>=e);
    printf("\n root=%f",x1);
    printf("\n no of iteration %d\n",i);
    getch();
    return(0);
}
