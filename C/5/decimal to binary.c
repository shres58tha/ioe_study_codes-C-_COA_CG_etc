// program to generate binary equivalent of a decimal no.
#include<stdio.h>
#include <stdlib.h>
//#include<math.h>

#define block 3 // just change value of letter to select corrosponding block while comparing

#if (block==1)
/*
int pw (int digit, int n){
    int ret_val=1;
    //printf ("\n in pw funct digit    %d   n %d", digit, n);
    for (;n;n--) ret_val*=digit; // raise power of the digit n times till n becomes 0

    //printf ("\n ret_val   %d", ret_val);
return (ret_val); // needs to nbe last line in the function.
}*/

 long long int deci_bin( int num){
     long long int  bin_num=0, place=1;
        if(num >524287) {printf("mem overflow max decimal no = 524287 \n"); exit (1);}
        while (num){
        bin_num=bin_num+num%2*place;  // extract least significant bit equivalent and set it on least sinnificant bit in bin_num
        num/=2;  // setnum to extract next least significant bit
        place*=10;
        // printf("%lld\n",bin_num);  // debug line
        }
    return bin_num;
}

int main(){
    int num1;
    long long int  bin_num=0;

	printf(" \n\n Enter a number to convert to binary:");
	scanf("%d",&num1);
	bin_num=deci_bin(num1);
	printf("\n binary equivalent of %d is  %lld \n",num1,bin_num);  // ask how to print more than 512 dec equivalent
	printf ("\n\n");

}
#endif

//*/

#if (block==2) // refined
long long int deci_bin( int num){
     long long int  bin_num=0, place=1;
        if(num >524287) {printf("mem overflow max decimal no = 524287  \n"); exit (1);}
        while (num){
        bin_num = bin_num + num%2*place;  // extract least significant bit equivalent and set it on least sinnificant bit in bin_num
        num/=2;  // setnum to extract next least significant bit
        place*=10;
        // printf("%lld\n",bin_num);  // debug line
        }
    return bin_num;
}

int main(){
    int num1;

	printf(" \n\n Enter a number to convert to binary:");
	scanf("%d",&num1);
	printf("\n binary equivalent of %d is  %lld \n",num1,deci_bin(num1));  // ask how to print more than 512 dec equivalent
	printf ("\n\n");
}
#endif
//*/

#if (block==3) // alternative logic  \
// update nice logic but found error, actually it is converting it to the binary encoded decimal not binary.
void dis_bin_of_digit(int i){
            switch (i) {
            case 0: {printf("0000 ");break;}    
            case 1: {printf("0001 ");break;}
            case 2: {printf("0010 ");break;}
            case 3: {printf("0011 ");break;}
            case 4: {printf("0100 ");break;}
            case 5: {printf("0101 ");break;}
            case 6: {printf("0110 ");break;}
            case 7: {printf("0111 ");break;}
            case 8: {printf("1000 ");break;}
            case 9: {printf("1001 ");break;}
            case 10: {printf("1010 ");break;}
            case 11: {printf("1011 ");break;}
            case 12: {printf("1100 ");break;}
            case 13: {printf("1101 ");break;}
            case 14: {printf("1110 ");break;}
            case 15: {printf("1111 ");break;}
            default: {printf("wrong way to call function; argument passed %i \n ",i);exit (1);}
        }
    }


    
long long int pwr(int base,int n){
    long long int ret_val=1;
    for (int i=1; i<=n; i++){ ret_val*=base; }
    return ret_val;
    } // return power of base to  num

int count_digits(long long int num){
    int num_digit=0;
    while (num){ num=num/10; num_digit++; }
    return num_digit;
    }   // return number of digits in given number


int main(){
long long int num;
int i = 1, num_digit=0, digit;
//long long bin=0;
    printf("\n Enter number please : ");
    scanf("%lld",&num);

    num_digit=count_digits(num); // num_digits becomes no of digits in the number

    if (num>=9223372036854775807)printf("\n max decimal digit entered overflow \n the max allowed is 9223372036854775807 \n" ); // debug line
    printf("\n binary encoed representation of number %lld is : \n", num);
    if (num < 0) {printf("\n - "); num=-num;}  // handles negaive case
    //printf("\n binary representation of number %lld is : \n", num);
    for (i=num_digit-1; i>=0;i--){ // i intialized num_digits -1 so as to extract first digit on followig divison
        digit=num/pwr(16,i);num%=pwr(16,i);  //both divide and mod operation are needed. / extracts first digit and % turncates the first digit
        dis_bin_of_digit(digit);
    }
    printf("\n");
}


#endif
