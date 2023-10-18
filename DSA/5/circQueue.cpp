#include<stdio.h>
# define MAX 5
int arr[MAX];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("\nQueue Overflow\n");
        return;
    }
    if(front == -1 || rear == -1 ) {
        front = 0;
        rear = 0;
    }
    else {
        if(rear == MAX-1)
            rear = 0;
        else
            rear = rear+1;
    }
    arr[rear] = item ;
}

void dequeue() {
    if(front == -1) {
        printf("\nQueue Underflow\n");
        return ;
    }
    printf("Element dequeued is : %d\n",arr[front]);
    if(front == rear) {
        front = -1;
        rear=-1;
    }
    else {
        if(front == MAX-1)
            front = 0;
        else
            front = front+1;
    }
}

void display() {
    int front_pos = front,rear_pos = rear;
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if( front_pos <= rear_pos )
    while(front_pos <= rear_pos) {
        printf("%d ",arr[front_pos]);
        front_pos++;
    }
    else {
        while(front_pos <= MAX-1) {
            printf("%d ",arr[front_pos]);
                front_pos++;
        }
        front_pos = 0;
        while(front_pos <= rear_pos) {
            printf("%d ",arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

int main() {
    int choice,item;
    do {
        printf("\n Menu ");
        printf("\n 1. enqueue operation");
        printf("\n 2. dequeue operation");
        printf("\n 3. display operation");
        printf("\n 4. quit \n");
        printf("\n enter choice ");
        scanf("%d",&choice);
        switch(choice) {
            case 1 :
                printf("Input the element for enqueuing in queue : ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2 :
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Wrong choice\n");
        }
    }while(choice!=4);
    return 0;
}
