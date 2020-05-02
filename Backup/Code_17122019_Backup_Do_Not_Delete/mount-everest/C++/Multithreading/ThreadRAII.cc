#include <iostream>
#include <thread>
#include <chrono>

class ThreadRAII {
    private:
        std::thread &m_Thread;
    public:
        ThreadRAII(std::thread & thread_ref)
            : m_Thread(thread_ref)
        {}
        ~ThreadRAII() {
            if (m_Thread.joinable())
            {
                m_Thread.detach();
            }
        }
};

void foo() {
    for (int i = 0; i < 5; i++)
    {
        std::cout << std::this_thread::get_id() << ": " << i << " :: executing\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main (int argc, char *argv[]) 
{
    std::thread t1(foo);
    ThreadRAII threadRaiiObj(t1);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "exiting :: " << std::this_thread::get_id() << " : thread\n"; 
    return 0;
}

