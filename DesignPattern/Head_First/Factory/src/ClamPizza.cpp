#include <Factory/ClamPizza.h>

ClamPizza::ClamPizza()
{
    name = "Clam Pizza";
    dough = "Thin crust";
    sauce = "White garlic sauce";
    toppings.push_back("Clams");
    toppings.push_back("Grated parmesan cheese");
}
