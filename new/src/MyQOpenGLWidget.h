#ifndef INC_3DVIEWER_V1_MYQOPENGLWIDGET_H
#define INC_3DVIEWER_V1_MYQOPENGLWIDGET_H

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLBuffer>
#include <QMouseEvent>
#include <QWheelEvent>
#include "struct/object3/object3.h"

#include <iostream>

class MyQOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT

 public:
  explicit MyQOpenGLWidget(QWidget* parent = nullptr);
  ~MyQOpenGLWidget() override;

   object3_t** cur_obect = nullptr;
  // Projection interface
  int perspective = 0;  // 1 for on perspective mode

  // Edges interface
  int lineType = 0; // for stripple
  float lineWidth = 1; // 1 default and min, 25.5 max value;
  QColor colorLine = QColor();

  // Vertices interface
  QColor colorVer = QColor();
  float pointWidth = 5; // 1 default, min 5, 25.5 max value;
  int pointType = 1; // 0 - disable, 1 - square, 2 - circle

  void mousePressEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void wheelEvent(QWheelEvent* event) override;

  void saveBmpImage(const QString& filename);
  void saveJpegImage(const QString& filename);

 protected:
  bool leftButtonPress = false;
  bool rightButtonPress = false;

  QPoint leftButtonPoint;
  QPoint rightButtonPoint;

  // QOpenGLWidget interface
  QColor color = QColor();
  QOpenGLShaderProgram *prog = nullptr;

  void initializeGL() override;
  void paintGL() override;

 private:
 signals:
  void leftButtonMove(QPoint shift);
  void rightButtonMove(QPoint shift);
  void mouseScroll(int y);

 public slots:
  void changeBackgroundColor(int r, int g, int b);
  void changeColorLine(int r, int g, int b);
  void changeVerLine(int r, int g, int b);
};

#endif  // INC_3DVIEWER_V1_MYQOPENGLWIDGET_H
