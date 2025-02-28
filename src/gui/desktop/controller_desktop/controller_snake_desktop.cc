#include "controller_snake_desktop.h"

#include <QApplication>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPainter>
#include <QRect>

using namespace s21;

SnakeGameRender::SnakeGameRender(QWidget *parent)
    : QWidget{parent},
      snake{},
      apple{},
      Parameters{},
      Direction{Down},
      State{StartGame},
      timer{nullptr} {
  apple.generate_apple(snake, &State);

  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &SnakeGameRender::updateGame);
  Parameters.speed = 500;
  Parameters.get_high_score();
  timer->start(Parameters.speed);
}

SnakeGameRender::~SnakeGameRender() {
  timer->stop();
  delete (timer);
}

void SnakeGameRender::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event)
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  int windowWidth = this->width();
  int windowHeight = this->height();
  int cellSize = qMin(windowWidth / WIDTH, windowHeight / HEIGHT);

  GameRenderer::RenderGrid(painter, cellSize);
  GameRenderer::RenderPixel(painter, apple.get_x_apple(), apple.get_y_apple(),
                            cellSize, Qt::red);
  GameRenderer::RenderPixel(painter, snake.get_head_x(), snake.get_head_y(),
                            cellSize, Qt::green);
  for (int i = 0; i < snake.get_length_body(); i++) {
    GameRenderer::RenderPixel(painter, snake.get_x_pixel_body(i),
                              snake.get_y_pixel_body(i), cellSize,
                              Qt::darkGreen);
  }
  GameRenderer::RenderInfo(painter, cellSize, windowHeight, 20,
                           snake.get_length_body() - INITIAL_BODY_LENGTH,
                           Parameters.high_score, Parameters.level,
                           Parameters.speed, false);
}

void SnakeGameRender::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Up && Direction != Down) {
    Direction = Up;
    State = Shifting;
  } else if (event->key() == Qt::Key_Down && Direction != Up) {
    Direction = Down;
    State = Shifting;
  } else if (event->key() == Qt::Key_Left && Direction != Right) {
    Direction = Left;
    State = Shifting;
  } else if (event->key() == Qt::Key_Right && Direction != Left) {
    Direction = Right;
    State = Shifting;
  } else if (event->key() == Qt::Key_Escape) {
    Parameters.set_high_score(snake.get_length_body() - INITIAL_BODY_LENGTH);
    this->close();
  } else if (event->key() == Qt::Key_P) {
    if (State != Pausa) {
      State = Pausa;
      timer->stop();
    } else if (State == Pausa) {
      State = Moving;
      timer->start(Parameters.speed);
    }
  } else if (event->key() == Qt::Key_Space) {
    State = Fast;
  }
}

void SnakeGameRender::updateGame() {
  if (State == Fast) {
    int temp_speed = 150;
    timer->setInterval(temp_speed);
    State = Moving;
  } else {
    timer->setInterval(Parameters.speed);
  }

  int temp_level = Parameters.level;
  if (State != End) {
    snake.eating_apple(&snake, apple, Direction, &State, &Parameters);
    snake.move_snake(snake, Direction, &State);
    Coliseum(snake, &State);
  }

  if (State == GameOver) {
    GameRestart();
  }

  if (Parameters.level > temp_level) {
    timer->setInterval(Parameters.speed);
  }

  update();
}

void SnakeGameRender::GameRestart() {
  timer->stop();
  QMessageBox msgBox;
  msgBox.setText("Игра окончена!");
  msgBox.setInformativeText("Начать заново или выйти?");
  msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
  msgBox.setDefaultButton(QMessageBox::Retry);

  int ret = msgBox.exec();

  if (ret == QMessageBox::Retry) {
    State = Rest;
    snake.restart_snake();
    snake.set_head_position(5, 10);
    Parameters.speed = 500;
    Parameters.level = 0;
    Parameters.set_high_score(snake.get_length_body() - INITIAL_BODY_LENGTH);
    Direction = Down;
    timer->start(Parameters.speed);
    update();
  } else {
    Parameters.set_high_score(snake.get_length_body() - INITIAL_BODY_LENGTH);
    QApplication::quit();
  }
}
