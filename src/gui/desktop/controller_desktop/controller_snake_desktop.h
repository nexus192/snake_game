#ifndef SNAKEGAMERENDER_H
#define SNAKEGAMERENDER_H

#include <QObject>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QWidget>

#include "../../../BrickGame/snake/Snake.h"
#include "../desktop_front.h"

using namespace s21;

#define FAST_SPEED 150

class SnakeGameRender : public QWidget {
  Q_OBJECT

 public:
  SnakeGameRender(QWidget *parent = nullptr);
  ~SnakeGameRender();
  void Render_Field(QPainter &painter, int cellSize);
  void Render_Info(QPainter &painter, int cellSize);
  void updateGame();
  void GameRestart();

 protected:
  void paintEvent(QPaintEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;

 private:
  Snake snake;
  Apple apple;
  GameParameters Parameters;
  VectorDirection Direction;
  StateGame State;
  QTimer *timer;
};

#endif  // SNAKEGAMERENDER_H
