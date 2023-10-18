// applicatio of stack 
#include <stdio.h>
#include<stdlib.h> //exit
#include<string.h> //strcat
#include <ctype.h>  //isdigit , isalpha

#define SIZE 100
char stack[SIZE+3]; //size + '(' + ')' + '/0'
int top=-1;
int isEmpty(){
    return (top<0?1:0);
}
int isFull(){
    return (top>=SIZE-1?1:0);
}
void push(char item){
    if (isFull())
        printf("\n Stack OVERFLOW \n");
    else
        stack[++top]=item;
    return;
}
char pop(){
    if (isEmpty()){
        printf("\n Stack EMPTY \n");
        return 0;
    }
    else
       return stack[top--];
}
char peek(){
    return stack[top];
}

int precedence(char symbol){
    switch(symbol){
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:            //not sure why this is needed
            return 0;
    }
}
void infix2postfix(char infix[],char postfix_exp[]){
    int i=0,j=0;
    char item,next,infix_exp[SIZE+1]={'\0'};
    push('(');   // this and line below actually takes care of handling full expression
    strcpy(infix_exp,infix);
    strcat(infix_exp,")"); //string needed null char needed to stop concating
    item=infix_exp[i];
    while(item!='\0'){
        //printf(" while ");
        switch(item){
             //(c <= 32 && c >= 0) || c == 127;   whitespace
            case 0 ... 32:
            case 127:
                printf("\titem : whitespace\n");
                break;   // ignore whitespace characteres
            case '(':
                push (item);
                printf("\titem (\n");
                break;
            case ')':  
                printf("\titem )\n");
                while ( ( next=pop() ) !='(' ){
                    printf("\titem %c\n",next);
                    postfix_exp[j++]=next;
                }
                break;
            case '^':
            case '/':
            case '*':
            case '%':
            case '+':
            case '-':    
                while(!isEmpty() && precedence(stack[top])>=precedence(item)){
                    printf("\titem %c\n",stack[top]);
                    postfix_exp[j++]=pop();
                }
                push(item);
                printf("\titem %c\n",item);  
                break;
             default:
                //printf("item default %c\n",item);
                postfix_exp[j++]=item;
        }
    item=infix_exp[++i];
    printf("postfix_exp %s\n",postfix_exp);
    }
    postfix_exp[j]='\0';
return;
}

int main(){
    char infix[SIZE+1]={'\0'}, postfix[SIZE+1]={'\0'}; // size + '\0' initilized to enable printing stack as string
    printf("enter infix ");
    //gets(infix);  // gets is dangerous and should not be used
    fgets(infix,SIZE,stdin); // gets character only upto  SIZE leaves rest in stdin
    int len = strlen(infix);
    if (infix[len - 1] == '\n') // remove trailing '\n'
        infix[len - 1] = 0;
    fflush(stdin); //flush stdin
    infix2postfix(infix,postfix);
    printf("\ninfix   %s",infix )  ;
    printf("\npostfix %s\n",postfix);
    return 0;
}
