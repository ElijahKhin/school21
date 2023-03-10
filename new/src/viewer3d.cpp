#include "viewer3d.h"
#include "./ui_viewer3d.h"
#include <QFileDialog>

Viewer3D::Viewer3D(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Viewer3D) {
  ui->setupUi(this);

  connect(ui->load_file, SIGNAL(clicked()), this, SLOT(load_file()));

  connect(ui->move_x_spin, SIGNAL(valueChanged(double)), this,
          SLOT(obj3_move()));
  connect(ui->move_y_spin, SIGNAL(valueChanged(double)), this,
          SLOT(obj3_move()));
  connect(ui->move_z_spin, SIGNAL(valueChanged(double)), this,
          SLOT(obj3_move()));

  connect(ui->rotate_x_spin, SIGNAL(valueChanged(double)), this,
          SLOT(obj3_rotate()));
  connect(ui->rotate_y_spin, SIGNAL(valueChanged(double)), this,
          SLOT(obj3_rotate()));
  connect(ui->rotate_z_spin, SIGNAL(valueChanged(double)), this,
          SLOT(obj3_rotate()));

  connect(ui->scale_x_spin, SIGNAL(valueChanged(double)), this,
          SLOT(obj3_scale()));
  connect(ui->scale_y_spin, SIGNAL(valueChanged(double)), this,
          SLOT(obj3_scale()));
  connect(ui->scale_z_spin, SIGNAL(valueChanged(double)), this,
          SLOT(obj3_scale()));

  connect(ui->openGLWidget, SIGNAL(rightButtonMove(QPoint)), this,
          SLOT(updateShift(QPoint)));
  connect(ui->openGLWidget, SIGNAL(leftButtonMove(QPoint)), this,
          SLOT(updateRotate(QPoint)));
  connect(ui->openGLWidget, SIGNAL(mouseScroll(int)), this,
          SLOT(updateScale(int)));

  connect(ui->color_red_spin, SIGNAL(valueChanged(int)), this,
          SLOT(changeBackgroundColor()));
  connect(ui->color_green_spin, SIGNAL(valueChanged(int)), this,
          SLOT(changeBackgroundColor()));
  connect(ui->color_blue_spin, SIGNAL(valueChanged(int)), this,
          SLOT(changeBackgroundColor()));

  connect(ui->orthographic, SIGNAL(clicked()), this, SLOT(changePerspective()));
  connect(ui->perspective, SIGNAL(clicked()), this, SLOT(changePerspective()));

  connect(ui->edges_type_combo, SIGNAL(currentIndexChanged(int)), this,
          SLOT(changeTypeEdges(int)));
  connect(ui->edges_size_spin, SIGNAL(valueChanged(int)), this,
          SLOT(changeSizeEdges(int)));
  connect(ui->edges_red_spin, SIGNAL(valueChanged(int)), this,
          SLOT(changeColorEdges()));
  connect(ui->edges_green_spin, SIGNAL(valueChanged(int)), this,
          SLOT(changeColorEdges()));
  connect(ui->edges_blue_spin, SIGNAL(valueChanged(int)), this,
          SLOT(changeColorEdges()));

  connect(ui->vertex_type_combo, SIGNAL(currentIndexChanged(int)), this,
          SLOT(changeTypeVertexes(int)));
  connect(ui->vertex_size_spin, SIGNAL(valueChanged(int)), this,
          SLOT(changeSizeVertexes(int)));
  connect(ui->vertex_red_spin, SIGNAL(valueChanged(int)), this,
          SLOT(changeColorVertexes()));
  connect(ui->vertex_green_spin, SIGNAL(valueChanged(int)), this,
          SLOT(changeColorVertexes()));
  connect(ui->vertex_blue_spin, SIGNAL(valueChanged(int)), this,
          SLOT(changeColorVertexes()));

  connect(ui->jpeg_button, SIGNAL(clicked()), this, SLOT(saveJpegImage()));
  connect(ui->bmp_button, SIGNAL(clicked()), this, SLOT(saveBmpImage()));
  connect(ui->gif_button, SIGNAL(clicked()), this, SLOT(saveGifImage()));

  this->loadSettings();
  ui->openGLWidget->cur_obect = &(this->current_obj3);

  changeBackgroundColor();

  changeTypeEdges(ui->edges_type_combo->currentIndex());
  changeSizeEdges(ui->edges_size_spin->value());
  changeColorEdges();

  changeTypeVertexes(ui->vertex_type_combo->currentIndex());
  changeSizeVertexes(ui->vertex_size_spin->value());
  changeColorVertexes();

  changePerspective();
}

