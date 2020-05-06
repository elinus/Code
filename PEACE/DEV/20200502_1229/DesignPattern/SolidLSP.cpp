#include <iostream>

using namespace std;

class Rectangle {
protected:
  int width, height;

public:
  Rectangle(const int width, const int height) : width(width), height(height) {}
  int getWidth() const { return width; }
  virtual void setWidth(int width) { this->width = width; }
  int getHeight() const { return height; }
  virtual void setHeight(int height) { this->height = height; }
  int area() const { return width * height; }
};

class Square : public Rectangle {
public:
  Square(int size) : Rectangle(size, size) {}
  void setWidth(int width) { this->width = width = height; }
  void setHeight(int width) { this->height = width = height; }
};

struct RectangleFactory {
  static Rectangle createRectangle(int w, int h);
  static Rectangle createSquare(int s);
};

void process(Rectangle &r) {
  int w = r.getWidth();
  r.setHeight(10);
  cout << "expected area = " << (w * 10) << ", got = " << r.area() << endl;
}

int main(int argc, char const *argv[]) {
  Rectangle rect{5, 5};
  process(rect);

  Square sq(5);
  process(sq);

  return 0;
}
