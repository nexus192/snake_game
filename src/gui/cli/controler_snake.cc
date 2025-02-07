#include "controler_snake.h"

#include "front_end.h"

void start_game() {
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

void Game_Pausa(WINDOW* field) {
  int chh;
  while ((chh = wgetch(field)) != 'p') {
    ;
  }
}

void Contol_Key(WINDOW* field, VectorDirection* Direction, StateGame* State) {
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
    Game_Pausa(field);
  } else if (ch == 'q') {
    *State = End;
  } else {
    return;
  }
}

void Render_Field(WINDOW* field, Snake& snake, Apple& apple) {
  werase(field);
  box(field, 0, 0);

  auto draw_element = [&](int y, int x, int color_pair) {
    wattron(field, COLOR_PAIR(color_pair));
    mvwaddch(field, y + 1, x * 2 + 1, ' ');
    mvwaddch(field, y + 1, x * 2 + 2, ' ');
    wattroff(field, COLOR_PAIR(color_pair));
  };

  draw_element(apple.get_y_apple(), apple.get_x_apple(), 3);
  draw_element(snake.get_head_y(), snake.get_head_x(), 2);

  for (int k = 0; k < snake.get_length_body(); k++) {
    draw_element(snake.get_y_pixel_body(k), snake.get_x_pixel_body(k), 1);
  }

  wrefresh(field);
}

void Render_Info(WINDOW* info, Snake& snake, GameParameters& Parameters) {
  werase(info);
  box(info, 0, 0);
  mvwprintw(info, 1, 1, "SCORE: %d",
            snake.get_length_body() - INITIAL_BODY_LENGTH);

  if (snake.get_length_body() - INITIAL_BODY_LENGTH < Parameters.high_score) {
    mvwprintw(info, 2, 1, "HIGH SCORE: %d", Parameters.high_score);
  } else {
    mvwprintw(info, 2, 1, "HIGH SCORE: %d",
              snake.get_length_body() - INITIAL_BODY_LENGTH);
  }
  mvwprintw(info, 3, 1, "LEVEL: %d", Parameters.level);
  mvwprintw(info, 4, 1, "SPEED: %d", Parameters.speed);
  wrefresh(info);
}
