#include "Snake.h"

HeadSnake::HeadSnake() : x(5), y(10) {}
HeadSnake::HeadSnake(int x, int y) : x(x), y(y) {}

void HeadSnake::move_point_up() { this->y--; }
void HeadSnake::move_point_down() { this->y++; }
void HeadSnake::move_point_right() { this->x++; }
void HeadSnake::move_point_left() { this->x--; }

int HeadSnake::get_point_x() const { return this->x; }
int HeadSnake::get_point_y() const { return this->y; }

void BodySnake::set_position(int x, int y) {
  this->x_body = x;
  this->y_body = y;
}
int BodySnake::get_body_x() { return x_body; }
int BodySnake::get_body_y() { return y_body; }

Snake::Snake() {
  body_snake = new BodySnake[4];
  body_snake[0].set_position(5, 9);
  body_snake[1].set_position(5, 8);
  body_snake[2].set_position(5, 7);
  body_snake[3].set_position(5, 6);
};

void Snake::move_snake(HeadSnake head_other) {
  for (int i = 3; i >= 0; i--) {
    if (i == 0) {
      body_snake[i].set_position(head_other.x, head_other.y);
    } else {
      body_snake[i] = body_snake[i - 1];
    }
  }
}

int Snake::get_x_pixel_body(int pixel) const {
  return body_snake[pixel].get_body_x();
}
int Snake::get_y_pixel_body(int pixel) const {
  return body_snake[pixel].get_body_y();
}

void Contol_Key(VectorDirection* Direction, int ch) {
  if (ch == KEY_UP) {
    if (ch != KEY_DOWN) {
      *Direction = Up;
    }
  } else if (ch == KEY_DOWN) {
    if (ch != KEY_UP) {
      *Direction = Down;
    }
  } else if (ch == KEY_RIGHT) {
    if (ch != KEY_LEFT) {
      *Direction = Right;
    }
  } else if (ch == KEY_LEFT) {
    if (ch != KEY_RIGHT) {
      *Direction = Left;
    }
  }
}
