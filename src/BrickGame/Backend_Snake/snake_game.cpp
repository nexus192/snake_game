#include <ncurses.h>
#include <unistd.h>

// #include <algorithm>
// #include <cmath>
// #include <stdexcept>
#include <utility>

#include "../../gui/cli/Frontend_Snake.h"
#include "Snake.h"

int main() {
  srand(time(NULL));
  WINDOW* field = init_ncurses();
  int ch;
  Snake snake;
  Apple apple;
  VectorDirection Direction = Down;
  StateGame State = StartGame;
  WINDOW* info = newwin(12, 22, 0, 24);
  apple.generate_apple(snake);

  while ((State != End) || (State != Win)) {
    usleep(500000);
    werase(info);
    box(info, 0, 0);
    wrefresh(field);
    Contol_Key(field, &Direction, &State);
    snake.eating_apple(&snake, apple, Direction, &State);
    snake.move_snake(snake, Direction, &State);
    Coliseum(snake, &State);
    showField(field, snake, apple);
    if (State == End)
      mvwprintw(info, 8, 8, "End");
    else
      mvwprintw(info, 8, 8, "Norm");
    wrefresh(info);
  }
  endwin();
}
