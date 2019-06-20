#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define ESC_KEY 27
#define UP_ARROW_KEY 259
#define LEFT_ARROW_KEY 260
#define RIGHT_ARROW_KEY 261
#define PLAYER_TOP_ROW_SIZE 8
#define PLAYER_BOTTOM_ROW_SIZE 8

void initialize();
void quit();
void execute_until_esc();
void player_control();
void player_shoot();
void print_all();
void print_wave(int a, int b, int enemy_qty, int enemy_line, char *enemy_sprite);
void move_wave(int a, int enemy_qty, int enemy_line, int max_x, int speed, char *enemy_sprite);