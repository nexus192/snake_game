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

void DrawPixel(int y, int x, int color_pair, WINDOW *win);
void RenderGameInfo(int high_score, int score, int level, int speed,
                    bool is_paused, bool is_game_over, bool is_snake,
                    WINDOW *win);
void CleanGameInfo(GameInfo_t *game_info, WINDOW *win);
void RenderNextFigure(GameInfo_t *game_info, WINDOW *win);

#ifdef __cplusplus
}
#endif

#endif  // SRC_FRONT_END_H_
