#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "sprites.h"

#define ESC_KEY 27
#define DOWN_ARROW_KEY 258
#define UP_ARROW_KEY 259
#define LEFT_ARROW_KEY 260
#define RIGHT_ARROW_KEY 261
#define PLAYER_01_SIZE 5
#define PLAYER_02_SIZE 7

/* Variável responsável pela detecção do teclado */
int ch;
/* Coordenadas do jogador, coordenadas dos limites do terminal */
int player_x, player_y, max_x, max_y;
/* Strings responsáveis pelo jogador */
char player_01[10] = "__|__", player_02[10]= "|_____|";

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

/* Função responsável pelo controle do jogador */
void player_control(){

    /* Detecta a tecla pressionada no teclado */
    ch = getch();
    switch(ch){

        /* Se for ESC, sai do jogo */
        case ESC_KEY:
            quit();
            break;

        /* Se for a setinha esquerda, anda com o conjunto pra esquerda */
        case LEFT_ARROW_KEY:
            if (player_x > 0){
                move(player_y, 0);
                wclrtoeol(stdscr);
                move(player_y-1, 0);
                wclrtoeol(stdscr);
                player_x--;
            }
            break;

        /* Se for a setinha direita, anda com o conjunto pra direita */
        case RIGHT_ARROW_KEY:
            if (player_x < max_x - PLAYER_02_SIZE){
                move(player_y, 0);
                wclrtoeol(stdscr);
                move(player_y-1, 0);
                wclrtoeol(stdscr);
                player_x++;
            }
            break;
        }
        refresh();
        mvprintw(player_y-1, player_x+1, player_01);
        mvprintw(player_y, player_x, player_02);
}

/* Executa até pressionar a tecla Esc */
void execute_until_esc() {

        /* Detecta e regista os limites do terminal */
    getmaxyx(stdscr, max_y, max_x);

    /* Determina a poisção inicial da nave */
    player_x = (max_x/2) - 3;
    player_y = max_y - 3;

    /* Imprime a posição inicial da nave */
    mvprintw(player_y-1, player_x+1, player_01);
    mvprintw(player_y, player_x, player_02);

    /* Quantidade de inimigos por linha e de linhas de inimigos*/
    int enemy_qty = 11;
    int enemy_line = 5;

    /*Imprime a posição inicial da wave de inimigos*/
    print_wave(1, 1, enemy_qty, enemy_line, enemy_type1);

    /*Move a wave de inimigos até 2 linhas antes do jogador*/
    int line;
    for(line = 1; line < player_y-enemy_line-6; line++){

      move_wave(line, enemy_qty, enemy_line, max_x, 0.25*100000, enemy_type1);

    }

    while (1) {
        /* Função responsável pelo controle do jogador */
        player_control();

	}
}
