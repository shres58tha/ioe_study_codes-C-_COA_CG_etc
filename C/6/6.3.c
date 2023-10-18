// program to get list of number and sort them and display them
#include<stdio.h>
#include <stdlib.h>
//#include<math.h>

#define block 1 // just change value of letter to select corrosponding block while comparing

#if (block==1)

int main(){
    float num[100],tmp;  // max list size 100
    int sz_lst, i, j;
    printf(" \nenter the list size of numbers :");
    scanf("%d",&sz_lst);
    if (sz_lst>100){printf("\n max size of list 100: \n exiting"); exit (1);}

    for (int i=0;i<sz_lst;i++){
        printf("enter a num : ");
        scanf ("%f",&num[i]);
    }
    //sort (&num[0],n);  // it is a lib function
    for( i=0;i<sz_lst;i++){
        for ( j=i+1;j<sz_lst;j++){
            if (num[i]>num[j]) {tmp=num[i]; num[i]=num[j];num[j]=tmp;}//swap the number
        }
    }

    for (int i=0;i<sz_lst;i++){printf("  %f\n",num[i]);}  
    printf("\n");

return 0;
}


#endif



#if (block==2) // refined

#endif


#if (block==3) // alternative logic


#endif
