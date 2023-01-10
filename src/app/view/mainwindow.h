#ifndef CPP4_3DVIEWER_V2_0_0_SRC_APP_VIEW_MAINWINDOW_H_
#define CPP4_3DVIEWER_V2_0_0_SRC_APP_VIEW_MAINWINDOW_H_

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QtWidgets/QWidget>

#include "../controller/facade.h"
#include "QtGifImage/include/QtGifImage/qgifimage.h"
#include "glwidget.h"
#include "viewsettings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow(Facade *facade, QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void TimerSlot();
  void on_x_valueChanged(double arg1);
  void on_y_valueChanged(double arg1);
  void on_z_valueChanged(double arg1);
  void on_open_file_clicked();
  void on_screencast_clicked();
  void on_angle_x_valueChanged(int arg1);
  void on_angle_y_valueChanged(int arg1);
  void on_angle_z_valueChanged(int arg1);
  void on_save_image_clicked();
  void on_scale_valueChanged(double arg1);
  void on_line_type_currentIndexChanged(int index);
  void on_vertex_type_currentIndexChanged(int index);
  void on_line_thickness_valueChanged(double arg1);
  void on_vertex_size_valueChanged(double arg1);
  void on_default_2_stateChanged(int arg1);
  void on_projection_type_currentIndexChanged(int index);
  void on_color_back_clicked();
  void on_color_line_clicked();
  void on_color_vertex_clicked();

 private:
  Ui::MainWindow *ui_;
  Facade *facade_;
  QTimer *timer_;
  QGifImage *gif_;
  int time_{};
  ViewSettings *view_settings_;
  QImage *photo_;
  QString qfile_name_;
  QString correct_file_name_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_0_SRC_APP_VIEW_MAINWINDOW_H_
