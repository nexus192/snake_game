#ifndef SRC_FRONT_END_H_
#define SRC_FRONT_END_H_

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../../BrickGame/BackEnd_Tetris/back_end.h"
#include "../../../BrickGame/BackEnd_Tetris/tetris.h"

WINDOW *init_ncurses(void);

void init_space_game(Game_space *game_space);
UserAction_t game_loop(WINDOW *window, Game_space *game_space,
                       GameInfo_t *game_info, UserAction_t *user_actions,
                       Figur *figur);
void init_game_info(GameInfo_t *game_info);
void render_space_game(Game_space *game_space, WINDOW *win);
void render_game_info(GameInfo_t *game_info, UserAction_t user_act,
                      WINDOW *win);
void clean_space_game(Game_space *game_space);
void clean_game_info(GameInfo_t *game_info, WINDOW *win);
void print_figur_in_game_poly(Game_space *game_space, Figur *figur);
void print_next_figur(GameInfo_t *game_info);
void game_remove(Game_space *game_space, GameInfo_t *game_info);

#endif  // SRC_FRONT_END_H_
