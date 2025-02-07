#ifndef FRONTEBD_CONTROLER_SNAKE_H_
#define FRONTEBD_CONTROLER_SNAKE_H_

#include <ncurses.h>

#include "../../BrickGame/BackEnd_Snake/Snake.h"

using namespace s21;

void InitGame();
void ContolKey(WINDOW *field, VectorDirection *Direction, StateGame *State);
void GamePausa(WINDOW *field);

void RenderField(WINDOW *field, Snake &snake, Apple &apple);

#endif  // FRONTEBD_CONTROLER_SNAKE_H_
