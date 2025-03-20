#include <ncurses.h>

int main() {
        initscr();
        keypad(stdscr, TRUE);
        noecho();

        printw("Press any key to check its keycode (Press 'q'(Keycode: 113) to exit)\n");

        int ch = getch();
        while (ch != 'q') {
                clear();
                printw("Keycode: %d\n", ch);
                refresh();
                
                ch = getch();
        }

        endwin();
        
        return 0;
}
