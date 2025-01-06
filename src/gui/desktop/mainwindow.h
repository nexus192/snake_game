#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../BrickGame/BackEnd_Snake/Snake.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Push_Button_Tetris();
    void Push_Button_Snake();
    void Push_Button_Exit();

private:
    Ui::MainWindow *ui;
    void Spatial_Button();
};
#endif // MAINWINDOW_H
