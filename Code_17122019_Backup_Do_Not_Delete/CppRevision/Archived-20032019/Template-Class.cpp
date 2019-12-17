#include <iostream>

using namespace std;

template <class point> class Point {
public:
  Point() {}

  Point(point px, point py) : px(px), py(py) {
    cout << "Point object construction" << endl;
  }

  void printPoint() { cout << "X: " << px << ", Y: " << py << endl; }

private:
  point px;
  point py;
};

template <class derPoint> class Point3D : Point<derPoint> {
public:
  Point3D(derPoint px, derPoint dy, derPoint dz) : px(px), py(py), pz(pz) {
    cout << "Point3d object construction" << endl;
  }
  void printPoint() {
    cout << "X: " << px << ", Y: " << py << ", Z: " << pz << endl;
  }

private:
  derPoint px;
  derPoint py;
  derPoint pz;
};

int main(int argc, char *argv[]) {
  Point<int> basePoint(5, 5);
  Point3D<double> derivedPoint(99.9, 99.9, 99.9);

  cout << "basePoint is ";
  basePoint.printPoint();

  cout << "derivedPoint is ";
  derivedPoint.printPoint();

  return 0;
}
