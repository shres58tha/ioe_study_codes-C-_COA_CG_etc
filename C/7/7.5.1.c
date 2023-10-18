// program to get list of number and sort them
#include<stdio.h>
#include <stdlib.h>

#include <string.h> //for gets()
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
        return j;// total no of characters found

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
            if (*t==*s) return 0;
            else return (*s-*t);
}

void strct(char *t, const char *s){  // concatanates source string to target string *t+*s
        while (*t){t++;}
        t--; //increment t till end of string. it should contain null char now hence decrement it

        for (;*s;s++,t++){*t=*s;}
        *t='\0'; //copy the char from s to the end of t set null char at end of t
}

int str_wrd_cnt(const char *s){
        int  ret_cnt=0; for (; *s; s++){if(*s==' ')ret_cnt++; for (;*s==' ';s++);} // second for is to skip consequative white space
//alt   int  ret_cnt=0; while(*s){if(*s==' '&& *(s+1)!= ' ')ret_cnt++;s++;} // count words only if whitspace is followed by non whitespace

        return ret_cnt+1; // no of words equal 1 more than count of white space
        }

void str_rev(const char *s, char *t){
        int ln,i;
        ln=strln(s);printf("\nln %d\n",ln);
        for (i=0;i<=ln-1;i++){t[i]=s[ln-1-(i)];//remove null at end of string  i+1 because index starts from 0
        //printf("aaaa%c",t[i]);
        }
        t[i]='\0'; //restore null
        } //veerified
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

// example usage ln=fnd_sbstr(str,sub,&loc[0]); int *p requires address
int fnd_sbstr( char *s,  char *t, int *p){// returns all the position of start of sub str location starting from count 1
                                            /// Sir this function is giving some unseolved troubles
        int i=1,j=0,k=0,flag=0,ln_str,ln_sub;
        char *x,*y;
        ln_str=strln(s);
        ln_sub=strln(t);
        printf("x %d\n",ln_sub);
        y=s; // pointer y made equal to pointer s
        for (i=0;i<ln_str;i++){
            x=t;
            //printf("x %c", *x);
            for (j=0;j<ln_sub;j++){
                if (*y==*x) {x++;y++;i++;}   //y and s and i are linked
                else break;
            }
            if(j==ln_sub) {p[k]=i;k++;}
            p[i]=k;
            i++;k=k+j;
            }

        return k; // gives no of finds
        }

#define MAX_LIMIT 50
int main(){
    char str[MAX_LIMIT];
    char str2[MAX_LIMIT];
    char rev_st[MAX_LIMIT];
    char sub[MAX_LIMIT];
    int  loc[MAX_LIMIT]={0};// all the values are 0 set so we can distinguish between found location
    int ln=0,n;
    printf("enter the sentence\n");
    read_str(str,MAX_LIMIT);
    printf("enter the substring\n");
    read_str(sub,MAX_LIMIT);



    str_rev (str,rev_st);
    printf("reversed str");
    display_str(rev_st);

    ln=fnd_sbstr(str,sub,&loc[0]);
    printf("\n location of substring %d  loc %d",ln, loc[1]);
    strcp(str,str2); // perserve orginal string
     for (int i=0;i<ln;i++ ) printf ("\n%d",loc[i]);
     printf("\n-----------------------");
     for (int i=0;loc[i]!=0;i++ ) {printf ("\n%d",loc[i]);
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
