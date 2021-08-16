#include "Order.h"

Order::Order() {

  Observer *casherDisplay = new CashierDisplay();
  Observer *customerDisplay = new CustomerDisplay();

  mAddItemTopic = new AddItemTopic();
  mAddPaymentTopic = new AddPaymentTopic();
  mCompleteOrderTopic = new CompleteOrderTopic();

  mAddItemTopic->registerObserver(casherDisplay);
  mAddPaymentTopic->registerObserver(casherDisplay);
  mCompleteOrderTopic->registerObserver(casherDisplay);

  mAddItemTopic->registerObserver(customerDisplay);
  mAddPaymentTopic->registerObserver(customerDisplay);
  mCompleteOrderTopic->registerObserver(customerDisplay);
}

void Order::addItem(Item item) {
  mCart.push_back(item);
  std::string line = item.mName + " $ " + std::to_string(item.mPrice);
  mAddItemTopic->notifyObservers(line);
}

void Order::makePayment(Payment payment) {
  mPayments.push_back(payment);
  std::string line = payment.mType + " $ " + std::to_string(payment.mAmount);
  mAddPaymentTopic->notifyObservers(line);
}

void Order::completeOrder() {
  std::string line = "Order completed.";
  mCompleteOrderTopic->notifyObservers(line);
}
