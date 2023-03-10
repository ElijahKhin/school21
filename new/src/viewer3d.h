#ifndef VIEWER3D_H
#define VIEWER3D_H
#include <QMainWindow>
#include <iostream>
#include "./parser/core.h"
#include "QtGifImage-master/src/gifimage/qgifimage.h"
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class Viewer3D;
}
QT_END_NAMESPACE

class Viewer3D : public QMainWindow {
  Q_OBJECT

 public:
  explicit Viewer3D(QWidget *parent = nullptr);
  ~Viewer3D() override;

  QString sfileName;

 private:
  Ui::Viewer3D *ui;
  int startTime, tmpTime;
  float timePrint;
  const int gifFps = 10, gifLength = 5;
  QTimer* timer;
  QGifImage* gif;

 protected:
  object3_t *current_obj3 = nullptr;
  bool ignore_event = false;

  void setEnableTools(bool state);

  void loadSettings();
  void saveSettings();

 protected slots:
  void load_file();

  void obj3_move();
  void obj3_rotate();
  void obj3_scale();

  void updateShift(QPoint shift);
  void updateRotate(QPoint shift);
  void updateScale(int y);

  void changeBackgroundColor();

  void changePerspective();

  void changeTypeEdges(int index_type);
  void changeSizeEdges(int shift);
  void changeColorEdges();

  void changeTypeVertexes(int index_type);
  void changeSizeVertexes(int shift);
  void changeColorVertexes();

  void saveJpegImage();
  void saveBmpImage();
  void saveGifImage();

 private slots:
  void oneGif();
};
#endif  // VIEWER3D_H
