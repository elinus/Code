#include <cmath>
#include <iostream>
#include <memory>

enum class PointType { Cartesian, Polar };

struct Point {
  int x = 14, y = 20;
  virtual ~Point(){};
  virtual std::unique_ptr<Point> create() = 0;
  virtual std::unique_ptr<Point> clone() = 0;
};

struct Point2D : public Point {
  virtual std::unique_ptr<Point> create() {
    return std::make_unique<Point2D>();
  }
  virtual std::unique_ptr<Point> clone() {
    return std::make_unique<Point2D>(*this);
  }
};

struct Point3D : public Point {
  virtual std::unique_ptr<Point> create() {
    return std::make_unique<Point3D>();
  }
  virtual std::unique_ptr<Point> clone() {
    return std::make_unique<Point3D>(*this);
  }
};

void who_am_i(Point *point) {
  auto new_point = point->create();
  std::cout << "new point => (x = " << new_point->x << ", y = " << new_point->y
            << ")\n";
  auto dup_point = point->clone();
  std::cout << "dup point => (x = " << dup_point->x << ", y = " << dup_point->y
            << ")\n";
}

int main(int argc, char const *argv[]) {
  Point2D point2d;
  point2d.x = 11;
  point2d.y = 16;
  who_am_i(&point2d);
  return 0;
}
