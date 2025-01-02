#ifndef SNAKEGAMERENDER_H
#define SNAKEGAMERENDER_H

#include <QPainter>
#include <QWidget>
#include <QObject>
#include <QPaintEvent>
#include <QTimer>
#include "../../BrickGame/Backend_Snake/Snake.h"

class SnakeGameRender : public QWidget
{
    Q_OBJECT

public:
    SnakeGameRender(QWidget *parent = nullptr);
    ~SnakeGameRender();
    void Render_Field(QPainter &painter);
    void control_key(QKeyEvent *event); // Method to handle key press
    void updateGame();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override; // Override key press event

private:
    Snake snake; // Assume you have a Snake class handling snake movement
    Apple apple;
    GameParameters Parameters;
    VectorDirection Direction;
    StateGame State;
    QTimer *timer;
};

#endif // SNAKEGAMERENDER_H
