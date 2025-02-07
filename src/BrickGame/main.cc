#include <termios.h>  // Linux/macOS: для getch() без Enter
#include <unistd.h>

#include <iostream>

// #include "../gui/cli/Snake/Frontend_Snake.h"
#include "../gui/cli/controler_snake.h"
#include "../gui/cli/controler_tetris.h"
// #include "../gui/cli/front_end.h"
// #include "./BackEnd_Snake/Snake.h"
// #include "./BackEnd_Tetris/back_end.h"

char mygetch() {
  struct termios oldt, newt;
  char ch;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}

int main() {
  std::cout << "=====================================\n";
  std::cout << "          WELCOME TO THE GAME        \n";
  std::cout << "=====================================\n\n";

  std::cout << "  Please pick a game:\n\n";
  std::cout << "  [S] Snake     |     [T] Tetris\n";
  std::cout << "-------------------------------------\n";
  std::cout << "  [Q] Quit\n\n";
  std::cout << "=====================================\n";

  bool isRunning = true;

  while (isRunning) {
    char userChoice = mygetch();

    switch (userChoice) {
      case 'S':
      case 's':
        std::cout << "\nStarting Snake...\n";
        usleep(1000);
        start_game();
        break;

      case 'T':
      case 't':
        std::cout << "\nStarting Tetris...\n";
        init_game();
        break;

      case 'Q':
      case 'q':
        std::cout << "\nExiting...\n";
        isRunning = false;
        break;

      default:
        std::cout << "\nInvalid input. Please press S, T, or Q.\n";
    }
  }

  return 0;
}
