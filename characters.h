#ifndef CHARACTERS_H
#define CHARACTERS_H

extern int ch, last_ch;
extern int player_x, player_y, max_x, max_y;
//extern Tplayer;
extern struct Tplayer player;

void player_control(struct Tplayer *player, int max_x);

#endif
