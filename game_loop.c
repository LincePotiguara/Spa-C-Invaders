#include <ncurses.h>
#include "characters.h"
#include "game_loop.h"
#include "main.h"
#include "sprites.h"

/* Executa até pressionar a tecla Esc */
void execute_until_esc(
        struct Tplayer *player,
        int max_x, int
        enemy_qty,
        int enemy_line,
        char *enemy_sprite
    ) {
    /* Imprime a posição inicial da wave de inimigos */
    print_wave(1, 1, enemy_qty, enemy_line, enemy_sprite, player, max_x);

    /* Move a wave de inimigos até 2 linhas antes do jogador */
    int line = 0; int i;
    for(line = 1; line < (player->player_y)-enemy_line-6; line++) {

       move_wave(
           line, enemy_qty,
           enemy_line,
           max_x,
           100*1000,
           enemy_sprite,
           player
           );
    }
    while (1) {
        line++;
        /* Função responsável pelo controle do jogador */
        player_control(player, max_x);
        /* Função responsável por atualizar a tela */
        print_all(player);

        /* Move os aliens */
        // move_wave(
        //     line, enemy_qty,
        //     enemy_line,
        //     max_x,
        //     2.5*1000,
        //     enemy_sprite,
        //     player
        // );
        // if(line < (player->player_y)-enemy_line-6){
        //     /* final da tela */
        //     break;
        // }
	}
}
