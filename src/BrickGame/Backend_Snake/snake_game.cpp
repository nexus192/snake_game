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
  VectorDirection Direction = Down;
  StateGame State = StartGame;
  WINDOW* info = newwin(12, 22, 0, 24);
  snake.get_head_x();

  while ((ch = wgetch(field)) != 'q') {
    usleep(500000);
    werase(info);
    box(info, 0, 0);
    wrefresh(field);
    if (ch == 'p') {
      int chh;
      while ((chh = wgetch(field)) != 'p') {
        showField(field, snake);
      }
    }
    int chchc = wgetch(field);

    Contol_Key(&Direction, &State, chchc);
    snake.move_snake(snake, Direction, &State);
    // mvwprintw(info, 2, 2, "%d \n   %d", snake.get_head_x(),
    // snake.get_head_y());
    Coliseum(snake, &State);
    showField(field, snake);
    if (State == End) mvwprintw(info, 8, 8, "End");
    wrefresh(info);
  }
  endwin();
}
