#ifndef TETRISGAMERENDER_H
#define TETRISGAMERENDER_H

#include <QObject>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QWidget>

#include "../../../BrickGame/tetris/tetris_backend.h"
#include "../desktop_front.h"

class TetrisGameRender : public QWidget {
  Q_OBJECT

 public:
  TetrisGameRender(QWidget *parent = nullptr);
  ~TetrisGameRender();
  void GameRestart();
  void updateGame_T();

 protected:
  void paintEvent(QPaintEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;

 private:
  Game_space game_space;
  GameInfo_t game_info;
  UserAction_t user_actions;
  VectorDirection direction;
  Figur figur;
  bool end = true;
  QTimer *timer;
};

#endif  // TETRISGAMERENDER_H
