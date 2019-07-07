#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>

using namespace std::placeholders;

class Application {
    private:
        std::mutex mMutex;
        bool mDataLoaded;
        std::condition_variable mCondVar;
    public:
        Application(): mDataLoaded(false) {}
        void loadData() {
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));
            std::cout << "Loading data from xml." << std::endl;
            std::lock_guard<std::mutex> lg(mMutex);
            mDataLoaded = true;
            mCondVar.notify_one();
        }
        bool isDataLoaded() {
            return mDataLoaded;
        }
        void mainTask() {
            std::cout << "Do some handshaking!" << std::endl;
            std::unique_lock<std::mutex> ul(mMutex);
            //mMutex.lock();
            //while (mDataLoaded != true) {
                //mMutex.unlock();
                std::cout << "Data not loaded. Sleeping..!" << std::endl;
                //std::this_thread::sleep_for(std::chrono::milliseconds(500));
                //mMutex.lock();
            //}
            //mMutex.unlock();
            mCondVar.wait(ul, std::bind(&Application::isDataLoaded, this));
            std::cout << "Do processing on loaded data!" << std::endl;
        }
};

int main(int argc, char const *argv[])
{
    Application app;
    std::thread t1(&Application::loadData, &app);
    std::thread t2(&Application::mainTask, &app);
    t1.join();
    t2.join();
    return 0;
}

