#include <ncurses.h>
#include <unistd.h>
#include "characters.h"
#include "main.h"
#include "sprites.h"

/*Função para mostrar a wave na tela e apagar a última wave mostrada*/
void print_wave(
        int a,
        int b,
        int enemy_qty,
        int enemy_line,
        struct Tplayer *player,
        int max_x,
        int first,
        int line
    ) {
    b = b/10;
    int i, j;
    for(i = 0; i < enemy_line; i++) {
        for(j = 0; j < enemy_qty; j++) {

            if(enemy_matrix[i][j] == 1){

              mvprintw((i*2)+a, (j*5)+b, alien.sprite);
              mvprintw((i*2)+a+1, (j*5)+b, alien.sprite);
              if(a%2 == 1){
                  mvprintw((i*2)+(1*a), (j*5)+b-1, " ");
                  mvprintw((i*2)+(1*a)+1, (j*5)+b-1, " ");
              } else {
                  mvprintw((i*2)+(1*a), (j*5)+b+3, " ");
                  mvprintw((i*2)+(1*a)+1, (j*5)+b+3, " ");
              }

              refresh();
            } else {

              mvprintw((i*2)+a, (j*5)+b, alien.blank);
              mvprintw((i*2)+a+1, (j*5)+b, alien.blank);
              if(a%2 == 1){
                  mvprintw((i*2)+(1*a), (j*5)+b-1, " ");
                  mvprintw((i*2)+(1*a)+1, (j*5)+b-1, " ");
              } else {
                  mvprintw((i*2)+(1*a), (j*5)+b+3, " ");
                  mvprintw((i*2)+(1*a)+1, (j*5)+b+3, " ");
              }

            }

            player_control(player, max_x);
            print_all(player, first, a);

        }

    }

    move(player->player_y+2, 0);
    clrtoeol();
    mvprintw(player->player_y+1, 0, "Recorde: %d", hiscore);
    mvprintw(player->player_y+2, 0, "Pontos: %d", score);

}

/* Função para movimentar a wave */
void move_wave(
        int a,
        int enemy_qty,
        int enemy_line,
        int max_x,
        int speed,
        struct Tplayer *player
    ) {

    int i, j, last_diff = 0, first_diff = 0;

    /*Controlador de colunas existentes*/
    int columns_alive[ENEMY_QUANTITY];

    /*Inicialização do controlador das colunas*/
    for(i = 0; i < ENEMY_QUANTITY; i++){

         columns_alive[i] = 0;
    }

    /*Verificar quais colunas ainda existem*/
    for(i = 0; i < ENEMY_LINES; i++){
       for(j = 0; j < ENEMY_QUANTITY; j++){

         if(enemy_matrix[i][j] == 1){
           columns_alive[j] = 1;
         }
       }
    }

    /*Calcula a diferença entre o último alien da wave original e da atual*/
    for(i = ENEMY_QUANTITY-1; i >= 0; i--){

      if(i == ENEMY_QUANTITY-1){

        if(columns_alive[ENEMY_QUANTITY-1] == 0){
            last_diff += 5;

        }else {

          break;
        }

      } else if(columns_alive[i+1] == 0){

        if(columns_alive[i] == 0){
            last_diff += 5;

        } else {

          break;
        }
      }

    }

    /*Calcula a diferença entre o primeiro alien da wave original e da atual*/
    for(i = 0; i < ENEMY_QUANTITY; i++){

      if(i == 0){

        if(columns_alive[0] == 0){
            first_diff += 5;

        }else {

          break;
        }

      } else if(columns_alive[i-1] == 0){

        if(columns_alive[i] == 0){
            first_diff += 5;

        } else {

          break;
        }
      }

    }

    /* Se a linha é ímpar, a wave está no canto esquerdo */
    if(a%2 == 1) {
        int first = (0 - first_diff);
        int last = first + (5*enemy_qty-2) - last_diff;

        /* Apaga os elementos que sobraram da wave na sua
        * última passagem, apagando toda a tela */
        wclear(stdscr);

        /* Imprime a wave até o último elemento chegar no
        * canto direito, com intervalo entre as impressões */
        for(i = first*10; last <= max_x; i++) {
            print_wave(
                a,
                i,
                enemy_qty,
                enemy_line,
                player,
                max_x,
                first,
                a
            );
            if(i%10 == 0) {
                last++;
                first++;
            }
            if(i%2) {
                /* Velocidade da bala */
                player->bullet_y--;
                if (player->bullet_y < 0) {
                    player->already_fired = 0;
                }
           }

            refresh();
            usleep(speed);
        }

    /* A linha é par, a wave está no canto direito */
    } else {
        int last = max_x - last_diff;
        int first = max_x - (5*enemy_qty-2) + last_diff;

        /* Apaga os elementos que sobraram da wave na sua
        /*última passagem, apagando toda a tela */
        wclear(stdscr);

        /* Imprime a wave até o primeiro elemento chegar no
        * canto esquerdo, com intervalo entre as impressões */
        for(i = first*10; i >= (0-first_diff)*10; i--) {
            print_wave(
                a,
                i,
                enemy_qty,
                enemy_line,
                player,
                max_x,
                first,
                a
            );
            if(i%10 == 0) {
                last--;
                first--;
            }
            if(i%2) {
                /* Velocidade da bala */
                player->bullet_y--;
                if (player->bullet_y < 0) {
                    player->already_fired = 0;
                }
            }
            refresh();
            usleep(speed);
        }
    }
}
