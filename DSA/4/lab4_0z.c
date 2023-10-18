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
    if(top>SIZE){
        printf("\nstack overflow\n");
        exit(1);
    }
    else{
        stack[++top] = x;
        printf("\n%d\n",top);
    }
}

int pop(){
    if(top<-1){
        printf("\nstack empty\n");
        exit(1);
    }
    else{
        return(stack[top--]);
    }
}

int evalpostfix(char exp[]){
    int n1,n2,result,num;
    char *ch = exp;
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
                    result = n1 + n2;
                    break;
                }
                case '-':{
                    result = n2 - n1;
                    break;
                }
                case '*':{
                    result = n1 * n2;
                    break;
                }
                case '/':{
                    result = n2 / n1;
                    break;
                }
            }
            push(result);
        }
        ch++;
    }
return(pop());
}
int main(){
    char exp[SIZE+3];
    char *ch;
    printf("Enter the expression : ");
    fgets(exp,SIZE,stdin);
    printf("\nThe result of expression %s = %d\n\n",exp,evalpostfix(exp));
    return 0;
}
