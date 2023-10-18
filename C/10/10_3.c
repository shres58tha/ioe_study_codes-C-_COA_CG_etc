#include<stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX_LIMIT 100
#define LIMIT 30
#define NU_LT 100

typedef struct std0{
    char name[LIMIT];
    int roll;
    char address[LIMIT];
    int marks_obt;
    } stdnt;
    
void *randstring(char*p, int length) {
    char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";//key select string
    //size_t stringLen = strlen(chars);   // size_t is alias fot int type thsat is guarenteed to hold the size of longest data structure possible...
    int ln =sizeof chars -1;
    //srand(time(NULL)); // initialization here caused trouble as the seed remains same in due time of this code exceution
    ///proof why this is called pseudo random no generator

    if (length < 1) length = 1; // minimum size of the string generate is 1

    for (int n = 0, key;n < length;n++) { key = rand() % ln; p[n] = chars[key];} // select key and get corrosponding letter from string
    p[length] = '\0'; //set null character at he end of the generated random string
}

int comparator(const void* p, const void* q){
	return strcmp(((stdnt*)p)->name,  //standard lib function for use in qsort  //type casting
				((stdnt*)q)->name);
}


int main(){
FILE *p;
FILE *ptr;
char buffer[LIMIT+1], ch;  //buffer use is needed while using fprintf and fscanf


    stdnt student[NU_LT ], *s[NU_LT ];

    srand(time(0));

    for (int i=0;i<NU_LT ;i++){
    randstring(student[i].name, 5); // get random name
    student[i].roll=i;
    randstring(student[i].address,7); //get random address
    student[i].marks_obt=rand()%100;

    }
    ptr=fopen("./student.dat","wb+");
    p=ptr;//perserving the intial positionA to the file
    //
    /*
     for (int i=0;i<NU_LT;i++){
     printf(" \n student[%d] %s %d %d ",i,student[i].name ,student[i].roll,student[i].marks_obt);
     fprintf( p, " \n student[%d] %s %d %d ",i,student[i].name ,student[i].roll,student[i].marks_obt); //written in individual data

    }
    fprintf(p,"\n");
    printf("\n");
    //*/
    
    
    //printf("sizeof stdnt= %ld    %ld \n",sizeof (stdnt),sizeof (student));
    fwrite(student, sizeof (stdnt), NU_LT,p );
    
    //////////////////////
    //fclose(ptr);
    //ptr=fopen("./student.dat","rb+");
    //p=ptr; //FILE * pointer duplication is meaningless. as when one is changed other is seem to be efffected. looks like only one file handle is active at any time.
    
    //rewind (p);
    
    if (fseek(p,0,SEEK_SET)!=0) printf("error setting pointer to intial");
    stdnt student_temp[NU_LT];
    
    /* destroy data in student
    for (int i=0;i<NU_LT ;i++){
    strcpy(student[i].name, "0"); // get random name
    student[i].roll=0;
    strcpy(student[i].address,"0"); //get random address
    student[i].marks_obt=0;

    }
    */

    if (fread(student_temp, sizeof (stdnt),NU_LT,  p)==0)
        printf ("error reading \n");
    
    qsort( student_temp, NU_LT,sizeof(stdnt),comparator  ) ; //qsort (arr, n, sizeof(struct Student), comparator); in stdlib.h

    for (int i=0;i<NU_LT ;i++){
    printf("\n%s    %d  %s  %d",student_temp[i].name,student_temp[i].roll,student_temp[i].address,student_temp[i].marks_obt);

    }
    printf("\n\n");
    
return 0;
}
