#include<stdio.h>
#define MAX_LIMIT 1000

int main(){
FILE *p;
FILE *ptr;
char  ch;
    ptr=fopen("./filec.txt","w+");
    //p=ptr;//perserving the intial position to the file is meaning less as they are linked
    do {
    ch=getc(stdin);
    putc(ch,ptr);

    }while (ch!='\n');
return 0;
}
