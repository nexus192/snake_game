#ifndef SRC_FRONT_END_H_
#define SRC_FRONT_END_H_

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../../BrickGame/BackEnd_Tetris/back_end.h"

WINDOW *init_ncurses(void);

UserAction_t game_loop(WINDOW *window, Game_space *game_space,
                       GameInfo_t *game_info, UserAction_t *user_actions,
                       Figur *figur);
void render_space_game(Game_space *game_space, WINDOW *win);
void render_game_info(GameInfo_t *game_info, UserAction_t user_act,
                      WINDOW *win);
void clean_game_info(GameInfo_t *game_info, WINDOW *win);
void game_pause(WINDOW* window, UserAction_t* us_sct);
void control_key(Figur* figur, WINDOW* window, Game_space* game_space,
                 UserAction_t* user_actions);
void restart_game(UserAction_t* user_actions, GameInfo_t* game_info,
                  WINDOW* window);

#endif  // SRC_FRONT_END_H_
