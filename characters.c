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
            if (player.player_x > 0){
                move(player.player_y, 0);
                wclrtoeol(stdscr);
                move(player.player_y-1, 0);
                wclrtoeol(stdscr);
                player.player_x--;
            }
            break;

        /* Se for a setinha direita, anda com o conjunto pra direita */
        case RIGHT_ARROW_KEY:
            if (player.player_x < max_x - PLAYER_BOTTOM_ROW_SIZE){
                move(player.player_y, 0);
                wclrtoeol(stdscr);
                move(player.player_y-1, 0);
                wclrtoeol(stdscr);
                player.player_x++;
            }
            break;
        default:
            break;
        }
        //refresh();
        mvprintw(player.player_y-1, player.player_x, player.top_row);
        mvprintw(player.player_y, player.player_x, player.bottom_row);
}

void move_alien() {
	/* Apaga a posição ataual do alien */
	move (alien.alien_y, alien.alien_x);
	wclrtoeol (stdscr);
	move (alien.alien_y-1, alien.alien_x);
	wclrtoeol (stdscr);

	/* movimento do alien */
	if ((alien.alien_x+alien.direction)>=(max_x-ALIEN_TOP_ROW_SIZE) || (alien.alien_x+alien.direction)<0) {
		alien.direction *= -1;
		if ((alien.alien_y+1)<(player.player_y-1))
			alien.alien_y += 1;
		else
			quit();
	}
	alien.alien_x += alien.direction;

	/* imprime o alien na tela novamente */
	//refresh();
	mvprintw (alien.alien_y-1, alien.alien_x, alien.top_row);
	mvprintw (alien.alien_y, alien.alien_x, alien.bottom_row);
}
