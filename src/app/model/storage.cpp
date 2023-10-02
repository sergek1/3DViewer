#include "storage.h"

namespace s21 {

std::string Storage::ReadFile(const std::string& file_name) {
  std::string correct_file_name;
  std::ifstream in(file_name);
  ClearStorage();
  if (!in) throw std::invalid_argument("You should choose file");
  if (file_name.substr(file_name.size() - 4, 4) != ".obj")
    throw std::invalid_argument("Invalid file extension");
  size_t n = file_name.find_last_of('/');
  correct_file_name = file_name.substr(n + 1, file_name.size() - n);
  while (in) {
    std::string line;
    size_t pos = 1;
    getline(in, line);
    std::string substr = line.substr(0, 2);
    if (line.substr(0, 2) == "v ") {
      CollectV(line, &pos);
    } else if (line.substr(0, 2) == "f ") {
      CollectF(line);
    }
  }
  transformed_v_vector_ = v_vector_;
  in.close();
  return correct_file_name;
}

void Storage::CollectV(const std::string& line, size_t *pos) {
  double x, y, z;
  x = GetVertexCoordinate(line, pos);
  if (line[*pos] != ' ') throw std::invalid_argument("Wrong File Format");
  y = GetVertexCoordinate(line, pos);
  if (line[*pos] != ' ') throw std::invalid_argument("Wrong File Format");
  z = GetVertexCoordinate(line, pos);
  v_vector_.push_back(x);
  v_vector_.push_back(y);
  v_vector_.push_back(z);
}

void Storage::CollectF(const std::string& line) {
  std::vector<uint32_t> polygon_vertexes;
  size_t n = line.find(' ');
  while (n != std::string::npos) {
    if (n + 1 < line.size() && std::isdigit(line.at(n + 1))) {
      polygon_vertexes.push_back(std::stoi(line.substr(n + 1), nullptr) - 1);
    }
    n = line.find(' ', n + 1);
  }
  f_vector_.push_back(std::move(polygon_vertexes));
}

double Storage::GetVertexCoordinate(const std::string& line, size_t *pos) {
  double value{};
  size_t end_pos{};
  value = std::stod(line.substr(*pos), &end_pos);
  *pos += end_pos;
  return value;
}

void Storage::Calculate() {
  double rx = get_angle_x() * M_PI / 180;
  double ry = get_angle_y() * M_PI / 180;
  double rz = get_angle_z() * M_PI / 180;
  for (size_t j = 0; j < transformed_v_vector_.size() / 3; ++j) {
    double tmp_xy = cos(rx) * v_vector_[j * 3 + 1] * get_scale() +
                    sin(rx) * v_vector_[j * 3 + 2] * get_scale();
    transformed_v_vector_[j * 3 + 1] = tmp_xy;
    double tmp_xz = -sin(rx) * v_vector_[j * 3 + 1] * get_scale() +
                    cos(rx) * v_vector_[j * 3 + 2] * get_scale();
    transformed_v_vector_[j * 3 + 2] = tmp_xz;
    double tmp_yx = cos(ry) * v_vector_[j * 3 + 0] * get_scale() +
                    sin(ry) * transformed_v_vector_[j * 3 + 2];
    transformed_v_vector_[j * 3 + 0] = tmp_yx;
    double tmp_yz = -sin(ry) * v_vector_[j * 3 + 0] * get_scale() +
                    cos(ry) * transformed_v_vector_[j * 3 + 2];
    transformed_v_vector_[j * 3 + 2] = tmp_yz;
    double tmp = transformed_v_vector_[j * 3 + 0];
    double tmp_zx = cos(rz) * transformed_v_vector_[j * 3 + 0] +
                    sin(rz) * transformed_v_vector_[j * 3 + 1];
    transformed_v_vector_[j * 3 + 0] = tmp_zx;
    double tmp_zy = -sin(rz) * tmp + cos(rz) * transformed_v_vector_[j * 3 + 1];
    transformed_v_vector_[j * 3 + 1] = tmp_zy;
    transformed_v_vector_[j * 3 + 0] += get_delta_x();
    transformed_v_vector_[j * 3 + 1] += get_delta_y();
    transformed_v_vector_[j * 3 + 2] += get_delta_z();
  }
}

void Storage::ClearStorage() {
  v_vector_.clear();
  f_vector_.clear();
  transformed_v_vector_.clear();
  delta_x_ = delta_y_ = delta_z_ = angle_x_ = angle_y_ = angle_z_ = 0,
  scale_ = 1;
}

}  // namespace s21
