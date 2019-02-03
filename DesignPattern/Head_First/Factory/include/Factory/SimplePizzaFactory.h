#ifndef __SIMPLE_PIZZA_FACTORY_H__
#define __SIMPLE_PIZZA_FACTORY_H__

#include <Factory/CheesePizza.h>
#include <Factory/ClamPizza.h>
#include <Factory/PepperoniPizza.h>
#include <Factory/Pizza.h>
#include <Factory/VeggiePizza.h>
#include <string>

class SimplePizzaFactory {
public:
  Pizza *createPizza(std::string type);
};

#endif // !__SIMPLE_PIZZA_FACTORY_H__
