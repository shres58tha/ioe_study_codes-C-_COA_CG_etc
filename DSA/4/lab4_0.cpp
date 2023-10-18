#include<stdlib.h>
#include<stdio.h>
#define max 50
int q[max+1], r=-1, f=-1;
void enqueue(){
    int d;
    if(f==-1 || r==-1 )
        f++;        //increment to indicate something in queue
    if( f<max){     //add data to queue
        printf("\n enter the data ");
        scanf("%d",&d);
        q[++r]=d;   // // increment rear adding at the rear
    }
    else
        printf("\n Queue is full \n");
}
void dequeue(){
    if( f>r || f==-1 || r==-1 || f>=max || r>=max ){  //condition in which queue is empty
        printf("\n Queue is empty resetting the queue\n f:%d r:%d",f,r);
        f=-1; r=-1;
    }
    else     //add data to queue
        printf("\n data dequeued %d\n",q[f++]); // return the val at the front and point to next in queue
}
void display(){ // show content of the queue
    if(f>r || r==-1 )
        printf("\n Queue is empty \n");   //increment to indicate something in queue
    else if( f<max){    
           printf("\n Queue start \n");
           for (int i=f; i<=r; i++){
           printf("\n pos %d = %d\n",i, q[i]);
          }  o
    }
}
int main(){
    int choice;
    while(1){
          printf("\n Menu ");
          printf("\n 1. enqueue operation");
          printf("\n 2. dequeue operation");
          printf("\n 3. display operation");
          printf("\n 4. quit \n");
          printf("\n enter choice ");
          scanf("%d",&choice);
          switch (choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\ninvalid choice\n");
          }
    }
return 0;
}
