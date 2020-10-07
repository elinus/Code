#include <iostream>
#include <thread>

class ThreadRAII {
    public:
            ThreadRAII(std::thread &threadObj): mThread(threadObj) {}
            ~ThreadRAII() {
                if (mThread.joinable()) {
                    mThread.detach();
                }
            }
    private:
        std::thread &mThread;
};

void foo() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread function executing!" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1(foo);
    ThreadRAII trObj(t1);
    return 0;
}

