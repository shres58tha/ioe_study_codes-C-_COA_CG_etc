// program to get list of number and sort them and display using functions1
#include<stdio.h>
#include <stdlib.h>
//#include<math.h>

#define block 1 // just change value of letter to select corrosponding block while comparing

#if (block==1)
void read( int *p, int sz_lst){
    for (int i=0;i<sz_lst;i++){printf("enter a num : ");scanf ("%d", p+i);} //print and scan numbers ///using pointer arthematic
}
void sort(int *p,int sz_lst){
    int tmp;
    for (int i=0;i<sz_lst;i++){
        for (int j=i+1;j<sz_lst;j++){
            if (*(p+i)>*(p+j)) {tmp=*(p+i); *(p+i)=*(p+j);*(p+j)=tmp;}//swap the number
        }
    }
}
void display(int *p,int sz_lst){    // displays list of nimber in array sequentally
    for (int i=0;i<sz_lst;i++){printf("  %d\n",p[i]);}  //using pointer reference // array representation also works
 }

int main(){
    int num[100],sum=0,tmp;  // max list size 100
    int n, i, j;
    printf(" \nenter the list size of numbers :");
    scanf("%d",&n);
    if (n>100){printf("\n max size of list 100: \n exiting"); exit (1);}

    read (&num[0],n); // reads number in the list inting type list
    //sort (&num[0],n);  // it is a lib function
    sort(&num[0],n); // sorts number in list

    printf("\nsorted list\n");

    display(&num[0],n);  //displays number in the list inting type

    printf("\n");

return 0;
}


#endif



#if (block==2) // refined

#endif


#if (block==3) // alternative logic


#endif
