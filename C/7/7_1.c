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
        // while (*s!=0){s++;i++;}
        return i;
        } // verified working counts till the null character . string is always terminated by null character

void strcp(const char *s, char *t){
        for(;*s;s++,t++)*t=*s;*t='\0'; // put the terminating character in the target string as it is not copied by for loop
        //while (*s){*t=*s;s++;t++;}  *t='/0';
        }
int strcm(const char *s, char *t){
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
}

void strct(char *t, const char *s){  // concatanates source string to target string
        while (*t){t++;}
        t--; //increment t till end of string. it should contain null char now hence decrement it

        for (;*s;s++,t++){*t=*s;}
        *t='\0'; //copy the char from s to the end of t set null char at end of t
}


#define MAX_LIMIT 50
int main(){
    char str[MAX_LIMIT]; // max list size 50
    char str2[MAX_LIMIT];
    int ln;
    printf("\n enter the string up to %d chracter: ", MAX_LIMIT );
    fgets(str,MAX_LIMIT,stdin);    //fgets(str, MAX_LIMIT, stdin);
    //scanf("%[^\n]s ",str);       /// this works as scanf scans until newline or enter is hit
                                ///gets() is depreciated not recognised any more security reason
                                ///scanf("%s\n",str); or scanf("%s ",str); for removing dangling new line in buffer
    printf("\n the entered string is :%s",str);
    // puts("the entered string is"); puts(str); alternate puts is equivalent to printf("\n"put's argument"\n);

    //printf(" the str lenght is %d",strln(str));
    strcp(str,str2);
    printf("\n org. string str %s and str2 %s",str,str2);
    printf("\n");

return 0;
}


#endif



#if (block==2) // refined

#endif


#if (block==3) // alternative logic


#endif
