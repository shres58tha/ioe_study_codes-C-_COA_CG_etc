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
        return j;
        }  // no of char found
        /*
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

void strcp(const char *t, char *s){ // copies string from (target to source)
        for(;*s;s++,t++)*t=*s;*t='\0'; // put the terminating character in the target string as it is not copied by for loop
        //while (*s){*t=*s;s++;t++;}  *t='/0';
        }

int strcm(const char *s1,const char *s2){// a better one than the below one simplified
        for(;*s1||*s2;s1++,s2++) // which ever string is shorter terminates first // this avoids the mem fault
            if (*s2==*s1) return 0;
            else return (*s1-*s2);
}

/*//int strcm(const char *s, char *s2){
        int flag;
        for(;*s||*s2;s++,s2++){ // which ever string is shorter terminates first // this avoids the mem fault
            if (*s2==*s);// simply continue the loop do nothing, can put continue too but is unecessary
            else if (*s>*s2)
                    return 1; // first argument is greater than the 2nd argument
                 else
                    return -1; // vice-versa
        }
        if (*s2==*s) return 0; // check the lenght          //both are identical
        else    if (*s>*s2)
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
                printf("enter a string of max size %d ",sz);
               // scanf("%[^\n]s ",p);scanf("%c");
                fgets(p,sz,stdin);
}


void display_str(char *p){printf("\%s",p);}

/*******************************************************************************************/

void swp_char(char *a, char *b){
char t;
t=*a;
*a=*b; //putchar(*a);
*b=t; //putchar(*b);
} //swap values of two numbers using pointer
void rev_str(char*p){  // simple function but gave headache
int ln;
char tmp;
ln=strln(p);
///for (int i=0,j=ln-1;i!=j;i++,j--){  // the condition testing != fails for add numbered string logical erro
///for (int i=0,j=ln-1;i<ln;i++,j--){   // reverses the string twice it we get original string back once loop is done
for (int i=0,j=ln-1;i<j;i++,j--){//swp_char((p+i),&p[j]); //last index+1 has NULL
    tmp=p[i];
    //printf("\ntmp_%c",p[i]);
    p[i]=p[j]; p[j]=tmp; // swap letters of array last index+1 has NULL hence ln=index of last char -2
    //printf("\np[%d]_%c ,, p[%d]_%c",i,p[i],j,p[j]);
    }
    //printf("in rev %s",p);

}

/*********************************************************************************************/
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

/**************************************************************************/
/// sorting algotrithms

void swp_num(int *a, int *b){int t; t=*a; *a=*b; *b=t; } //swap values of two numbers using pointer

void srt_bbl(int *num, int ln){ // bubble sort
int i,j;
for (i=0;i<ln;i++){
            for (j=i; j<ln; j++){
            if (*(num+i)>*(num+j))swp_num((num+i),(num+j));}
    }
}

void srt_slct(int *num, int ln){ // selection sort
            int i,j, m;
                for (i=0;i<ln-1;i++){ // treat half of the list as sorted and since 1 element is always sorted no need to check it means ist and last element
                    m=i;  // m =location of min value assuming i s the minimum
                    for (j=i+1; j<ln; j++){ //this loop does all the comparing compares all rest element with min
                        if (*(num+m)>*(num+j)) m=j;}
                    if (m!=i)swp_num((num+m),(num+i));
                }
            }

void srt_insrt(int *num, int ln){
            int i,j, tmp;
                for (i=1;i<ln;i++){ // treat half of the list as sorted and since 1 element is always sorted no need to check it means ist and last element
                    tmp=num[i];  // m =location of min value assuming i s the minimum
                    j=i-1;
                    while(tmp<num[j]&&j>=0){num[j+1]=num[j];j--;}
                    num[j+1]=tmp;
                }
            }




/*******************************************************************************************/


#define Sz 5
#define MAX_LIMIT 50
int main(){
    char str[MAX_LIMIT]; // max list size 50
    char str2[MAX_LIMIT];
    int p[MAX_LIMIT]={0};
    int ln;
    char str1[Sz][MAX_LIMIT];
    char *s_array[Sz];
    //int p[MAX_LIMIT]={0};

    for (int i=0;i<Sz;i++) s_array[i]=&str1[i][0];

    for(int i=0;i<Sz;i++) read_str(str1[i],MAX_LIMIT);
    printf("\n original array \n");
    for(int i=0;i<Sz;i++) display_str(str1[i]);
    printf("\n ");
    for(int i=0;i<Sz;i++) display_str(s_array[i]);
    sort_str(&s_array[0],Sz);

    printf("\n sorted array \n");
    for(int i=0;i<Sz;i++) display_str(s_array[i]);


    printf("\n enter the string up to %d chracter: ", MAX_LIMIT );
    fgets(str,MAX_LIMIT,stdin);    //fgets(str, MAX_LIMIT, stdin);
                                ///gets() is depreciated not recognised any more security reason
                                ///scanf("%s\n",str); or scanf("%s ",str); for removing dangling new line in buffer
    printf("\n the entered string is :%s",str);
    strcp(str,str2);
    printf("\n org. string : %s & copy string is :%s", str, str2 );

    printf("\n");

    printf("\n enter the string2 up to %d chracter: ", MAX_LIMIT );
    //fgets(str,MAX_LIMIT,stdin);    //fgets(str, MAX_LIMIT, stdin);
    scanf("%[^\n]s ",str2);       /// this works as scanf scans until newline or enter is hit
                                ///gets() is depreciated not recognised any more security reason
                                ///scanf("%s\n",str); or scanf("%s ",str); for removing dangling new line in buffer
    printf("\n lenght of str %s is: %d:",str,strln(str));

    printf("\n the location of \"%c\" of words in the string %s is: %d",' ',str,str_ch_loc(str,' ')); // no of words equall to no of single space +1
    printf("\n the no of words in the string %s is: %d",str,str_wrd_cnt(str)); // no of words equall to no of single space +1

    printf("\n the location of \"%c\" of in the string %s is: \n",'1',str);
    str_ch_all_loc(str,'1',&p[0]);
    for(int i=0; p[i]>0; i++){printf("  %d  ",p[i]);} // prints all the loacation index [0]== 1


    printf("\n");
    printf ("demonstarting reverse string function"); //reverse string
    printf("\noriginal string");
    display_str(str);
    rev_str(str);
    printf("\nreversed string");
    display_str(str);

    printf("\n");



return 0;

}


#endif



#if (block==2) // refined

#endif


#if (block==3) // alternative logic


#endif
