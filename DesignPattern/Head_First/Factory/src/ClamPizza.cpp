#include <Factory/ClamPizza.h>

ClamPizza::ClamPizza() {
  name = "Clam Pizza";
  dough = "Thin crust";
  sauce = "White garlic sauce";
  toppings.emplace_back("Clams");
  toppings.emplace_back("Grated parmesan cheese");
}
