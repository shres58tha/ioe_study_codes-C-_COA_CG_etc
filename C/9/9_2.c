// program create a structure array and sort the array based on different basis
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define Sz 5
#define MAX_LIMIT 50


struct employee{
        char name[MAX_LIMIT];
        char address[MAX_LIMIT];
        long int phone;
    };


// setting up rules for comparison
// to sort the employee based on names
int comparator(const void* p, const void* q)
{
	return strcmp(((struct employee*)p)->address,  //standard lib function for use in qsort  //type casting
				((struct employee*)q)->address);
}


void read_employee(struct employee *p){
        printf("\n\t enter the data for emplyoee");
        printf("\n ->.name    :"); scanf("%s",p->name);
        printf("\n ->.address :"); scanf("%s",p->address); //scanf("%*d ");
        printf("\n ->.phone   :"); scanf("%ld",&p->phone);
}

void print_employee(struct employee *p){
        printf("\n\t the data for emplyoee");
        printf("\n ->.name    : %s",p->name);
        printf("\n ->.address : %s",p->address);
        printf("\n ->.phone   : %ld",p->phone);
        printf("\n");
}
/******************MAIN*****************************/

int main(){

    struct employee emp[5] = {\
        {"abcdef", "yxwvu",3456789},\
        {"bcdef", "xwvu",456789},\
        {"cedf", "wvu",56789},\
        {"def", "vu",6789},\
        {"ef", "u",789},\
        };


         // declaration of emp with struct of company

        //for (int i=0; i<5;i++)read_employee(&emp[i]);

        struct employee *p[5], *tmp;
        p[0]=&emp[0];
        char *temp[5];
        qsort( emp, 5,sizeof(struct employee),comparator  ) ; //qsort (arr, n, sizeof(struct Student), comparator); in stdlib.h
        for (int i=0; i<5;i++) print_employee(&emp[i]) ;

return 0;

}