void Viewer3D::loadSettings() {
  FILE* file = fopen("settings.my", "r");
  if (!file) return;

  double tmp_d;
  int tmp_i;

  if (!fscanf(file, "%lf", &tmp_d)) {
    fclose(file);
    return;
  }
  this->ui->move_x_spin->setValue(tmp_d);
  if (!fscanf(file, "%lf", &tmp_d)) {
    fclose(file);
    return;
  }
  this->ui->move_y_spin->setValue(tmp_d);
  if (!fscanf(file, "%lf", &tmp_d)) {
    fclose(file);
    return;
  }
  this->ui->move_z_spin->setValue(tmp_d);

  if (!fscanf(file, "%lf", &tmp_d)) {
    fclose(file);
    return;
  }
  this->ui->rotate_x_spin->setValue(tmp_d);
  if (!fscanf(file, "%lf", &tmp_d)) {
    fclose(file);
    return;
  }
  this->ui->rotate_y_spin->setValue(tmp_d);
  if (!fscanf(file, "%lf", &tmp_d)) {
    fclose(file);
    return;
  }
  this->ui->rotate_z_spin->setValue(tmp_d);

  if (!fscanf(file, "%lf", &tmp_d)) {
    fclose(file);
    return;
  }
  this->ui->scale_x_spin->setValue(tmp_d);
  if (!fscanf(file, "%lf", &tmp_d)) {
    fclose(file);
    return;
  }
  this->ui->scale_y_spin->setValue(tmp_d);
  if (!fscanf(file, "%lf", &tmp_d)) {
    fclose(file);
    return;
  }
  this->ui->scale_z_spin->setValue(tmp_d);

  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->color_red_spin->setValue(tmp_i);
  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->color_green_spin->setValue(tmp_i);
  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->color_blue_spin->setValue(tmp_i);

  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  if (tmp_i)
    this->ui->perspective->setChecked(true);
  else
    this->ui->orthographic->setChecked(true);

  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->edges_type_combo->setCurrentIndex(tmp_i);
  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->edges_size_spin->setValue(tmp_i);
  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->edges_red_spin->setValue(tmp_i);
  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->edges_green_spin->setValue(tmp_i);
  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->edges_blue_spin->setValue(tmp_i);

  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->vertex_type_combo->setCurrentIndex(tmp_i);
  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->vertex_size_spin->setValue(tmp_i);
  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->vertex_red_spin->setValue(tmp_i);
  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->vertex_green_spin->setValue(tmp_i);
  if (!fscanf(file, "%d", &tmp_i)) {
    fclose(file);
    return;
  }
  this->ui->vertex_blue_spin->setValue(tmp_i);

  fclose(file);
}

void Viewer3D::saveSettings() {
  FILE* file = fopen("settings.my", "w");
  if (!file) return;

  fprintf(file, "%lf ", this->ui->move_x_spin->value());
  fprintf(file, "%lf ", this->ui->move_y_spin->value());
  fprintf(file, "%lf ", this->ui->move_z_spin->value());

  fprintf(file, "%lf ", this->ui->rotate_x_spin->value());
  fprintf(file, "%lf ", this->ui->rotate_y_spin->value());
  fprintf(file, "%lf ", this->ui->rotate_z_spin->value());

  fprintf(file, "%lf ", this->ui->scale_x_spin->value());
  fprintf(file, "%lf ", this->ui->scale_y_spin->value());
  fprintf(file, "%lf ", this->ui->scale_z_spin->value());

  fprintf(file, "%d ", this->ui->color_red_spin->value());
  fprintf(file, "%d ", this->ui->color_green_spin->value());
  fprintf(file, "%d ", this->ui->color_blue_spin->value());

  fprintf(file, "%d ", !this->ui->orthographic->isChecked());

  fprintf(file, "%d ", this->ui->edges_type_combo->currentIndex());
  fprintf(file, "%d ", this->ui->edges_size_spin->value());
  fprintf(file, "%d ", this->ui->edges_red_spin->value());
  fprintf(file, "%d ", this->ui->edges_green_spin->value());
  fprintf(file, "%d ", this->ui->edges_blue_spin->value());

  fprintf(file, "%d ", this->ui->vertex_type_combo->currentIndex());
  fprintf(file, "%d ", this->ui->vertex_size_spin->value());
  fprintf(file, "%d ", this->ui->vertex_red_spin->value());
  fprintf(file, "%d ", this->ui->vertex_green_spin->value());
  fprintf(file, "%d ", this->ui->vertex_blue_spin->value());

  fclose(file);
}

