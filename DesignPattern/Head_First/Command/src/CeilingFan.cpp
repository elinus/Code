#include <Command/CeilingFan.h>

CeilingFan::CeilingFan(std::string location) { this->location = location; }

void CeilingFan::high() {
  level = HIGH;
  std::cout << location << " ceiling fan is on high\n";
}

void CeilingFan::medium() {
  level = MEDIUM;
  std::cout << location << " ceiling fan is on medium\n";
}

void CeilingFan::low() {
  level = LOW;
  std::cout << location << " ceiling fan is on low\n";
}

void CeilingFan::off() {
  level = 0;
  std::cout << location << " ceiling fan is off\n";
}

int CeilingFan::getSpeed() { return level; }
