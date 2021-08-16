#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

namespace sm_stl {

template <typename T> class Vector {
public:
  Vector(size_t capacity = 10)
      : capacity(capacity), length(0),
        buffer(static_cast<T *>(::operator new(sizeof(T) * capacity))) {
    std::cout << TAG << "Constructor!. length = " << length
              << ", buffer addr. = " << buffer << "\n";
  }

  ~Vector() {
    std::cout << TAG << "Destructor!. deleting buffer addr. = " << buffer
              << "\n";
    std::unique_ptr<T, Deleter> deleter(buffer, Deleter());
    for (int i = length - 1; i >= 0; --i) {
      buffer[i].~T();
    }
  }

  Vector(const Vector &other)
      : capacity(other.length), length(0),
        buffer(static_cast<T *>(::operator new(sizeof(T) * capacity))) {
    std::cout << TAG << "Copy Constructor!. length = " << length
              << ", buffer addr. = " << buffer << "\n";
    try {
      for (int i = 0; i < other.length; ++i) {
        push_back(other.buffer[i]);
      }
    } catch (...) {
      std::unique_ptr<T, Deleter> deleter(buffer, Deleter());
      for (int i = length - 1; i >= 0; ++i) {
        buffer[i].~T();
      }
      throw;
    }
  }

  void swap(Vector &other) noexcept {
    std::swap(other.capacity, capacity);
    std::swap(other.length, length);
    std::swap(other.buffer, buffer);
  }

  Vector &operator=(const Vector &other) {
    std::cout << TAG << "Assignment!. length = " << length
              << ", buffer addr. = " << buffer << "\n";
    Vector tmp(other);
    tmp.swap(*this);
    return *this;
  }

  Vector(Vector &&move) noexcept : capacity(0), length(0), buffer(nullptr) {
    std::cout << TAG << "Move Constructor!. length = " << length
              << ", buffer addr. = " << buffer << "\n";
    move.swap(*this);
  }

  Vector &operator=(Vector &&move) noexcept {
    std::cout << TAG << "Move Assignment!. length = " << length
              << ", buffer addr. = " << buffer << "\n";
    move.swap(*this);
    return *this;
  }

  void push_back(const T &value) {
    std::cout << TAG << "push_back!" << std::endl;
    resizeIfRequired();
    pushBackInternal(value);
  }

  void pop_back() {
    std::cout << TAG << "pop_back!" << std::endl;
    length--;
    buffer[length].~T();
  }

  void reserve(std::size_t capacityUpperBound) {
    if (capacityUpperBound > capacity) {
      reserveCapacity(capacityUpperBound);
    }
  }

private:
  std::string TAG = "[Vector] ";
  std::size_t capacity;
  std::size_t length;
  T *buffer;

  struct Deleter {
    void operator()(T *buffer) const { ::operator delete(buffer); }
  };

  void resizeIfRequired() {
    if (length == capacity) {
      std::size_t newCapacity = std::max(2.0, capacity * 1.5);
      reserveCapacity(newCapacity);
    }
  }

  void pushBackInternal(const T &value) {
    new (buffer + length) T(value);
    length++;
  }

  void reserveCapacity(std::size_t newCapacity) {
    Vector<T> tmpBuffer(newCapacity);
    std::for_each(buffer, buffer + length,
                  [&tmpBuffer](T const &v) { tmpBuffer.pushBackInternal(v); });
    tmpBuffer.swap(*this);
  }
};
} // namespace sm_stl

#endif /* __VECTOR_H__ */
