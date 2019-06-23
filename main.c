#include "main.h"

/* Variáveis responsáveis pela detecção do teclado */
int ch;

/* Struct responsável pelo jogador */
struct Tplayer{
    char *top_row;
    char *bottom_row;
    char *bullet;

    /* Coordenadas do jogador*/
    int player_x, player_y;

    /* Coordenadas do tiro do jogador */
    int bullet_x, bullet_y;

    bool already_fired;
};

/* Coordenadas dos limites do terminal */
int max_x, max_y; 

/* Define o player */
struct Tplayer player;

/* Inicializa a tela */
void initialize() {
    initscr();

    /* Checando por falhas */
    if(stdscr == NULL) {
        fprintf(stderr, "Ocorreu um erro ao inicializar ncurses\n");
        exit(1);
    }

    /* Deixa de mostrar as teclas pressionadas e habilita as setas */
    noecho();
    keypad(stdscr, TRUE);

    /* Deixa o cursor invisível */
    curs_set(0);
}

int main(int argc, char ** argv) {
    /* Inicializa a tela */
    initialize();
    
    /* Registra entrada de maneira não bloqueante */
    nodelay(stdscr, 1);

    /* Detecta e regista os limites do terminal */
    getmaxyx(stdscr, max_y, max_x);

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

    /* Executa até pressionar a tecla Esc */
    execute_until_esc();

    /* Libera a memória e finaliza o programa */
    quit();
    return 0;
}

/* Executa até pressionar a tecla Esc */
void execute_until_esc() {

    while (1) {
        /* Função responsável pelo controle do jogador */
        player_control();
        
        /* Função responsável por atualizar a tela */
        print_all();
	}
}

/* Função responsável pelo controle do jogador */
void player_control(){

    /* Detecta a tecla pressionada no teclado */
    ch = getch();
    switch(ch){
        /* Se for ESC, sai do jogo */
        case ESC_KEY:
            quit();
            break;

        /* Se for a setinha pra cima, atira */
        case UP_ARROW_KEY:
            
            /* Verifica se já existe um tiro do jogador em jogo */
            if (!(player.already_fired)){
                /* Define a coordenada x do tiro do jogador */
                player.bullet_x = player.player_x+(PLAYER_TOP_ROW_SIZE)/2;
                player.bullet_y = player.player_y-2;
                player.already_fired = 1;         
            }
            break;

        /* Se for a setinha esquerda, anda com o conjunto pra esquerda */
        case LEFT_ARROW_KEY:
            if (player.player_x > 0){
                player.player_x--;
            }
            break;

        /* Se for a setinha direita, anda com o conjunto pra direita */
        case RIGHT_ARROW_KEY:
            if (player.player_x < max_x - PLAYER_BOTTOM_ROW_SIZE){
                player.player_x++;
            }
            break;

        default:
            break;
        }
    player.bullet_y--;
    if (player.bullet_y < 0) {
        player.already_fired = 0;
    }
}

/* Função responsável pelo tiro do jogador */


void print_all(){
    move(player.player_y, 0);
    move(player.player_y-1, 0);
    mvprintw(player.player_y-1, player.player_x, player.top_row);
    mvprintw(player.player_y, player.player_x, player.bottom_row);
    mvprintw(player.bullet_y, player.bullet_x, player.bullet);
    mvdelch(player.bullet_y+1, player.bullet_x);
    refresh();
    move(0, 0);
    wclrtoeol(stdscr);
    refresh();
    usleep(30*1000);
}

/* Sai da tela */
void quit() {
    delwin(stdscr);
    endwin();
    exit(0);
}