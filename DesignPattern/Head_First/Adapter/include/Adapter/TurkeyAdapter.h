#ifndef __TURKEY_ADAPTER_H__
#define __TURKEY_ADAPTER_H__

#include <Adapter/Duck.h>
#include <Adapter/Turkey.h>

class TurkeyAdapter : public Duck {
    public:
        TurkeyAdapter(Turkey *turkey);
        void quack() override;
        void fly() override;
    private:
        Turkey *turkey;

};

#endif
