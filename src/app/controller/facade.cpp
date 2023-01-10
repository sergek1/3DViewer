#include "facade.h"

namespace s21 {

QString Facade::ReadFile(QString file_name) {
  Adapter *p = new Adapter(storage_);
  return p->ReadFile(file_name);
}

std::vector<double> &Facade::GetTransformedVertexes() {
  return storage_->GetTransformedVertexes();
}

std::vector<std::vector<uint32_t>> &Facade::GetFacets() {
  return storage_->GetFacets();
}

void Facade::MoveXYZ(int XYZ, double value) {
  if (XYZ == 0)
    storage_->set_delta_x(value);
  else if (XYZ == 1)
    storage_->set_delta_y(value);
  else
    storage_->set_delta_z(value);
  storage_->Calculate();
}

void Facade::RotateXYZ(int XYZ, double value) {
  if (XYZ == 0)
    storage_->set_angle_x(value);
  else if (XYZ == 1)
    storage_->set_angle_y(value);
  else
    storage_->set_angle_z(value);
  storage_->Calculate();
}

void Facade::ScaleXYZ(double value) {
  if (value) {
    storage_->set_scale(value);
    storage_->Calculate();
  }
}

}  // namespace s21
