#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
    return(x*x-4*x-10);
}
int main()
{
    float a,b,c;
    int count=0;
    printf("enter initial guess");
    scanf("%f %f",&a,&b);
    if((f(a)*f(b))>0)
    {
        printf("Invalid guess");	
    }
    else
        
    {
        do{
            c=b-((b-a)*f(b)/(f(b)-f(a)));
            if(f(b)*f(a)<0)
                a=c;
            else
                b=c;
            count++;
            printf(" \n no.of iterations -->%d, root=%f",count,c);
        }
        while(fabs(b-a)>0.00001);
        printf("\n the  required solution is =%f \n",c);
        printf(" \n no 0f iterations=%d\n",count);
    }
    getch();
    return(0);
}
