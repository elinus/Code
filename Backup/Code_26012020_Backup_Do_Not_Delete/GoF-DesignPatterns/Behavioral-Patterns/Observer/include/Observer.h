#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <string>

class Observer {
    public:
        virtual ~Observer() = default;
        virtual void update(const std::string& str) = 0;
};

#endif /* __OBSERVER_H__ */
