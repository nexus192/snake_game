#include "controler_snake.h"

#include "front_end.h"

void InitGame() {
  srand(time(NULL));
  WINDOW* field = init_ncurses();
  WINDOW* info = newwin(22, 12, 0, 22);
  Snake snake;
  Apple apple;
  GameParameters Parameters;
  VectorDirection Direction = Down;
  StateGame State = StartGame;
  apple.generate_apple(snake, &State);

  while ((State != End) && (State != Win)) {
    usleep(Parameters.speed);
    ContolKey(field, &Direction, &State);
    if (State != End) {
      snake.eating_apple(&snake, apple, Direction, &State, &Parameters);
      snake.move_snake(snake, Direction, &State);
      Coliseum(snake, &State);
      RenderField(field, snake, apple);
      // RenderInfo(info, snake, Parameters);
      RenderGameInfo(Parameters.high_score,
                     snake.get_length_body() - INITIAL_BODY_LENGTH, 0,
                     Parameters.speed, false, false, true, info);
    }
  }
  Parameters.set_high_score(snake.get_length_body() - INITIAL_BODY_LENGTH);
  endwin();
}

void GamePausa(WINDOW* field) {
  int chh;
  while ((chh = wgetch(field)) != 'p') {
    ;
  }
}

void ContolKey(WINDOW* field, VectorDirection* Direction, StateGame* State) {
  int ch = wgetch(field);
  if (ch == KEY_UP && *Direction != Down) {
    *Direction = Up;
    *State = Shifting;
  } else if (ch == KEY_DOWN && *Direction != Up) {
    *Direction = Down;
    *State = Shifting;
  } else if (ch == KEY_RIGHT && *Direction != Left) {
    *Direction = Right;
    *State = Shifting;
  } else if (ch == KEY_LEFT && *Direction != Right) {
    *Direction = Left;
    *State = Shifting;
  } else if (ch == 'p') {
    *State = Pausa;
    GamePausa(field);
  } else if (ch == 'q') {
    *State = End;
  } else {
    return;
  }
}

void RenderField(WINDOW* field, Snake& snake, Apple& apple) {
  werase(field);
  box(field, 0, 0);

  DrawPixel(apple.get_y_apple(), apple.get_x_apple(), 3, field);
  DrawPixel(snake.get_head_y(), snake.get_head_x(), 2, field);

  for (int k = 0; k < snake.get_length_body(); k++) {
    DrawPixel(snake.get_y_pixel_body(k), snake.get_x_pixel_body(k), 1, field);
  }

  wrefresh(field);
}
