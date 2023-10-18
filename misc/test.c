#include <stdio.h>


struct person {
     char name[100];
     char address [100];
     float salary;
};

void increase_sal(struct person list[]);

int main(){
   struct person list[5];
   
   for (int i=0;i<5;i++){
       printf ("\nenter name of person %d :", i+1);
       scanf("%[^\n]s",list[i].name);
       getchar();
       printf ("enter name of address :");
       scanf("%[^\n]s",list[i].address);
       getchar();
       printf ("enter salary :");
       scanf("%f",&list[i].salary);
       getchar();       
}

    increase_sal(list);
    for (int i=0;i<5;i++){
       printf ("\n name:  %s",list[i].name);
       printf ("\n address: %s",list[i].address);
       printf ("\n salary: %f",list[i].salary);
       printf ("\n");
    }
    return 0;
}
void increase_sal(struct person list[]){
    for (int i=0;i<5;i++){
        list[i].salary=list[i].salary*1.15;
    }
    return;
}
