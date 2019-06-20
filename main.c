#include "main.h"

int main(int argc, char ** argv) {
    /* Inicializa a tela */
    initialize();
    /* Registra entrada de maneira não bloqueante */
    nodelay(stdscr, 1);
    /* Executa até pressionar a tecla Esc */
    execute_until_esc();
    /* Libera a memória e finaliza o programa */
    quit();
    return 0;
}
