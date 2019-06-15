#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define ESC_KEY 27
void initialize();
void execute_until_esc();
void quit(WINDOW *win);