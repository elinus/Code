#include <cassert>
#include <iostream>

struct Shape {
  virtual uint_fast32_t area() const = 0;
};

struct Rectangle : Shape {
  Rectangle(uint_fast32_t width, uint_fast32_t height)
      : width{width}, height{height} {}
  virtual void set_width(uint_fast32_t width) { this->width = width; }
  virtual void set_height(uint_fast32_t height) { this->height = height; }
  uint_fast32_t get_width() const { return width; }
  uint_fast32_t get_height() const { return height; }
  uint_fast32_t area() const override { return width * height; }

private:
  uint_fast32_t width, height;
};

struct Square : Shape {
  Square(uint_fast32_t size) : size{size} {}
  void set_size(uint_fast32_t size) { this->size = size; }
  uint_fast32_t area() const override { return size * size; }

private:
  uint_fast32_t size;
};

struct ShapeFactory {
  static Shape CreateRectangle(uint32_t width, uint32_t height);
  static Shape CreateSquare(uint32_t size);
};

void process(Shape &s) {
  //
  assert((5 * 5) == s.area());
}

int main(int argc, char const *argv[]) {
  Rectangle r{5, 15};
  process(r);
  Square s{5};
  process(s);
  return 0;
}
