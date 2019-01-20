#include <Factory/VeggiePizza.h>

VeggiePizza::VeggiePizza()
{
    name = "Veggie Pizza";
    dough = "Crust";
    sauce = "Marinara sauce";
    toppings.push_back("Shredded mozzarella");
    toppings.push_back("Grated parmesan");
    toppings.push_back("Diced onion");
    toppings.push_back("Sliced mushrooms");
    toppings.push_back("Sliced red pepper");
    toppings.push_back("Sliced black olives");
}
