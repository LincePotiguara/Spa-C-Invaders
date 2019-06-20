#include "characters.h"
#include "main.h"
#include <ncurses.h>
#include <unistd.h>

/* Função responsável pelo controle do jogador */
void player_control(){

    /* Detecta a tecla pressionada no teclado */
    ch = getch();
    switch(ch){

        /* Se for ESC, sai do jogo */
        case ESC_KEY:
            quit();
            break;

        /* Se for a setinha esquerda, anda com o conjunto pra esquerda */
        case LEFT_ARROW_KEY:
            if (player_x > 0){
                move(player_y, 0);
                wclrtoeol(stdscr);
                move(player_y-1, 0);
                wclrtoeol(stdscr);
                player_x--;
            }
            break;

        /* Se for a setinha direita, anda com o conjunto pra direita */
        case RIGHT_ARROW_KEY:
            if (player_x < max_x - PLAYER_02_SIZE){
                move(player_y, 0);
                wclrtoeol(stdscr);
                move(player_y-1, 0);
                wclrtoeol(stdscr);
                player_x++;
            }
            break;
        default:
            break;
        }
        //refresh();
        mvprintw(player_y-1, player_x, player_01);
        mvprintw(player_y, player_x, player_02);
}

void move_alien() {

	/* Apaga a posição ataual do alien */
	move (alien_y, alien_x);
	wclrtoeol (stdscr);
	move (alien_y-1, alien_x);
	wclrtoeol (stdscr);

	/* movimento do alien */
	if ((alien_x+direction)>=(max_x-ALIEN_01_SIZE) || (alien_x+direction)<0)
		direction *= -1;
	alien_x += direction;

	/* imprime o alien na tela novamente */
	//refresh();
	mvprintw (alien_y-1, alien_x, alien_01);
	mvprintw (alien_y, alien_x, alien_02);
}
