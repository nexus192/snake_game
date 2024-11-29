#include "Snake.h"

HeadSnake::HeadSnake() : x(5), y(10) {}
HeadSnake::HeadSnake(int x, int y) : x(x), y(y) {}

void HeadSnake::move_head_up() { this->y--; }
void HeadSnake::move_head_down() { this->y++; }
void HeadSnake::move_head_right() { this->x++; }
void HeadSnake::move_head_left() { this->x--; }

int HeadSnake::get_head_x() const { return this->x; }
int HeadSnake::get_head_y() const { return this->y; }

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
Snake::~Snake() { delete body_snake; }

void Snake::move_snake(Snake& snake, VectorDirection Direction,
                       StateGame* State) {
  *State = Moving;
  for (int i = 3; i >= 0; i--) {
    if (i == 0) {
      body_snake[i].set_position(snake.get_head_x(), snake.get_head_y());
    } else {
      body_snake[i] = body_snake[i - 1];
    }
  }
  if (Direction == Up) {
    snake.move_head_up();
  } else if (Direction == Down) {
    snake.move_head_down();
  } else if (Direction == Right) {
    snake.move_head_right();
  } else if (Direction == Left) {
    snake.move_head_left();
  }
}

int Snake::get_x_pixel_body(int pixel) const {
  return body_snake[pixel].get_body_x();
}
int Snake::get_y_pixel_body(int pixel) const {
  return body_snake[pixel].get_body_y();
}

void Contol_Key(VectorDirection* Direction, StateGame* State, int ch) {
  if (ch == KEY_UP && *Direction != Down) {
    *Direction = Up;
    *State = Shifting;
  } else if (ch == KEY_DOWN && *Direction != Up) {
    *Direction = Down;
    *State = Shifting;
  } else if (ch == KEY_RIGHT && *Direction != Left) {
    *Direction = Right;
    *State = Shifting;
  } else if (ch == KEY_LEFT && *Direction != Right) {
    *Direction = Left;
    *State = Shifting;
  } else if (ch == 'p') {
    // funk
    *State = Pausa;
  }
}

void Coliseum(int x_head, int y_head, StateGame* state_game) {
  if (x_head < 0 || x_head > 9) {
    *state_game = End;
  }
  if (y_head < 0 || y_head > 19) {
    *state_game = End;
  }
}

// void Definition_Vector(VectorDirection Direction, Snake* snake) {
//   if (Direction == Up) {
//     snake->move_head_up();
//   } else if (Direction == Down) {
//     snake->move_head_down();
//   } else if (Direction == Right) {
//     snake->move_head_right();
//   } else if (Direction == Left) {
//     snake->move_head_left();
//   }
// }
