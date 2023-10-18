// program to get list of number and sort them using pointers
// warnings are due to few unused variables 6 of them
#include<stdio.h>
#include <stdlib.h>
#include<time.h> // for random number


void swp_num(int *a, int *b){int t; t=*a; *a=*b; *b=t; } //swap values of two numbers using pointer
void srt_bbl(int *num, int ln){
int i,j;
for (i=0;i<ln;i++){
            for (j=i; j<ln; j++){
            if (*(num+i)>*(num+j))swp_num((num+i),(num+j));}
    }
}

void srt_slct(int *num, int ln){
            int i,j, m;
                for (i=0;i<ln-1;i++){ // treat half of the list as sorted and since 1 element is always sorted no need to check it means ist and last element
                    m=i;  // m =location of min value assuming i s the minimum
                    for (j=i+1; j<ln; j++){ //this loop does all the comparing compares all rest element with min
                        if (*(num+m)>*(num+j)) m=j;}
                    if (m!=i)swp_num((num+m),(num+i));
                }
            }

void srt_insrt(int *num, int ln){
            int i,j, tmp;
                for (i=1;i<ln;i++){ // treat half of the list as sorted and since 1 element is always sorted no need to check it means ist and last element
                    tmp=num[i];  // m =location of min value assuming i s the minimum
                    j=i-1;
                    while(tmp<num[j]&&j>=0){num[j+1]=num[j];j--;}
                    num[j+1]=tmp;
                }
            }



#define Sz 5
#define MAX_LIMIT 50
int main(){
time_t t;
srand((unsigned) time(&t));

    int num[MAX_LIMIT];
    int ln=MAX_LIMIT;
    float sum=0,avg;
    int *p;
    int tmp, i,j;



    for( int i = 0 ; i < ln ; i++ )
   {
      num[i] = rand() % 100;
      printf("%4d", num[i]);
   } // array initialized in normal way

    /*p=&num[0]; // putting base address of num arrray in int pointer p
    //sorting  // selection sort
    for ( i=0;i<ln;i++){
            for (j=i; j<ln; j++){
            if (*(p+i)>*(p+j))swp_num((p+i),(p+j));}
    }*/
    srt_insrt(num,ln);
    //srt_slct(num,ln);
    //srt_bbl(num,ln);// ok and running
    printf("\nsorted  selection array\n");
    for( int i = 0 ; i < ln ; i++ ) printf("%5d", num[i]);

return 0;

}


