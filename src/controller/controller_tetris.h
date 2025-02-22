#ifndef SRC_CONTROLER_TETRIS_H_
#define SRC_CONTROLER_TETRIS_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "../BrickGame/tetris/tetris_backend.h"

#ifdef __cplusplus
extern "C" {
#endif

int init_game();

UserAction_t GameLoop(WINDOW *window, WINDOW *Info_Window,
                      Game_space *game_space, GameInfo_t *game_info,
                      UserAction_t *user_actions, Figur *figur);
void GamePause(WINDOW *window, UserAction_t *us_sct);
void RanderField(Game_space *game_space, WINDOW *win);
void ControlKey(Figur *figur, WINDOW *window, Game_space *game_space,
                UserAction_t *user_actions, VectorDirection *direction);
void RestartGame(UserAction_t *user_actions, GameInfo_t *game_info,
                 WINDOW *window);

#ifdef __cplusplus
}
#endif

#endif  // SRC_CONTROLER_TETRIS_H
