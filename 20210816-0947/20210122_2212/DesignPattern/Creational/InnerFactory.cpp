#include <cmath>
#include <iostream>

using namespace std;

enum class PointType { cartesian, polar };

class Point {
  float m_x;
  float m_y;
  PointType m_type;
  Point(float x, float y, PointType pt) : m_x{x}, m_y{y}, m_type{pt} {}
  friend class PointFactory;

public:
  friend ostream &operator<<(ostream &out, const Point &point) {
    out << "x = " << point.m_x << ", y = " << point.m_y << "\n";
    return out;
  }

  struct Factory {
    static Point NewCartesian(float x, float y) {
      return {x, y, PointType::cartesian};
    }
    static Point NewPolar(float a, float b) {
      return {a * sin(b), a * cos(b), PointType::polar};
    }
  };
};

int main(int argc, char const *argv[]) {
  auto point = Point::Factory::NewPolar(1, 4);
  cout << point;
  return 0;
}
