#ifndef SRC_FRONT_END_H_
#define SRC_FRONT_END_H_

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TEXT_Y 7

WINDOW* init_ncurses(void);

void DrawPixel(int y, int x, int color_pair, WINDOW* win);
void RenderGameInfo(int high_score, int score, int level, int speed,
                    bool is_paused, bool is_game_over, bool is_snake,
                    WINDOW* win);
void RenderNextFigure(int** game_info, WINDOW* win);

#ifdef __cplusplus
}
#endif

#endif  // SRC_FRONT_END_H_
