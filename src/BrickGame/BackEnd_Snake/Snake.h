#ifndef SNAKE_H_
#define SNAKE_H_

#include <unistd.h>

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>
#include <utility>
#include <vector>

namespace s21 {

#define WIDTH 10
#define HEIGHT 20
#define INITIAL_BODY_LENGTH 4
#define STANDART_SPEED 500000

typedef enum VectorDirection { Up, Down, Right, Left } VectorDirection;

typedef enum StateGame {
  StartGame,
  Spawn,
  Moving,
  Shifting,
  Eating,
  Pausa,
  End,
  Win
} StateGame;

class BodySnake;
class HeadSnake;
class Snake;

class Apple {
 private:
  int x;
  int y;

  // int get_random_x();
  // int get_random_y();

 public:
  int get_x_apple() const;
  int get_y_apple() const;
  void generate_apple(Snake& snake, StateGame* State);
};
class HeadSnake {
 private:
  int x;
  int y;

 public:
  HeadSnake();
  HeadSnake(int x, int y);

  void move_haed(VectorDirection Direction);

  int get_head_x() const;
  int get_head_y() const;
};

class BodySnake {
 private:
  int x_body;
  int y_body;

 public:
  BodySnake();
  BodySnake(int x, int y);
  int get_body_x() const;
  int get_body_y() const;
};

class GameParameters {
 public:
  int level;
  int speed;
  int high_score;
  GameParameters();
  void get_high_score();
  void set_high_score(int score);
  void parameter_changes(int score);
};

class Snake : public HeadSnake, protected BodySnake {
 private:
  std::vector<BodySnake> body_snake;
  HeadSnake head_snake;
  int body_length;

 public:
  Snake();

  void move_snake(Snake& snake, VectorDirection Direction, StateGame* State);
  void eating_apple(Snake* snake, Apple& apple, VectorDirection direction,
                    StateGame* State, GameParameters* Parameters);
  void add_body_snake(Snake* snake, VectorDirection direction);

  int get_x_pixel_body(int pixel) const;
  int get_y_pixel_body(int pixel) const;
  int get_length_body() const;
};

int get_random_x();
int get_random_y();

void Coliseum(Snake& snake, StateGame* state_game);

}  // namespace s21

#endif  // SNAKE_H_
