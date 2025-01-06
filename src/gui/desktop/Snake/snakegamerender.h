#ifndef SNAKEGAMERENDER_H
#define SNAKEGAMERENDER_H

#include <QPainter>
#include <QWidget>
#include <QObject>
#include <QPaintEvent>
#include <QTimer>
#include "../../../BrickGame/BackEnd_Snake/Snake.h"

class SnakeGameRender : public QWidget
{
    Q_OBJECT

public:
    SnakeGameRender(QWidget *parent = nullptr);
    ~SnakeGameRender();
    void Render_Field(QPainter &painter, int cellSize);
    void Render_Info(QPainter &painter, int cellSize);
    void Control_Key(QKeyEvent *event); // Method to handle key press
    void updateGame();

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

#endif // SNAKEGAMERENDER_H
