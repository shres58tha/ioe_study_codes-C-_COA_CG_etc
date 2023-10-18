// note manuel's question misumderstood so ended up programming circutious code but has a good examples in handling the matrix elements
// program to initialize square matrix and sort each row so that  the min no in each row is in diagonal elements
#include<stdio.h>
#include <stdlib.h>
//#include<math.h>

#define block 1 // just change value of letter to select corrosponding block while comparing

#if (block==1)
void read( float *p, int sz_lst){
    for (int i=0;i<sz_lst;i++){printf("enter a num : ");scanf ("%f", p+i);} //print and scan numbers ///using pointer arthematic
}
void srt_bubble(float *p,int sz_lst){
    float tmp;
    for (int i=0;i<sz_lst;i++){
        for (int j=i+1;j<sz_lst;j++){
            if (*(p+i)>*(p+j)) {tmp=*(p+i); *(p+i)=*(p+j);*(p+j)=tmp;}//swap the number
        }
    }
}
void shift_lst(float *p,int sz_lst, int place){  // takes argument of base address of array, size of array and no of place to shift circularly
    float tmp;
    for (int i=0; i<place;i++){
            tmp=*(p+sz_lst-1); // save the value at highest position in array
            for (int j=(sz_lst-1);j>=0;j--) *(p+j)=*(p+j-1); // shift value from 2nd last to last point in array
            *(p+0)=tmp; //restore the highest position value the lowest position
    }
}
void dsply_lst(float *p,int sz_lst){    // displays list of nimber in array sequentally
    for (int i=0;i<sz_lst;i++){printf("  %f\n",p[i]);}  //using pointer reference // array representation also works
 }

int main(){
    float sq_num[5][5],sum=0,tmp;  // max list size 100
    int n, i, j;
    for (i=0; i<5; i++)
        {
        printf(" \n enter the numbers for row %d the matrix : \n",i+1);
        read (&sq_num[i][0],5);
        }
    for (i=0; i<5; i++)
        srt_bubble(&sq_num[i][0],5);   // sort each row in ascending order

    for (i=0; i<5; i++)
        shift_lst( &sq_num[i][0], 5, i);

    for (i=0; i<5; i++)
        {
        printf("row %d : \n",i+1);
        dsply_lst(&sq_num[i][0],5);    // display each row
        }

    printf("\n");

return 0;
}


#endif



#if (block==2) // refined

#endif


#if (block==3) // alternative logic


#endif
