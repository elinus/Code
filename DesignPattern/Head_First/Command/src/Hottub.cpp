#include <Command/Hottub.h>

Hottub::Hottub() {}

void Hottub::on() { on_ = true; }

void Hottub::off() { on_ = false; }

void Hottub::bubblesOn() {
  if (on_) {
    std::cout << "Hottub is bubbling!\n";
  }
}

void Hottub::bubblesOff() {
  if (on_) {
    std::cout << "Hottub is not bubbling\n";
  }
}

void Hottub::jetsOn() {
  if (on_) {
    std::cout << "Hottub jets are on\n";
  }
}

void Hottub::jetsOff() {
  if (on_) {
    std::cout << "Hottub jets are off\n";
  }
}

void Hottub::setTemperture(int temperature) { this->temperature = temperature; }

void Hottub::heat() {
  temperature = 105;
  std::cout << "Hottub is heating to a steaming 105 degrees\n";
}

void Hottub::cool() {
  temperature = 98;
  std::cout << "Hottub is cooling to 98 degrees\n";
}
