#ifndef __PIZZA_STORE_H__
#define __PIZZA_STORE_H__

#include <Factory/Pizza.h>
#include <Factory/SimplePizzaFactory.h>
#include <string>

class PizzaStore {
private:
  SimplePizzaFactory *factory;

public:
  PizzaStore(SimplePizzaFactory *simplePizzaFactory);
  Pizza *orderPizza(std::string type);
};

#endif // !__PIZZA_STORE_H__
