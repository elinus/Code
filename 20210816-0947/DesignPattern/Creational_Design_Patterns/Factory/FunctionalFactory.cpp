#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <memory>

enum class PointType { Point2D, Point3D };

struct Point {
  //   int x = 14, y = 20;
  virtual ~Point(){};
  //   virtual std::unique_ptr<Point> create() = 0;
  //   virtual std::unique_ptr<Point> clone() = 0;
};

struct Point2D : public Point {
  //   virtual std::unique_ptr<Point> create() {
  //     return std::make_unique<Point2D>();
  //   }
  //   virtual std::unique_ptr<Point> clone() {
  //     return std::make_unique<Point2D>(*this);
  //   }
};

struct Point3D : public Point {
  //   virtual std::unique_ptr<Point> create() {
  //     return std::make_unique<Point3D>();
  //   }
  //   virtual std::unique_ptr<Point> clone() {
  //     return std::make_unique<Point3D>(*this);
  //   }
};

// void who_am_i(Point *point) {
//   auto new_point = point->create();
//   std::cout << "new point => (x = " << new_point->x << ", y = " <<
//   new_point->y
//             << ")\n";
//   auto dup_point = point->clone();
//   std::cout << "dup point => (x = " << dup_point->x << ", y = " <<
//   dup_point->y
//             << ")\n";
// }

class PointFunctionalFactory {
private:
  std::map<PointType, std::function<std::unique_ptr<Point>()>> m_factories;

public:
  PointFunctionalFactory() {
    m_factories[PointType::Point2D] = []() {
      return std::make_unique<Point2D>();
    };
    m_factories[PointType::Point3D] = []() {
      return std::make_unique<Point3D>();
    };
  }
  std::unique_ptr<Point> create(PointType type) { return m_factories[type](); }
};

int main(int argc, char const *argv[]) {
  //   Point2D point2d;
  //   point2d.x = 11;
  //   point2d.y = 16;
  //   who_am_i(&point2d);
  PointFunctionalFactory pf;
  auto point_2d = pf.create(PointType::Point2D);
  return 0;
}
