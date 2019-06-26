#ifndef SPRITES_H
#define SPRITES_H
#define size 4

extern char *enemy_type1;
extern struct Tenemy alien;
extern int enemy_matrix[ENEMY_LINES][ENEMY_QUANTITY];
extern unsigned int score;

void print_wave(
    int a,
    int b,
    int enemy_qty,
    int enemy_line,
    struct Tplayer *player,
    int max_x,
    int first,
    int line
);

void move_wave(
    int a,
    int enemy_qty,
    int enemy_line,
    int max_x,
    int speed,
    struct Tplayer *player
);

#endif
