// program to reverse array
#include<stdio.h>

void reverse_array(int *p, int sz){   // entirely by using pointers
    int temp;           
    for (int i=0; i<sz/2;i++){  // swapping must be done till the center of the element if run for full lenght reversed twice
        temp=*(p+i);
        *(p+i)=*(p+sz-1-i);  // last element of the array has index sz-1
        *(p+sz-1-i)=temp;
    }
}                      

#define MAX_LIMIT 501 // gcc complains that if the pointer is increased to full val of array so + 1  is a buffer
int main(){
    int arr[MAX_LIMIT], sz;
    printf("enter the no of element in list max %d :", MAX_LIMIT);
    scanf ("%d",&sz);
    printf (" enter %d numbers seperated by white space :", sz);
    for(int i=0;i<sz;i++)
       scanf ("%d",(arr+i)); // store the scanned value at address arr+i 
                   
    reverse_array(arr, sz);
    
    printf("\nreversed array\n");
        for(int i=0;i<sz;i++)
                printf ("%d\t",*(arr+i)); // print value at address p+i 
    printf("\n");

return 0;

}

