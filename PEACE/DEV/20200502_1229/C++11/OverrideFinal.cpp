#include <iostream>

class A {
public:
	virtual const char* getName() { return "A"; }
};
 
class B : public A {
public:
	virtual const char* getName() override final { return "B"; } 
};
 
class C : public B
{
public:
	//virtual const char* getName() override { return "C"; } // compile error: overrides B::getName(), which is final
};

class D final : public A {
    public:
    virtual const char* getName() override final { return "D"; } 
};

//error: base 'D' is marked 'final'
// class E : public D {
// };

int main(int argc, char const *argv[])
{
    
    return 0;
}
