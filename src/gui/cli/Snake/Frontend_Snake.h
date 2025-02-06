#ifndef FRONTEBD_SNAKE_H_
#define FRONTEBD_SNAKE_H_

#include <ncurses.h>

#include "../../../BrickGame/BackEnd_Snake/Snake.h"

namespace s21 {

WINDOW* init_ncurses();
void start_game();
void Contol_Key(WINDOW* field, VectorDirection* Direction, StateGame* State);
void Game_Pausa(WINDOW* field);
void Render_Field(WINDOW* field, Snake& snake, Apple& apple);
void Render_Info(WINDOW* info, Snake& snake, GameParameters& Parameters);

}  // namespace s21
#endif  // FRONTEBD_SNAKE_H_
