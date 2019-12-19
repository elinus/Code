#include "Item.h"
#include "Order.h"
#include "Payment.h"
#include <iostream>

int main(int argc, char *argv[]) {
  Order *order = new Order();
  order->addItem(Item("Pizza", 6.99));
  order->addItem(Item("Wine", 9.99));
  order->addItem(Item("Beer", 5.99));
  order->addItem(Item("Apple", 1.49));
  std::cout << "-----------------------\n";

  order->makePayment(Payment("CASH", 20.00));
  order->makePayment(Payment("CREDIT", 10.00));
  order->makePayment(Payment("DEBIT", 10.00));
  std::cout << "-----------------------\n";

  order->completeOrder();

  return 0;
}
