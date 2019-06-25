#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include "sprites.h"
#include "characters.h"
#include "game_loop.h"

/* Define o player */
struct Tplayer player;

/* Quantidade de inimigos por linha e de linhas de inimigos */
#define enemy_qty 11
#define enemy_line 5

int enemy_matrix[enemy_line][enemy_qty];

/* Variáveis responsáveis pela detecção do teclado */
int ch;

int main(int argc, char **argv) {
    /* Coordenadas dos limites do terminal */
    int max_x, max_y;

    /* Inicializa a tela */
    initialize(&max_x, &max_y);

    /* Registra entrada de maneira não bloqueante */
    nodelay(stdscr, 1);

    animation(max_x, max_y);

    /* Define o formado do jogador e do tiro */
    player.top_row = "  __|__  ";
    player.bottom_row = " |_____| ";
    player.bullet = "|";
    player.already_fired = 0;

    /* Determina a poisção inicial da nave */
    player.player_x = (max_x/2) - 3;
    player.player_y = max_y - 3;

    /* Imprime a posição inicial da nave */
    mvprintw(player.player_y-1, player.player_x, player.top_row);
    mvprintw(player.player_y, player.player_x, player.bottom_row);
    refresh();

    /* Definições dos sprites dos inimigos */
    char *enemy_type1 = "***";

    for(int i = 0; i < enemy_line; i++){
        for(int j = 0; j < enemy_qty; j++){

            enemy_matrix[i][j] = 1;

        }

    }

    /* Executa até pressionar a tecla Esc */
    execute_until_esc(&player, max_x, enemy_qty, enemy_line, enemy_type1);

    /* Libera a memória e finaliza o programa */
    quit();
    return 0;
}

/* Inicializa a tela */
void initialize(int *max_x, int *max_y) {
    initscr();

    /* Checando por falhas */
    if(stdscr == NULL) {
        fprintf(stderr, "Ocorreu um erro ao inicializar ncurses\\\\n");
        exit(1);
    }

    /* Detecta e regista os limites do terminal */
    getmaxyx(stdscr, *max_y, *max_x);

    /* Deixa de mostrar as teclas pressionadas e habilita as setas */
    noecho();
    keypad(stdscr, TRUE);

    /* Deixa o cursor invisível */
    curs_set(0);
}

/* Sai da tela */
void quit() {
    delwin(stdscr);
    endwin();

    for(int i = 0; i < enemy_line; i++){
        for(int j = 0; j < enemy_qty; j++){

            printf("%d ", enemy_matrix[i][j]);

        }
        puts ("");
    }
    
    exit(0);
}

/* Função responsável pelo tiro do jogador */
void print_all(struct Tplayer *player, int first, int line) {
    int at_position;
    // move(player->player_y, 0);
    // move(player->player_y-1, 0);
    int x, y, alien_x, alien_y;
    alien_y = (player->bullet_x - first)/5;
    alien_x = (player->bullet_y - line)/2;
    getyx(stdscr, y, x);
    mvprintw(player->player_y-1, player->player_x, player->top_row);
    mvprintw(player->player_y, player->player_x, player->bottom_row);
    at_position = mvinch(player->bullet_y-1, player->bullet_x);
    if(at_position == '*') {
        // if(alien_x >= 5 ) printf("alien_x e maior que 5\\\\n");
        // if(alien_y >= 11 ) printf("alien_x e maior que 11\\\\n");
        enemy_matrix[alien_x][alien_y] = 0;

    }
    mvprintw(player->bullet_y-1, player->bullet_x, player->bullet);
    //mvdelch(player->bullet_y, player->bullet_x);
    mvprintw(player->bullet_y, player->bullet_x, " ");
    move(y, x);
    // refresh();
    // move(0, 0);
    // wclrtoeol(stdscr);
    // refresh();
    //usleep(30*1000);
}

