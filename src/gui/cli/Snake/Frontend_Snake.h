#ifndef FRONTEBD_SNAKE_H_
#define FRONTEBD_SNAKE_H_

#include <ncurses.h>

#include "../../../BrickGame/BackEnd_Snake/Snake.h"

WINDOW* init_ncurses();
void Contol_Key(WINDOW* field, VectorDirection* Direction, StateGame* State);
void Game_Pausa(WINDOW* field);
void Render_Field(WINDOW* field, Snake& snake, Apple& apple);
void Render_Info(WINDOW* info, Snake& snake, GameParameters& Parameters);

#endif  // FRONTEBD_SNAKE_H_
