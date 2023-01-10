#include <gtest/gtest.h>

#include "storage.h"

const double kEpsilon_ = 1e-5;

void CheckVectors(std::vector<double> res, std::vector<double> etalon) {
  for (size_t i = 0; i < res.size(); ++i) {
    ASSERT_NEAR(res[i], etalon[i], kEpsilon_);
  }
}

TEST(ParsingTests, case_1) {
  s21::Storage storage;
  storage.ReadFile("./test/cube.obj");
  EXPECT_EQ(storage.GetTransformedVertexes().size() / 3, 8);
  EXPECT_EQ(storage.GetFacets().size(), 12);
}

TEST(transformation_tests, moving) {
  s21::Storage storage;
  storage.ReadFile("./test/cube.obj");
  storage.set_delta_x(17);
  storage.set_delta_y(17);
  storage.set_delta_z(17);
  storage.Calculate();
  std::vector<double> res = storage.GetTransformedVertexes();
  std::vector<double> etalon{17, 17, 17, 17, 17, 18, 17, 18, 17, 17, 18, 18,
                             18, 17, 17, 18, 17, 18, 18, 18, 17, 18, 18, 18};
  ASSERT_EQ(res, etalon);
}

TEST(transformation_tests, rotation) {
  s21::Storage storage;
  storage.ReadFile("./test/cube.obj");
  storage.set_angle_x(120);
  storage.set_angle_y(120);
  storage.set_angle_z(120);
  storage.Calculate();
  std::vector<double> res = storage.GetTransformedVertexes();
  res.shrink_to_fit();
  std::vector<double> etalon{
      0,          0,        0,         0.966506, -0.0580127, 0.25,
      -0.0580127, 0.899519, 0.433013,  0.908494, 0.841506,   0.683013,
      0.25,       0.433013, -0.866025, 1.21651,  0.375,      -0.616025,
      0.191987,   1.33253,  -0.433013, 1.15849,  1.27452,    -0.183013};
  CheckVectors(res, etalon);
}

TEST(transformation_tests, scale) {
  s21::Storage storage;
  storage.ReadFile("./test/cube.obj");
  storage.set_scale(0.5);
  storage.Calculate();
  std::vector<double> res = storage.GetTransformedVertexes();
  std::vector<double> etalon{0, 0,   0,   0,   0,   0.5, 0,   0.5,
                             0, 0,   0.5, 0.5, 0.5, 0,   0,   0.5,
                             0, 0.5, 0.5, 0.5, 0,   0.5, 0.5, 0.5};
  ASSERT_EQ(res, etalon);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
