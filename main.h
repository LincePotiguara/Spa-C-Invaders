#ifndef MAIN_H
#define MAIN_H

#define ESC_KEY 27
#define PLAYER_TOP_ROW_SIZE 8
#define PLAYER_BOTTOM_ROW_SIZE 8

#define ALIEN_TOP_ROW_SIZE 7
#define ALIEN_BOTTOM_ROW_SIZE 7

#define LEFT_ARROW_KEY 260
#define RIGHT_ARROW_KEY 261

/* Struct responsável pelo jogador */
struct Tplayer {
	char *top_row;
	char *bottom_row;
	char *bullet;

	/* Coordenadas do jogador */
	int player_x, player_y;

	/* Coordenadas do tiro do jogador */
	int bullet_x, bullet_y;

	int already_fired;
};

/* Struct responsável pelo alien */
struct Talien {
	char *top_row;
	char *bottom_row;
	char *bullet;

	/* Coordenadas do alien e direção */
	int alien_x, alien_y, direction;

	/* Coordenadas do tiro do alien */
	int bullet_x, bullet_y;

	int already_fired;
};

void initialize();
void quit();

#endif
