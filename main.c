#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ESC_KEY 27
#define PLAYER_TOP_ROW_SIZE 8
#define PLAYER_BOTTOM_ROW_SIZE 8

/* Variáveis responsáveis pela detecção do teclado */
int ch;

/* Struct responsável pelo jogador */
typedef struct {
    char *top_row;
    char *bottom_row;
    char *bullet;

    /* Coordenadas do jogador*/
    int player_x, player_y;

    /* Coordenadas do tiro do jogador */
    int bullet_x, bullet_y;

    int already_fired;
} Tplayer;

/* Inicializa a tela */
void initialize(int *max_x, int *max_y) {
    initscr();

    /* Checando por falhas */
    if(stdscr == NULL) {
        fprintf(stderr, "Ocorreu um erro ao inicializar ncurses\n");
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
    exit(0);
}

/* Função responsável pelo controle do jogador */
void player_control(Tplayer *player, int max_x){

    /* Detecta a tecla pressionada no teclado */
    ch = getch();
    switch(ch){
        /* Se for ESC, sai do jogo */
        case ESC_KEY:
            quit();
            break;

        /* Se for a setinha pra cima, atira */
        case KEY_UP:

            /* Verifica se já existe um tiro do jogador em jogo */
            if (!(player->already_fired)){
                /* Define a coordenada x do tiro do jogador */
                player->bullet_x = player->player_x+(PLAYER_TOP_ROW_SIZE)/2;
                player->bullet_y = player->player_y-2;
                player->already_fired = 1;
            }
            break;

        /* Se for a setinha esquerda, anda com o conjunto pra esquerda */
        case KEY_LEFT:
            if (player->player_x > 0){
                (player->player_x)--;
            }
            break;

        /* Se for a setinha direita, anda com o conjunto pra direita */
        case KEY_RIGHT:
            if (player->player_x < max_x - PLAYER_BOTTOM_ROW_SIZE){
                (player->player_x)++;
            }
            break;

        default:
            break;
        }
    player->bullet_y--;
    if (player->bullet_y < 0) {
        player->already_fired = 0;
    }
}

/* Função responsável pelo tiro do jogador */
void print_all(Tplayer *player){
    move(player->player_y, 0);
    move(player->player_y-1, 0);
    mvprintw(player->player_y-1, player->player_x, player->top_row);
    mvprintw(player->player_y, player->player_x, player->bottom_row);
    mvprintw(player->bullet_y, player->bullet_x, player->bullet);
    mvdelch(player->bullet_y+1, player->bullet_x);
    refresh();
    move(0, 0);
    wclrtoeol(stdscr);
    refresh();
    usleep(30*1000);
}

/*Função para mostrar a wave na tela e apagar a última wave mostrada*/
void print_wave(
        int a,
        int b,
        int enemy_qty,
        int enemy_line,
        char *enemy_sprite,
        Tplayer *player,
        int max_x
    ) {

    b = b/10;

    int i, j;
    for(i = 0; i < enemy_line; i++){
        for(j = 0; j < enemy_qty; j++){

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

/*Função para movimentar a wave*/
void move_wave(
        int a,
        int enemy_qty,
        int enemy_line,
        int max_x,
        int speed,
        char *enemy_sprite,
        Tplayer *player
    ) {

    int i;

    /*Se a linha é ímpar, a wave está no canto esquerdo*/
    if(a%2 == 1) {

        int last = 5*enemy_qty-1;

        /*Apaga os elementos que sobraram da wave na sua
        * última passagem*/
        print_wave(a-1, 1, enemy_qty, enemy_line, "   ", player, max_x);

        /*Imprime a wave até o último elemento chegar no
        * canto direito, com intervalo entre as impressões*/
        for(i = 1; last <= max_x; i++){

            print_wave(a, i, enemy_qty, enemy_line, enemy_sprite, player, max_x);
            if(i%10 == 0){
                last++;
            }
            usleep(speed);

        }

        /*A linha é par, a wave está no canto direito*/
    } else {

        int first = max_x-(5*enemy_qty)+2;

        /*Apaga os elementos que sobraram da wave na sua
        * última passagem*/
        print_wave(a-1, 10*(first+1), enemy_qty, enemy_line, "   ", player, max_x);

        /*Imprime a wave até o primeiro elemento chegar no
        * canto esquerdo, com intervalo entre as impressões*/
        for(i = first*10+9; i >= 1; i--){

            print_wave(a, i, enemy_qty, enemy_line, enemy_sprite, player, max_x);
            usleep(speed);

        }

    }

}

/* Executa até pressionar a tecla Esc */
void execute_until_esc(Tplayer *player, int max_x, int enemy_qty, int enemy_line, char *enemy_sprite) {

  /*Imprime a posição inicial da wave de inimigos*/
  print_wave(1, 1, enemy_qty, enemy_line, enemy_sprite, player, max_x);


  /*Move a wave de inimigos até 2 linhas antes do jogador*/
  int line;
  for(line = 1; line < (player->player_y)-enemy_line-6; line++){

    move_wave(line, enemy_qty, enemy_line, max_x, 0.0025*1000000, enemy_sprite, player);

  }

  while (1) {

      /* Função responsável pelo controle do jogador */
      player_control(player, max_x);
      /* Função responsável por atualizar a tela */
      print_all(player);
	}

}

int main(int argc, char ** argv) {

    /* Coordenadas dos limites do terminal */
    int max_x, max_y;

    /* Inicializa a tela */
    initialize(&max_x, &max_y);

    /* Registra entrada de maneira não bloqueante */
    nodelay(stdscr, 1);

    /* Define o player */
    Tplayer player;

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

    /*Definições dos sprites dos inimigos*/
    char *enemy_type1 = "***";

    /* Quantidade de inimigos por linha e de linhas de inimigos*/
    int enemy_qty = 11;
    int enemy_line = 5;

    /* Executa até pressionar a tecla Esc */
    execute_until_esc(&player, max_x, enemy_qty, enemy_line, enemy_type1);

    /* Libera a memória e finaliza o programa */
    quit();
    return 0;
}
