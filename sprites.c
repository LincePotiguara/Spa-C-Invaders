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
        int max_x
    ) {
    b = b/10;
    int i, j;
    for(i = 0; i < enemy_line; i++) {
        for(j = 0; j < enemy_qty; j++) {
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
            player_control(player, max_x);

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

    int i;

    /* Se a linha é ímpar, a wave está no canto esquerdo */
    if(a%2 == 1) {

        int last = 5*enemy_qty-1;

        /* Apaga os elementos que sobraram da wave na sua
        * última passagem */
        print_wave(a-1, 1, enemy_qty, enemy_line, "   ", player, max_x);

        /* Imprime a wave até o último elemento chegar no
        * canto direito, com intervalo entre as impressões */
        for(i = 1; last <= max_x; i++) {
            print_wave(
                a, 
                i, 
                enemy_qty, 
                enemy_line, 
                enemy_sprite, 
                player, max_x
            );
            if(i%10 == 0) {
                last++;
            }
            usleep(speed);
        }
    /* A linha é par, a wave está no canto direito */
    } else {

        int first = max_x-(5*enemy_qty)+2;

        /* Apaga os elementos que sobraram da wave na sua
        * última passagem*/
        print_wave(
            a -1,
            10*(first+1), 
            enemy_qty, 
            enemy_line, 
            "   ", 
            player, max_x
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
                max_x
            );
            usleep(speed);
        }
    }
}