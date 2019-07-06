#include <iostream>
#include <thread>
#include <functional>

class ThreadWrapper {
    private:
        std::thread threadHandler;
    public:
        ThreadWrapper(std::function<void> func): 
            threadHandler(func) {}
        ~ThreadWrapper() { 
            if (threadHandler.joinable()) {
                threadHandler.join();
            }
        }

        ThreadWrapper(const ThreadWrapper &) = delete;
        ThreadWrapper& operator =(const ThreadWrapper &) = delete;
        ThreadWrapper(ThreadWrapper && other): 
            threadHandler(std::move(other.threadHandler)) {
                std::cout << "Move Constructor is called!" << std::endl;
        }
        ThreadWrapper& operator =(const ThreadWrapper && other) {
            std::cout << "Move Assignment is called!" << std::endl;
            if (threadHandler.joinable()) {
                threadHandler.join();
            }
            threadHandler = std::move(other.threadHandler);
            return *this;
        }

};

int main(int argc, char const *argv[])
{
    
    return 0;
}

