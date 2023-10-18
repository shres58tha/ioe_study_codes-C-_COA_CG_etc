#include <stdio.h>
#define MAX_SIZE 100 // max size of stack
void display();
void push();
void pop();
int stack[MAX_SIZE]; // stack
int size_stack, top; // global variables

int main(){
    int choice;
    top=-1; // stack empty
    printf("enter the size of the stack (< max_size 99) : ");
    scanf ("%d",&size_stack);
    do{

        printf ("\n 1. PUSH \n 2. POP \n 3. DISPLAY \n 4. EXIT \n\nEnter choice(select int) :");
        scanf ( "%d",&choice);

        switch(choice){
            case 1:{
                push();
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                printf(" Exit");
                break;
            }
            default :{
                printf("\nenter valid choice \n");
            }
        }
    }while(choice !=4);
return 0;
}

void push(){
    int data;
    if(top == size_stack-1){
        printf("\nStack overflow\n");
       }
    else{
        printf("\nenter data to push into the stack :");
        scanf("%d",&data);
        top++;
        stack[top]=data;
    }
    return;
}

void pop(){
    int data;
    if(top == -1){
        printf("\nStack empty\n");
       }
    else{
        data=stack[top];
        top--;
        printf("\nthe popped data is %d\n\n",data);
    }
    return;
}


void display(){
    if(top == -1){
        printf("\nStack empty\n");
       }
    else {
        printf("\ndata in stack\n");
        for ( int pos=top; pos>-1;pos--){
                printf("%d\n",stack[pos]);
            }
        printf("\n\n");
        }
    return;
}
