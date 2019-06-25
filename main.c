#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include "sprites.h"
#include "characters.h"
#include "game_loop.h"

/* Define o player */
struct Tplayer player;

/* Quantidade de inimigos por linha e de linhas de inimigos */
#define enemy_qty 11
#define enemy_line 5

int enemy_matrix[enemy_line][enemy_qty];

/* Variáveis responsáveis pela detecção do teclado */
int ch;

int main(int argc, char **argv) {

    /* Coordenadas dos limites do terminal */
    int max_x, max_y;

    /* Inicializa a tela */
    initialize(&max_x, &max_y);

    /* Registra entrada de maneira não bloqueante */
    nodelay(stdscr, 1);

    /* Define o formado do jogador e do tiro */
    player.top_row = "  __|__  ";
    player.bottom_row = " |_____| ";
    player.bullet = "|";
    player.already_fired = 0;

    /* Determina a poisção inicial da nave */
    player.player_x = (max_x/2) - 3;
    player.player_y = max_y - 3;

    /* Imprime a posição inicial da nave */
    mvprintw(player.player_y-1, player.player_x, player.top_row);
    mvprintw(player.player_y, player.player_x, player.bottom_row);
    refresh();

    /* Definições dos sprites dos inimigos */
    char *enemy_type1 = "***";

    for(int i = 0; i < enemy_line; i++){
        for(int j = 0; j < enemy_qty; j++){

            enemy_matrix[i][j] = 1;

        }

    }

    /* Executa até pressionar a tecla Esc */
    execute_until_esc(&player, max_x, enemy_qty, enemy_line, enemy_type1);

    /* Libera a memória e finaliza o programa */
    quit();
    return 0;
}

/* Inicializa a tela */
void initialize(int *max_x, int *max_y) {
    initscr();

    /* Checando por falhas */
    if(stdscr == NULL) {
        fprintf(stderr, "Ocorreu um erro ao inicializar ncurses\n");
        exit(1);
    }

    /* Detecta e regista os limites do terminal */
    getmaxyx(stdscr, *max_y, *max_x);

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

    for(int i = 0; i < enemy_line; i++){
        for(int j = 0; j < enemy_qty; j++){

            printf("%d ", enemy_matrix[i][j]);

        }
        puts ("");
    }
    
    exit(0);
}

/* Função responsável pelo tiro do jogador */
void print_all(struct Tplayer *player, int first, int line) {
    int at_position;
    // move(player->player_y, 0);
    // move(player->player_y-1, 0);
    int x, y, alien_x, alien_y;
    alien_y = (player->bullet_x - first)/5;
    alien_x = (player->bullet_y - line)/2;
    getyx(stdscr, y, x);
    mvprintw(player->player_y-1, player->player_x, player->top_row);
    mvprintw(player->player_y, player->player_x, player->bottom_row);
    at_position = mvinch(player->bullet_y-1, player->bullet_x);
    if(at_position == '*') {
        // if(alien_x >= 5 ) printf("alien_x e maior que 5\n");
        // if(alien_y >= 11 ) printf("alien_x e maior que 11\n");
        enemy_matrix[alien_x][alien_y] = 0;

    }
    mvprintw(player->bullet_y-1, player->bullet_x, player->bullet);
    //mvdelch(player->bullet_y, player->bullet_x);
    mvprintw(player->bullet_y, player->bullet_x, " ");
    move(y, x);
    // refresh();
    // move(0, 0);
    // wclrtoeol(stdscr);
    // refresh();
    //usleep(30*1000);
}
