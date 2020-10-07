#ifndef __ORDER_H__
#define __ORDER_H__

#include "Item.h"
#include "Payment.h"
#include "Observer.h"
#include "CashierDisplay.h"
#include "CustomerDisplay.h"
#include "Topic.h"
#include "AddItemTopic.h"
#include "AddPaymentTopic.h"
#include "CompleteOrderTopic.h"
#include <vector>
#include <string>

class Order {
    private:
        std::vector<Item> mCart;
        std::vector<Payment> mPayments;
        Topic *mAddItemTopic;
        Topic *mAddPaymentTopic;
        Topic *mCompleteOrderTopic;
    public:
        Order();
        void addItem(Item item);
        void makePayment(Payment payment);
        void completeOrder();
};

#endif /* __ORDER_H__ */
