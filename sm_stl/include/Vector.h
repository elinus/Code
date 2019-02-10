#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <string>

namespace sm_stl {

template <typename T> class Vector {
public:
  Vector(size_t size = 10) : size(size), buffer(new T[size]) {
    std::cout << TAG << "Constructor!. size = " << size
              << ", buffer addr. = " << buffer << "\n";
  }

  ~Vector() {
    std::cout << TAG << "Destructor!. deleting buffer addr. = " << buffer
              << "\n";
    delete[] buffer;
  }

  Vector(const Vector &other) : size(other.size), buffer(new T[size]) {
    std::cout << TAG << "Copy Constructor!. size = " << size
              << ", buffer addr. = " << buffer << "\n";
    std::copy(other.buffer, other.buffer + other.size, buffer);
  }

  Vector &operator=(const Vector &other) {
    std::cout << TAG << "Assign operator!. size = " << size
              << ", buffer addr. = " << buffer << "\n";
    *this;
  }

private:
  std::string TAG = "[Vector] ";
  std::size_t size;
  T *buffer;
};
} // namespace sm_stl

#endif /* __VECTOR_H__ */
