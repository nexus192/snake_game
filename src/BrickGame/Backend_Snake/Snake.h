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

 public:
  Snake();
  ~Snake();

  void move_snake(Snake& snake, VectorDirection Direction);

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

void Contol_Key(VectorDirection* Direction, int ch);
// void Definition_Vector(VectorDirection Direction, Snake* snake);

#endif  // SNAKE_H_
