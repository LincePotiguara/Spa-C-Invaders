#include <ncurses.h>
#include "characters.h"
#include "game_loop.h"
#include "main.h"

/* Executa até pressionar a tecla Esc */
void execute_until_esc() {
    char progress_bar[] = {'-', '\\', '|', '/'};
    int progress = 0;
    while (1) {
        mvwaddch(stdscr,0, 0, progress_bar[progress]);
        /* Função responsável pelo controle do jogador */
        player_control();
        progress = (progress + 1)%4;
	}
}
