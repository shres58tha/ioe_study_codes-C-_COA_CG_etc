//#include "infix2postf.c"
#include <stdio.h>
#include<stdlib.h> //exit
#include<string.h> //strcat
#include <ctype.h> //isdigit , isalpha

#define SIZE 100

int stack[SIZE+2];
int top = -1;

void push(int x){
    printf("push top = %d x=%d\n",top,x);
    //(top<SIZE) ? stack[++top] = x : exit(printf("\nstack overflow\n"));
    if(top>SIZE){
        printf("\nstack overflow\n");
        exit(1);
    }
    else{
        //top++;
        stack[++top] = x;
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

int main(){
    char exp[SIZE+3];
    char *ch;
    int n1,n2,n3,num;
    printf("Enter the expression : ");
    fgets(exp,SIZE,stdin);
    ch = exp;
    while(*ch != '\0'){
        printf("%c", *ch);
        if(isdigit(*ch)){
            num = *ch - 48; //convert to number ie *ch - '\0'  48 is ascii val of 0
            push(num);
        }
        else{
            n1 = pop();
            n2 = pop();
            switch(*ch){
                case '+':{
                    n3 = n1 + n2;
                    break;
                }
                case '-':{
                    n3 = n2 - n1;
                    break;
                }
                case '*':{
                    n3 = n1 * n2;
                    break;
                }
                case '/':{
                    n3 = n2 / n1;
                    break;
                }
            }
            push(n3);
        }
        ch++;
    }
    printf("\nThe result of expression %s = %d\n\n",exp,pop());
    return 0;
}
