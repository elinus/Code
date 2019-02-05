#include <iostream>
#include <memory>

class Sample {
public:
  Sample() { std::cout << __func__ << std::endl; }

  ~Sample() { std::cout << __func__ << std::endl; }

  void operator()(Sample *x) {
    std::cout << "Operator: " << __func__ << std::endl;
    delete[] x;
  }
};

void deleter(Sample *arrPtr) {
  std::cout << __func__ << std::endl;
  delete[] arrPtr;
}

int main(int argc, char *argv[]) {
  std::shared_ptr<Sample> p1(new Sample[5], deleter);

  std::cout << "\n";
  std::shared_ptr<Sample> p2(new Sample[5], [](Sample *x) {
    std::cout << "Lambda: " << __func__ << std::endl;
    delete[] x;
  });

  std::cout << "\n";
  std::shared_ptr<Sample> p3(new Sample[5], Sample());
  return 0;
}
