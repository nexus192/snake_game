#include "tetrisgamerender.h"
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>

TetrisGameRender::TetrisGameRender(QWidget *parent)
    : QWidget(parent), user_actions(Start), timer(new QTimer(this)) {
    setFocusPolicy(Qt::StrongFocus);
    init_space_game(&game_space);
    init_game_info(&game_info);
    game_info.next_figur = get_random_number();
    game_info.speed = START_SPEED;
    game_info.level = START_LEVEL;

    init_figur(1, &figur);

    connect(timer, &QTimer::timeout, this, &TetrisGameRender::updateGame_T);
    timer->start(500);
}

TetrisGameRender::~TetrisGameRender() {
    delete timer;
}

void TetrisGameRender::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int windowWidth = this->width();
    int windowHeight = this->height();
    int cellSize = qMin(windowWidth / GAME_COL, windowHeight / GAME_ROW);

    Render_Field_T(painter, cellSize);
    Render_Info_T(painter, cellSize);
}

void TetrisGameRender::Render_Field_T(QPainter &painter, int cellSize) {
    QRect rect(0, 0, WIDTH * cellSize, HEIGHT * cellSize);
    QPen pen(Qt::black, 2);
    painter.setPen(pen);
    painter.drawRect(rect);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            QRect cell(j * cellSize, i * cellSize, cellSize, cellSize);
            painter.drawRect(cell);

            if (game_space.space[i][j] == 3) {
                painter.fillRect(cell, Qt::red);
            }
        }
    }
}

void TetrisGameRender::Render_Info_T(QPainter &painter, int cellSize) {
    int windowHeight = this->height();
    int textX = cellSize * WIDTH + 10; // Смещаем текст вправо от игрового поля
    int fontSize = windowHeight / 25;
    QFont font;
    font.setPointSize(fontSize);
    painter.setFont(font);

    int textY = 20;

    QPen whitePen(Qt::white);
    painter.setPen(whitePen);

    painter.drawText(textX, textY, "NEXT");

    // Координаты для следующей фигуры
    int nextFigureX = textX;
    int nextFigureY = textY + fontSize;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            QRect cell(nextFigureX + j * cellSize, nextFigureY + i * cellSize, cellSize, cellSize);
            painter.drawRect(cell);
           if (game_info.next[i][j] == 3) {
                painter.fillRect(cell, Qt::red);
            }
        }
    }

    textY = nextFigureY + 6 * cellSize + 10;

    painter.drawText(textX, textY, "Score: " + QString::number(game_info.score));
    textY += fontSize + 5;
    painter.drawText(textX, textY, "High score: " + QString::number(game_info.high_score));
    textY += fontSize + 5;
    painter.drawText(textX, textY, "Level: " + QString::number(game_info.level));
    textY += fontSize + 5;
    painter.drawText(textX, textY, "Speed: " + QString::number(game_info.speed));

    if (user_actions == Pause) {
        textY += fontSize + 5;
        painter.drawText(textX, textY, "Pause");
    }
}

void TetrisGameRender::updateGame_T() {
    if (conditions_of_falling_down(figur, game_space)) {
        figur_falling_down(&figur, &user_actions, &game_space);
    } else {
        figur.move_triger = 1;

        find_full_line(&game_space, &game_info);
        game_level_and_speed(&game_info);

        init_figur(game_info.next_figur, &figur);
        game_info.next_figur = get_random_number();
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
        QApplication::quit();
    }
}

void TetrisGameRender::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left && traffic_permit_left(&game_space, &figur)) {
        kill_figur(&figur, &game_space);
        figur.position[1]--;
        figur.position[3]--;
        figur.position[5]--;
        figur.position[7]--;
    } else if (event->key() == Qt::Key_Right && traffic_permit_right(&game_space, &figur)) {
        kill_figur(&figur, &game_space);
        figur.position[1]++;
        figur.position[3]++;
        figur.position[5]++;
        figur.position[7]++;
    } else if (event->key() == Qt::Key_Down && traffic_permit_down(&game_space, &figur)) {
        kill_figur(&figur, &game_space);
        figur.position[0]++;
        figur.position[2]++;
        figur.position[4]++;
        figur.position[6]++;
    } else if (event->key() == Qt::Key_Up && traffic_permit_flip(&game_space, &figur)) {
        kill_figur(&figur, &game_space);
        rotation_figurs(&figur);
    }
    // else if (Qt::Key_Escape){
    //     this->close();
    // }
    else if (Qt::Key_P) {
        if (user_actions != Pause) {
            user_actions = Pause;
            timer->stop();
        } else if(user_actions == Pause) {
            user_actions = Start;
            timer->start(game_info.speed);
        }
    }
    print_figur_in_game_poly(&game_space, &figur);
    update();
}

