#define size 4

char enemy_type1[size] = "***";

void print_wave(int a, int b, int enemy_qty, int enemy_line, char *enemy_sprite){

  /* Imprime a Wave e apaga a anterior*/
  int i, j;
  for(i = 0; i < enemy_line; i++){
    for(j = 0; j < enemy_qty; j++){

      mvprintw((i*2)+(1*a), (j*5)+b, enemy_sprite);
      mvprintw((i*2)+(1*a)+1, (j*5)+b, enemy_sprite);

      if(a%2 == 1){

        mvprintw((i*2)+(1*a), (j*5)+b-1, " ");
        mvprintw((i*2)+(1*a)+1, (j*5)+b-1, " ");

      } else {

        mvprintw((i*2)+(1*a), (j*5)+b+3, " ");
        mvprintw((i*2)+(1*a)+1, (j*5)+b+3, " ");

      }

    }
  }

}

void move_wave(int a, int enemy_qty, int enemy_line, int max_x, int speed, char *enemy_sprite){

  int i;

  if(a%2 == 1){

    int last = 5*enemy_qty;
    print_wave(a-1, 1, enemy_qty, enemy_line, "   ");

    for(i = 1; last <= max_x; i++){

      print_wave(a, i, enemy_qty, enemy_line, enemy_sprite);
      refresh();
      last++;
      usleep(speed);

    }
  } else {

    int first = max_x-(5*enemy_qty)-1;
    print_wave(a-1, first+2, enemy_qty, enemy_line, "   ");

    for(i = first; i >= 1; i--){

      print_wave(a, i, enemy_qty, enemy_line, enemy_sprite);
      refresh();
      usleep(speed);

    }

  }

}
