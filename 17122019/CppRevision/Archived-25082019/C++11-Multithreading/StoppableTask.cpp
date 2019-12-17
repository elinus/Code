#include <iostream>
#include <thread>
#include <future>

class Stoppable {
    private:
        std::promise<void> promiseObj;
        std::future<void> futureObj;
    public:
        Stoppable(): futureObj(promiseObj.get_future()) {}
        virtual void run() = 0;
        void operator ()() {
            run();
        }
        bool stopRequested() {
            if (futureObj.wait_for(std::chrono::milliseconds(0)) == std::future_status::timeout)
                return false;
            return true;
        }
        void stop() {
            promiseObj.set_value();
        }
        Stoppable(Stoppable && other): 
            promiseObj(std::move(other.promiseObj)), futureObj(std::move(other.futureObj)) {
                std::cout << "Move Constructor is called!" << std::endl;
        }
        Stoppable & operator =(Stoppable && other) {
            std::cout << "Move Assignment is called!" << std::endl;
            promiseObj = std::move(other.promiseObj);
            futureObj = std::move(other.futureObj);
            return *this;
        }
};

class MyTask : public Stoppable {
    public:
        void run() {
            std::cout << "Task Start!" << std::endl;
            while (stopRequested() == false) {
                std::cout << "Doing Some Work" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
            std::cout << "Task End!" << std::endl;
        }
};

int main(int argc, char const *argv[])
{
    MyTask task;
    std::thread th([&](){
            task.run();
            });
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "Asking Task to Stop" << std::endl;
    task.stop();
    th.join();
    std::cout << "Thread Joined!" << std::endl;
    std::cout << "Exiting Main Function!!" << std::endl;

    return 0;
}

