#include <Factory/PepperoniPizza.h>

PepperoniPizza::PepperoniPizza()
{
    name = "Pepperoni Pizza";
    dough = "Crust";
    sauce = "Marinara sauce";
    toppings.push_back("Sliced Pepperoni");
    toppings.push_back("Sliced Onion");
    toppings.push_back("Grated parmesan cheese");
}
