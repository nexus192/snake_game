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
  Snake snake;
  VectorDirection Direction = Down;
  WINDOW* info = newwin(12, 22, 0, 24);

  while ((ch = wgetch(field)) != 'q') {
    werase(info);
    box(info, 0, 0);
    // mvwprintw(info, 2, 2,
    //           "x_body_1: %d \n y_body_1: %d \n x_body_2: %d \n y_body_2: %d
    //           \n " "x_body_3: %d \n y_body_3: %d \n x_body_4: %d \n y_body_4:
    //           %d ", snake.get_x_pixel_body(0), snake.get_y_pixel_body(0),
    //           snake.get_x_pixel_body(1), snake.get_y_pixel_body(1),
    //           snake.get_x_pixel_body(2), snake.get_y_pixel_body(2),
    //           snake.get_x_pixel_body(3), snake.get_y_pixel_body(3));
    wrefresh(info);
    wrefresh(field);
    if (ch == 'p') {
      int chh;
      while ((ch = wgetch(field)) != 'p') {
        showField(field, snake);
      }
    }
    Contol_Key(&Direction, ch);
    snake.move_snake(snake, Direction);
    showField(field, snake);
    napms(700);
  }
  endwin();
}
