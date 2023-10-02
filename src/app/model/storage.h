#ifndef CPP4_3DVIEWER_V2_0_0_SRC_APP_MODEL_STORAGE_H_
#define CPP4_3DVIEWER_V2_0_0_SRC_APP_MODEL_STORAGE_H_

#include <cmath>
#include <fstream>
#include <vector>

namespace s21 {

class Storage {
 public:
  Storage() : v_vector_(), f_vector_(), transformed_v_vector_() {}
  ~Storage() {}

  std::string ReadFile(const std::string& file_name);
  void Calculate();
  std::vector<double> &GetTransformedVertexes() {
    return transformed_v_vector_;
  }
  std::vector<std::vector<uint32_t>> &GetFacets() { return f_vector_; }
  void set_delta_x(double value) { delta_x_ = value; }
  void set_delta_y(double value) { delta_y_ = value; }
  void set_delta_z(double value) { delta_z_ = value; }
  void set_angle_x(double value) { angle_x_ = value; }
  void set_angle_y(double value) { angle_y_ = value; }
  void set_angle_z(double value) { angle_z_ = value; }
  void set_scale(double value) { scale_ = value; }
  double get_delta_x() const { return delta_x_; }
  double get_delta_y() const { return delta_y_; }
  double get_delta_z() const { return delta_z_; }
  double get_angle_x() const { return angle_x_; }
  double get_angle_y() const { return angle_y_; }
  double get_angle_z() const { return angle_z_; }
  double get_scale() const { return scale_; }
  void ClearStorage();

 private:
  std::vector<double> v_vector_;
  std::vector<std::vector<uint32_t>> f_vector_;
  std::vector<double> transformed_v_vector_;
  double delta_x_{}, delta_y_{}, delta_z_{}, angle_x_{}, angle_y_{}, angle_z_{};
  double scale_ = 1;
  void CollectV(const std::string& line, size_t *pos);
  void CollectF(const std::string& line);
  double GetVertexCoordinate(const std::string& line, size_t *pos);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_0_SRC_APP_MODEL_STORAGE_H_
