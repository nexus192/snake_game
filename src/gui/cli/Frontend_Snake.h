#ifndef FRONTEBD_SNAKE_H_
#define FRONTEBD_SNAKE_H_

#include <ncurses.h>

#include "../../BrickGame/Backend_Snake/Snake.h"

WINDOW* init_ncurses();
void showField(WINDOW* field, Snake& snake);

#endif  // FRONTEBD_SNAKE_H_
