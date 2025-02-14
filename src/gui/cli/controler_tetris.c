#include "controler_tetris.h"

#include <time.h>

#include "front_end.h"

int init_game() {
  Game_space game_space = {0};
  GameInfo_t game_info = {0};
  UserAction_t user_actions = Start;
  init_space_game(&game_space);
  init_game_info(&game_info);
  game_info.next_figur = get_random_number();
  game_info.speed = START_SPEED;
  game_info.level = START_LEVEL;
  int ch;
  bool end = true;
  WINDOW *window = init_ncurses();
  WINDOW *Info_Window = newwin(22, 12, 0, 22);
  game_info.high_score = readNumberFromFile();
  while (end == true && (user_actions == Start || user_actions == Restart)) {
    if (user_actions == Restart) {
      clean_space_game(&game_space);
      CleanGameInfo(&game_info, Info_Window);
      RenderNextFigure(&game_info, Info_Window);
      RenderGameInfo(game_info.high_score, game_info.score, game_info.level,
                     game_info.speed, false, false, false, Info_Window);
    }
    while ((ch = wgetch(window)) != 'q' && user_actions != Terminate &&
           user_actions != Game_over) {
      Figur figur;
      get_figur(&figur, game_info);
      game_info.next_figur = get_random_number();
      CleanGameInfo(&game_info, Info_Window);
      user_actions = GameLoop(window, Info_Window, &game_space, &game_info,
                              &user_actions, &figur);
      find_full_line(&game_space, &game_info);
      game_level_and_speed(&game_info);
      if (check_on_game_over(game_space) == true) {
        user_actions = Game_over;
      }
    }
    RestartGame(&user_actions, &game_info, Info_Window);
  }
  if (game_info.score > game_info.high_score) {
    writeNumberToFile(game_info.score);
  }
  game_remove(&game_space, &game_info);
  endwin();
  return 0;
}

UserAction_t GameLoop(WINDOW *window, WINDOW *Info_Window,
                      Game_space *game_space, GameInfo_t *game_info,
                      UserAction_t *user_actions, Figur *figur) {
  UserAction_t us_act = Start;
  struct timespec start, end;
  double elapsed;

  while (figur->move_triger == 0 && *user_actions == Start &&
         us_act != Terminate) {
    GamePause(window, &us_act);
    CleanGameInfo(game_info, Info_Window);
    print_figur_in_game_poly(game_space, figur);
    print_next_figur(game_info);
    RanderField(game_space, window);
    RenderNextFigure(game_info, Info_Window);
    RenderGameInfo(game_info->high_score, game_info->score, game_info->level,
                   game_info->speed, false, false, false, Info_Window);
    if (conditions_of_falling_down(*figur, *game_space) == true) {
      clock_gettime(CLOCK_MONOTONIC, &start);
      do {
        ControlKey(figur, window, game_space, &us_act);

        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed = (end.tv_sec - start.tv_sec) +
                  (end.tv_nsec - start.tv_nsec) / 1000000000.0;
      } while (elapsed < START_SPEED /
                             pow(VELOCITY_MULTIPLIER, game_info->level) /
                             START_SPEED);
      figur_falling_down(figur, &us_act, game_space);
      flushinp();
    } else {
      figur->move_triger = 1;
    }
  }
  return us_act;
}

void ControlKey(Figur *figur, WINDOW *window, Game_space *game_space,
                UserAction_t *user_actions) {
  int ch = wgetch(window);
  if (ch == KEY_LEFT && (traffic_permit_left(game_space, figur) == true)) {
    kill_figur(figur, game_space);
    figur->position[1]--;
    figur->position[3]--;
    figur->position[5]--;
    figur->position[7]--;
    print_figur_in_game_poly(game_space, figur);
    RanderField(game_space, window);
    *user_actions = TLeft;
  } else if (ch == KEY_RIGHT &&
             (traffic_permit_right(game_space, figur) == true)) {
    kill_figur(figur, game_space);
    figur->position[1]++;
    figur->position[3]++;
    figur->position[5]++;
    figur->position[7]++;
    print_figur_in_game_poly(game_space, figur);
    RanderField(game_space, window);
    *user_actions = TRight;
  } else if (ch == KEY_DOWN && traffic_permit_down(game_space, figur) == true) {
    kill_figur(figur, game_space);
    figur->position[0]++;
    figur->position[2]++;
    figur->position[4]++;
    figur->position[6]++;
    print_figur_in_game_poly(game_space, figur);
    RanderField(game_space, window);
    *user_actions = TDown;
  } else if (ch == KEY_UP && traffic_permit_flip(game_space, figur) == true) {
    kill_figur(figur, game_space);
    rotation_figurs(figur);
    print_figur_in_game_poly(game_space, figur);
    RanderField(game_space, window);
    *user_actions = TUp;
  } else if (ch == 'p') {
    *user_actions = Pause;
  } else if (ch == 'q') {
    *user_actions = Terminate;
    figur->move_triger = 1;
  }
}

void RanderField(Game_space *game_space, WINDOW *win) {
  werase(win);
  box(win, 0, 0);

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (game_space->space[i][j] == 3) {
        DrawPixel(i, j, 1, win);
      } else {
        DrawPixel(i, j, 0, win);
      }
    }
  }

  wrefresh(win);
}

void RestartGame(UserAction_t *user_actions, GameInfo_t *game_info,
                 WINDOW *window) {
  int ch1;
  bool end = true;
  while (*user_actions == Game_over && end == true) {
    RenderNextFigure(game_info, window);
    RenderGameInfo(game_info->high_score, game_info->score, game_info->level,
                   game_info->speed, false, true, false, window);
    ch1 = wgetch(window);
    if (ch1 == 'r') {
      *user_actions = Restart;
      game_info->score = 0;
      game_info->level = 1;
    } else if (ch1 == 'q') {
      end = false;
    }
  }
}

void GamePause(WINDOW *window, UserAction_t *us_sct) {
  while (*us_sct == Pause) {
    int ch1;
    if ((ch1 = wgetch(window)) == 'p') {
      *us_sct = Start;
    }
  }
}
