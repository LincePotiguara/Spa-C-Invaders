#include <ncurses.h>
#include <unistd.h>
#include "main.h"
#include "sprites.h"

/*Função para mostrar a wave na tela e apagar a última wave mostrada*/
void print_wave(
        int a,
        int b,
        int enemy_qty,
        int enemy_line,
        char *enemy_sprite,
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

              mvprintw((i*2)+a, (j*5)+b, enemy_sprite);
              mvprintw((i*2)+a+1, (j*5)+b, enemy_sprite);
              if(a%2 == 1){
                  mvprintw((i*2)+(1*a), (j*5)+b-1, " ");
                  mvprintw((i*2)+(1*a)+1, (j*5)+b-1, " ");
              } else {
                  mvprintw((i*2)+(1*a), (j*5)+b+3, " ");
                  mvprintw((i*2)+(1*a)+1, (j*5)+b+3, " ");
              }

              refresh();
            } else {

              mvprintw((i*2)+a, (j*5)+b, "   ");
              mvprintw((i*2)+a+1, (j*5)+b, "   ");
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

}

/* Função para movimentar a wave */
void move_wave(
        int a,
        int enemy_qty,
        int enemy_line,
        int max_x,
        int speed,
        char *enemy_sprite,
        struct Tplayer *player
    ) {

    int i, last, first;

    /* Se a linha é ímpar, a wave está no canto esquerdo */
    if(a%2 == 1) {
        last = 5*enemy_qty-1;
        first = 0;

        /* Apaga os elementos que sobraram da wave na sua
        * última passagem */
        print_wave(
            a-1,
            1,
            enemy_qty,
            enemy_line,
            "   ",
            player,
            max_x,
            first,
            a
        );

        /* Imprime a wave até o último elemento chegar no
        * canto direito, com intervalo entre as impressões */
        for(i = 1; last <= max_x; i++) {
            print_wave(
                a,
                i,
                enemy_qty,
                enemy_line,
                enemy_sprite,
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
        first = max_x-(5*enemy_qty)+2;
        last = max_x;

        /* Apaga os elementos que sobraram da wave na sua
        * última passagem*/
        print_wave(
            a -1,
            10*(first+1),
            enemy_qty,
            enemy_line,
            "   ",
            player,
            max_x,
            first,
            a
        );
        /* Imprime a wave até o primeiro elemento chegar no
        * canto esquerdo, com intervalo entre as impressões */
        for(i = first*10 + 9; i >= 1; i--) {
            print_wave(
                a,
                i,
                enemy_qty,
                enemy_line,
                enemy_sprite,
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
