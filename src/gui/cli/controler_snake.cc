#include "controler_snake.h"

#include <iostream>

#include "front_end.h"

void InitGame() {
  srand(time(NULL));
  WINDOW* field = init_ncurses();
  WINDOW* info_window = newwin(22, 12, 0, 22);
  Snake snake;
  Apple apple;
  GameParameters Parameters;
  VectorDirection Direction = Down;
  StateGame State = StartGame;
  apple.generate_apple(snake, &State);

  int temp_speed = Parameters.speed;

  while ((State != End) && (State != Win)) {
    ContolKey(field, &Direction, &State);

    if (State == Fast) {
      temp_speed = Parameters.speed / 3;
    } else {
      temp_speed = Parameters.speed;
    }

    if (State != GameOver && State != End) {
      snake.eating_apple(&snake, apple, Direction, &State, &Parameters);
      snake.move_snake(snake, Direction, &State);
      Coliseum(snake, &State);
      RenderField(field, snake, apple);
      RenderGameInfo(
          Parameters.high_score, snake.get_length_body() - INITIAL_BODY_LENGTH,
          Parameters.level, Parameters.speed, false, false, true, info_window);
    }

    if (State == GameOver) {
      RestartGame(&State, &Parameters, snake, &Direction, info_window);
    }

    flushinp();
    usleep(temp_speed);
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
  } else if (ch == 'g') {
    *State = Fast;
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

void RestartGame(StateGame* state, GameParameters* parameters, Snake& snake,
                 VectorDirection* direction, WINDOW* window) {
  int ch1{};
  bool end = true;
  while (*state == GameOver && end == true) {
    RenderGameInfo(
        parameters->high_score, snake.get_length_body() - INITIAL_BODY_LENGTH,
        parameters->level, parameters->speed, false, true, true, window);
    ch1 = wgetch(window);
    if (ch1 == 'r') {
      *state = Rest;
      snake.restart_snake();
      snake.set_head_position(5, 10);
      parameters->speed = START_SPEED;
      parameters->level = 0;
      parameters->set_high_score(snake.get_length_body() - INITIAL_BODY_LENGTH);
      *direction = Down;
    } else if (ch1 == 'q') {
      end = false;
      *state = End;
    }
    flushinp();
  }
}
