#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>                  /*  for sleep()  */
#include <curses.h>


int main(void) {

    WINDOW * mainwin = initscr();

    
    /*  Initialize ncurses  */

    if ( mainwin == NULL ) {
	fprintf(stderr, "Error initialising ncurses.\n");
	exit(EXIT_FAILURE);
    }


    /*  Display "Hello, world!" in the centre of the
	screen, call refresh() to show our changes, and
	sleep() for a few seconds to get the full screen effect  */

    addstr("Welcome");
    refresh();
    sleep(3);
    mvaddstr(1, 5, "x");
    mvaddstr(1, 2, "x");
    mvaddstr(2, 4, "x");
    mvaddstr(3, 1, "x");
    refresh();
    sleep(3);
    clear();
    mvaddstr(1, 6, "x");
    mvaddstr(1, 3, "x");
    mvaddstr(2, 5, "x");
    mvaddstr(3, 2, "x");
    refresh();
    sleep(3);


    /*  Clean up after ourselves  */

    delwin(mainwin);
    endwin();
    refresh();

    return EXIT_SUCCESS;
}

