#include <stdio.h>
#include <string.h>
void reverse(){
    char s[100];
    char ch='y';
    printf("Enter a string to reverse\n");
    gets(s);
    strrev(s);
    printf("Reverse of the string: %s\n", s);
}

void calc(){
    char operator;
    float num1, num2, result;
    /* Input a number operator and second number from user */
    printf("Enter firrst number operaor second number[ENTER]:");
    printf("\nExample:  10+20[Enter]: ");
    scanf("%f%c%f", &num1,&operator,&num2);
     
	if( operator=='+')
	  {
	   result= num1+num2;
	   printf("Addition=%.2f",result);
       }
	else if (operator =='-') 
	   {
	   result = num1- num2;
	   printf("Subtraction=%.2f",result);
       }
	else if (operator =='*') 
	   {
	   result = num1 * num2;
	   printf("Multiplication=%.2f",result);
       }
	else if (operator =='/') 
	   {
	   result = num1 / num2;
	   printf("Division=%.2f",result);
       }
	 else
	   printf("Invalid operator please input +, -, *, / ") ;
	 return 0;
}

void matrix_max_element{
  int m, n, c, d, matrix[100][100], maximum;

  printf("Enter the number of rows and columns of matrix\n");
  scanf("%d%d",&m,&n);

  printf("Enter the elements of the matrix\n");

  for (c = 0; c < m; c++)
    for(d = 0; d < n; d++)
      scanf("%d", &matrix[c][d]);

  maximum = matrix[0][0];

  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      if (matrix[c][d] > maximum)
        maximum = matrix[c][d];

  printf("Maximum element in the matrix is %d\n", maximum);
}
int main(){
    int choice;
    char ch;
    do{
            printf("1. for reversing string\n");
            printf("2. for simple calculator\n");
            printf("3. for max element of 4*4 matrix \n");
            scanf ("%d", &ch);
            switch (){
                case 1:
                    reverse ();
                case 2:
                    calc();
                case 3:
                    matrix_max_element();
                    
            }
            printf(" press y to continue \n press any to exit :")
            scanf ("%d", &ch);
    while((ch =="y"| ch=="Y"))
    return 0;
    }
