#include <iostream>
#include <thread>
#include <functional>
#include <vector>

class ThreadWrapper {
    private:
        std::thread threadHandler;
    public:
        ThreadWrapper(std::function<void()> func): 
            threadHandler(func) {}
        ~ThreadWrapper() { 
            if (threadHandler.joinable()) {
                threadHandler.join();
            }
        }

        ThreadWrapper(const ThreadWrapper &) = delete;
        ThreadWrapper& operator=(ThreadWrapper &) = delete;
        ThreadWrapper(ThreadWrapper && other): 
            threadHandler(std::move(other.threadHandler)) {
                std::cout << "Move Constructor is called!" << std::endl;
        }
        ThreadWrapper& operator =(ThreadWrapper && other) {
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
    std::function<void()> func = []() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << __func__ << " :: " << std::this_thread::get_id() << std::endl;
    };

    { // Block
        ThreadWrapper wrapper(func);
    }

    std::vector<ThreadWrapper> threadList;
    ThreadWrapper t1(func);
    ThreadWrapper t2(func);
    
    threadList.push_back(std::move(t1));
    threadList.push_back(std::move(t2));

    ThreadWrapper t3(func);

    threadList[1] = std::move(t3);
    
    return 0;
}

