#ifndef FRONTEBD_CONTROLER_SNAKE_H_
#define FRONTEBD_CONTROLER_SNAKE_H_

#include <ncurses.h>

#include "../BrickGame/snake/Snake.h"

using namespace s21;

void InitGame();
void ContolKey(WINDOW* field, VectorDirection* Direction, StateGame* State);
void GamePausa(WINDOW* field);

void RenderField(WINDOW* field, Snake& snake, Apple& apple);
void RestartGame(StateGame* state, GameParameters* parameters, Snake& snake,
                 VectorDirection* direction, WINDOW* window);

#endif  // FRONTEBD_CONTROLER_SNAKE_H_