Viewer3D::~Viewer3D() {
  this->saveSettings();

  free_object3(&this->current_obj3);
  delete ui;
}

void Viewer3D::changeBackgroundColor() {
  this->ui->openGLWidget->changeBackgroundColor(
      this->ui->color_red_spin->value(), this->ui->color_green_spin->value(),
      this->ui->color_blue_spin->value());
}

void Viewer3D::obj3_move() {
  if (!this->current_obj3 || this->ignore_event) return;

  double shift_x = this->ui->move_x_spin->value() - this->current_obj3->shift.x;
  double shift_y = this->ui->move_y_spin->value() - this->current_obj3->shift.y;
  double shift_z = this->ui->move_z_spin->value() - this->current_obj3->shift.z;
  object3_move(this->current_obj3, {shift_x, shift_y, shift_z});
  this->ui->openGLWidget->update();
}

void Viewer3D::obj3_rotate() {
  if (!this->current_obj3 || this->ignore_event) return;

  double shift_x =
      this->ui->rotate_x_spin->value() - this->current_obj3->rotate.x;
  double shift_y =
      this->ui->rotate_y_spin->value() - this->current_obj3->rotate.y;
  double shift_z =
      this->ui->rotate_z_spin->value() - this->current_obj3->rotate.z;
  object3_rotate(this->current_obj3, {shift_x, shift_y, shift_z});
  this->ui->openGLWidget->update();
}

void Viewer3D::obj3_scale() {
  if (!this->current_obj3 || this->ignore_event) return;

  double shift_x =
      this->ui->scale_x_spin->value() / this->current_obj3->scale.x;
  double shift_y =
      this->ui->scale_y_spin->value() / this->current_obj3->scale.y;
  double shift_z =
      this->ui->scale_z_spin->value() / this->current_obj3->scale.z;
  object3_scale(this->current_obj3, {shift_x, shift_y, shift_z});
  this->ui->openGLWidget->update();
}

void Viewer3D::load_file() {
  QString fileName = QFileDialog::getOpenFileName(this, "Choose file", nullptr,
                                                  "Object(*.obj)");
  if (fileName.isNull()) return;
  this->ui->file_info->setText("File name: " + fileName);

  if (this->current_obj3) free_object3(&this->current_obj3);

  this->current_obj3 =
      parse_object3_from_obj_file(fileName.toStdString().c_str());
  if (this->current_obj3) {
    QString vertexes =
        "Vertexex: " + QString::number(this->current_obj3->list_vertex3.count);
    QString polygon = " Polygons: " +
                      QString::number(this->current_obj3->list_polygon.count);
    this->ui->vertical_info->setText(vertexes + polygon);

    object3_move(this->current_obj3, {this->ui->move_x_spin->value(),
                                      this->ui->move_y_spin->value(),
                                      this->ui->move_z_spin->value()});
    object3_rotate(this->current_obj3, {this->ui->rotate_x_spin->value(),
                                        this->ui->rotate_y_spin->value(),
                                        this->ui->rotate_z_spin->value()});
    object3_scale(this->current_obj3, {this->ui->scale_x_spin->value(),
                                       this->ui->scale_y_spin->value(),
                                       this->ui->scale_z_spin->value()});
    this->ui->openGLWidget->update();
  }
}

void Viewer3D::updateShift(QPoint shift) {
  if (!this->current_obj3) return;

  this->ignore_event = true;
  this->ui->move_x_spin->setValue(this->ui->move_x_spin->value() +
                                  (double)shift.x() / 250);
  this->ui->move_y_spin->setValue(this->ui->move_y_spin->value() +
                                  -(double)shift.y() / 250);
  this->ignore_event = false;

  object3_move(
      this->current_obj3,
      {this->ui->move_x_spin->value() - this->current_obj3->shift.x,
       this->ui->move_y_spin->value() - this->current_obj3->shift.y, 0});
  this->ui->openGLWidget->update();
}

