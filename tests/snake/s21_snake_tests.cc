#include <gtest/gtest.h>

#include "../../src/BrickGame/snake/Snake.h"

using namespace s21;

TEST(HeadSnakeTest, DefaultConstructor) {
  HeadSnake head;
  EXPECT_EQ(head.get_head_x(), 5);
  EXPECT_EQ(head.get_head_y(), 10);
}

TEST(HeadSnakeTest, ParameterizedConstructor) {
  HeadSnake head(3, 7);
  EXPECT_EQ(head.get_head_x(), 3);
  EXPECT_EQ(head.get_head_y(), 7);
}

TEST(HeadSnakeTest, MoveHead) {
  HeadSnake head;
  head.move_haed(Up);
  EXPECT_EQ(head.get_head_y(), 9);
  head.move_haed(Down);
  EXPECT_EQ(head.get_head_y(), 10);
  head.move_haed(Right);
  EXPECT_EQ(head.get_head_x(), 6);
  head.move_haed(Left);
  EXPECT_EQ(head.get_head_x(), 5);
}

TEST(HeadSnakeTest, SetHeadPosition) {
  HeadSnake head;
  head.set_head_position(2, 8);
  EXPECT_EQ(head.get_head_x(), 2);
  EXPECT_EQ(head.get_head_y(), 8);
}

TEST(BodySnakeTest, Constructor) {
  BodySnake body(4, 6);
  EXPECT_EQ(body.get_body_x(), 4);
  EXPECT_EQ(body.get_body_y(), 6);
}

TEST(SnakeTest, DefaultConstructor) {
  Snake snake;
  EXPECT_EQ(snake.get_length_body(), 4);
  EXPECT_EQ(snake.get_x_pixel_body(0), 5);
  EXPECT_EQ(snake.get_y_pixel_body(0), 9);
}

TEST(SnakeTest, MoveSnake) {
  Snake snake;
  StateGame state = Moving;
  snake.move_snake(snake, Up, &state);
  EXPECT_EQ(snake.get_head_y(), 9);
  snake.move_snake(snake, Right, &state);
  EXPECT_EQ(snake.get_head_x(), 6);
}

TEST(SnakeTest, AddBodySnake) {
  Snake snake;
  int old_length = snake.get_length_body();
  snake.add_body_snake(&snake, Down);
  EXPECT_EQ(snake.get_length_body(), old_length + 1);
}

TEST(SnakeTest, RestartSnake) {
  Snake snake;
  snake.restart_snake();
  EXPECT_EQ(snake.get_length_body(), 4);
  EXPECT_EQ(snake.get_x_pixel_body(0), 5);
  EXPECT_EQ(snake.get_y_pixel_body(0), 9);
}

TEST(AppleTest, GenerateApple) {
  Snake snake;
  Apple apple;
  StateGame state;
  apple.generate_apple(snake, &state);
  EXPECT_GE(apple.get_x_apple(), 0);
  EXPECT_LE(apple.get_x_apple(), 9);
  EXPECT_GE(apple.get_y_apple(), 0);
  EXPECT_LE(apple.get_y_apple(), 19);
}

TEST(ColiseumTest, CollisionDetection) {
  Snake snake;
  StateGame state = Moving;
  snake.set_head_position(-1, 5);
  Coliseum(snake, &state);
  EXPECT_EQ(state, GameOver);

  state = Moving;
  snake.set_head_position(5, 20);
  Coliseum(snake, &state);
  EXPECT_EQ(state, GameOver);
}

TEST(SnakeTest, EatingApple) {
  Snake snake;
  Apple apple;
  GameParameters parameters;
  StateGame state = Moving;
  VectorDirection direction = Right;

    apple.generate_apple(snake, &state);

  // Устанавливаем положение головы змейки и яблока одинаковыми
  snake.set_head_position(apple.get_x_apple(), apple.get_y_apple());

  // Длина змейки до еды
  int initial_length = snake.get_length_body();

  // Вызываем функцию
  snake.eating_apple(&snake, apple, direction, &state, &parameters);

  for (int i = 0; i < 500; i++) {
    apple.generate_apple(snake, &state);
  }

  // Проверяем, что длина змейки увеличилась
  EXPECT_EQ(snake.get_length_body(), initial_length + 1);
}