void animation(int max_x, int max_y){

    usleep(200000);
    mvprintw(max_y-5, max_x/2 - 15 , "    __                    ");
    refresh();
    usleep(200000);
    mvprintw(max_y-4, max_x/2 - 15, "   / /   __  ______ _____ ");
    refresh();
    usleep(200000);
    mvprintw(max_y-3, max_x/2 - 15, "  / /   / / / / __ `/ __ \\");
    refresh();
    usleep(200000);
    mvprintw(max_y-2, max_x/2 - 15, " / /___/ /_/ / /_/ / / / /");
    refresh();
    usleep(200000);
    mvprintw(max_y-1, max_x/2 - 15, "/_____/\\__,_/\\__,_/_/ /_/ ");
    refresh();
    usleep(200000);
    mvprintw(max_y-0, max_x/2 - 15, "                          ");
    refresh();
    usleep(1500000);
    
    clear();
    refresh();

    usleep(200000);
    mvprintw(max_y-5-max_y/3, max_x/2 - 15, "    ____                ");
    refresh();
    usleep(200000);
    mvprintw(max_y-4-max_y/3, max_x/2 - 15, "   /  _/___ _____  _____");
    refresh();
    usleep(200000);
    mvprintw(max_y-3-max_y/3, max_x/2 - 15, "   / // __ `/ __ \\/ ___/");
    refresh();
    usleep(200000);
    mvprintw(max_y-2-max_y/3, max_x/2 - 15, " _/ // /_/ / /_/ / /    ");
    refresh();
    usleep(200000);
    mvprintw(max_y-1-max_y/3, max_x/2 - 15, "/___/\\__, /\\____/_/     ");
    refresh();
    usleep(200000);
    mvprintw(max_y-0-max_y/3, max_x/2 - 15, "    /____/              ");
    refresh();
    usleep(1500000);

    clear();
    refresh();

    usleep(200000);
    mvprintw(max_y-5-2*max_y/3, max_x/2 - 15, "   ______          __     ");
    refresh();
    usleep(200000);
    mvprintw(max_y-4-2*max_y/3, max_x/2 - 15, "  / ____/___ _____/ /_  __");
    refresh();
    usleep(200000);
    mvprintw(max_y-3-2*max_y/3, max_x/2 - 15, " / /   / __ `/ __  / / / /");
    refresh();
    usleep(200000);
    mvprintw(max_y-2-2*max_y/3, max_x/2 - 15, "/ /___/ /_/ / /_/ / /_/ / ");
    refresh();
    usleep(200000);
    mvprintw(max_y-1-2*max_y/3, max_x/2 - 15, "\\____/\\__,_/\\__,_/\\__,_/  ");
    refresh();
    usleep(200000);
    mvprintw(max_y-0-2*max_y/3, max_x/2 - 15, "                          ");
    refresh();
    usleep(1500000);

    clear();
    refresh();

    usleep(200000);
    mvprintw(0, max_x/2 - 20, "   ____        _       __       __     ");
    refresh();
    usleep(200000);
    mvprintw(1, max_x/2 - 20, "  / __ \\__  __(_)___  / /____  / /___ _");
    refresh();
    usleep(200000);
    mvprintw(2, max_x/2 - 20, " / / / / / / / / __ \\/ __/ _ \\/ / __ `/");
    refresh();
    usleep(200000);
    mvprintw(3, max_x/2 - 20, "/ /_/ / /_/ / / / / / /_/  __/ / /_/ / ");
    refresh();
    usleep(200000);
    mvprintw(4, max_x/2 - 20, "\\___\\_\\__,_/_/_/ /_/\\__/\\___/_/\\__,_/  ");
    refresh();
    usleep(200000);
    mvprintw(5, max_x/2 - 20, "                                       ");
    refresh();
    usleep(1500000);

    clear();
    refresh();

    usleep(200000);
    mvprintw(max_y/2 - 6, max_x/2 - 30, "   _____                   ______                     ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 5, max_x/2 - 30, "  / ___/____  ____ _      / ____/                     ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 4, max_x/2 - 30, "  \\__ \\/ __ \\/ __ `/_____/ /                          ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 3, max_x/2 - 30, " ___/ / /_/ / /_/ /_____/ /___                        ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 2, max_x/2 - 30, "/____/ .___/\\__,_/      \\____/                        ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 1, max_x/2 - 30, "    /_/      ____                     __              ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 0, max_x/2 - 30, "            /  _/___ _   ______ _____/ /__  __________");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 1, max_x/2 - 30, "            / // __ \\ | / / __ `/ __  / _ \\/ ___/ ___/");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 2, max_x/2 - 30, "          _/ // / / / |/ / /_/ / /_/ /  __/ /  (__  ) ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 3, max_x/2 - 30, "         /___/_/ /_/|___/\\__,_/\\__,_/\\___/_/  /____/  ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 4, max_x/2 - 30, "                                                      ");
    refresh();
    usleep(1500000);

    clear();
    refresh();

    usleep(200000);
    mvprintw(max_y/2 - 6, max_x/2 - 30, "    ____                                                  ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 5, max_x/2 - 30, "   / __ \\________  __________   _________  ____ _________ ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 4, max_x/2 - 30, "  / /_/ / ___/ _ \\/ ___/ ___/  / ___/ __ \\/ __ `/ ___/ _ \\");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 3, max_x/2 - 30, " / ____/ /  /  __(__  |__  )  (__  ) /_/ / /_/ / /__/  __/");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 2, max_x/2 - 30, "/_/   /_/   \\___/____/____/  /____/ .___/\\__,_/\\___/\\___/ ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 1, max_x/2 - 30, "           __                __  /_/        __            ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 0, max_x/2 - 30, "          / /_____     _____/ /_____ ______/ /_           ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 1, max_x/2 - 30, "         / __/ __ \\   / ___/ __/ __ `/ ___/ __/           ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 2, max_x/2 - 30, "        / /_/ /_/ /  (__  ) /_/ /_/ / /  / /_             ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 3, max_x/2 - 30, "        \\__/\\____/  /____/\\__/\\__,_/_/   \\__/             ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 4, max_x/2 - 30, "                                                          ");
    refresh();

    char ch;
    while(1){
        ch = getch();
        if (ch == ' ')
            break;
    }

    clear();
    refresh();
    usleep(350000);

    mvprintw(max_y/2 - 6, max_x/2 - 30, "    ____                                                  ");
    refresh();
    mvprintw(max_y/2 - 5, max_x/2 - 30, "   / __ \\________  __________   _________  ____ _________ ");
    refresh();
    mvprintw(max_y/2 - 4, max_x/2 - 30, "  / /_/ / ___/ _ \\/ ___/ ___/  / ___/ __ \\/ __ `/ ___/ _ \\");
    refresh();
    mvprintw(max_y/2 - 3, max_x/2 - 30, " / ____/ /  /  __(__  |__  )  (__  ) /_/ / /_/ / /__/  __/");
    refresh();
    mvprintw(max_y/2 - 2, max_x/2 - 30, "/_/   /_/   \\___/____/____/  /____/ .___/\\__,_/\\___/\\___/ ");
    refresh();
    mvprintw(max_y/2 - 1, max_x/2 - 30, "           __                __  /_/        __            ");
    refresh();
    mvprintw(max_y/2 - 0, max_x/2 - 30, "          / /_____     _____/ /_____ ______/ /_           ");
    refresh();
    mvprintw(max_y/2 + 1, max_x/2 - 30, "         / __/ __ \\   / ___/ __/ __ `/ ___/ __/           ");
    refresh();
    mvprintw(max_y/2 + 2, max_x/2 - 30, "        / /_/ /_/ /  (__  ) /_/ /_/ / /  / /_             ");
    refresh();
    mvprintw(max_y/2 + 3, max_x/2 - 30, "        \\__/\\____/  /____/\\__/\\__,_/_/   \\__/             ");
    refresh();
    mvprintw(max_y/2 + 4, max_x/2 - 30, "                                                          ");
    refresh();

    usleep(300000);

    clear();
    refresh();

    usleep(1000000);
}