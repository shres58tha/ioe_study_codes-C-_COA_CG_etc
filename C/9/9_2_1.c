// program create a structure array and sort the array based on different basis
#include<stdio.h>
#include<string.h>

#define MAX_LIMIT 50


struct employee{
        char name[MAX_LIMIT];
        char address[MAX_LIMIT];
        long int phone;
    };

void read(struct employee *p){
        printf("\n ->name    :"); scanf("%[^\n]s",p->name);getchar();
        printf("\n ->address :"); scanf("%[^\n]s",p->address);getchar();
        printf("\n ->phone   :"); scanf("%ld%*c",&p->phone);//getchar();
}

void display(struct employee p){
        printf("\n .name    : %s",p.name);
        printf("\n .address : %s",p.address);
        printf("\n .phone   : %ld",p.phone);
        printf("\n");
}
void sort(struct employee p[], int n){
    struct employee temp;
    for (int i=0; i<n; i++){
        for (int j=0; j<n-i-1; j++){
            if(strcmp (p[j+1].name, p[j].name)){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
/******************MAIN*****************************/

int main(){
    int sz;
    struct employee emp[MAX_LIMIT+1];
    printf ("enter size of list . max %d :", MAX_LIMIT);
    scanf("%d%*c",&sz);


    for (int i=0; i<sz;i++){
        printf("\nemployee : %d",i+1);
        read (&emp[i]);
    }
    
    sort( emp, sz ); 
    printf("\n\n\tsorted by employee name \n");
    for (int i=0; i<sz;i++) {
        printf("\nemployee : %d",i+1);
        display(emp[i]) ;
    }
       

return 0;

}
