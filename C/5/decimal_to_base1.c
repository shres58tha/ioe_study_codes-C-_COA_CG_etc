// program to generate binary equivalent of a decimal no.
#include<stdio.h>
#include <stdlib.h>

void dis_base_of_digit(int digit, int base){ // upto base 16
    if (base<2) {printf(" cannot handle base equal or less than 1 for this subfunction \n"); return ;}
    
    // for base 1 handle it in calling function with following code change num to the variable that is used to extract digits
    
    /* 
    if (base = 1){
        for (int i=1;num >0;num--,i++){
        printf("|");  
        if (i=5) {
        i=0;  //print tally in group of 5
        printf(" ");
            }
        }
    }
    else {
    // extract digits and call this function
    }  // actually really easy to implement this using the wrapper funtion
     
     */
        
    if (base <=16)
        switch (digit) {
            case 0: {printf("0");break;}    
            case 1: {printf("1");break;}
            case 2: {printf("2");break;}
            case 3: {printf("3");break;}
            case 4: {printf("4");break;}
            case 5: {printf("5");break;}
            case 6: {printf("6");break;}
            case 7: {printf("7");break;}
            case 8: {printf("8");break;}
            case 9: {printf("9");break;}
            case 10: {printf("a");break;}
            case 11: {printf("b");break;}
            case 12: {printf("c");break;}
            case 13: {printf("d");break;}
            case 14: {printf("e");break;}
            case 15: {printf("f");break;}
            }
    else 
        printf ("'%d' ",digit);   // for higher than base 16
    }
    
long long int pwr(int base,int n){
    long long int ret_val=1;
    if (n<0) {printf("pwr subfunction cannot handle negative powers"); return -1;} // -1 means error
    for (int i=1; i<=n; i++) {ret_val*=base;}
    return ret_val;
    } // return power of base to  num

long long int count_base_digits(long long int num, int base){  // count digits in base
    if (base<1) {printf(" cannot hande base equal or less than 1\n"); return -1;}  // -1 means error
    if (base=1) {return num;}  // special case
    int num_digit=0;
    while (num){ num=num/base; num_digit++; }
    return num_digit;
    } 
    
int main(){
long long int num;
int base;
int  num_digit=0, digit;
//long long bin=0;
    printf("\n Enter number please : ");
    while ((scanf(" %lld%*[^\n]", &num)) == 0)  // Neither success (1) nor EOF fin  *[^\n] discad all to the end 
    {   // clear what is left, the * means only match and discard:even new line
        scanf("%*[^\n]c%*c"); 
        // input was not a number, ask again:
        printf("\n Enter a number : ");
    }
    
    printf("\n Enter base please : "); // finally a solution for stdin buffer
       
    while ((scanf(" %d%*[^\n]", &base)) == 0)  // Neither success (1) nor EOF fin
    {
        // clear what is left, the * means only match and discard:
        scanf("%*[^\n]c%*c");
        // input was not a number, ask again:
        printf("\n Enter a base number: ");
    }
  
    if (base<0) {printf(" this program cannot handle base less than 1\n"); return -1;}
    
    // check max value this program can handle
    if (num>=9223372036854775807)printf("\n max decimal digit entered overflow \n the max allowed is 9223372036854775807 \n" ); 
    
    printf("\n base %d encoded representation of number %lld is : \n\t",base, num);
    
    if (num < 0) {printf("\n - "); num=-num;}  // handles negaive case
    
    if (base == 1){
        for (int i=1;num >0;num--,i++){
        printf("|");  
        if (i==5) {//print tally in group of 5
        i=0;  
        printf(" ");
            }
        }
        printf ("\n");
    }
    else {
        num_digit=count_base_digits(num,base); // num_digits becomes no of digits in the base number
   
        for (int i=num_digit-1; i>=0;i--){ // i intialized num_digits -1 so as to extract first digit on followig divison
        //both divide and mod operation are needed. extracts first digit and % turncates the first digit
        digit=num/pwr(base,i);
        num%=pwr(base,i);  
        // display base equivalent using pass to function
        dis_base_of_digit(digit,base);
        }
    printf("\n");
    }
    
return 0;
}
