#include <Command/GarageDoor.h>

GarageDoor::GarageDoor(std::string location) { this->location = location; }

void GarageDoor::up() { std::cout << location << " garage Door is up\n"; }

void GarageDoor::down() { std::cout << location << " garage Door is down\n"; }

void GarageDoor::stop() { std::cout << location << " garage Door is stop\n"; }

void GarageDoor::lightOn() { std::cout << location << " garage light is on\n"; }

void GarageDoor::lightOff() {
  std::cout << location << " garage light is off\n";
}
