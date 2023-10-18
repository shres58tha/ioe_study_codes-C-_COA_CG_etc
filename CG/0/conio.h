// Minimal conio.h for old BGI programs
// For a real implementation, have a look at
// https://github.com/nowres/conio-for-linux
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>


void clrscr (void);
void gotoxy (int, int);
int getch(void);
int getche(void);
void clrscr(void);
void gotoxy(int x, int y);



// gotoxy() function definition

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}


// clrscr() function definition
void clrscr(void)
{
    system("clear");
}


// -----
/* reads from keypress, doesn't echo */


int getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

/* reads from keypress, echoes */
int getche(void)
{
    char ch;
/*    struct termios oldattr, newattr;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );*/
    ch = getchar();
 //   tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}


// ----- end of file conio.h


/*

static struct termios old, new;

// Initialize new terminal i/o settings 
void initTermios(int echo)
{
    tcgetattr(0, &old); //grab old terminal i/o settings
    new = old; //make new settings same as old settings
    new.c_lflag &= ~ICANON; //disable buffered i/o
    new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
    tcsetattr(0, TCSANOW, &new); //apply terminal io settings
}

// Restore old terminal i/o settings 
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

// Read 1 character - echo defines echo mode 
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

//Read 1 character without echo getch() function definition.
char getch(void)
{
    return getch_(0);
}

//Read 1 character with echo getche() function definition.
char getche(void)
{
    return getch_(1);
}
*/

