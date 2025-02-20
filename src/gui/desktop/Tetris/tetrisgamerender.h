#ifndef TETRISGAMERENDER_H
#define TETRISGAMERENDER_H

#include <QPainter>
#include <QWidget>
#include <QObject>
#include <QPaintEvent>
#include <QTimer>

#include "../../../BrickGame/tetris/back_end.h"

class TetrisGameRender : public QWidget
{
    Q_OBJECT

public:
    TetrisGameRender(QWidget *parent = nullptr);
    ~TetrisGameRender();
    void Render_Field_T(QPainter &painter, int cellSize);
    void Render_Info_T(QPainter &painter, int cellSize);
    void Control_Key_T(QKeyEvent *event); // Method to handle key press
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


#endif // TETRISGAMERENDER_H
