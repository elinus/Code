#include <cassert>
#include <iostream>

struct Rectangle {
  Rectangle(uint_fast32_t width, uint_fast32_t height)
      : width{width}, height{height} {}
  virtual void set_width(uint_fast32_t width) { this->width = width; }
  virtual void set_height(uint_fast32_t height) { this->height = height; }
  uint_fast32_t get_width() const { return width; }
  uint_fast32_t get_height() const { return height; }
  uint_fast32_t area() const { return width * height; }

protected:
  uint_fast32_t width, height;
};

struct Square : Rectangle {
  Square(uint_fast32_t size) : Rectangle{size, size} {}
  void set_width(uint_fast32_t width) { this->width = this->height = width; }
  void set_height(uint_fast32_t height) { this->height = this->width = height; }
};

void process(Rectangle &r) {
  uint_fast32_t w = r.get_width();
  r.set_height(10);
  assert((w * 10) == r.area());
}

int main(int argc, char const *argv[]) {
  Rectangle r{5, 5};
  process(r);
  Square s{5};
  process(s);
  return 0;
}
