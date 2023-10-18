// program create a structure array and sort the array based on different basis
#include<stdio.h>

typedef struct cmplx{
     float real;
     float img;
    }complex;
complex cmplx_add(complex p, complex t){   // pass by val
     complex num;
     num.real=p.real + t.real;
     num.img=p.img + t.img;
     return  num;
    }

complex cmplx_sub(complex *p, complex *t){ // pass by ref
     complex num;
     num.real=(*p).real - t->real;
     num.img=p->img - t->img;
     return  num;
    }

void scan_cmplx(complex *p){
       printf(" Enter a real part :");scanf("%f",&((*p).real));   // type casting with a pointer is a hell
       printf(" Enter a img part :");scanf("%f",&p->img);      // here scanf is asking for the adress to put the float
     }

void print_cmplx(complex p){
       printf(" %f %+f i\n",p.real,p.img);
     }

int main(){
    complex num1, num2, sum,diff;
    printf("\n enter num1 \n"); scan_cmplx(&num1); 
    printf("\n enter num2 \n"); scan_cmplx(&num2);
    sum=cmplx_add(num1,num2);   // pass by val
    diff=cmplx_sub(&num1,&num2);//pass by ref
    printf("\n sum : "); print_cmplx(sum);  printf("\n");
    printf("\n diff: "); print_cmplx(diff); printf("\n\n");
return 0;
}
