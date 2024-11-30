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
  for (int i = snake.body_length - 1; i >= 0; i--) {
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

void Snake::eating_apple(Snake* snake, Apple& apple,
                         VectorDirection direction) {
  if ((snake->get_head_x() == apple.get_x_apple()) &&
      (snake->get_head_y() == apple.get_y_apple())) {
    snake->add_body_snake(snake, direction);
    apple.generate_apple(*snake);
  }
}
void Snake::add_body_snake(Snake* snake, VectorDirection direction) {
  body_snake.insert(body_snake.begin(),
                    BodySnake(snake->get_head_x(), snake->get_head_y()));
  if (direction == Up) {
    snake->head_snake.move_head_up();
  } else if (direction == Down) {
    snake->head_snake.move_head_down();
  } else if (direction == Left) {
    snake->head_snake.move_head_left();
  } else {
    snake->head_snake.move_head_right();
  }
  snake->body_length++;
}

int Snake::get_x_pixel_body(int pixel) const {
  return body_snake.at(pixel).get_body_x();
}
int Snake::get_y_pixel_body(int pixel) const {
  return body_snake.at(pixel).get_body_y();
}

int Snake::get_length_body() const { return body_snake.size(); }

void Apple::generate_apple(Snake& snake) {
  bool check_on_correct = false;
  int counter = 0;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist_x(0, 9);
  std::uniform_int_distribution<> dist_y(0, 19);

  while (check_on_correct == false) {
    this->x = dist_x(gen);
    this->y = dist_y(gen);
    for (int i = 0; i < snake.get_length_body(); i++) {
      if ((this->x != snake.get_x_pixel_body(i)) &&
          (this->y != snake.get_y_pixel_body(i))) {
        counter++;
      }
    }
    if (counter == snake.get_length_body()) {
      if ((this->x != snake.get_head_x()) && (this->y != snake.get_head_y())) {
        check_on_correct = true;
      }
    }
    counter = 0;
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
