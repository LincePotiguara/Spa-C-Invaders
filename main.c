#include "main.h"

void quit(WINDOW *win) {
    delwin(win);
    endwin();
    refresh();
    
}

int main( int argc, char ** argv ) {
    int ch;
    char keycode[17];
    initscr();

    /* Checando por falhas */
    if(stdscr == NULL) {
        fprintf(stderr, "Ocorreu um erro ao inicializar ncurses\n");
        exit(1);
    }

    /* Deixa de mostrar as teclas pressionadas e habilita as setas */
    noecho();
    keypad(stdscr, TRUE);

    /* Executa até pressionar a tecla Esc */
    while ( (ch = getch()) != ESC_KEY ) {
		snprintf(keycode, 16, "%d", ch);
		move(0, 0);
		clrtoeol();

        /* Escreve o códido da tecla na tela */
		wprintw(stdscr, keycode);
        refresh();

	}
    /* Libera a memória e finaliza o programa */
    quit(stdscr);
    return 0;
}