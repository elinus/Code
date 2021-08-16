#include <functional>
#include <iostream>
#include <map>
#include <memory>

using namespace std;

struct Point {};
struct Point2D : Point {};
struct Point3D : Point {};

enum class PointType { Point2D, Point3D };

class PointFunctionalFactory {
  map<PointType, function<unique_ptr<Point>()>> m_factories;

public:
  PointFunctionalFactory() {
    m_factories[PointType::Point2D] = [] { return make_unique<Point2D>(); };
    m_factories[PointType::Point3D] = [] { return make_unique<Point3D>(); };
  }
  unique_ptr<Point> create(PointType type) { return m_factories[type](); }
};

int main() {

  PointFunctionalFactory pf;
  auto p2D = pf.create(PointType::Point2D);
  return 0;
}