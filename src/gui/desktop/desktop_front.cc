#include "desktop_front.h"

void GameRenderer::RenderGrid(QPainter &painter, int cellSize) {
  QRect rect(0, 0, WIDTH * cellSize, HEIGHT * cellSize);
  QPen pen(Qt::black, 2);
  painter.setPen(pen);
  painter.drawRect(rect);
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      QRect cell(i * cellSize, j * cellSize, cellSize, cellSize);
      painter.drawRect(cell);
    }
  }
}

void GameRenderer::RenderPixel(QPainter &painter, int x, int y, int cellSize,
                               Qt::GlobalColor color) {
  QRect pixel(x * cellSize, y * cellSize, cellSize, cellSize);
  painter.fillRect(pixel, color);
}

void GameRenderer::RenderInfo(QPainter &painter, int cellSize, int windowHeight,
                              int height, int score, int high_score, int level,
                              int speed, bool isPaused) {
  int textX = cellSize * WIDTH + 5;
  int fontSize = windowHeight / 25;
  QFont font;
  font.setPointSize(fontSize);
  painter.setFont(font);

  std::string s = "Score: " + std::to_string(score);

  // Устанавливаем белый цвет для текста
  QPen whitePen(Qt::white);
  painter.setPen(whitePen);
  painter.drawText(textX, height, s.data());

  height += fontSize + 5;
  if (score < high_score) {
    std::string hs = "High score: " + std::to_string(high_score);
    painter.drawText(textX, height, hs.data());
  } else {
    std::string hs = "High score: " + std::to_string(score);
    painter.drawText(textX, height, hs.data());
  }

  height += fontSize + 5;
  std::string l = "Level: " + std::to_string(level);
  painter.drawText(textX, height, l.data());

  height += fontSize + 5;
  std::string sp = "Speed: " + std::to_string(speed);
  painter.drawText(textX, height, sp.data());

  if (isPaused == true) {
    height += fontSize + 5;
    painter.drawText(textX, height, "Pause");
  }
}

void GameRenderer::RenderNextFigure(QPainter &painter, int cellSize,
                                    int windowHeight, int **next) {
  int textX = cellSize * WIDTH + 10;
  int fontSize = windowHeight / 25;
  QFont font;
  font.setPointSize(fontSize);
  painter.setFont(font);

  int textY = 20;

  QPen whitePen(Qt::white);
  painter.setPen(whitePen);

  painter.drawText(textX, textY, "NEXT");

  int nextFigureX = textX;
  int nextFigureY = textY + fontSize;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 6; j++) {
      QRect cell(nextFigureX + j * cellSize, nextFigureY + i * cellSize,
                 cellSize, cellSize);
      painter.drawRect(cell);
      if (next[i][j] == 3) {
        painter.fillRect(cell, Qt::red);
      }
    }
  }
}
