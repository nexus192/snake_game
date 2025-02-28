#include <QApplication>

#include "./gui/desktop/controller_desktop/controller_snake_desktop.h"
#include "./gui/desktop/controller_desktop/controller_tetris_desktop.h"
#include "./gui/desktop/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainWindow Windiw;
  Windiw.setWindowTitle("BrickGame 2.0");
  Windiw.show();

  return app.exec();
}
