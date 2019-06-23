#include <ncurses.h>
#include "characters.h"
#include "game_loop.h"
#include "main.h"
#include "sprites.h"

/* Executa até pressionar a tecla Esc */
void execute_until_esc() {
    /* Quantidade de inimigos por linha e de linhas de inimigos*/
    int enemy_qty = 11;
    int enemy_line = 5;

    /*Imprime a posição inicial da wave de inimigos*/
    print_wave(1, 1, enemy_qty, enemy_line, enemy_type1);

    /*Move a wave de inimigos até 2 linhas antes do jogador*/
    for(int line = 1; line < player_y-enemy_line - 6; line++) {
      move_wave(line, enemy_qty, enemy_line, max_x, 250*100, enemy_type1);
    }
    while (1) {
        /* Função responsável pelo controle do jogador */
        player_control();
	}
}
