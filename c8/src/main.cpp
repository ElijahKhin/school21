#include <QApplication>

#include "viewer3d.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  Viewer3D w;
  w.show();
  return a.exec();
}
