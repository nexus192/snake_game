#include <ncurses.h>

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <utility>

#include "../../gui/cli/Frontend_Snake.h"
#include "Snake.h"

int main() {
  WINDOW* field = init_ncurses();
  int ch;
  HeadSnake Head_Snake(5, 10);
  Snake snake;
  VectorDirection Direction = Down;

  while ((ch = wgetch(field)) != 'q') {
    Contol_Key(&Direction, ch);

    if (Direction == Up) {
      Head_Snake.move_point_up();
    } else if (Direction == Down) {
      Head_Snake.move_point_down();
    } else if (Direction == Right) {
      Head_Snake.move_point_right();
    } else if (Direction == Left) {
      Head_Snake.move_point_left();
    }
    showField(field, Head_Snake, snake);
    snake.move_snake(Head_Snake);
    napms(700);
  }
  endwin();
}
