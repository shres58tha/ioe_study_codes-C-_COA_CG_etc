#include<stdio.h>
#include <stdlib.h>  // for exit();


#define LIMIT 30


int main(){
FILE *ptr;

typedef struct std0{
    char name[LIMIT];
    int roll;
    int age;
    } stdnt;
    stdnt std;

    if ((ptr=fopen("./student.dat","wb+"))==NULL) {
        printf("error opening file");
        exit(1);
    }


    for (int i=0;i<5;i++){  // structure initiliazatioin
    printf("\n enter std name :"); scanf("%[^\n]s",std.name);
    printf("\n enter std roll :"); scanf("%d",&std.roll);
    printf("\n enter std age :"); scanf("%d%*c",&std.age);
       
    fprintf( ptr, "%s\t%d\t%d\n",std.name ,std.roll,std.age);
    }


return 0;
}
