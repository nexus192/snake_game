#ifndef SRC_TETRIS_H_
#define SRC_TETRIS_H_

#include <ncurses.h>
#include <stdbool.h>

#define GAME_ROW 22
#define GAME_COL 12

#define START_POS_FIGUR_X 1
#define START_POS_FIGUR_Y 6

#define COUNT_BLOCS_IN_FIGUR 4

#define START_SPEED 500
#define START_LEVEL 1
#define LEVEL_UP 600

typedef enum UserAction_t {
  Start,
  Pause,
  Terminate,
  Left = KEY_LEFT,
  Right = KEY_RIGHT,
  Up = KEY_UP,
  Down = KEY_DOWN,
  Action,
  Game_over,
  Restart
} UserAction_t;

typedef struct Game_space {
  int** space;
  int row;
  int col;
} Game_space;

typedef struct GameInfo_t {
  int** next;
  int next_figur;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

typedef struct Figur {
  int position[COUNT_BLOCS_IN_FIGUR * 2];
  int figur_type;
  int move_triger;
  int rotations_position;
  int code;
} Figur;

#endif  // SRC_TETRIS_H_
