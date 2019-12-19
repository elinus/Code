#ifndef __PAYMENT_H__
#define __PAYMENT_H__

#include <string>

class Payment {
    public:
        const std::string mType;
        const double mAmount;
        Payment(std::string type, double amount);
};

#endif /* __PAYMENT_H__ */
