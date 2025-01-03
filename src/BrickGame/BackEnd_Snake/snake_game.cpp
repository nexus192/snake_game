#include <ncurses.h>
#include <unistd.h>

#include "../../gui/cli/Snake/Frontend_Snake.h"
#include "Snake.h"

int main() {
  srand(time(NULL));
  WINDOW* field = init_ncurses();
  WINDOW* info = newwin(12, 22, 0, 24);
  Snake snake;
  Apple apple;
  GameParameters Parameters;
  VectorDirection Direction = Down;
  StateGame State = StartGame;
  apple.generate_apple(snake, &State);

  while ((State != End) && (State != Win)) {
    usleep(Parameters.speed);
    Contol_Key(field, &Direction, &State);
    if (State != End) {
      snake.eating_apple(&snake, apple, Direction, &State, &Parameters);
      snake.move_snake(snake, Direction, &State);
      Coliseum(snake, &State);
      Render_Field(field, snake, apple);
      Render_Info(info, snake, Parameters);
    }
  }
  Parameters.set_high_score(snake.get_length_body() - INITIAL_BODY_LENGTH);
  endwin();
}
