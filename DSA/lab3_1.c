#include <stdio.h>
#include<stdlib.h> //exit
#include<string.h> //strcat
#include <ctype.h>  //isdigit , isalpha

#define SIZE 100
char stack[SIZE+3]={'\0'}; //size + '(' + ')' + '/0'
int top=-1;
void push(char item){
    if (top >=SIZE-1){
        printf("\n Stack OVERFLOW \n");
    }
    else{ 
        //top++;
        stack[++top]=item;
    }
    //printf("\npushed\n");
    return;
}
char pop(){
    //printf(" pop");
    char item;
    if (top <0){
        printf("\n Stack EMPTY \n");
        item='\0';
    }
    else{
        item=stack[top--];
        stack[top+1]='\0'; // for permitting to print stack as string
        //top--;
    }
    //printf(" popped %c",item);
    return item;
}
int is_operator(char symbol){
	int ret_val=0;
    if (symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-'){
        ret_val=1;
    }
    return (ret_val);
}
int precedence(char symbol){
    int ret_val=0;
    if (symbol == '^')
        ret_val=3;
    else if (symbol == '*'||symbol=='/')
        ret_val=2;
    else if (symbol == '+'||symbol=='-')
        ret_val=1;
    //printf("\nprecedence %d\n",ret_val);
    return ret_val;
}
void infix2postfix(char infix_exp[],char postfix_exp[]){
    int i=0,j=0;
    char item,x;
    push('(');
    strcat(infix_exp,")"); //string needed null char needed to stop concating
    item=infix_exp[i];
    while(item!='\0'){
        if (item =='('){
            push (item);
            //printf("\titem ( \n");
        }
        else if (isdigit(item)||isalpha(item) ){
            // printf("\titem %c \n ",item);
            postfix_exp[j++]=item;
            //j++;
        }
        else if(is_operator(item)==1 ){
            x=pop();
            while(precedence(x)>=precedence(item)){
            	//printf("\titem %c\n",x);
                postfix_exp[j]=x;
                j++;
                x=pop();
                }
             push(x);
             push(item);
             //printf("\titem %c\n",item);
        }
        else if (item == ')'){
            //printf("\titem )\n");
            x=pop();
            while (x!='('){
                 printf("\titem %c\n",x);
                 postfix_exp[j++]=x;
                 //j++;
                 x=pop();
            }
        }
        else if (item!='\0'){
            printf("\t NULL\n");
            //exit (1);
        }
        else {
            printf("\t INVALID EXPR\n");
            exit(1);
        }
        i++;
        item=infix_exp[i]; // get new item from the infix_exp
         printf("postfix_exp :%s \nstack       :%s\n \titem %c \n",postfix_exp,stack, item);
    }
    if (top>0){
        printf("invalid infix");
        exit (1);
    }
    postfix_exp[j]='\0';
    printf(" infix2postfix ");
    return;
}

int main(){
    char infix[SIZE+1]={'\0'}, postfix[SIZE+1]={'\0'}; // size + '\0' 
    // setting all the mem loction to null is necesssary to print stack as string
    printf("enter infix ");
    //gets(infix);  // gets is dangerous and should not be used
    fgets(infix,SIZE,stdin); // gets character only upto  SIZE leaves rest in stdin
	fflush(stdin); //flush stdin
    puts(postfix);
    infix2postfix(infix,postfix);
    puts(postfix);
    return 0;
}
