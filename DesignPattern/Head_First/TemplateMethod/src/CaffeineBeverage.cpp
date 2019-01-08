#include <TemplateMethod/CaffeineBeverage.h>

void CaffeineBeverage::prepareRecipe()
{
    boilWater();
    brew();
    pourInCup();
    if(customerWantsCondiments()) {
        addCondiments();
    }
}

void CaffeineBeverage::boilWater()
{
    std::cout << "Boiling water" << std::endl;
}

void CaffeineBeverage::pourInCup()
{
    std::cout << "Pouring into cup" << std::endl;
}

bool CaffeineBeverage::customerWantsCondiments()
{
    return true;
}
