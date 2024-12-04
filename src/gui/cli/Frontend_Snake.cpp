#include "Frontend_Snake.h"

WINDOW* init_ncurses() {
  initscr();
  noecho();
  keypad(stdscr, true);
  timeout(50);
  curs_set(0);
  WINDOW* field = newwin(22, 22, 0, 0);
  cbreak();
  keypad(field, true);
  nodelay(field, 1);  // что бы программа не ожидала ввода
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_RED, COLOR_RED);
  init_pair(3, COLOR_GREEN, COLOR_GREEN);

  return field;
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

void Game_Pausa(WINDOW* field) {
  int chh;
  while ((chh = wgetch(field)) != 'p') {
    ;
  }
}

void Render_Field(WINDOW* field, Snake& snake, Apple& apple) {
  werase(field);
  box(field, 0, 0);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (i == apple.get_y_apple() && j == apple.get_x_apple()) {
        wattron(field, COLOR_PAIR(3));
        mvwaddch(field, i + 1, j * 2 + 1, ' ');
        mvwaddch(field, i + 1, j * 2 + 2, ' ');
        wattroff(field, COLOR_PAIR(3));
      }
      if (i == snake.get_head_y() && j == snake.get_head_x()) {
        wattron(field, COLOR_PAIR(2));
        mvwaddch(field, i + 1, j * 2 + 1, ' ');
        mvwaddch(field, i + 1, j * 2 + 2, ' ');
        wattroff(field, COLOR_PAIR(2));
      }
    }
  }

  for (int k = 0; k < snake.get_length_body(); k++) {
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
