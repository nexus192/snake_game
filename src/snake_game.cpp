#include <ncurses.h>

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <utility>

#define WIDTH 10
#define HEIGHT 20

typedef enum VectorDirection { Up, Down, Right, Left } VectorDirection;

class BodySnake;
class HeadSnake;

typedef struct position_elements_body_snake {
  int x;
  int y;
} position_elements_body_snake;

class HeadSnake {
  friend BodySnake;

 private:
  int x;
  int y;

 public:
  HeadSnake() : x(5), y(10) {}
  HeadSnake(int x, int y) : x(x), y(y) {}

  void move_point_up() { this->y--; }
  void move_point_down() { this->y++; }
  void move_point_right() { this->x++; }
  void move_point_left() { this->x--; }

  int get_point_x() const { return this->x; }
  int get_point_y() const { return this->y; }
};

class BodySnake {
 private:
  position_elements_body_snake* body_snake;
  HeadSnake head;

 public:
  BodySnake(HeadSnake& head) : head(head) {
    body_snake = new position_elements_body_snake[4];
    body_snake[0].x = 5;
    body_snake[0].y = 9;
    body_snake[1].x = 5;
    body_snake[1].y = 8;
    body_snake[2].x = 5;
    body_snake[2].y = 7;
    body_snake[3].x = 5;
    body_snake[3].y = 6;
  }

  void move_snake(HeadSnake head_other) {
    for (int i = 3; i >= 0; i--) {
      if (i == 0) {
        body_snake[i].x = head_other.x;
        body_snake[i].y = head_other.y;
      } else {
        body_snake[i] = body_snake[i - 1];
      }
    }
  }

  int get_x_pixel_body(int pixel) const { return body_snake[pixel].x; }
  int get_y_pixel_body(int pixel) const { return body_snake[pixel].y; }
};

void showField(WINDOW* field, HeadSnake& head_snake, BodySnake& body_snake) {
  werase(field);
  box(field, 0, 0);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (i == head_snake.get_point_y() && j == head_snake.get_point_x()) {
        wattron(field, COLOR_PAIR(1));
        mvwaddch(field, i + 1, j * 2 + 1, ' ');
        mvwaddch(field, i + 1, j * 2 + 2, ' ');
        wattroff(field, COLOR_PAIR(1));
      }
    }
  }

  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < HEIGHT; i++) {
      for (int j = 0; j < WIDTH; j++) {
        if (i == body_snake.get_y_pixel_body(k) &&
            j == body_snake.get_x_pixel_body(k)) {
          wattron(field, COLOR_PAIR(1));
          mvwaddch(field, i + 1, j * 2 + 1, ' ');
          mvwaddch(field, i + 1, j * 2 + 2, ' ');
          wattroff(field, COLOR_PAIR(1));
        }
      }
    }
  }
  wrefresh(field);
}

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, true);
  timeout(50);
  curs_set(0);
  WINDOW* field = newwin(22, 22, 0, 0);
  keypad(field, true);
  nodelay(field, 1);  // что бы программа не ожидала ввода
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_WHITE, COLOR_WHITE);
  int ch;
  HeadSnake Head_Snake(5, 10);
  BodySnake Body_Snake(Head_Snake);
  VectorDirection Direction = Down;

  while ((ch = wgetch(field)) != 'q') {
    if (ch == KEY_UP) {
      if (ch != KEY_DOWN) {
        Direction = Up;
      }
    } else if (ch == KEY_DOWN) {
      if (ch != KEY_UP) {
        Direction = Down;
      }
    } else if (ch == KEY_RIGHT) {
      if (ch != KEY_LEFT) {
        Direction = Right;
      }
    } else if (ch == KEY_LEFT) {
      if (ch != KEY_RIGHT) {
        Direction = Left;
      }
    }

    if (Direction == Up) {
      Head_Snake.move_point_up();
    } else if (Direction == Down) {
      Head_Snake.move_point_down();
    } else if (Direction == Right) {
      Head_Snake.move_point_right();
    } else if (Direction == Left) {
      Head_Snake.move_point_left();
    }
    Body_Snake.move_snake(Head_Snake);
    showField(field, Head_Snake, Body_Snake);
    napms(700);
  }
  endwin();
}
