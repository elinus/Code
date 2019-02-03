#include <Facade/PopcornPopper.h>

PopcornPopper::PopcornPopper(std::string description) {
  this->description = description;
}

void PopcornPopper::on() { std::cout << description << " on\n"; }

void PopcornPopper::off() { std::cout << description << " off\n"; }

void PopcornPopper::pop() { std::cout << description << " popping popcorn\n"; }

std::string PopcornPopper::toString() { return description; }
