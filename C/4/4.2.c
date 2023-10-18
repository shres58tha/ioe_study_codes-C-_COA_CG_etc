//prime no generating prime program  not a good program.
#include <stdio.h>
#include <math.h>


int main() {
    int low, high, i, flag, temp;
    printf("Enter two numbers(intervals): ");
    scanf("%d %d", &low, &high);
    // swap numbers if low is greather than high
    if (low > high) {
        temp = low;
        low = high;
        high = temp;
    }

    if (low<0) {printf("\n only positive should be entered\n");return 1;}
    printf("\n Prime numbers between %d and %d are: ", low, high);

    if (low==1||low==0) low=2; // as one is not considered prime no by defination "prime has exactly two factors one iself and one." /// bla bla
 while (low < high) {  // check the no for divisibilty from all the numbers from 1 to low and set flag if it is divisible
        flag = 0;

        for (i = 2; i <= low / 2; ++i) { //when low is 1 or 2 this loop is never excuted hence flag remains 0 and hence they are printedout as prime no.
              if (low % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("%d ", low);
        ++low;
	//pow(2,2);
    }
    printf("\n");
    return 0;
}
