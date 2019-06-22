#ifndef SPRITES_H
#define SPRITES_H
#define size 4

extern char enemy_type1[];

void print_wave(
    int a,
    int b,
    int enemy_qty, 
    int enemy_line, 
    char *enemy_sprite
);

void move_wave(
    int a,
    int enemy_qty, 
    int enemy_line, 
    int max_x, 
    int speed, 
    char *enemy_sprite
);

#endif
