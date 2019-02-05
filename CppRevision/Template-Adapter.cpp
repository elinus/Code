#include <iostream>
#include <string>

using namespace std;

class Cat {
public:
  void makeCatNoise() { cout << catnoise.c_str() << endl; }

private:
  string catnoise = "meow meow";
};

class AnimalInterface {
public:
  virtual ~AnimalInterface() {}
  virtual void execute() = 0;
};

template <class T> class AnimalAdapter : public AnimalInterface {
public:
  AnimalAdapter(T *o, void (T::*m)()) {
    animalObject = o;
    animalFunction = m;
  }
  ~AnimalAdapter() { delete animalObject; }

  void execute() { (animalObject->*animalFunction)(); }

private:
  T *animalObject;
  void (T::*animalFunction)();
};

int main(int argc, char *argv[]) {
  AnimalAdapter<Cat> cat(new Cat(), &Cat::makeCatNoise);
  cat.execute();
  return 0;
}
