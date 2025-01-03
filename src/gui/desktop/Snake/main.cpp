#include "mainwindow.h"
#include "snakegamerender.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow Windiw;

    Windiw.setWindowTitle("BrickGame 2.0");
    Windiw.show();

    // SnakeGameRender field;


    // field.setStyleSheet(
    //     "QWidget {"
    //     "   background-color: #18191C;"  // Цвет фона
    //     "   color: white;"                // Цвет текста
    //     "   border: 3px solid #2C2F36;"   // Цвет рамки и толщина
    //     "   border-radius: 10px;"         // Скругленные углы рамки
    //     "}");
    // field.setWindowTitle("Snake");
    // field.resize(400, 400); // Set size to match our grid
    // field.show();
 
    return app.exec();
}
