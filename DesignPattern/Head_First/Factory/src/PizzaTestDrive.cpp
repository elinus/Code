#include <Factory/Pizza.h>
#include <Factory/PizzaStore.h>
#include <Factory/SimplePizzaFactory.h>

int main(int argc, char *argv[]) {
  auto *factory = new SimplePizzaFactory();
  auto *store = new PizzaStore(factory);

  Pizza *pizza = store->orderPizza("cheese");
  std::cout << "We ordered a " << pizza->getName() << "\n";
  std::cout << pizza->toString() << "\n";

  pizza = store->orderPizza("veggie");
  std::cout << "We ordered a " << pizza->getName() << "\n";
  std::cout << pizza->toString() << "\n";

  return 0;
}
