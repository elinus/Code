#include <iostream>
#include <thread>
#include <chrono>

class ThreadRAII
{
private:
    std::thread& m_Thread;
public:
    ThreadRAII(std::thread & thread_object) : m_Thread(thread_object)
    {}
    ~ThreadRAII() {
        if (m_Thread.joinable()) {
            m_Thread.detach();
        }
    }
};

void foo() {
    for (size_t i = 0; i < 10; i++) {
        std::cout << "foo executing..\n";
        // std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    
}

int main(int argc, char const *argv[]) {
    std::thread th_foo { foo };
    ThreadRAII thread_raii { th_foo };
    return 0;
}
