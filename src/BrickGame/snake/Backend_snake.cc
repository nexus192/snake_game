#include "Snake.h"

namespace s21 {

HeadSnake::HeadSnake()
    : x{START_POSITION_HEAD_SNAKE_X}, y{START_POSITION_HEAD_SNAKE_Y} {};
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

void HeadSnake::set_head_position(int x_, int y_) {
  this->x = x_;
  this->y = y_;
}

BodySnake::BodySnake() {};
BodySnake::BodySnake(int x, int y) : x_body{x}, y_body{y} {};
int BodySnake::get_body_x() const { return x_body; }
int BodySnake::get_body_y() const { return y_body; }

Snake::Snake() {
  body_snake.push_back(
      BodySnake(START_POSITION_BODY_SNAKE_X, START_POSITION_BODY_SNAKE_Y));
  body_snake.push_back(
      BodySnake(START_POSITION_BODY_SNAKE_X, START_POSITION_BODY_SNAKE_Y - 1));
  body_snake.push_back(
      BodySnake(START_POSITION_BODY_SNAKE_X, START_POSITION_BODY_SNAKE_Y - 2));
  body_snake.push_back(
      BodySnake(START_POSITION_BODY_SNAKE_X, START_POSITION_BODY_SNAKE_Y - 3));
  body_length = INITIAL_BODY_LENGTH;
};

void Snake::move_snake(Snake& snake, VectorDirection Direction,
                       StateGame* State) {
  if (*State != Spawn) {
    for (int i = snake.body_length - 1; i >= 0; i--) {
      if (i == 0) {
        body_snake.front() = BodySnake(snake.get_head_x(), snake.get_head_y());
      } else {
        body_snake.at(i) = body_snake.at(i - 1);
      }
    }
    snake.move_haed(Direction);
  }
  *State = Moving;
}

void Snake::eating_apple(Snake* snake, Apple& apple, VectorDirection direction,
                         StateGame* State, GameParameters* Parameters) {
  if ((snake->get_head_x() == apple.get_x_apple()) &&
      (snake->get_head_y() == apple.get_y_apple())) {
    *State = Eating;
    snake->add_body_snake(snake, direction);
    apple.generate_apple(*snake, State);
    Parameters->parameter_changes(snake->get_length_body() -
                                  INITIAL_BODY_LENGTH);
  }
}

void Snake::add_body_snake(Snake* snake, VectorDirection direction) {
  body_snake.insert(body_snake.begin(),
                    BodySnake(snake->get_head_x(), snake->get_head_y()));
  snake->move_haed(direction);
  snake->body_length++;
}

void Snake::restart_snake() {
  this->body_snake.clear();
  this->body_snake.push_back(
      BodySnake(START_POSITION_BODY_SNAKE_X, START_POSITION_BODY_SNAKE_Y));
  this->body_snake.push_back(
      BodySnake(START_POSITION_BODY_SNAKE_X, START_POSITION_BODY_SNAKE_Y - 1));
  this->body_snake.push_back(
      BodySnake(START_POSITION_BODY_SNAKE_X, START_POSITION_BODY_SNAKE_Y - 2));
  this->body_snake.push_back(
      BodySnake(START_POSITION_BODY_SNAKE_X, START_POSITION_BODY_SNAKE_Y - 3));
  this->body_length = INITIAL_BODY_LENGTH;
}

int Snake::get_x_pixel_body(int pixel) const {
  return body_snake.at(pixel).get_body_x();
}
int Snake::get_y_pixel_body(int pixel) const {
  return body_snake.at(pixel).get_body_y();
}

int Snake::get_length_body() const { return body_snake.size(); }

void Apple::generate_apple(Snake& snake, StateGame* State) {
  *State = Spawn;
  std::mt19937 gen(std::random_device{}());
  std::uniform_int_distribution<int> dist_x(0, 9);
  std::uniform_int_distribution<int> dist_y(0, 19);

  bool apple_generated = false;

  while (!apple_generated) {
    this->x = dist_x(gen);
    this->y = dist_y(gen);

    apple_generated = true;
    for (int i = 0; i < snake.get_length_body(); i++) {
      if (this->x == snake.get_x_pixel_body(i) &&
          this->y == snake.get_y_pixel_body(i)) {
        apple_generated = false;
        break;
      }
    }
    if (this->x == snake.get_head_x() && this->y == snake.get_head_y()) {
      apple_generated = false;
    }
  }
}

int Apple::get_x_apple() const { return this->x; }
int Apple::get_y_apple() const { return this->y; }

GameParameters::GameParameters() {
  speed = 500000;
  level = START_LEVEL;
  high_score = 0;
  get_high_score();
};

void GameParameters::get_high_score() {
  std::ifstream inputFile("./src/game_state/score_snake.txt");
  inputFile >> high_score;
  inputFile.close();
}

void GameParameters::set_high_score(int score) {
  if (score > high_score) {
    std::ofstream outputFile("./src/game_state/score_snake.txt");
    outputFile << score;
    outputFile.close();
  }
}

void GameParameters::parameter_changes(int score) {
  if ((score % LEVEL_STEP) == 0 && level != MAX_LEVEL) {
    level++;
    speed -= speed * SPEED_REDUCTION_PERETGE;
  }
}

void Coliseum(Snake& snake, StateGame* state_game) {
  if (snake.get_head_x() < 0 || snake.get_head_x() > 9) {
    *state_game = GameOver;
  }
  if (snake.get_head_y() < 0 || snake.get_head_y() > 19) {
    *state_game = GameOver;
  }
  for (int i = 0; i < snake.get_length_body(); i++) {
    if ((snake.get_head_x() == snake.get_x_pixel_body(i)) &&
        (snake.get_head_y() == snake.get_y_pixel_body(i))) {
      *state_game = GameOver;
    }
  }
}

}  // namespace s21
