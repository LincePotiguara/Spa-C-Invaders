#ifndef GAME_LOOP_H
#define GAME_LOOP_H

extern int ch;
extern int player_x, player_y, max_x, max_y;
//extern Tplayer;
extern struct Tplayer player;

void execute_until_esc(
    struct Tplayer *player,
    int max_x, int
    enemy_qty,
    int enemy_line
);

#endif
