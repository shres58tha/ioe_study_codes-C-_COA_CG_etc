#include <stdio.h>
float avg_array(int array[], int);
void print_odd_elements (int array[], int num);
void print_even_elements (int array[], int num);
#define size 10

int main(){
    int array[size];
    for (int i=0;i<size;i++){
        printf ("enter  number[%d] :",i);
        scanf("%d",&array[i]);
    }
    printf ("passing array to avg_array(); average is : %f \n",avg_array(array,size) );
    print_odd_elements (array, size);
    print_even_elements (array, size);
return 0;
}
float avg_array (int array[], int num){
    int sum=0;
    for (int i=0;i<num;i++)   sum+=array[i];
    return ((float)sum/num );
}

void print_odd_elements (int array[], int num){
    printf ("Odd elements in array are:");
    for (int i=0;i<num;i++) if (array[i]%2==1) printf ("%d,  ",array[i]);
    printf("\n");
}

void print_even_elements (int array[], int num){
    printf ("Even elements in array are:");
    for (int i=0;i<num;i++) if (array[i]%2==0) printf ("%d,  ",array[i]);
    printf("\n");
}
