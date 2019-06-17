#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "game_loop.h"
#include "characters.h"

/* Variável responsável pela detecção do teclado */
int ch;

/* Coordenadas do jogador, coordenadas dos limites do terminal */
int player_x, player_y, max_x, max_y;

/* Strings responsáveis pelo jogador */
char *player_01 = " __|__ ", *player_02 = "|_____|";

int main(int argc, char ** argv) {
    /* Inicializa a tela */
    initialize();
    
    /* Detecta e regista os limites do terminal */
    getmaxyx(stdscr, max_y, max_x);

    /* Determina a poisção inicial da nave */
    player_x = (max_x/2) - 3;
    player_y = max_y - 3;

    /* Imprime a posição inicial da nave */
    mvprintw(player_y-1, player_x, player_01);
    mvprintw(player_y, player_x, player_02);

    /* Executa até pressionar a tecla Esc */
    execute_until_esc();
    /* Libera a memória e finaliza o programa */
    quit();
    return 0;
}

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

    /* Deixa o cursor invisível */
    curs_set(0);
}

/* Sai da tela */
void quit() {
    delwin(stdscr);
    endwin();
    exit(0);
}
