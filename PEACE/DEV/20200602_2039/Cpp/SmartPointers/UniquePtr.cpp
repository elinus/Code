#include <iostream>
#include <memory>
#include <vector>
#include <cstdio>
#include <functional>
#include <cassert>
#include <fstream>

struct B {
    virtual void bar() {
        std::cout << "B::bar\n";
    }
    virtual ~B() = default;
};

struct D : B {
    D() {
        std::cout << "D::D\n";
    }
    ~D() {
        std::cout << "D::~D\n";
    }
    void bar() override {
        std::cout << "D::bar\n";
    }
};

std::unique_ptr<D> pass_through(std::unique_ptr<D> p) {
    p->bar();
    return p;
}

int main (int argc, const char *argv[]) {
    std::cout << "Unique ownership semantic demo\n"; 
    {
        auto p = std::make_unique<D>();
        auto q = pass_through(std::move(p));
        assert(!p);
        q->bar();
    }

    std::cout << "Runtime polymorphism demo\n";
    {
        std::unique_ptr<B> p = std::make_unique<D>();
        p->bar();
        std::vector<std::unique_ptr<B>> v;
        v.push_back(std::make_unique<D>());
        v.push_back(std::move(p));
        v.emplace_back(new D);
        for(auto& p: v) p->bar();
    }
    return 0;
}

