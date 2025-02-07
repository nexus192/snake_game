#ifndef FRONTEBD_CONTROLER_SNAKE_H_
#define FRONTEBD_CONTROLER_SNAKE_H_

#include <ncurses.h>

#include "../../BrickGame/BackEnd_Snake/Snake.h"

using namespace s21;

void start_game();
void Contol_Key(WINDOW *field, VectorDirection *Direction, StateGame *State);
void Game_Pausa(WINDOW *field);

void Render_Info(WINDOW *info, Snake &snake, GameParameters &Parameters);
void Render_Field(WINDOW *field, Snake &snake, Apple &apple);

#endif  // FRONTEBD_CONTROLER_SNAKE_H_
