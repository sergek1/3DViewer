#include "mainwindow.h"

#include "ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(Facade *facade, QWidget *parent)
    : QMainWindow(parent),
      ui_(new Ui::MainWindow),
      facade_(facade),
      view_settings_(&ViewSettings::GetInstance()) {
  ui_->setupUi(this);
  view_settings_->ReadViewSettings();
  this->ui_->line_thickness->setValue(view_settings_->get_line_width());
  this->ui_->vertex_size->setValue(view_settings_->get_vertex_size());
  this->ui_->line_type->setCurrentIndex(view_settings_->get_line_type());
  this->ui_->vertex_type->setCurrentIndex(view_settings_->get_vertex_type());
  this->ui_->projection_type->setCurrentIndex(
      view_settings_->get_projection_type());
  this->ui_->GLwidget->gl_facade = facade_;
}
MainWindow::~MainWindow() { delete ui_; }
void MainWindow::on_x_valueChanged(double arg1) {
  ui_->GLwidget->gl_facade->MoveXYZ(0, arg1);
}

void MainWindow::on_y_valueChanged(double arg1) {
  ui_->GLwidget->gl_facade->MoveXYZ(1, arg1);
}

void MainWindow::on_z_valueChanged(double arg1) {
  ui_->GLwidget->gl_facade->MoveXYZ(2, arg1);
}

void MainWindow::on_scale_valueChanged(double arg1) {
  ui_->GLwidget->gl_facade->ScaleXYZ(arg1);
}

void MainWindow::on_open_file_clicked() {
  try {
    qfile_name_ = QFileDialog::getOpenFileName(this, "Выбрать файл");
    correct_file_name_ = facade_->ReadFile(qfile_name_);
    this->ui_->file_name->setText(correct_file_name_);
    int vertexes_number =
        this->ui_->GLwidget->gl_facade->GetTransformedVertexes().size() / 3;
    int facets_number = this->ui_->GLwidget->gl_facade->GetFacets().size();
    int edges_number = vertexes_number + facets_number - 2;
    this->ui_->vertexes_edges->setText(
        "Vertexes: " + QString::number(vertexes_number) +
        " Polygons: " + QString::number(facets_number) +
        " Edges: " + QString::number(edges_number));
    ui_->x->setValue(0);
    ui_->y->setValue(0);
    ui_->z->setValue(0);
    ui_->angle_x->setValue(0);
    ui_->angle_y->setValue(0);
    ui_->angle_z->setValue(0);
    ui_->scale->setValue(1);
  } catch (const std::exception &ex) {
    QMessageBox::warning(this, "Werror", ex.what());
  }
}

void MainWindow::on_screencast_clicked() {
  gif_ = new QGifImage(QSize(640, 480));
  gif_->setDefaultDelay(100);
  photo_ = new QImage;
  time_ = 0;
  timer_ = new QTimer(this);
  connect(timer_, SIGNAL(timeout()), this, SLOT(TimerSlot()));
  timer_->start(100);
}

void MainWindow::TimerSlot() {
  ++time_;
  *photo_ = ui_->GLwidget->grabFramebuffer();
  *photo_ =
      photo_->scaled(640, 480, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
  gif_->addFrame(*photo_, 100);
  if (time_ == 50) {
    timer_->stop();
    QString path = QFileDialog::getExistingDirectory();
    correct_file_name_.resize(correct_file_name_.size() - 4);
    gif_->save(path + "/" + correct_file_name_ + ".gif");
    delete gif_;
  }
}

void MainWindow::on_angle_x_valueChanged(int arg1) {
  ui_->GLwidget->gl_facade->RotateXYZ(0, arg1);
}

void MainWindow::on_angle_y_valueChanged(int arg1) {
  ui_->GLwidget->gl_facade->RotateXYZ(1, arg1);
}

void MainWindow::on_angle_z_valueChanged(int arg1) {
  ui_->GLwidget->gl_facade->RotateXYZ(2, arg1);
}

void MainWindow::on_save_image_clicked() {
  if (correct_file_name_.size()) {
    QString path = QFileDialog::getExistingDirectory();
    correct_file_name_.resize(correct_file_name_.size() - 4);
    ui_->GLwidget->grabFramebuffer().save(
        path + "/" + correct_file_name_ + ".jpeg", NULL, 100);
    ui_->GLwidget->grabFramebuffer().save(
        path + "/" + correct_file_name_ + ".bmp", NULL, 100);
  }
}

void MainWindow::on_line_type_currentIndexChanged(int index) {
  view_settings_->set_line_type(index);
}

void MainWindow::on_vertex_type_currentIndexChanged(int index) {
  view_settings_->set_vertex_type(index);
}

void MainWindow::on_line_thickness_valueChanged(double arg1) {
  view_settings_->set_line_width(arg1);
}

void MainWindow::on_vertex_size_valueChanged(double arg1) {
  view_settings_->set_vertex_size(arg1);
}

void MainWindow::on_default_2_stateChanged(int arg1) {
  if (arg1) {
    this->ui_->x->setValue(0);
    this->ui_->y->setValue(0);
    this->ui_->z->setValue(0);
    this->ui_->angle_x->setValue(0);
    this->ui_->angle_y->setValue(0);
    this->ui_->angle_z->setValue(0);
    ui_->scale->setValue(1);
    this->ui_->line_thickness->setValue(1);
    this->ui_->vertex_size->setValue(1);
    QColor color_back;
    color_back.setRgb(0);
    view_settings_->set_color_back(color_back);

    QColor color_line;
    color_line.setRgb(255, 255, 255);
    view_settings_->set_color_line(color_line);
    QColor color_vertex;
    color_vertex.setRgb(255, 255, 255);
    view_settings_->set_color_vertex(color_vertex);
    this->ui_->line_type->setCurrentIndex(0);
    this->ui_->vertex_type->setCurrentIndex(0);
    this->ui_->projection_type->setCurrentIndex(0);
    this->ui_->GLwidget->xRot = this->ui_->GLwidget->yRot = 0;
  }
}

void MainWindow::on_projection_type_currentIndexChanged(int index) {
  view_settings_->set_projection_type(index);
}

void MainWindow::on_color_back_clicked() {
  QColor color_back = QColorDialog::getColor(Qt::white, this, "Choose a color");
  if (color_back.isValid()) view_settings_->set_color_back(color_back);
}

void MainWindow::on_color_line_clicked() {
  QColor color_line = QColorDialog::getColor(Qt::white, this, "Choose a color");
  if (color_line.isValid()) view_settings_->set_color_line(color_line);
}

void MainWindow::on_color_vertex_clicked() {
  QColor color_vertex =
      QColorDialog::getColor(Qt::white, this, "Choose a color");
  if (color_vertex.isValid()) view_settings_->set_color_vertex(color_vertex);
}

}  // namespace s21
