#ifndef __CASHIERDISPLAY_H__
#define __CASHIERDISPLAY_H__

#include "Observer.h"
#include <iostream>
#include <string>

class CashierDisplay : public Observer {
    public:
        void update(const std::string& str);
};

#endif /* __CASHIERDISPLAY_H__ */
