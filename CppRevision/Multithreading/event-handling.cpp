#include<iostream>
#include<thread>
#include<mutex>

class Test
{
    std::mutex mtx;
    bool dataLoaded;
    public:
    Test()
    {
        dataLoaded = false;
    }
    void loadData()
    {
        // Make This Thread sleep for 1 Second
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Loading Data from XML" << std::endl;

        // Lock The Data structure
        std::lock_guard<std::mutex> guard(mtx);

        // Set the flag to true, means data is loaded
        dataLoaded = true;

    }
    void mainTask()
    {
        std::cout << "Do Some Handshaking" << std::endl;

        // Acquire the Lock
        mtx.lock();
        // Check if flag is set to true or not
        while(dataLoaded != true)
        {
            // Release the lock
            mtx.unlock();

            std::cout << "Waiting for data ..." << std::endl;
            
            //sleep for 100 milli seconds
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            // Acquire the lock
            mtx.lock();
        }
        // Release the lock
        mtx.unlock();
        //Doc processing on loaded Data
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
