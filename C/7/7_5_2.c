
// i wanted to get all the location of the start of substring in the  array of pointers not just first instance
// realized that it should be possible just doing with the pointers increament till end of sub string and then decrementing the pointer to the initial letter
// of sub string ie just run the code in reverse .yesterday but had not got time to implement it

#include <stdio.h>
#include <string.h>


void read_str(char *p,int sz){
                printf("enter a string of max size %d :",sz);
               // scanf("%[^\n]s ",p);scanf("%*c");// 2nd printf scans the dangling \n and discards it
                fgets(p,sz,stdin);
}
void display_str(char *p){printf("\n%s",p);}// function to display str

int strln(const char *s){
        int  i=0; for (i=0; *s; s++,i++);
        // while (*s!=0){s++;i++;}    //alt code
        return i;
        } // verified working counts till the null character . string is always terminated by null character


#define MAX_LIMIT 50
int main(){
    char str[MAX_LIMIT]={'\0'};
    char sub[MAX_LIMIT]={'\0'};

  char *p1, *p2, *p3;
  int i=0,j=0,flag=0,ln;

   
    printf("enter the sentence\n");
    read_str(str,MAX_LIMIT);
    printf("enter the substring\n");
    read_str(sub,MAX_LIMIT);
  
    
  p1 = str;
  ln=strlen(str);
  int ln_sub=strlen(sub);
 
  for(i = 0; i<ln; i++)
  {
    if(*p1 == *p2)
      {
          p3 = p1;
          for(j = 0;j<ln_sub;j++)
          {
            if(*p3 == *p2)
            {
              p3++;p2++;
            }
            else
              break;
          } 
          p2 = sub;
          if(j == strlen(sub))
          {
             flag = 1;
            printf("\nSubstring found at index : %d\n",i);
          }
      }
    p1++;
  }
  if(flag==0)
  {
       printf("Substring NOT found");
  }
return (0);
}
