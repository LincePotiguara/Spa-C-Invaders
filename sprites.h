#define size 4

char enemy_type1[size] = "***";

void print_wave(int a, int b, int enemy_qty, int enemy_line){

  /* Imprime a Wave*/
  int i, j;
  for(i = 0; i < enemy_line; i++){
    for(j = 0; j < enemy_qty; j++){

      mvprintw((i*2)+(1*a), (j*5)+b, enemy_type1);
      mvprintw((i*2)+(1*a)+1, (j*5)+b, enemy_type1);

      mvprintw((i*2)+(1*a), (j*5)+b-1, " ");
      mvprintw((i*2)+(1*a)+1, (j*5)+b-1, " ");

    }
  }

}

void move_wave(int a, int enemy_qty, int enemy_line, int max_x, int speed){

  int i;
  int last = 5*enemy_qty+2;
  for(i = 1; last < max_x; i++){

    print_wave(a, i, enemy_qty, enemy_line);
    refresh();
    last++;
    usleep(speed);

  }

}
