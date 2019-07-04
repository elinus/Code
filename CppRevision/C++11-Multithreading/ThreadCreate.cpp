#include <iostream>
#include <thread>

void foo() {
    for (int i = 0; i < 5; ++i) {
        std::cout << __func__ << ": " << i << std::endl;
    }
}

void bar() {
    static int counter = 0;
    for (int i = 0; i < 5; ++i) {
        std::cout << __func__ << ": " << ++counter << std::endl;
    }
}

class FooBar {
    public:
        void operator ()() {
            for (int i = 0; i < 5; i++) {
                std::cout << __func__ << "[" <<std::this_thread::get_id() << "]:=> " << i << std::endl;
            }
        }
};

int main(int argc, char const *argv[])
{
    /* Thread creation using function pointer */
    std::thread t1(foo);
    bar();

    /* Thread creation using lambda function */
    std::thread t2([]{
            for (int i = 0; i < 5; i++) {
                std::cout << "Lambda func: " << __func__ << ":=> " << i << std::endl;
            }
            });
    bar();

    if (t1.get_id() != t2.get_id()) {
        std::cout << "T1 Id: " << t1.get_id() << std::endl;
        std::cout << "T2 Id: " << t2.get_id() << std::endl;
    }
    t1.join();
    t2.join();

    /* Thread creation using function object */
    std::thread t3((FooBar()));
    bar();
    t3.join();

    std::cout << "Exiting main thread!" << std::endl;
    return 0;
}

