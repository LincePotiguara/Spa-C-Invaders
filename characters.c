#include <ncurses.h>
#include "characters.h"
#include "main.h"

/* Função responsável pelo controle do jogador */
void player_control(struct Tplayer *player, int max_x) {

    /* Detecta a tecla pressionada no teclado */
    ch = getch();
    switch(ch) {
        /* Se for ESC, sai do jogo */
        case ESC_KEY:
            quit();
            break;

        /* Se for a setinha pra cima, atira */
        case KEY_UP:
            /* Verifica se já existe um tiro do jogador em jogo */
            if (!(player->already_fired)) {

                /* Define a coordenada x do tiro do jogador */
                player->bullet_x = player->player_x+(PLAYER_TOP_ROW_SIZE)/2;
                player->bullet_y = player->player_y-2;
                player->already_fired = 1;
            }
            break;

        /* Se for a setinha esquerda, anda com o conjunto pra esquerda */
        case KEY_LEFT:
            if (player->player_x > 0){
                (player->player_x)--;
            }
            break;

        /* Se for a setinha direita, anda com o conjunto pra direita */
        case KEY_RIGHT:
            if (player->player_x < max_x - PLAYER_BOTTOM_ROW_SIZE) {
                (player->player_x)++;
            }
            break;
        default:
            break;
        }
    player->bullet_y--;
    if (player->bullet_y < 0) {
        player->already_fired = 0;
    }
}