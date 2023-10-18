//program to check the  entered number is palindrome or not
#include <stdio.h>
int main() {
    int n, reversedN = 0, remainder, originalN; //ireveredN is the sum accumulator so need to be set 0
    printf("Enter an integer: ");
    scanf("%d", &n);
    originalN = n;
    // reversed integer is stored in reversedN
    while (n != 0) {
        remainder = n % 10;   // extract the digits from number
        n /= 10; // after extracting the digits reduce val by 10 tfor preperation for extract of next digit
        reversedN = reversedN * 10 + remainder; // append digit after multiplying by 10

    }
    // palindrome if orignalN and reversedN are equal
    if (originalN == reversedN)
        printf("%d is a palindrome.", originalN);
    else
        printf("%d is not a palindrome.", originalN);
    return 0;
}
