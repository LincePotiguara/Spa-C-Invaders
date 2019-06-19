#ifndef CHARACTERS_H
#define CHARACTERS_H

extern int ch;
extern int player_x, player_y, max_x, max_y;
extern char *player_01, *player_02;
extern int alien_x, alien_y, direction;
extern char *alien_01, *alien_02;

void player_control();
void move_alien();

#endif
