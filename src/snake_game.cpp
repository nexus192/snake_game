#include <ncurses.h>

#define WIDTH 10
#define HEIGTH 20

typedef enum VectorDirection { Up, Down, Right, Left } VectorDirection;

class Snake {
 private:
  class BodySnake {
   private:
    int x_body;
    int y_body;

   public:
    BodySnake(int x, int y) {
      this->x_body = x;
      this->y_body = y;
    };
  };

 public:
  class HeadSnake {
   private:
    int x;
    int y;

   public:
    HeadSnake(int x, int y) {
      this->x = x;
      this->y = y;
    };
    void move_point_up() { this->y--; }
    void move_point_down() { this->y++; }
    void move_point_right() { this->x++; }
    void move_point_left() { this->x--; }
    int get_point_x() { return this->x; }
    int get_point_y() { return this->y; }
  };

  HeadSnake *getHead_x() { return; }
};

void showField(WINDOW *field, Snake::HeadSnake Head_Snake) {
  werase(field);
  box(field, 0, 0);
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      if (i == Head_Snake.get_point_y() && j == Head_Snake.get_point_x()) {
        wattron(field, COLOR_PAIR(1));
        mvwaddch(field, i + 1, j * 2 + 1, ' ');
        mvwaddch(field, i + 1, j * 2 + 2, ' ');
        wattroff(field, COLOR_PAIR(1));
      }
    }
  }
  wrefresh(field);
};

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, true);
  timeout(50);
  curs_set(0);
  WINDOW *field = newwin(22, 22, 0, 0);
  keypad(field, true);
  nodelay(field, 1);  // что бы программа не ожидала ввода
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  init_pair(2, COLOR_WHITE, COLOR_WHITE);
  int ch;
  Snake::HeadSnake Head_Snake(5, 10);
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
    showField(field, Head_Snake);
    napms(700);
  }
  endwin();
}
