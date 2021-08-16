#include <algorithm>
#include <iostream>
#include <vector>

class MemoryBlock {
public:
  explicit MemoryBlock(size_t length)
      : _length(length), _data(new int[length]) {
    std::cout << this << " :: In MemoryBlock(size_t). length = " << _length
              << "." << std::endl;
  }

  ~MemoryBlock() {
    std::cout << this << " :: In ~MemoryBlock(). length = " << _length << ".";
    if (_data != nullptr) {
      std::cout << " Deleting resource.";
      delete[] _data;
    }
    std::cout << std::endl;
  }

  MemoryBlock(const MemoryBlock &other)
      : _length(other._length), _data(new int[other._length]) {
    std::cout << this << " :: In MemoryBlock(const MemoryBlock&). length = "
              << other._length << ". Copying resource." << std::endl;
    std::copy(other._data, other._data + _length, _data);
  }

  MemoryBlock(MemoryBlock &&other) : _data(nullptr), _length(0) {
    std::cout << this
              << " :: In MemoryBlock(MemoryBlock&&). length = " << other._length
              << ". Moving resource." << std::endl;
    _data = other._data;
    _length = other._length;
    other._data = nullptr;
    other._length = 0;
  }

  MemoryBlock &operator=(const MemoryBlock &other) {
    std::cout << this << " :: In operator=(const MemoryBlock&). length = "
              << other._length << ". Copying resource." << std::endl;
    if (this != &other) {
      delete[] _data;
      _length = other._length;
      _data = new int[other._length];
      std::copy(other._data, other._data + _length, _data);
    }
    return *this;
  }

  MemoryBlock &operator=(MemoryBlock &&other) {
    std::cout << this
              << " :: In operator=(MemoryBlock&&). length = " << other._length
              << "." << std::endl;
    if (this != &other) {
      delete[] _data;
      _data = other._data;
      _length = other._length;
      other._data = nullptr;
      other._length = 0;
    }
    return *this;
  }

  size_t getLength() { return _length; }

private:
  size_t _length;
  int *_data;
};

int main(int argc, char const *argv[]) {
  std::vector<MemoryBlock> v;
  v.push_back(MemoryBlock(25));
  v.push_back(MemoryBlock(75));
  v.insert(v.begin() + 1, MemoryBlock(50));
  return 0;
}
