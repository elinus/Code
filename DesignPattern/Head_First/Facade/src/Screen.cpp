#include <Facade/Screen.h>

Screen::Screen(std::string description) { this->description = description; }

void Screen::up() { std::cout << description << " going up\n"; }

void Screen::down() { std::cout << description << " going down\n"; }

std::string Screen::toString() { return description; }
