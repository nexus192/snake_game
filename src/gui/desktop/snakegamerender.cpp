#include "snakegamerender.h"

#include <QPainter>
#include <QRect>
#include <QKeyEvent>

SnakeGameRender::SnakeGameRender(QWidget *parent) : QWidget(parent), Direction(Down), State(StartGame)
{
    apple.generate_apple(snake, &State);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SnakeGameRender::updateGame);
    timer->start(500);  // Обновление игры каждую 1/10 секунды
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

    Render_Field(painter);

    QRect appleCell(apple.get_x_apple() * 20, apple.get_y_apple() * 20, 20, 20);
    painter.setBrush(Qt::red);
    painter.fillRect(appleCell, Qt::red);

    QRect snakeHeadCell(snake.get_head_x() * 20, snake.get_head_y() * 20, 20, 20);
    painter.setBrush(Qt::green);
    painter.fillRect(snakeHeadCell, Qt::green);

    painter.setBrush(Qt::darkGreen);
    for (int i = 0; i < snake.get_length_body(); i++) {
        QRect bodyCell(snake.get_x_pixel_body(i) * 20, snake.get_y_pixel_body(i) * 20, 20, 20);
        painter.fillRect(bodyCell, Qt::darkGreen);
    }
    Parameters.set_high_score(snake.get_length_body() - INITIAL_BODY_LENGTH);

    QFont font;
    font.setPointSize(14);
    painter.setFont(font);
    std::string s = "Score: " + std::to_string(snake.get_length_body() - INITIAL_BODY_LENGTH);
    painter.drawText(205, 55, s.data());
    std::string hs = "High score: " + std::to_string(Parameters.high_score);
    painter.drawText(205, 85, hs.data());
    std::string l = "Level: " + std::to_string(Parameters.level);
    painter.drawText(205, 115, l.data());
    std::string sp = "Speed: " + std::to_string(Parameters.speed);
    painter.drawText(205, 145, sp.data());
    if (State == Pausa) {
        painter.drawText(205, 175, "Pause");
    }

}

void SnakeGameRender::Render_Field(QPainter &painter)
{
    QRect rect(0, 0, 200, 400);

    QPen pen(Qt::black, 2);
    painter.setPen(pen);
    painter.drawRect(rect);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            QRect cell(i * 20, j * 20, 20, 20);
            painter.drawRect(cell);
        }
    }
}

void SnakeGameRender::keyPressEvent(QKeyEvent *event)
{
    // Call the control_key method when a key is pressed
    control_key(event);
}

void SnakeGameRender::control_key(QKeyEvent *event)
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
    case Qt::Key_W:
        Direction = Up;
        State = Shifting;
        break;
    case Qt::Key_S:
        Direction = Up;
        State = Shifting;
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
