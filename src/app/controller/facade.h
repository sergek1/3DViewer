#ifndef CPP4_3DVIEWER_V2_0_0_SRC_APP_CONTROLLER_FACADE_H_
#define CPP4_3DVIEWER_V2_0_0_SRC_APP_CONTROLLER_FACADE_H_

#include <QMainWindow>

#include "../model/storage.h"

namespace s21 {

class Adaptee {
 public:
  virtual ~Adaptee() = default;
  virtual QString ReadFile(QString str) = 0;
};

class Adapter : public Adaptee {
 public:
  Adapter(Storage *p) : storage_(p) {}
  ~Adapter() override {}
  QString ReadFile(QString str) override {
    std::string res = storage_->ReadFile(str.toStdString());
    return QString::fromStdString(res);
  }

 private:
  Storage *storage_;
};

class Facade {
 public:
  explicit Facade(Storage *storage) : storage_(storage) {}
  ~Facade(){};
  Facade(const Facade &f) = delete;
  void operator=(const Facade &f) = delete;

  QString ReadFile(QString file_name);
  std::vector<std::vector<uint32_t>> &GetFacets();
  std::vector<double> &GetTransformedVertexes();
  void MoveXYZ(int XYZ, double value);
  void RotateXYZ(int XYZ, double value);
  void ScaleXYZ(double value);
  void ClearStorage() { storage_->ClearStorage(); }

 private:
  Storage *storage_;
};

}  // namespace s21

#endif  //  CPP4_3DVIEWER_V2_0_0_SRC_APP_CONTROLLER_FACADE_H_
