#ifndef SRC_FRONT_END_H_
#define SRC_FRONT_END_H_

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

// #include "../../BrickGame/BackEnd_Snake/Snake.h"
#include "../../BrickGame/BackEnd_Tetris/back_end.h"

WINDOW *init_ncurses(void);

void render_space_game(Game_space *game_space, WINDOW *win);
void render_game_info(GameInfo_t *game_info, UserAction_t user_act,
                      WINDOW *win);
void clean_game_info(GameInfo_t *game_info, WINDOW *win);

#ifdef __cplusplus
}
#endif

#endif  // SRC_FRONT_END_H_
