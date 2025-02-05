#include "tetrisgamerender.h"

#include <QPainter>
#include <QRect>
#include <QKeyEvent>

TetrisGameRender::TetrisGameRender(QWidget *parent) : QWidget(parent), game_space{0}, game_info{0}, user_actions(Start) {
    figur = {{1, 5, 2, 5, 2, 6, 2, 7}, 2, 0, 0, 3};
    init_space_game(&game_space);
    get_figur(&figur, game_info);
    // game_info.next_figur = get_random_number();
    game_info.speed = START_SPEED;
    game_info.level = START_LEVEL;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TetrisGameRender::updateGame_T);
    game_info.speed = 500;
    timer->start(game_info.speed);
}

TetrisGameRender::~TetrisGameRender() {
    delete(timer);
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
    QRect rect(0, 0, GAME_COL * cellSize, GAME_ROW * cellSize);
    QPen pen(Qt::black, 2);
    painter.setPen(pen);
    painter.drawRect(rect);

    // Рисуем клетки поля
    for (int i = 0; i < GAME_COL + 2; i++) {
        for (int j = 0; j < GAME_ROW + 2; j++) {
            QRect cell(i * cellSize, j * cellSize, cellSize, cellSize);
            painter.drawRect(cell);
        }
    }

    for (int i = 0; i < GAME_COL + 2; i++) {
        for (int j = 0; j < GAME_ROW + 2; j++) {
            if(i == 0 || i == GAME_COL - 1){
                QRect cell(i * cellSize, j * cellSize, cellSize, cellSize);
                painter.fillRect(cell, Qt::white);
            }
            if(j == 0 || j == GAME_ROW -1){
                QRect cell(i * cellSize, j * cellSize, cellSize, cellSize);
                painter.fillRect(cell, Qt::white);
            }
        }
    }

    QRect pixelCell_1(figur.position[1] * cellSize, figur.position[0] * cellSize, cellSize, cellSize);
    painter.setBrush(Qt::red);
    painter.fillRect(pixelCell_1, Qt::red);

    QRect pixelCell_2(figur.position[3] * cellSize, figur.position[2] * cellSize, cellSize, cellSize);
    painter.setBrush(Qt::red);
    painter.fillRect(pixelCell_2, Qt::red);

    QRect pixelCell_3(figur.position[5] * cellSize, figur.position[4] * cellSize, cellSize, cellSize);
    painter.setBrush(Qt::red);
    painter.fillRect(pixelCell_3, Qt::red);

    QRect pixelCell_4(figur.position[7] * cellSize, figur.position[6] * cellSize, cellSize, cellSize);
    painter.setBrush(Qt::red);
    painter.fillRect(pixelCell_4, Qt::red);

}

void TetrisGameRender::Render_Info_T(QPainter &painter, int cellSize) {
    int windowHeight = this->height();
    int textX = cellSize * GAME_COL + 45;
    int fontSize = windowHeight / 25;
    QFont font;
    font.setPointSize(fontSize);
    painter.setFont(font);

    int textY = windowHeight / 10;

    // Устанавливаем белый цвет для текста
    QPen whitePen(Qt::white);
    painter.setPen(whitePen);
    // painter.drawText(textX, textY, s.data());

    textY += fontSize + 5;
    std::string hs = "x_0 " + std::to_string(figur.position[0]);
    painter.drawText(textX, textY, hs.data());

    textY += fontSize + 5;
    std::string l = "y_0 " + std::to_string(figur.position[1]);
    painter.drawText(textX, textY, l.data());

    textY += fontSize + 5;
    std::string hl = "x_1 " + std::to_string(figur.position[2]);
    painter.drawText(textX, textY, hl.data());

    textY += fontSize + 5;
    std::string ll = "y_1 " + std::to_string(figur.position[3]);
    painter.drawText(textX, textY, ll.data());

    textY += fontSize + 5;
    std::string hsl = "x_2 " + std::to_string(figur.position[4]);
    painter.drawText(textX, textY, hsl.data());

    textY += fontSize + 5;
    std::string lll = "y_2 " + std::to_string(figur.position[5]);
    painter.drawText(textX, textY, lll.data());

    textY += fontSize + 5;
    std::string hsll = "x_3 " + std::to_string(figur.position[6]);
    painter.drawText(textX, textY, hsll.data());

    textY += fontSize + 5;
    std::string llll = "y_3 " + std::to_string(figur.position[7]);
    painter.drawText(textX, textY, llll.data());
}

void TetrisGameRender::keyPressEvent(QKeyEvent *event) {
    Control_Key_T(event);
}

void TetrisGameRender::Control_Key_T(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Up:
        if (traffic_permit_flip(&game_space, &figur) == true) {
            kill_figur(&figur, &game_space);
            rotation_figurs(&figur);
            print_figur_in_game_poly(&game_space, &figur);
        }
        break;
    case Qt::Key_Down:
        if(traffic_permit_down(&game_space, &figur) == true){
            kill_figur(&figur, &game_space);
            figur.position[0]++;
            figur.position[2]++;
            figur.position[4]++;
            figur.position[6]++;
            print_figur_in_game_poly(&game_space, &figur);
        }
        break;
    case Qt::Key_Right:
        if(traffic_permit_right(&game_space, &figur) == true){
            kill_figur(&figur, &game_space);
            figur.position[1]++;
            figur.position[3]++;
            figur.position[5]++;
            figur.position[7]++;
            print_figur_in_game_poly(&game_space, &figur);
        }
        break;
    case Qt::Key_Left:
        if(traffic_permit_left(&game_space, &figur) == true){
            kill_figur(&figur, &game_space);
            figur.position[1]--;
            figur.position[3]--;
            figur.position[5]--;
            figur.position[7]--;
            print_figur_in_game_poly(&game_space, &figur);
        }
        break;

    }
}

void TetrisGameRender::updateGame_T() {

    if(figur.move_triger == 1) {
        get_figur(&figur, game_info);
    }
    // game_info.next_figur = get_random_number();


    if (conditions_of_falling_down(figur, game_space) == true) {
        // print_figur_in_game_poly(&game_space, &figur);
        figur_falling_down(&figur);
    //     remove_trash_on_poly(&figur, &game_space);
    }
    else {
        figur.move_triger = 1;
    }

    find_full_line(&game_space, &game_info);
    game_level_and_speed(&game_info);
    if (check_on_game_over(game_space) == false) {
        user_actions = Game_over;
    }

        update();
}

