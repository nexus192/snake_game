#include <QApplication>

#include "Snake/snakegamerender.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainWindow Windiw;
  Windiw.setWindowTitle("BrickGame 2.0");
  Windiw.show();

  return app.exec();
}
