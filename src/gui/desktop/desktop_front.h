#ifndef DESKTOP_FRONT_H
#define DESKTOP_FRONT_H

#include <QPainter>
#include <QWidget>

#include "../../BrickGame/common/common.h"

class GameRenderer {
 public:
  static void RenderGrid(QPainter &painter, int cellSize);
  static void RenderPixel(QPainter &painter, int x, int y, int cellSize,
                          Qt::GlobalColor color);
  static void RenderInfo(QPainter &painter, int cellSize, int windowHeight,
                         int height, int score, int high_score, int level,
                         int speed, bool isPaused);
  static void RenderNextFigure(QPainter &painter, int cellSize,
                               int windowHeight, int **next);
};

#endif  // DESKTOP_FRONT_H
