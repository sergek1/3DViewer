#ifndef CPP4_3DVIEWER_V2_0_0_SRC_APP_VIEW_GLWIDGET_H_
#define CPP4_3DVIEWER_V2_0_0_SRC_APP_VIEW_GLWIDGET_H_

#include <OpenGL/glu.h>

#include <QColorDialog>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtOpenGL>
#include <QtWidgets/QWidget>

#include "../controller/facade.h"
#include "viewsettings.h"

namespace s21 {

class GLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  explicit GLWidget(QWidget *parent = 0);
  Facade *gl_facade;
  float xRot = 0, yRot = 0;

 private:
  ViewSettings *settings_;
  QPoint mPos_;
  QTimer timer_;
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void Draw();
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_0_SRC_APP_VIEW_GLWIDGET_H_
