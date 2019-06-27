#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "sprites.h"
#include "characters.h"
#include "game_loop.h"
#include "animation.h"
#include <stdio.h>


/* Define o player */
struct Tplayer player;

/* Define os inimigos */
struct Tenemy alien;

/* Pontuação */
unsigned int score = 0, hiscore = 0;

/* Matriz que guarda o estado dos inimigos */
int enemy_matrix[ENEMY_LINES][ENEMY_QUANTITY];

/* Variáveis responsáveis pela detecção do teclado */
int ch;
// FILE* file;

int main(int argc, char **argv) {
    // file = fopen("debug.log", "w");
    /* Coordenadas dos limites do terminal */
    int max_x, max_y;

    /* Inicializa a tela */
    initialize(&max_x, &max_y);

    /* Registra entrada de maneira não bloqueante */
    nodelay(stdscr, 1);

    //animation(max_x, max_y);
    /* Recupera o hiscore */
    save();

    /* Define o formado do jogador e do tiro */
    player.top_row = "  __|__  ";
    player.bottom_row = " |_____| ";
    player.bullet = "|";
    player.already_fired = 0;

    /* Define o formato dos inimigos */
    alien.sprite = "***";
    alien.blank = "   ";

    /* Determina a poisção inicial da nave */
    player.player_x = (max_x/2) - 3;
    player.player_y = max_y - 3;

    /* Imprime a posição inicial da nave */
    mvprintw(player.player_y-1, player.player_x, player.top_row);
    mvprintw(player.player_y, player.player_x, player.bottom_row);
    refresh();

    for(int i = 0; i < ENEMY_LINES; i++){
        for(int j = 0; j < ENEMY_QUANTITY; j++){
            enemy_matrix[i][j] = 1;
        }
    }

    score = 0;

    /* Executa até pressionar a tecla Esc */
    execute_until_esc(
        &player,
        max_x,
        ENEMY_QUANTITY,
        ENEMY_LINES
    );

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

void save() {
    FILE *f;
    unsigned int stored_score;
    f = fopen("save.dat", "rb+");

    /* Se não existir, crie */
    if(f == NULL) {
        f = fopen("save.dat", "wb+");
        if(f == NULL) return;
    }
    fread(&stored_score, sizeof(unsigned int), 1, f);
    if(hiscore > stored_score) {
        rewind(f);
        fwrite(&hiscore, sizeof(unsigned int), 1, f);
    } else {
        hiscore = stored_score;
    }
    fclose(f);
}
/* Sai da tela */
void quit() {
    delwin(stdscr);
    endwin();

    // for(int i = 0; i < ENEMY_LINES; i++){
    //     for(int j = 0; j < ENEMY_QUANTITY; j++){

    //         printf("%d ", enemy_matrix[i][j]);

    //     }
    //     puts ("");
    // }
    save();
    // fclose(file);

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
    at_position = mvinch(player->bullet_y, player->bullet_x);

    /* Checa a colisão com o inimigo */
    if(at_position == '*') {
        // debug_matrix();
        // if(alien_x >= 5 ) printf("alien_x e maior que 5\\\\n");
        // if(alien_y >= 11 ) printf("alien_x e maior que 11\\\\n");
        enemy_matrix[alien_x][alien_y] = 0;
        score += 10;
        if(score > hiscore) hiscore = score;
        mvprintw(player->bullet_y-1, player->bullet_x, " ");
        player->bullet_y = -1;

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

// void debug_matrix() {
//     for(int i = 0; i < ENEMY_LINES; i++){
//         for(int j = 0; j < ENEMY_QUANTITY; j++){
//             fprintf(file, "%d ", enemy_matrix[i][j]);
//         }
//         fprintf(file, "\n");
//     }
//     fprintf(file, "%d\n", player.bullet_y);
// }
