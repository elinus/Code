#include <iostream>
#include <memory>

using namespace std;

struct Point {
  virtual ~Point() = default;
  virtual unique_ptr<Point> create() = 0;
  virtual unique_ptr<Point> clone() = 0;
};

struct Point2d : Point {
  unique_ptr<Point> create() override { return make_unique<Point2d>(); }
  unique_ptr<Point> clone() override { return make_unique<Point2d>(*this); }
};

struct Point3d : Point {
  unique_ptr<Point> create() override { return make_unique<Point3d>(); }
  unique_ptr<Point> clone() override { return make_unique<Point3d>(*this); }
};

void who_am_i(Point *who) {
  auto new_who = who->create();      // virtual constructor
  auto duplicate_who = who->clone(); // virtual copy-constructor
  delete who;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
