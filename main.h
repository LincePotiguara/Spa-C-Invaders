#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define ESC_KEY 27
#define PLAYER_TOP_ROW_SIZE 8
#define PLAYER_BOTTOM_ROW_SIZE 8

/* Quantidade de inimigos por linha e de linhas de inimigos */
#define ENEMY_QUANTITY 11
#define ENEMY_LINES 5

/* Struct responsável pelo jogador */
struct Tplayer {
    char *top_row;
    char *bottom_row;
    char *bullet;

    /* Coordenadas do jogador*/
    int player_x, player_y;

    /* Coordenadas do tiro do jogador */
    int bullet_x, bullet_y;

    int already_fired;
};

/* Struct dos sprites dos inimigos */
struct Tenemy {
    char *sprite;
    char *blank;
};

//typedef struct _Tplayer Tplayer;

void print_all(struct Tplayer *player, int first, int last);
void quit();
void initialize(int *max_x, int *max_y);
