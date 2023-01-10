#include <QApplication>

#include "view/mainwindow.h"

#define GL_SILENCE_DEPRECATION

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Storage storage;
  s21::Facade facade(&storage);
  s21::MainWindow w(&facade);
  w.show();
  return a.exec();
}
