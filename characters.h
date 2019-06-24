#ifndef CHARACTERS_H
#define CHARACTERS_H

extern int ch, last_ch;
extern struct Tplayer player;
extern int max_x, max_y;

extern struct Talien alien;
extern int alien_x, alien_y, direction;
extern char *alien_01, *alien_02;

void player_control();
void move_alien();

#endif
