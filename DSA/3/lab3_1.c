#include<stdio.h>
#include<string.h>
#define size 100
char stack[size+2];
int top=-1;
void push(char item){
    if (top >=size-1){
        printf("\n Stack OVERFLOW \n");
    }
    else{
        top++;
        stack[top]=item;
    }
    //printf("\npushed\n");
    return;
}
char pop(){
    printf(" locate1");
    char item;
    if (top <0){
        printf("\n Stack EMPTY \n");
        item='\0';
    }
    else{
        item=stack[top];
        top--;
    }
    //printf("\npopped\n");
    return item;
}
int is_operator(char symbol){
	int ret_val=0;
    if (symbol=='^'||symbol=='*'||symbol=='+'||symbol=='+'||symbol=='-'){
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
    printf("\nprecedence\n");
    return ret_val;
}

void infix2postfix(char infix_exp[],char postfix_exp[]){
    int i=0,j=0;
    char item,x;
    push('(');
    strcat(infix_exp,")");
    item=infix_exp[i];
    while(item!='\0'){
            printf(" locate a");
        if (item =='('){
            push (item);
            printf(" locate b");
        }
        else if (isdigit(item)||isalpha(item) ){
            printf(" locate c");
            printf(" item =%c \n %s",item,postfix_exp);
            postfix_exp[j]=item;
            j++;
        }
        else if(is_operator(item)==1 ){
            printf(" locate d");
            x=pop();
            while(precedence(x)>=precedence(item)){
            	printf(" whileeeee    %c /n",x);
                postfix_exp[j]=x;
                j++;
                x=pop();
                }
             push(x);
             push(item);
        }
        else if (item == ')'){
            printf(" locate e");
            x=pop();
            while (x!='('){
                 postfix_exp[j]=x;
                 j++;
                 x=pop();
            }
        }
        else{
            printf("invalid");
            exit (1);
        }
        i++;
        item=infix_exp[i];
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
    char infix[size]="\0", postfix[size]="\0";
    printf("enter infix ");
    gets(infix);
	//fflush(stdin);
	//scanf("%s",infix);
    infix2postfix(infix,postfix);
    puts(postfix);
    return 0;
}
