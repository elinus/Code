#ifndef __FLY_BEHAVIOUR__
#define __FLY_BEHAVIOUR__

class FlyBehaviour {
    public:
        virtual ~FlyBehaviour() 
        {}
        virtual void fly() = 0;
};

#endif
