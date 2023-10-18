#include<stdio.h>
#define MAX 3
int arr[MAX];
int front = -1, rear = -1;
void enqueue() {
    if ((rear+1) %MAX == front) {
        printf ("\nQueue Overflow\n");// queue is full
        return;
    }
    if(front == -1 || rear == -1 ) {
        front = rear = 0;
    }
    else {
        rear = (rear+1) % MAX;       //incrementing rear
    }
    printf("Input data for enqueuing : ");
    scanf("%d", &arr[rear]) ;           //assigning value
}
void dequeue() {
    if(front == -1) {
        printf("\nQueue Underflow\n");
        return ;
    }
    printf("Data dequeued is : %d\n",arr[front]);
    if(front == rear) {
        front = rear = -1;          //resetting Queue is empty
    }
    else {
        front = (front+1) % MAX;     //incrementing front
    }
}
void display() {
    int front_pos = front,rear_pos = rear;
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    else {
        printf("Queue elements :\n");
        while(front_pos != rear_pos) {
            printf("%d ", arr[front_pos]);
            front_pos = (front_pos+1) % MAX; //incrementing pointer circularly
        }
        printf("%d \n",arr[front_pos]); // print for the case front=rear
    }
}
int main() {
    int choice;
    do {
        printf("\n Menu ");
        printf("\n 1. enqueue operation");
        printf("\n 2. dequeue operation");
        printf("\n 3. display operation");
        printf("\n 4. quit \n");
        printf("\n enter choice ");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :
                enqueue();
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
    }while(choice != 4);
    return 0;
}