void Viewer3D::updateRotate(QPoint shift) {
  if (!this->current_obj3) return;

  vector3_t ang = {-(double)shift.y(), (double)shift.x(), 0};
  this->ignore_event = true;
  this->ui->rotate_x_spin->setValue(
      fmod(this->ui->rotate_x_spin->value() + ang.x, 360));
  this->ui->rotate_y_spin->setValue(
      fmod(this->ui->rotate_y_spin->value() + ang.y, 360));
  this->ui->rotate_z_spin->setValue(
      fmod(this->ui->rotate_z_spin->value() + ang.z, 360));
  this->ignore_event = false;
  object3_rotate(
      this->current_obj3,
      {this->ui->rotate_x_spin->value() - this->current_obj3->rotate.x,
       this->ui->rotate_y_spin->value() - this->current_obj3->rotate.y,
       this->ui->rotate_z_spin->value() - this->current_obj3->rotate.z});
  this->ui->openGLWidget->update();
}

void Viewer3D::updateScale(int y) {
  if (!this->current_obj3) return;
  double new_y = y / fabs(y) / 20;

  this->ignore_event = true;
  this->ui->scale_x_spin->setValue(this->ui->scale_x_spin->value() + new_y);
  this->ui->scale_y_spin->setValue(this->ui->scale_y_spin->value() + new_y);
  this->ui->scale_z_spin->setValue(this->ui->scale_z_spin->value() + new_y);
  this->ignore_event = false;

  object3_scale(
      this->current_obj3,
      {this->ui->scale_x_spin->value() / this->current_obj3->scale.x,
       this->ui->scale_y_spin->value() / this->current_obj3->scale.y,
       this->ui->scale_z_spin->value() / this->current_obj3->scale.z});
  this->ui->openGLWidget->update();
}

void Viewer3D::saveJpegImage() {
  QString fileName = QFileDialog::getSaveFileName(this, "Save file",
                                                  nullptr, "Image(*.jpeg)");
  if (fileName.isNull()) return;
  this->ui->openGLWidget->saveJpegImage(fileName);
}

void Viewer3D::saveBmpImage() {
  QString fileName = QFileDialog::getSaveFileName(this, "Save file",
                                                  nullptr, "Image(*.bmp)");
  if (fileName.isNull()) return;
  this->ui->openGLWidget->saveBmpImage(fileName);
}

void Viewer3D::saveGifImage() {
  sfileName = QFileDialog::getSaveFileName(this, "Save file", nullptr,
                                           "Image(*.gif)");
  if (sfileName.isNull()) return;

  gif = new QGifImage;
  gif->setDefaultDelay(1000 / gifFps);
  startTime = 0, tmpTime = 1000 / gifFps;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(oneGif()));
  timer->start(1000 / gifFps);

  this->ui->gif_button->setEnabled(false);
  this->ui->gif_label->setText("GIF recording, please wait...");
}

void Viewer3D::oneGif() {
  if (startTime == tmpTime) {
    QPixmap screenGIF(this->ui->openGLWidget->size());
    this->ui->openGLWidget->render(&screenGIF);
    QImage image = screenGIF.toImage();
    gif->addFrame(image, 1000 / gifFps);
    timePrint = (float)startTime / 1e3;
	tmpTime += 1000 / gifFps;
  }
  if (startTime == 1000 * gifLength) {
    gif->save(sfileName);
    timer->stop();

    disconnect(timer, SIGNAL(timeout()), this, SLOT(oneGif()));

    delete gif;
    delete timer;

    this->ui->gif_button->setEnabled(true);
    this->ui->gif_label->setText("");
  }
  startTime += 1000 / gifFps;
}

void Viewer3D::changeTypeEdges(int index_type) {
  this->ui->openGLWidget->lineType = index_type;
  this->ui->openGLWidget->update();
}

void Viewer3D::changeSizeEdges(int shift) {
  this->ui->openGLWidget->lineWidth = shift / 10.0;
  this->ui->openGLWidget->update();
}

void Viewer3D::changeColorEdges() {
  this->ui->openGLWidget->changeColorLine(this->ui->edges_red_spin->value(),
                                          this->ui->edges_green_spin->value(),
                                          this->ui->edges_blue_spin->value());
}

void Viewer3D::changeTypeVertexes(int index_type) {
  this->ui->openGLWidget->pointType = index_type;
  this->ui->openGLWidget->update();
}

void Viewer3D::changeSizeVertexes(int shift) {
  this->ui->openGLWidget->pointWidth = shift / 10.0;
  this->ui->openGLWidget->update();
}

void Viewer3D::changeColorVertexes() {
  this->ui->openGLWidget->changeVerLine(this->ui->vertex_red_spin->value(),
                                        this->ui->vertex_green_spin->value(),
                                        this->ui->vertex_blue_spin->value());
}

void Viewer3D::changePerspective() {
  this->ui->openGLWidget->perspective = !this->ui->orthographic->isChecked();
  this->ui->openGLWidget->update();
}
