#include <Factory/SimplePizzaFactory.h>
#include <Factory/PizzaStore.h>
#include <Factory/Pizza.h>

int main(int argc, char *argv[])
{
    SimplePizzaFactory *factory = new SimplePizzaFactory();
    PizzaStore *store = new PizzaStore(factory);

    Pizza *pizza = store->orderPizza("cheese");
    std::cout << "We ordered a " << pizza->getName() << "\n";
    std::cout << pizza->toString() << "\n";

    pizza = store->orderPizza("veggie");
    std::cout << "We ordered a " << pizza->getName() << "\n";
    std::cout << pizza->toString() << "\n";

    return 0;
}
