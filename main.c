#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "game_loop.h"
#include "characters.h"

/* Define o player */
struct Tplayer player;

/* Define o alien */
struct Talien alien;

/* Variável responsável pela detecção do teclado */
int ch;

/* Coordenadas dos limites do terminal */
int max_x, max_y;

/* Coordenadas do alien, direç~ao do movimento */
//int alien_x, alien_y, direction;

/* Strings responsáveis pelo jogador */
//char *player_01 = " __|__ ", *player_02 = "|_____|";

/* Strings responsáveis pelos aliens */
//char *alien_01 = "||/=\\||", *alien_02 = " |\\_/| ";

int main(int argc, char ** argv) {
    /* Inicializa a tela */
    initialize();

    /* Detecta e regista os limites do terminal */
    getmaxyx(stdscr, max_y, max_x);

    /* Registra entrada de maneira não bloqueante */
    nodelay(stdscr, 1);

	/* Define o formato do jogador e do tiro */
	player.top_row = "  __|__  ";
	player.bottom_row = " |_____| ";
    player.bullet = "|";
	player.already_fired = 0;

	/* Define o formato do alien e do tiro */
	alien.top_row = "||/=\\||", 
	alien.bottom_row = " |\\_/| ";
    alien.bullet = "|";
	alien.already_fired = 0;   

    /* Determina a posição inicial* da nave */
    player.player_x = (max_x/2) - 3;
    player.player_y = max_y - 3;

    /* Determina a posição inicial do alien e sua direcao */
    alien.alien_x = 10;
    alien.alien_y = 3;
	alien.direction = 1;

    /* Imprime a posição inicial do alien */
    mvprintw(alien.alien_y-1, alien.alien_x, alien.top_row);
    mvprintw(alien.alien_y, alien.alien_x, alien.bottom_row);

    /* Imprime a posição inicial da nave */
    mvprintw(player.player_y-1, player.player_x, player.top_row);
    mvprintw(player.player_y, player.player_x, player.bottom_row);

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
