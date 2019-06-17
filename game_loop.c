#include "characters.h"
#include "game_loop.h"
#include "main.h"

/* Executa até pressionar a tecla Esc */
void execute_until_esc() {
    while (1) {
        /* Função responsável pelo controle do jogador */
        player_control();
	}
}
