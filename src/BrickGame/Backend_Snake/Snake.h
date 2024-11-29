#ifndef SNAKE_H_
#define SNAKE_H_

#include <ncurses.h>

#include <vector>

#define WIDTH 10
#define HEIGHT 20
#define INITIAL_BODY_LENGTH 4

typedef enum VectorDirection { Up, Down, Right, Left } VectorDirection;

typedef enum StateGame {
  StartGame,
  Spawn,
  Moving,
  Shifting,
  Pausa,
  End
} StateGame;

class BodySnake;
class HeadSnake;
class Snake;

class HeadSnake {
 private:
  int x;
  int y;

 public:
  HeadSnake();
  HeadSnake(int x, int y);

  void move_head_up();
  void move_head_down();
  void move_head_right();
  void move_head_left();

  int get_head_x() const;
  int get_head_y() const;
};

class BodySnake {
 private:
  int x_body;
  int y_body;

 public:
  void set_position(int x, int y);
  int get_body_x();
  int get_body_y();
};

class Snake : public HeadSnake, protected BodySnake {
 private:
  BodySnake* body_snake;
  HeadSnake head_snake;
  int body_length;

 public:
  Snake();
  ~Snake();

  void move_snake(Snake& snake, VectorDirection Direction, StateGame* State);

  int get_x_pixel_body(int pixel) const;
  int get_y_pixel_body(int pixel) const;
};

// class Apple {
//   private:
//    int x;
//    int y;
//   public:
//    void generate_apple();
// };

void Contol_Key(VectorDirection* Direction, StateGame* State, int ch);
void Coliseum(int x_head, int y_head, StateGame* state_game);
// void Definition_Vector(VectorDirection Direction, Snake* snake);

#endif  // SNAKE_H_
