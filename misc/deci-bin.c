#include<stdio.h>
//#include<conio.h>
/*
int rvrs (int n){ // funtion reverses a number
int temp=0;
while (n>0){temp =temp*10+n%10; n/=10;}
return (temp);
}//*/

//followig switch displays the decimal no in binary format
void dis_bin_of_digit(int i){
            switch (i) {
            case 1: {printf("0001 ");break;}
            case 2: {printf("0010 ");break;}
            case 3: {printf("0011 ");break;}
            case 4: {printf("0100 ");break;}
            case 5: {printf("0101 ");break;}
            case 6: {printf("0110 ");break;}
            case 7: {printf("0111 ");break;}
            case 8: {printf("1000 ");break;}
            case 9: {printf("1001 ");break;}
            case 0: {printf("0000 ");break;}
            default: {printf("wrong way to call function; argument passed %i \n ",i);break;}
        }
    }

void dis_alphanum_of_digit(int i){
            switch (i) {
            case 1: {printf("one ");break;}
            case 2: {printf("two ");break;}
            case 3: {printf("three ");break;}
            case 4: {printf("four ");break;}
            case 5: {printf("five ");break;}
            case 6: {printf("six ");break;}
            case 7: {printf("seven ");break;}
            case 8: {printf("eight ");break;}
            case 9: {printf("nine ");break;}
            case 0: {printf("zero ");break;}
            default: {printf("wrong way to call function; argument passed %i \n ",i);break;}
        }
    }

// power function cause somehow sublime build cant link math.lib in gcc in linux tried solution but lacked time
int pwr(int base,int num){
    int ret_val=1;
    for (int i=1; i<=num; i++){ ret_val*=base; }
    return ret_val;
    } // return power of base to  num

int count_digits(int num){
    int num_digit=0;
    while (num){ num=num/10; num_digit++; }
    return num_digit;
    }   // return number of digits in given number

int main(){
int a=0,num;
int i = 1, num_digit=0, digit;
//long long bin=0;
    printf("\n Enter number please : ");
    scanf("%d",&a);
    num=a;

    num_digit=count_digits(num); // num_digits becomes no of digits in the number

    //printf("num_digit=%d  and num=%d\n",num_digit, num ); // debug line
    printf("\n binary representation of number %d is : \n", num);
    if (num < 0) {printf("\n - "); num=-num;}  // handles negaive case
    for (i=num_digit-1; i>=0;i--){ // i intialized num_digits -1 so as to extract first digit on followig divison
        digit=num/pwr(10,i);num%=pwr(10,i);  //both divide and mod operation are needed. / extracts first digit and % turncates the first digit
        dis_bin_of_digit(digit);
    }
    printf("\n");

    num=a;// reset value of a to entered no

    //printf("num_digit=%d  and num=%d\n",num_digit, num ); // debug line
    printf("\n\n\n alphanumeric representation of number %d is : \n", num);
    if (num < 0) {printf("\n neg. "); num=-num;}
    for (i=num_digit-1; i>=0;i--){ // i intialized num_digits -1 so as to extract first digit on followig divison
        digit=num/pwr(10,i);num%=pwr(10,i);  //both divide and mod operation are needed. / extracts first digit and % turncates the first digit
        dis_alphanum_of_digit(digit);
    }
    printf("\n");

return 0;

}
