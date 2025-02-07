#include "snakegamerender.h"

#include <QPainter>
#include <QRect>
#include <QKeyEvent>

using namespace s21;

SnakeGameRender::SnakeGameRender(QWidget *parent) : QWidget(parent), Direction(Down), State(StartGame)
{
    apple.generate_apple(snake, &State);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SnakeGameRender::updateGame);
    Parameters.speed = 500;
    timer->start(Parameters.speed);
}

SnakeGameRender::~SnakeGameRender()
{
    delete(timer);
}

void SnakeGameRender::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int windowWidth = this->width();
    int windowHeight = this->height();
    int cellSize = qMin(windowWidth / WIDTH, windowHeight / HEIGHT);

    Render_Field(painter, cellSize);

    Render_Info(painter, cellSize);

}

void SnakeGameRender::Render_Field(QPainter &painter, int cellSize)
{
    QRect rect(0, 0, WIDTH * cellSize, HEIGHT * cellSize);
    QPen pen(Qt::black, 2);
    painter.setPen(pen);
    painter.drawRect(rect);

    // Рисуем клетки поля
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            QRect cell(i * cellSize, j * cellSize, cellSize, cellSize);
            painter.drawRect(cell);
        }
    }

    // Рисуем яблоко (позиция яблока в клетках с учётом изменения размера)
    QRect appleCell(apple.get_x_apple() * cellSize, apple.get_y_apple() * cellSize, cellSize, cellSize);
    painter.setBrush(Qt::red);
    painter.fillRect(appleCell, Qt::red);

    // Рисуем голову змейки (позиция головы змейки в клетках с учётом изменения размера)
    QRect snakeHeadCell(snake.get_head_x() * cellSize, snake.get_head_y() * cellSize, cellSize, cellSize);
    painter.setBrush(Qt::green);
    painter.fillRect(snakeHeadCell, Qt::green);

    // Рисуем тело змейки (позиции тела змейки в клетках с учётом изменения размера)
    painter.setBrush(Qt::darkGreen);
    for (int i = 0; i < snake.get_length_body(); i++) {
        QRect bodyCell(snake.get_x_pixel_body(i) * cellSize, snake.get_y_pixel_body(i) * cellSize, cellSize, cellSize);
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
    std::string s = "Score: " + std::to_string(snake.get_length_body() - INITIAL_BODY_LENGTH);

    // Устанавливаем белый цвет для текста
    QPen whitePen(Qt::white);
    painter.setPen(whitePen);
    painter.drawText(textX, textY, s.data());

    textY += fontSize + 5;
    std::string hs = "High score: " + std::to_string(Parameters.high_score);
    painter.drawText(textX, textY, hs.data());

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


void SnakeGameRender::keyPressEvent(QKeyEvent *event)
{
    Control_Key(event);
}

void SnakeGameRender::Control_Key(QKeyEvent *event)
{
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
        this->close();
        break;
    case Qt::Key_P:
        if (State != Pausa) {
            State = Pausa;
            timer->stop();
        } else if(State == Pausa) {
            timer->start(Parameters.speed);
        }
        break;
    case Qt::Key_A:
        Direction = Up;
        State = Shifting;
        break;
    case Qt::Key_D:
        Direction = Up;
        State = Shifting;
        break;
    default:
        break;
    }
}

void SnakeGameRender::updateGame()
{
    if (State != End) {
        snake.eating_apple(&snake, apple, Direction, &State, &Parameters);
        snake.move_snake(snake, Direction, &State);
        Coliseum(snake, &State);
    }
    Parameters.set_high_score(snake.get_length_body() - INITIAL_BODY_LENGTH);

    update();
}
