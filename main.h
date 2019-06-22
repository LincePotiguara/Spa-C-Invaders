#ifndef MAIN_H
#define MAIN_H

#define ESC_KEY 27
#define DOWN_ARROW_KEY 258
#define UP_ARROW_KEY 259
#define LEFT_ARROW_KEY 260
#define RIGHT_ARROW_KEY 261
#define PLAYER_01_SIZE 5
#define PLAYER_02_SIZE 7


void execute_until_esc();
void initialize();
void quit();
void player_control();
#endif
