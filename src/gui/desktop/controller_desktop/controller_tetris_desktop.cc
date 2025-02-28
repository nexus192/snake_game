#include "controller_tetris_desktop.h"

#include <QApplication>
#include <QKeyEvent>
#include <QMessageBox>

TetrisGameRender::TetrisGameRender(QWidget *parent)
    : QWidget(parent),
      game_space(),
      game_info(),
      user_actions(Start),
      direction(Dormant),
      figur(),
      end(true),
      timer(new QTimer(this)) {
  setFocusPolicy(Qt::StrongFocus);
  init_space_game(&game_space);
  init_game_info(&game_info);
  game_info.next_figur = get_random_number();
  game_info.speed = 500;
  game_info.level = START_LEVEL;
  game_info.high_score = readNumberFromFile();

  init_figur(1, &figur);

  connect(timer, &QTimer::timeout, this, &TetrisGameRender::updateGame_T);
  timer->start(game_info.speed);
}

TetrisGameRender::~TetrisGameRender() { delete timer; }

void TetrisGameRender::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event)
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  int windowWidth = this->width();
  int windowHeight = this->height();
  int cellSize = qMin(windowWidth / WIDTH, windowHeight / HEIGHT);

  GameRenderer::RenderGrid(painter, cellSize);

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (game_space.space[i][j] == 3) {
        GameRenderer::RenderPixel(painter, j, i, cellSize, Qt::red);
      }
    }
  }

  GameRenderer::RenderNextFigure(painter, cellSize, windowHeight,
                                 game_info.next);

  int textY = 20 + 6 * cellSize + 10;

  GameRenderer::RenderInfo(painter, cellSize, this->height(), textY,
                           game_info.score, game_info.high_score,
                           game_info.level, game_info.speed, false);
}

void TetrisGameRender::updateGame_T() {
  int temp_level = game_info.level;
  print_figur_in_game_poly(&game_space, &figur);
  if (conditions_of_falling_down(figur, game_space)) {
    figur_falling_down(&figur, &game_space, &direction);
  } else {
    figur.move_triger = 1;

    find_full_line(&game_space, &game_info);
    game_level_and_speed(&game_info);

    init_figur(game_info.next_figur, &figur);
    game_info.next_figur = get_random_number();
  }

  if (game_info.level > temp_level) {
    timer->setInterval(game_info.speed);
  }

  if (check_on_game_over(game_space)) {
    timer->stop();
    GameRestart();
    return;
  }
  CleanGameInfo(&game_info);
  print_next_figur(&game_info);
  update();
}

void TetrisGameRender::GameRestart() {
  QMessageBox msgBox;
  msgBox.setText("Игра окончена!");
  msgBox.setInformativeText("Начать заново или выйти?");
  msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Close);
  msgBox.setDefaultButton(QMessageBox::Retry);

  int ret = msgBox.exec();

  if (ret == QMessageBox::Retry) {
    init_space_game(&game_space);
    init_game_info(&game_info);
    game_info.next_figur = get_random_number();
    game_info.speed = START_SPEED;
    game_info.level = START_LEVEL;
    init_figur(game_info.next_figur, &figur);
    user_actions = Start;

    timer->start(500);
    update();
  } else {
    if (game_info.score > game_info.high_score) {
      writeNumberToFile(game_info.score);
    }
    QApplication::quit();
  }
}

void TetrisGameRender::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Left &&
      traffic_permit_left(&game_space, &figur) && user_actions != Pause) {
    kill_figur(&figur, &game_space);
    MoveFigurLeft(&figur);
  } else if (event->key() == Qt::Key_Right &&
             traffic_permit_right(&game_space, &figur) &&
             user_actions != Pause) {
    kill_figur(&figur, &game_space);
    MoveFigurRight(&figur);
  } else if (event->key() == Qt::Key_Down &&
             traffic_permit_down(&game_space, &figur) &&
             user_actions != Pause) {
    kill_figur(&figur, &game_space);
    MoveFigurDown(&figur);
  } else if (event->key() == Qt::Key_Up &&
             traffic_permit_flip(&game_space, &figur) &&
             user_actions != Pause) {
    kill_figur(&figur, &game_space);
    rotation_figurs(&figur);
  } else if (event->key() == Qt::Key_Escape) {
    if (game_info.score > game_info.high_score) {
      writeNumberToFile(game_info.score);
    }
    this->close();
  } else if (event->key() == Qt::Key_P) {
    if (user_actions != Pause) {
      user_actions = Pause;
      timer->stop();
    } else if (user_actions == Pause) {
      user_actions = Start;
      timer->start(game_info.speed);
    }
  }
  print_figur_in_game_poly(&game_space, &figur);
  update();
}
