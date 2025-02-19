#ifndef SNAKE_H_
#define SNAKE_H_

#include <unistd.h>

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>
#include <utility>
#include <vector>

#include "./../common/common.h"

namespace s21 {

#define INITIAL_BODY_LENGTH 4

typedef enum VectorDirection { Up, Down, Right, Left } VectorDirection;

typedef enum StateGame {
  StartGame,
  Fast,
  Spawn,
  Moving,
  Shifting,
  Eating,
  Pausa,
  GameOver,
  End,
  Rest,
  Win
} StateGame;

class BodySnake;
class HeadSnake;
class Snake;

class Apple {
 public:
  int get_x_apple() const;
  int get_y_apple() const;
  void generate_apple(Snake& snake, StateGame* State);

 private:
  int x;
  int y;
};

class HeadSnake {
 public:
  HeadSnake();
  HeadSnake(int x, int y);
  ~HeadSnake() = default;

  void move_haed(VectorDirection Direction);

  int get_head_x() const;
  int get_head_y() const;

  void set_head_position(int x_, int y_);

 private:
  int x;
  int y;
};

class BodySnake {
 public:
  BodySnake();
  BodySnake(int x, int y);
  ~BodySnake() = default;
  int get_body_x() const;
  int get_body_y() const;

 private:
  int x_body;
  int y_body;
};

class GameParameters {
 public:
  int level;
  int speed;
  int high_score;
  GameParameters();
  ~GameParameters() = default;
  void get_high_score();
  void set_high_score(int score);
  void parameter_changes(int score);
};

class Snake : public HeadSnake, protected BodySnake {
 public:
  Snake();

  void move_snake(Snake& snake, VectorDirection Direction, StateGame* State);
  void eating_apple(Snake* snake, Apple& apple, VectorDirection direction,
                    StateGame* State, GameParameters* Parameters);
  void add_body_snake(Snake* snake, VectorDirection direction);
  void restart_snake();

  int get_x_pixel_body(int pixel) const;
  int get_y_pixel_body(int pixel) const;
  int get_length_body() const;

 private:
  std::vector<BodySnake> body_snake;
  HeadSnake head_snake;
  int body_length;
};

void Coliseum(Snake& snake, StateGame* state_game);

}  // namespace s21

#endif  // SNAKE_H_
