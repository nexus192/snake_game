#include "Snake.h"

HeadSnake::HeadSnake() : x{5}, y{10} {};
HeadSnake::HeadSnake(int x, int y) : x(x), y(y) {}

void HeadSnake::move_haed(VectorDirection Direction) {
  if (Direction == Up) {
    this->y--;
  } else if (Direction == Down) {
    this->y++;
  } else if (Direction == Right) {
    this->x++;
  } else if (Direction == Left) {
    this->x--;
  }
}

int HeadSnake::get_head_x() const { return this->x; }
int HeadSnake::get_head_y() const { return this->y; }

BodySnake::BodySnake() {};
BodySnake::BodySnake(int x, int y) : x_body{x}, y_body{y} {};
int BodySnake::get_body_x() const { return x_body; }
int BodySnake::get_body_y() const { return y_body; }

Snake::Snake() {
  body_snake.push_back(BodySnake(5, 9));
  body_snake.push_back(BodySnake(5, 8));
  body_snake.push_back(BodySnake(5, 7));
  body_snake.push_back(BodySnake(5, 6));
  body_length = INITIAL_BODY_LENGTH;
};

void Snake::move_snake(Snake& snake, VectorDirection Direction,
                       StateGame* State) {
  if (*State != Eating) {
    *State = Moving;
    for (int i = snake.body_length - 1; i >= 0; i--) {
      if (i == 0) {
        body_snake.front() = BodySnake(snake.get_head_x(), snake.get_head_y());
      } else {
        body_snake.at(i) = body_snake.at(i - 1);
      }
    }
    snake.move_haed(Direction);
  }
}

void Snake::eating_apple(Snake* snake, Apple& apple, VectorDirection direction,
                         StateGame* State) {
  if ((snake->get_head_x() == apple.get_x_apple()) &&
      (snake->get_head_y() == apple.get_y_apple())) {
    *State = Eating;
    snake->add_body_snake(snake, direction);
    apple.generate_apple(*snake);
  }
}
void Snake::add_body_snake(Snake* snake, VectorDirection direction) {
  body_snake.insert(body_snake.begin(),
                    BodySnake(snake->get_head_x(), snake->get_head_y()));
  snake->move_haed(direction);
  snake->body_length++;
}

int Snake::get_x_pixel_body(int pixel) const {
  return body_snake.at(pixel).get_body_x();
}
int Snake::get_y_pixel_body(int pixel) const {
  return body_snake.at(pixel).get_body_y();
}

int Snake::get_length_body() const { return body_snake.size(); }

int Apple::get_random_x() { return rand() % 10; }
int Apple::get_random_y() { return rand() % 20; }

void Apple::generate_apple(Snake& snake) {
  srand(time(NULL));
  this->x = get_random_x();
  for (int i = 0; i < 10; i++) {
    this->y = get_random_y();
  }
}

int Apple::get_x_apple() const { return this->x; }
int Apple::get_y_apple() const { return this->x; }

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
  *state_game = Moving;
}
