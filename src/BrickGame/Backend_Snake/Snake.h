#ifndef SNAKE_H_
#define SNAKE_H_

#include <ncurses.h>

#define WIDTH 10
#define HEIGHT 20

typedef enum VectorDirection { Up, Down, Right, Left } VectorDirection;

class BodySnake;
class HeadSnake;
class Snake;

class HeadSnake {
  friend Snake;

 private:
  int x;
  int y;

 public:
  HeadSnake();
  HeadSnake(int x, int y);

  void move_point_up();
  void move_point_down();
  void move_point_right();
  void move_point_left();

  int get_point_x() const;
  int get_point_y() const;
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

class Snake {
 private:
  BodySnake* body_snake;

 public:
  Snake();

  void move_snake(HeadSnake head_other);

  int get_x_pixel_body(int pixel) const;
  int get_y_pixel_body(int pixel) const;
};

void Contol_Key(VectorDirection* Direction, int ch);

#endif  // SNAKE_H_
