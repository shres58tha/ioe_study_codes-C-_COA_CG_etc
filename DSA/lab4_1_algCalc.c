//#include "infix2postf.c"
#include <stdio.h>
#include<stdlib.h> //exit
#include<string.h> //strcat
#include <ctype.h>  //isdigit , isalpha

#define SIZE 100

int stack[SIZE+3];
int top = -1;

void push(int x){
    printf("push top = %d x=%d\n",top,x);
    //(top<SIZE) ? stack[++top] = x : printf("\nstack overflow\n");
    if(top>SIZE){
        printf("\nstack overflow\n");
        exit(1);
    }
    else{
        top++;
        stack[top] = x;
        printf("push top = %d x=%d\n",top,x);
    }
}

int pop(){
    int a;
    if(top<-1){
        printf("\nstack empty\n");
        exit(1);
    }
    else{
        a=stack[top];
        printf("pop top = %d a=%d\n",top,a); 
        top--;
        return(a);
        
    }
}

int main()
{
    char exp[SIZE+3];
    char *e;
    int n1,n2,n3,num;
    printf("Enter the expression : ");
    fgets(exp,SIZE,stdin);
    e = exp;
    while(*e != '\0')
    {
        printf("%c",*e);
        if(isdigit(*e))
        {
            num = *e - 48;
            printf("qwe");
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}
