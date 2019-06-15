#include "main.h"

/* Inicializa a tela */
void initialize() {
    initscr();

    /* Checando por falhas */
    if(stdscr == NULL) {
        fprintf(stderr, "Ocorreu um erro ao inicializar ncurses\n");
        exit(1);
    }

    /* Deixa de mostrar as teclas pressionadas e habilita as setas */
    noecho();
    keypad(stdscr, TRUE);

}

/* Executa até pressionar a tecla Esc */
void execute_until_esc() {
    int ch;
    char keycode[17];
    while ( (ch = getch()) != ESC_KEY ) {
		snprintf(keycode, 16, "%d", ch);
		move(0, 0);
		clrtoeol();

        /* Escreve o código da tecla na tela */
		wprintw(stdscr, keycode);
        refresh();

	}
}

/* Sai da tela */
void quit() {
    delwin(stdscr);
    endwin();
    refresh();
}

int main(int argc, char ** argv) {
    /* Inicializa a tela */
    initialize();
    /* Executa até pressionar a tecla Esc */
    execute_until_esc();
    /* Libera a memória e finaliza o programa */
    quit();
    return 0;
}