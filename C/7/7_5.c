// program to get list of number and sort them
#include<stdio.h>
#include <stdlib.h>

#include <string.h> //for gets() but gets is depreciated and no longer supported
//#include<math.h>

#define block 1 // just change value of letter to select corrosponding block while comparing

#if (block==1)

/// string functions

 int strln(const char *s){
        int  i=0; for (i=0; *s; s++,i++);
        // while (*s!=0){s++;i++;}    //alt code
        return i;
        } // verified working counts till the null character . string is always terminated by null character

int str_ch_cnt(const char *s, char ch){ // function for character count
        int  ret_cnt=0; for (; *s; s++)if(*s==ch)ret_cnt++;
        return ret_cnt;
        } // not a good function  for word count

int str_ch_loc(const char *s, char ch){  // returns the location of first occurance of char ch
        int  i=0; for (i=0; *s; s++,i++)if(*s==ch)return i;
        return -1; // not found
        } // not a good function  for word count


int str_ch_all_loc(const char *s, char ch, int *p){  // returns all the position of char ch starting from count 1
        int  i=0,j=0;
        for (;*s;s++,i++)if(*s==ch){*(p+j)=i+1;j++;} // detail see the while block
        return j;
        }
        /*//debuged lines below
        int str_ch_all_loc(const char *s, char ch, int *p){  // returns all the position of char ch starting from count 1
        int  i=0,j=0;

        //printf ("\nrrrrrrrrrrrrrrrrrr %c ",ch);  //debug line
        while (*s){
                //printf("\n %c",*s);
                if(*s==ch){*(p+j)=i+1;
                printf("\t %d  p[%d]=%d",i ,j ,*(p+j));
                j++;
                } // *(p+j)=i+1 to make is possible to detect the first location
                s++;i++;  // check starting from 0
            }

        return j; // no of char found
        }
       */

void strcp(const char *s, char *t){
        for(;*s;s++,t++)*t=*s;*t='\0'; // put the terminating character in the target string as it is not copied by for loop
        //while (*s){*t=*s;s++;t++;}  *t='/0';
        }

int strcm(const char *s,const char *t){// a better one than the below one simplified
        for(;*s||*t;s++,t++) // which ever string is shorter terminates first // this avoids the mem fault
            if (*t==*s) continue; // terminating string containn null char one exp runs out and failswhen this statement fails 
            else return (*s-*t);
}

/*//int strcm(const char *s, char *t){
        int flag;
        for(;*s||*t;s++,t++){ // which ever string is shorter terminates first // this avoids the mem fault
            if (*t==*s);// simply continue the loop do nothing, can put continue too but is unecessary
            else if (*s>*t)
                    return 1; // first argument is greater than the 2nd argument
                 else
                    return -1; // vice-versa
        }
        if (*t==*s) return 0; // check the lenght          //both are identical
        else    if (*s>*t)
                    return 1; // first argument is greater than the 2nd argument
                else
                    return -1; //
}//*/

void strct(char *t, const char *s){  // concatanates source string to target string *t+*s
        while (*t){t++;}
        t--; //increment t till end of string. it should contain null char now hence decrement it

        for (;*s;s++,t++){*t=*s;}
        *t='\0'; //copy the char from s to the end of t set null char at end of t
}

int str_wrd_cnt(const char *s){
        int  ret_cnt=0; for (; *s; s++){if(*s==' ')ret_cnt++; for (;*s==' ';s++);} // second for is to skip consequative white space
        return ret_cnt+1; // no of words equal 1 more than count of white space
        } // not a good function  for word count

/***********************************************************************************/

void read_str(char *p,int sz){
                printf("enter a string of max size %d :",sz);
               // scanf("%[^\n]s ",p);scanf("%c");
                fgets(p,sz,stdin);
}
void sort_str(char **p,int rows){
    char *tmp;
    for (int i=0;i<rows;i++){
        for (int j=i+1;j<rows;j++){
            if ( strcm(*(p+i),*(p+j))>0){
                //printf(" srtcm arg1 %s   arg2 %s --> %d\n",*(p+i-1),*(p+j),strcm(*(p+i-1),*(p+j)));
                tmp=*(p+i);
                //printf("\n tmp %s",tmp);
                *(p+i)=*(p+j);
                //printf(" \n srtcm *(p+i-1) %s   *(p+j) %s --> %d\n",*(p+i-1),*(p+j));
                *(p+j)=tmp;
                } //printf("\n   *(p+j) %s",  *(p+j));
            }// }
    }
}


void display_str(char *p){printf("\n%s",p);}// function to display str

// example usage ln=fnd_sbstr(str,sub,&loc[0]); int *p requires address  // needs fixing

int fnd_sbstr(  char *s,  char *t, int *p){// returns all the position of start of sub str location starting from count 1
        int  i=0,j=0; char *x ,*y;
        int ln=strln(t); printf("\t\t\t\tln %d\n\n",ln);
           for(;*s;s++,i++){
                for(x=s,y=t;*y;y++,x++){
                    if(*y==*x && *(y+1)!='\0') { printf("in != *(y+1)=%c *y:%c    %c:*x ",*(y+1), *y, *x);
                    }
                    else
                        if(*y==*x && *(y+1)=='\0'){ printf("!= *(y+1)=%c *y:%c    %c:*x ", *(y+1), *y, *x); printf(" i=%d   j=%d  \n",i,j);
                    *(p+j)=i+1;

                    printf(" *(p+j)=%c i=%d   j=%d  \n",*(p+j),i,j);
                    j++;
                    }
                     // set starting location in int *p array at p[0]= location value is count place ie index+1
                   // else break;
                }
            }
        return j; // gives no of finds
        }

/*
int str_ch_all_loc(const char *s, char ch, int *p){  // returns all the position of char ch starting from count 1
        int  i=0,j=0;
        for (;*s;s++,i++)if(*s==ch){*(p+j)=i+1;j++;} // detail see the while block
        return j;
        }*/

#define MAX_LIMIT 50
int main(){
    char str[MAX_LIMIT];
    char str2[MAX_LIMIT];
    char sub[MAX_LIMIT];
    int  loc[MAX_LIMIT]={0};// all the values are 0 set so we can distinguish between found location
    int ln=0,n;
    printf("enter the sentence\n");
    read_str(str,MAX_LIMIT);
    printf("enter the substring\n");
    read_str(sub,MAX_LIMIT);


   ln=fnd_sbstr(str,sub,&loc[0]);printf("\nrrrrrrrrrrrrrr%d  loc %d",ln, loc[1]);
    strcp(str,str2); // perserve orginal string
     for (int i=0;i<n;i++ ) {printf ("\n%d",loc[i]);
    for (int i=0;loc[i]!=0;i++ ) {printf ("\n%d",loc[i]);}
        for(int j=0;sub[j]!='\0';j++) {n= loc[i]+j-1; str2[n]='*';}
        }
    display_str(str);
    display_str(str2);
    //printf("\n ");



return 0;
}


#endif



#if (block==2) // refined

#endif


#if (block==3) // alternative logic


#endif
