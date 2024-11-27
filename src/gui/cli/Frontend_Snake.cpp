#include "Frontend_Snake.h"

WINDOW* init_ncurses() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, true);
  timeout(50);
  curs_set(0);
  WINDOW* field = newwin(22, 22, 0, 0);
  keypad(field, true);
  nodelay(field, 1);  // что бы программа не ожидала ввода
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_RED, COLOR_RED);

  return field;
}

void showField(WINDOW* field, Snake& snake) {
  werase(field);
  box(field, 0, 0);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (i == snake.get_head_y() && j == snake.get_head_x()) {
        wattron(field, COLOR_PAIR(2));
        mvwaddch(field, i + 1, j * 2 + 1, ' ');
        mvwaddch(field, i + 1, j * 2 + 2, ' ');
        wattroff(field, COLOR_PAIR(2));
      }
    }
  }

  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        if (i == snake.get_y_pixel_body(k) && j == snake.get_x_pixel_body(k)) {
          wattron(field, COLOR_PAIR(1));
          mvwaddch(field, i + 1, j * 2 + 1, ' ');
          mvwaddch(field, i + 1, j * 2 + 2, ' ');
          wattroff(field, COLOR_PAIR(1));
        }
      }
    }
  }
  wrefresh(field);
}
