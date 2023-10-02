#include "glwidget.h"

#include "mainwindow.h"

namespace s21 {

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent), settings_(&ViewSettings::GetInstance()) {
  connect(&timer_, SIGNAL(timeout()), this, SLOT(update()));
  timer_.start(100);
}

void GLWidget::initializeGL() {}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void GLWidget::paintGL() {
  glEnable(GL_DEPTH_TEST);
  glClearColor(settings_->get_color_back().redF(),
               settings_->get_color_back().greenF(),
               settings_->get_color_back().blueF(), 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (settings_->get_projection_type() == 0)
    glOrtho(-100, 100, -100, 100, -100, 1000);
  else
      glFrustum(-10,10,-10,10,10,150);
//    gluPerspective(100, 1.2, 0.1, 1000.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotatef(xRot, 1, 0, 0);
  glRotatef(yRot, 0, 1, 0);
  Draw();
}

void GLWidget::Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  glEnableClientState(GL_VERTEX_ARRAY);
  glColor3f(settings_->get_color_line().redF(),
            settings_->get_color_line().greenF(),
            settings_->get_color_line().blueF());
  glLineWidth(settings_->get_line_width());
  glVertexPointer(3, GL_DOUBLE, 0, gl_facade->GetTransformedVertexes().data());
  if (settings_->get_line_type() == 0) {
    for (size_t i = 0; i < gl_facade->GetFacets().size(); ++i) {
      glDrawElements(GL_LINE_LOOP, gl_facade->GetFacets()[i].size(),
                     GL_UNSIGNED_INT, gl_facade->GetFacets()[i].data());
    }
  } else {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2, 0x00FF);
    for (size_t i = 0; i < gl_facade->GetFacets().size(); ++i) {
      glDrawElements(GL_LINE_LOOP, gl_facade->GetFacets()[i].size(),
                     GL_UNSIGNED_INT, gl_facade->GetFacets()[i].data());
    }
    glDisable(GL_LINE_STIPPLE);
  }
  if (settings_->get_vertex_type() != 0) {
    glColor3f(settings_->get_color_vertex().redF(),
              settings_->get_color_vertex().greenF(),
              settings_->get_color_vertex().blueF());
    glPointSize(settings_->get_vertex_size());
    if (settings_->get_vertex_type() == 1) {
      glEnable(GL_POINT_SMOOTH);
      glDrawArrays(GL_POINTS, 0,
                   gl_facade->GetTransformedVertexes().size() / 3);
      glDisable(GL_POINT_SMOOTH);
    } else {
      glDrawArrays(GL_POINTS, 0,
                   gl_facade->GetTransformedVertexes().size() / 3);
    }
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::mousePressEvent(QMouseEvent *mo) { mPos_ = mo->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent *mo) {
  xRot = 1 / M_PI * (mo->pos().y() - mPos_.y());
  yRot = 1 / M_PI * (mo->pos().x() - mPos_.x());
  update();
}

}  // namespace s21
