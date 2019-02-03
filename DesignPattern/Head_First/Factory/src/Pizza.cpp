#include <Factory/Pizza.h>

std::string Pizza::getName() { return name; }

void Pizza::prepare() { std::cout << "Preparing " << name << std::endl; }

void Pizza::bake() { std::cout << "Baking " << name << std::endl; }

void Pizza::cut() { std::cout << "Cutting " << name << std::endl; }

void Pizza::box() { std::cout << "Boxing " << name << std::endl; }

std::string Pizza::toString() {
  std::string display;
  display.append("---- ");
  display.append(name);
  display.append(" ----\n");
  display.append(dough);
  display.append("\n");
  display.append(sauce);
  display.append("\n");
  for (std::string topping : toppings) {
    display.append(topping + "\n");
  }
  return display;
}
