#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
Node node_default={0,NULL};

Node *head=NULL;  //by default it takes null ni

void startinsert ();
void lastinsert ();
void display();
void search();
int main () {
    printf ("\n%p\n",&head); //address of head
    printf ("\n%p\n", head); //address head points to
    
    int choice =0;
    while(choice != 4) {
        printf("\nMenu\
        \n1.Insert in begining\
        \n2.Insert at last\
        \n3.Display\
        \n4.Exit\n");
        printf("\nEnter choice :");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                startinsert();
                break;
            case 2:
                lastinsert();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nenter valid choice..");
        }
    }
    return 0;
}

void startinsert() {
    Node *ptr;
    ptr = (Node *) malloc(sizeof(Node *));
    if(ptr == NULL) {
        printf("\nOverflow");
    }
    else {
        printf("\nEnter value :");
        scanf("%d", &ptr->data);
        ptr->next = head;
        head = ptr;
        printf("Node inserted\n");
    }
}

void lastinsert() {
    Node *ptr,*temp;
    ptr = (Node *)malloc(sizeof(Node ));
    if(ptr == NULL) {
        printf("\nOverflow");
    }
    else {
        printf("\nEnter value :");
        scanf("%d",&ptr->data);
        if(head == NULL) {
            ptr -> next = NULL;
            head = ptr;
        }
        else {
            temp = head;
            while (temp -> next != NULL) {
                temp = temp -> next;
            }
            temp->next = ptr;
            ptr->next = NULL;
       }
        printf("Node inserted\n");
    }
}

void display() {
    Node *ptr;
    ptr = head;
    if(ptr == NULL) {
        printf("Empty\n");
    }
    else {
        printf("\nList..");
        while (ptr!=NULL) {
            printf("\n%d",ptr->data);
            ptr = ptr -> next;
        }
    }
    printf("\n\n");
}
/*output
 * Menu                
 * 1.Insert in begining                
 * 2.Insert at last                
 * 3.Display                
 * 4.Exit
 * 
 * Enter your choice :1
 * 
 * Enter value
 * 10
 * 
 * Node inserted
 * Menu                
 * 1.Insert in begining                
 * 2.Insert at last                
 * 3.Display                
 * 4.Exit
 * 
 * Enter your choice?1
 * 
 * Enter value
 * 20
 * 
 * Node inserted
 * Menu                
 * 1.Insert in begining                
 * 2.Insert at last                
 * 3.Display                
 * 4.Exit
 * 
 * Enter your choice?3
 * 
 * List
 * 20
 * 10
 * 
 * 
 * Menu                
 * 1.Insert in begining                
 * 2.Insert at last                
 * 3.Display                
 * 4.Exit
 * 
 * Enter your choice?2
 * 
 * Enter value?
 * 50
 * 
 * Node inserted
 * Menu                
 * 1.Insert in begining                
 * 2.Insert at last                
 * 3.Display                
 * 4.Exit
 * 
 * Enter your choice?3
 * 
 * List
 * 20
 * 10
 * 50
 * 
 * 
 * Menu                
 * 1.Insert in begining                
 * 2.Insert at last                
 * 3.Display                
 * 4.Exit
 * 
 * Enter your choice?4
 * 
 */
