#include <iostream>

using namespace std;

template <class Type> class Shape {
public:
  virtual Type area() = 0;
};

template <class Type> class Rectangle : public Shape<Type> {
public:
  Rectangle(int width, int height) : width(width), height(height) {}
  Type area() { return width * height; }

private:
  Type width, height;
};

int main(int argc, char *argv[]) {
  Rectangle<int> rec(14, 20);
  cout << rec.area() << endl;
  return 0;
}
