#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std::placeholders;

class Test
{
    std::mutex mut;
    std::condition_variable cV;
    bool loaded;
    public:
    Test()
    {
        loaded = false;
    }
    void loadData()
    {
        // Make This Thread sleep for 1 Second
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Loading Data from XML" << std::endl;
        // Lock The Data structure
        std::lock_guard<std::mutex> guard(mut);
        // Set the flag to true, means data is loaded
        loaded = true;
        // Notify the condition variable
        cV.notify_one();
    }
    
    bool dataLoaded()
    {
        return loaded;
    }
    
    void mainTask()
    {
        std::cout<<"Do Some Handshaking"<<std::endl;
        // Acquire the lock
        std::unique_lock<std::mutex> mlock(mut);
        // Start waiting for the Condition Variable to get signaled
        // Wait() will internally release the lock and make the thread to block
        // As soon as condition variable get signaled, resume the thread and
        // again acquire the lock. Then check if condition is met or not
        // If condition is met then continue else again go in wait.
        std::cout << "waiting for data.." << std::endl;
        cV.wait(mlock, std::bind(&Test::dataLoaded, this));
        std::cout << "Do Processing On loaded Data" << std::endl;
    }
};

int main()
{
    Test app;
    std::thread t1(&Test::mainTask, &app);
    std::thread t2(&Test::loadData, &app);
    t2.join();
    t1.join();
    return 0;
}
