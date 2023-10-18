 #include <stdio.h>
 #include <curses.h>

int main() {
    initscr();
    addstr("hit a key:");
    getch();
    return endwin();
}
//*/
