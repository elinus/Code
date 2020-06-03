#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

struct Base {
    Base() {
        std::cout << "Base::Base()\n";
    }
    ~Base() {
        std::cout << "Base::~Base()\n";
    }
};

struct Derived : public Base {
    Derived() {
        std::cout << "Derived::Derived()\n";
    }
    ~Derived() {
        std::cout << "Derived::~Derived()\n";
    }
};

void foo_thread(std::shared_ptr<Base> p) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::shared_ptr<Base> lp = p;
    static std::mutex io_mutex;
    std::lock_guard<std::mutex> lk(io_mutex);
    std::cout << "local pointer in a thread:\n"
        << "  lp.get() =  " << lp.get()
        << ", lp.use_count() = " << lp.use_count() << "\n";
}

int main (int argc, const char *argv[]) {
    std::shared_ptr<Base> p = std::make_shared<Derived>();
    std::cout << "Created shared Derived(as a pointer to Base):\n"
        << "  p.get() =  " << p.get()
        << ", p.use_count() = " << p.use_count() << "\n";

    std::thread t1(foo_thread, p), t2(foo_thread, p), t3(foo_thread, p);
    p.reset();
    
    std::cout << "Shared ownership b/w 3 threads and released ownership from main:\n"
        << "  p.get() =  " << p.get()
        << ", p.use_count() = " << p.use_count() << "\n";
    
    t1.join();
    t2.join();
    t3.join();
    std::cout << "All threads joined. exiting main.\n";
    return 0;
}

