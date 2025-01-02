#include "mainwindow.h"
#include "snakegamerender.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    SnakeGameRender field;
    field.resize(400, 400); // Set size to match our grid
    field.show();
 
    return app.exec();
}
