#include "snakegamerender.h"

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

  Render_Field(painter, cellSize);

  Render_Info(painter, cellSize);
}

void SnakeGameRender::Render_Field(QPainter &painter, int cellSize) {
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

  QRect appleCell(apple.get_x_apple() * cellSize,
                  apple.get_y_apple() * cellSize, cellSize, cellSize);
  painter.setBrush(Qt::red);
  painter.fillRect(appleCell, Qt::red);

  QRect snakeHeadCell(snake.get_head_x() * cellSize,
                      snake.get_head_y() * cellSize, cellSize, cellSize);
  painter.setBrush(Qt::green);
  painter.fillRect(snakeHeadCell, Qt::green);

  painter.setBrush(Qt::darkGreen);
  for (int i = 0; i < snake.get_length_body(); i++) {
    QRect bodyCell(snake.get_x_pixel_body(i) * cellSize,
                   snake.get_y_pixel_body(i) * cellSize, cellSize, cellSize);
    painter.fillRect(bodyCell, Qt::darkGreen);
  }
}

void SnakeGameRender::Render_Info(QPainter &painter, int cellSize) {
  int windowHeight = this->height();
  int textX = cellSize * WIDTH + 5;
  int fontSize = windowHeight / 25;
  QFont font;
  font.setPointSize(fontSize);
  painter.setFont(font);

  int textY = windowHeight / 10;
  std::string s =
      "Score: " + std::to_string(snake.get_length_body() - INITIAL_BODY_LENGTH);

  // Устанавливаем белый цвет для текста
  QPen whitePen(Qt::white);
  painter.setPen(whitePen);
  painter.drawText(textX, textY, s.data());

  textY += fontSize + 5;
  if (snake.get_length_body() - INITIAL_BODY_LENGTH < Parameters.high_score) {
    std::string hs = "High score: " + std::to_string(Parameters.high_score);
    painter.drawText(textX, textY, hs.data());
  } else {
    std::string hs = "High score: " + std::to_string(snake.get_length_body() -
                                                     INITIAL_BODY_LENGTH);
    painter.drawText(textX, textY, hs.data());
  }

  textY += fontSize + 5;
  std::string l = "Level: " + std::to_string(Parameters.level);
  painter.drawText(textX, textY, l.data());

  textY += fontSize + 5;
  std::string sp = "Speed: " + std::to_string(Parameters.speed);
  painter.drawText(textX, textY, sp.data());

  if (State == Pausa) {
    textY += fontSize + 5;
    painter.drawText(textX, textY, "Pause");
  }
}

void SnakeGameRender::keyPressEvent(QKeyEvent *event) { Control_Key(event); }

void SnakeGameRender::Control_Key(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_Up:
      Direction = Up;
      State = Shifting;
      break;
    case Qt::Key_Down:
      Direction = Down;
      State = Shifting;
      break;
    case Qt::Key_Left:
      Direction = Left;
      State = Shifting;
      break;
    case Qt::Key_Right:
      Direction = Right;
      State = Shifting;
      break;
    case Qt::Key_Escape:
      Parameters.set_high_score(snake.get_length_body() - INITIAL_BODY_LENGTH);
      this->close();
      break;
    case Qt::Key_P:
      if (State != Pausa) {
        State = Pausa;
        timer->stop();
      } else if (State == Pausa) {
        State = Moving;
        timer->start(Parameters.speed);
      }
      break;
    case Qt::Key_Space:
      State = Fast;
      break;
    default:
      break;
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
