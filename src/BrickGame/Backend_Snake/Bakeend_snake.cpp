#include "Snake.h"

HeadSnake::HeadSnake() : x{5}, y{10} {};
HeadSnake::HeadSnake(int x, int y) : x(x), y(y) {}

void HeadSnake::move_head_up() { this->y--; }
void HeadSnake::move_head_down() { this->y++; }
void HeadSnake::move_head_right() { this->x++; }
void HeadSnake::move_head_left() { this->x--; }

int HeadSnake::get_head_x() const { return this->x; }
int HeadSnake::get_head_y() const { return this->y; }

BodySnake::BodySnake() {};
BodySnake::BodySnake(int x, int y) : x_body{x}, y_body{y} {};
void BodySnake::set_position(int x, int y) {
  this->x_body = x;
  this->y_body = y;
}
int BodySnake::get_body_x() const { return x_body; }
int BodySnake::get_body_y() const { return y_body; }

Snake::Snake() {
  body_snake.push_back(BodySnake(5, 9));
  body_snake.push_back(BodySnake(5, 8));
  body_snake.push_back(BodySnake(5, 7));
  body_snake.push_back(BodySnake(5, 6));
  body_length = INITIAL_BODY_LENGTH;
};
Snake::~Snake() {};

void Snake::move_snake(Snake& snake, VectorDirection Direction,
                       StateGame* State) {
  *State = Moving;
  for (int i = 3; i >= 0; i--) {
    if (i == 0) {
      body_snake.at(i).set_position(snake.get_head_x(), snake.get_head_y());
    } else {
      body_snake.at(i) = body_snake.at(i - 1);
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
  return body_snake.at(pixel).get_body_x();
}
int Snake::get_y_pixel_body(int pixel) const {
  return body_snake.at(pixel).get_body_y();
}

int Snake::get_length_body() const { return this->body_length; }

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

void Coliseum(Snake& snake, StateGame* state_game) {
  if (snake.get_head_x() < 0 || snake.get_head_x() > 9) {
    *state_game = End;
  }
  if (snake.get_head_y() < 0 || snake.get_head_y() > 19) {
    *state_game = End;
  }
  for (int i = 0; i < snake.get_length_body(); i++) {
    if ((snake.get_head_x() == snake.get_x_pixel_body(i)) &&
        (snake.get_head_y() == snake.get_y_pixel_body(i))) {
      *state_game = End;
    }
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
