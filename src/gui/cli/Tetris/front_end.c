#include "front_end.h"

WINDOW *init_ncurses(void) {
  initscr();
  cbreak();
  refresh();
  WINDOW *window = newwin(24, 27, 0, 0);
  box(window, 0, 0);
  nodelay(window, 1);
  keypad(window, 1);
  noecho();
  curs_set(0);
  wrefresh(window);
  // wtimeout(window, 10);
  scrollok(window, 1);
  mouseinterval(1);

  return window;
}

UserAction_t game_loop(WINDOW *window, Game_space *game_space,
                       GameInfo_t *game_info, UserAction_t *user_actions,
                       Figur *figur) {
  UserAction_t us_act = Start;
  while (figur->move_triger == 0 && *user_actions == Start &&
         us_act != Terminate) {
    game_pause(window, &us_act);
    clean_game_info(game_info, window);
    if (conditions_of_falling_down(*figur, *game_space) == true) {
      box(window, 0, 0);
      print_figur_in_game_poly(game_space, figur);
      napms(game_info->speed);
      control_key(figur, window, game_space, &us_act);
      render_space_game(game_space, window);
      render_game_info(game_info, us_act, window);
      figur_falling_down(figur);
      remove_trash_on_poly(figur, game_space);
      wrefresh(window);
      flushinp();
    } else {
      figur->move_triger = 1;
    }
  }
  return us_act;
}

void render_space_game(Game_space *game_space, WINDOW *win) {
  for (int i = 0; i < GAME_ROW; i++) {
    for (int j = 0; j < GAME_COL; j++) {
      if (game_space->space[i][j] == 1) {
        mvwprintw(win, i + 1, j + 1, "#");
      } else if (game_space->space[i][j] == 2) {
        mvwprintw(win, i + 1, j + 1, "#");
      } else if (game_space->space[i][j] == 3) {
        mvwprintw(win, i + 1, j + 1, "@");
      } else {
        mvwprintw(win, i + 1, j + 1, " ");
      }
    }
  }
}

void render_game_info(GameInfo_t *game_info, UserAction_t user_act,
                      WINDOW *win) {
  mvwprintw(win, 1, 17, "NEXT");
  print_next_figur(game_info);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      if (game_info->next[i][j] == 1) {
        mvwprintw(win, i + 2, j + 16, "#");
      } else if (game_info->next[i][j] == 3) {
        mvwprintw(win, i + 2, j + 16, "@");
      } else {
        mvwprintw(win, i + 2, j + 16, " ");
      }
    }
  }

  mvwprintw(win, 7, 15, "HIGH SCORE");
  if (game_info->score < game_info->high_score) {
    mvwprintw(win, 8, 15, "%d", game_info->high_score);
  } else {
    mvwprintw(win, 8, 15, "%d", game_info->score);
  }

  mvwprintw(win, 10, 17, "SCORE");
  mvwprintw(win, 11, 17, "%d", game_info->score);

  mvwprintw(win, 13, 17, "LEVEL");
  mvwprintw(win, 14, 17, "%d", game_info->level);

  mvwprintw(win, 16, 17, "SPEED");
  mvwprintw(win, 17, 17, "%d", game_info->speed);

  if (user_act == Game_over) {
    mvwprintw(win, 20, 15, "GAME_OVER");
  } else if (user_act == Pause) {
    mvwprintw(win, 20, 17, "PAUSE");
  }
}

void clean_game_info(GameInfo_t *game_info, WINDOW *win) {
  for (int i = 1; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      game_info->next[i][j] = 0;
    }
  }
  mvwprintw(win, 20, 15, "         ");
}

void game_pause(WINDOW* window, UserAction_t* us_sct) {
  while (*us_sct == Pause) {
    int ch1;
    if ((ch1 = wgetch(window)) == 'p') {
      *us_sct = Start;
    }
  }
}

void control_key(Figur* figur, WINDOW* window, Game_space* game_space,
                 UserAction_t* user_actions) {
  int ch = wgetch(window);
  if (ch == KEY_LEFT && (traffic_permit_left(game_space, figur) == true)) {
    kill_figur(figur, game_space);
    figur->position[1]--;
    figur->position[3]--;
    figur->position[5]--;
    figur->position[7]--;
    print_figur_in_game_poly(game_space, figur);
    render_space_game(game_space, window);
  } else if (ch == KEY_RIGHT &&
             (traffic_permit_right(game_space, figur) == true)) {
    kill_figur(figur, game_space);
    figur->position[1]++;
    figur->position[3]++;
    figur->position[5]++;
    figur->position[7]++;
    print_figur_in_game_poly(game_space, figur);
    render_space_game(game_space, window);
  } else if (ch == KEY_DOWN && traffic_permit_down(game_space, figur) == true) {
    kill_figur(figur, game_space);
    figur->position[0]++;
    figur->position[2]++;
    figur->position[4]++;
    figur->position[6]++;
    print_figur_in_game_poly(game_space, figur);
    render_space_game(game_space, window);
  } else if (ch == KEY_UP && traffic_permit_flip(game_space, figur) == true) {
    kill_figur(figur, game_space);
    rotation_figurs(figur);
    print_figur_in_game_poly(game_space, figur);
    render_space_game(game_space, window);
  } else if (ch == 'p') {
    *user_actions = Pause;
  } else if (ch == 'q') {
    *user_actions = Terminate;
    figur->move_triger = 1;
  }
}

void restart_game(UserAction_t* user_actions, GameInfo_t* game_info,
                  WINDOW* window) {
  int ch1;
  bool end = true;
  while (*user_actions == Game_over && end == true) {
    render_game_info(game_info, *user_actions, window);
    if ((ch1 = wgetch(window)) == 'r') {
      *user_actions = Restart;
    } else if ((ch1 = wgetch(window)) == 'q') {
      end = false;
    }
  }
}
