// #include "./Snake/Frontend_Snake.h"
#include "front_end.h"

// #include <linux/time.h>
#include <time.h>

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

void DrawPixel(int y, int x, int color_pair, WINDOW* win) {  // cli

  wattron(win, COLOR_PAIR(color_pair));
  mvwaddch(win, y + 1, x * 2 + 1, ' ');
  mvwaddch(win, y + 1, x * 2 + 2, ' ');
  wattroff(win, COLOR_PAIR(color_pair));
};

/////////////////////////////////

void RenderNextFigure(GameInfo_t* game_info, WINDOW* win) {
  werase(win);
  box(win, 0, 0);
  mvwprintw(win, 1, 1, "NEXT");

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      if (game_info->next[i][j] == 1) {
        mvwprintw(win, i + 2, j + 1, "#");
      } else if (game_info->next[i][j] == 3) {
        mvwprintw(win, i + 2, j + 1, "@");
      } else {
        mvwprintw(win, i + 2, j + 1, " ");
      }
    }
  }

  // wrefresh(win);
}

void RenderGameInfo(int high_score, int score, int level, int speed,
                    bool is_paused, bool is_game_over, bool is_snake,
                    WINDOW* win) {
  if (is_snake == true) {
    werase(win);
    box(win, 0, 0);
  }

  mvwprintw(win, 7, 1, "HIGH SCORE");
  if (score < high_score) {
    mvwprintw(win, 8, 1, "%d", high_score);
  } else {
    mvwprintw(win, 8, 1, "%d", score);
  }

  mvwprintw(win, 10, 1, "SCORE");
  mvwprintw(win, 11, 1, "%d", score);

  mvwprintw(win, 13, 1, "LEVEL");
  mvwprintw(win, 14, 1, "%d", level);

  mvwprintw(win, 16, 1, "SPEED");
  mvwprintw(win, 17, 1, "%d", speed);

  if (is_game_over == true) {
    werase(win);
    box(win, 0, 0);
    mvwprintw(win, 10, 1, "GAME_OVER");
    mvwprintw(win, 15, 1, "[q]exit");
    mvwprintw(win, 16, 1, "[r]restart");
    wrefresh(win);
  } else if (is_paused == true) {
    mvwprintw(win, 20, 17, "PAUSE");
  }

  wrefresh(win);
}

void CleanGameInfo(GameInfo_t* game_info, WINDOW* win) {
  for (int i = 1; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      game_info->next[i][j] = 0;
    }
  }
  mvwprintw(win, 20, 15, "         ");
}  // cli
