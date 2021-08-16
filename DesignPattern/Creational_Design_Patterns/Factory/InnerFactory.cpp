#include <cmath>
#include <iostream>


enum class PointType { Cartesian, Polar };

class Point {
private:
  double m_x;
  double m_y;
  PointType m_type;
  Point(const double x, const double y, PointType type)
      : m_x{x}, m_y{y}, m_type{type} {}

public:
  friend std::ostream &operator<<(std::ostream &out, const Point &p) {
    return out << "x: " << p.m_x << " y: " << p.m_y;
  }
  struct Factory {
    static Point new_cartesion(double x, double y) {
      return Point{x, y, PointType::Cartesian};
    }
    static Point new_polar(double x, double y) {
      return Point{x * cos(y), y * sin(x), PointType::Polar};
    }
  };
};

int main(int argc, char const *argv[]) {
  /* code */
  auto pt = Point::Factory::new_polar(14, 3.14);
  std::cout << pt << std::endl;
  return 0;
}
