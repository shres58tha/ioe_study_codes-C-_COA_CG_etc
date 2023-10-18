// program create a structure
#include<stdio.h>

#define Sz 5
#define MAX_LIMIT 50
int main(){

    struct company{
        char name[MAX_LIMIT];
        char address[MAX_LIMIT];
        long int phone;
        int num_employee;
    };

    struct company cm1 ;//= {"hello", "where is this",98541238 ,125}; // declaration of cm1 with struct of company
        printf("enter the data for company cm1");
        printf("cm1.name :");  
        scanf("%[^\n]s",cm1.name); 
        getchar();
        printf("cm1.address :"); 
        scanf("%[^\n]s",cm1.address); 
        getchar();
        //scanf("%*[^\n]%*c", &x):


        printf("cm1.phone :"); scanf("%ld",&cm1.phone);
        printf("cm1.num_employee :"); scanf("%d",&cm1.num_employee);

       //output the value in structure cm1
        printf("the data for company cm1");
        printf("\n cm1.name : %s",cm1.name);
        printf("\n cm1.address :%s",cm1.address);
        printf("\n cm1.phone : %ld",cm1.phone);
        printf("\n cm1.num_employee : %d",cm1.num_employee);
printf("\n");
return 0;

}
