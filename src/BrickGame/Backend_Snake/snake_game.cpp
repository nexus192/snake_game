#include <ncurses.h>
#include <unistd.h>

// #include <algorithm>
// #include <cmath>
// #include <stdexcept>
#include <utility>

#include "../../gui/cli/Frontend_Snake.h"
#include "Snake.h"

int main() {
  WINDOW* field = init_ncurses();
  int ch;
  Snake snake;
  Apple apple;
  VectorDirection Direction = Down;
  StateGame State = StartGame;
  WINDOW* info = newwin(12, 22, 0, 24);
  snake.get_head_x();
  apple.generate_apple(snake);

  while ((ch = wgetch(field)) != 'q') {
    usleep(500000);
    werase(info);
    box(info, 0, 0);
    wrefresh(field);
    if (ch == 'p') {
      int chh;
      while ((chh = wgetch(field)) != 'p') {
        showField(field, snake, apple);
      }
    }
    int chchc = wgetch(field);

    Contol_Key(&Direction, &State, chchc);
    snake.eating_apple(&snake, apple, Direction, &State);
    snake.move_snake(snake, Direction, &State);
    // mvwprintw(info, 2, 2, "%d \n   %d", snake.get_head_x(),
    // snake.get_head_y());
    Coliseum(snake, &State);
    showField(field, snake, apple);
    if (State == End) mvwprintw(info, 8, 8, "End");
    mvwprintw(info, 8, 8, "len_body%d", snake.get_length_body());
    mvwprintw(info, 6, 6, "x_apple: %d", apple.get_x_apple());
    mvwprintw(info, 7, 6, "y_apple%d", apple.get_y_apple());
    wrefresh(info);
  }
  endwin();
}
