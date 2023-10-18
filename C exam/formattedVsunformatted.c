+/*
 *formatted iO takes tha format specifiers to dictate how the output is performed.
 * while unformatted iO is simply outputs the value or data that is passed to it with out formatiing and modifying it
 * eg of formatted output is printf() and scanf() family of function where diffrent are formats are specified using % as escape secquence
 *
 *while the example of the unformated io are getch() and  putch() family of fumction are unformatted io
 * 
 * 
 * getch () funtion is declared in header conio.h which is specifically used for the dos or windows os based io
 * 
 * getche() is similar to the operating of getch() except that it echos what is scanned in standard input to the standard output. ie it displays the key been pressed in the key board to the screen
 * 
 * getchar() is a function that is declared in the stdio.h header file and it operates in the simlar way as getch()
 * 
 * all these function take no argument and return the scanned values of key pressed
 *
 * getch() and getche() return the char type, the value retuned is the ascii scan code of the key being pressed

 * while getchar() returns int type value . the value returned is the ascii scan code of the key being pressed
 */

/*
#include <stdio.h>
#include <conio.h>

int main()
{
    char ch;
   printf("Waiting for a character to be pressed from the keyboard.\n");

   ch=getch();  // gets character pressed into ch
   printf("Waiting for a character to be pressed from the keyboard and echos.\n");
    ch=getch();  // gets character pressed into ch and echos it to stdout ie screen
   
   
   
   return 0;
}

*/
#include <stdio.h>

int main()
{
    char ch;
   printf("Waiting for a character to be pressed from the keyboard.\n");

   ch=getchar();  // gets character pressed into ch same as getch();
   printf("Waiting for a character to be pressed from the keyboard and echos.\n");
  
   
   
   return 0;
}
