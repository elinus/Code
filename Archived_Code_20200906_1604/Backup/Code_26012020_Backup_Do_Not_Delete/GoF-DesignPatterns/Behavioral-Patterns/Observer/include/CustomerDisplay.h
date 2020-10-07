#ifndef __CUSTOMERDISPLAY_H__

#include "Observer.h"
#include <iostream>
#include <string>

class CustomerDisplay : public Observer {
    public:
        void update(const std::string& str);
};

#define __CUSTOMERDISPLAY_H__
#endif /* __CUSTOMERDISPLAY_H__ */
