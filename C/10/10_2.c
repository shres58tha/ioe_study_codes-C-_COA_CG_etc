#include<stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX_LIMIT 1000
#define LIMIT 30


char *randstring(int length) {
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    size_t stringLen = strlen(string);   // size_t is alias for int type thsat is guarenteed to hold the size of longest data structure possible...
    char *randomString = NULL;

    //srand(time(NULL)); proof that the comuter uses pseudo random no generator

    if (length < 1) {
        length = 1;
    }

    randomString = (char*)malloc(sizeof(char) * (length +1));

    if (randomString) {
        short key = 0;

        for (int n = 0;n < length;n++) {
            key = rand() % stringLen;
            randomString[n] = string[key];
        }

        randomString[length] = '\0';

        return randomString;
    }
    else {
        printf("No memory");
        exit(1);
    }
}


int main(){
FILE *p;
FILE *ptr;
char buffer[MAX_LIMIT], ch;  //buffer use is needed while using fprintf and fscanf

typedef struct std0{
    char *name;
    int roll;
    char *address;
    int marks_obt;
    } stdnt;
    stdnt student[LIMIT], *s[LIMIT];

    srand(time(0)); rand()%100;
    if ((ptr=fopen("./student.dat","wb+"))==NULL) {
        printf("error opening file");
        exit(1);
    }

    p=ptr;//perserving the intial positionA to the file

    for (int i=0;i<LIMIT;i++){  // structure initiliazatioin
    student[i].name=randstring(5);
    student[i].roll=i;
    student[i].address=randstring(7);
    student[i].marks_obt=rand()%100;
    printf("\n student[%d] %s %d %s ",i,student[i].name ,student[i].roll,student[i].address);
    fprintf( p, "\n student[%d] %s %d %s ",i,student[i].name ,student[i].roll,student[i].address);
    }
    printf("\n");fprintf(p,"\n");
    

return 0;
}
