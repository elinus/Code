#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <utility>

std::mutex gMutex;

void print(const char* func) {
    gMutex.lock();
    std::cout << func << ": " << std::this_thread::get_id() << " executing\n";
    gMutex.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Foo(int n) {
    for (int i = 0; i < 5; i++) 
    {
        print(__func__);
        n++;
    }
}

void foo(int &n) {
    for (int i = 0; i < 5; i++) 
    {
        print(__func__);
        n++;
    }
}

class Bar {
    public:
        void operator()() {
            for (int i = 0; i < 5; i++) 
            {
                print(__func__);
            }
        }
};

class Baz {
    public:
        int m = 0;
        void Fizz(int n) {
            for (int i = 0; i < 5; i++) 
            {
                print(__func__);
                n++;
                m++;
            }
        }
};

int main (int argc, char *argv[]) 
{

    int n = 0;
    std::thread t1(Foo, n);

    Bar barObj;
    std::thread t2(barObj);

    std::thread t3([]() {
            for (int i = 0; i < 5; i++) 
            {
                print(__func__);
            }
            });
    
    std::thread t4(Foo, 0);
    if (t4.joinable())
    {
        t4.detach();
    }

    if (t1.joinable()) 
    {
        t1.join();
    }
    
    if (t2.joinable())
    {
        t2.join();
    }
    
    if (t3.joinable())
    {
        t3.join();
    }

    std::thread t5(foo, std::ref(n));
    Baz bazObj;
    std::thread t6(&Baz::Fizz, &bazObj, std::ref(n));

    if (t5.joinable())
    {
        t5.join();
    }

    if (t6.joinable())
    {
        t6.join();
    }

    std::cout << "After joining, n = " << n << "\n";
    std::cout << "After joining, Baz::m = " << bazObj.m << "\n";
    
    return 0;
}

