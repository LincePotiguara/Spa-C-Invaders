#include <ncurses.h>
#include <unistd.h>
#include "characters.h"
#include "game_loop.h"
#include "main.h"
#include "sprites.h"

extern enemy_matrix[ENEMY_LINES][ENEMY_QUANTITY];

/* Executa até pressionar a tecla Esc */
void execute_until_esc(
        struct Tplayer *player,
        int max_x, int
        enemy_qty,
        int enemy_line
    ) {
    /* Imprime a posição inicial da wave de inimigos */
    print_wave(
        1,
        1,
        enemy_qty,
        enemy_line,
        player,
        max_x,
        1,
        1
    );

    /* Move a wave de inimigos até 2 linhas antes do jogador */

    int line = ENEMY_LINES, last_destroyed = 0, waves = 0;
    int end = player->player_y-7;
    while(line <= end){

      int position = line - ENEMY_LINES + 1;

       move_wave(
           position,
           enemy_qty,
           enemy_line,
           max_x,
           10*1000,
           player
           );

       int i, j, lines_destroyed = 0;
       for(i = 0; i < ENEMY_LINES; i++){

          int defeated = 1;

          for(j = 0; j < ENEMY_QUANTITY; j++){
            if(enemy_matrix[i][j] == 1){
              defeated = 0;
            }
          }

          if(defeated == 1){
            lines_destroyed++;
          }

       }

       if(last_destroyed != lines_destroyed){
         end = end + (lines_destroyed - last_destroyed) + 1;
         last_destroyed = lines_destroyed;
       }

       line++;

       if(last_destroyed == ENEMY_LINES){

         waves++;
         line = ENEMY_LINES + waves;
         last_destroyed = 0;

       }

    }
}
