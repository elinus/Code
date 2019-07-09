#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
#include <condition_variable>

class Application {
    public:
        void producer() {
            for (int i = 0; i < 20; ++i) {
                std::unique_lock<std::mutex> ul(mMutex);
                if (mQueue.size() == MAX_QUEUE_SIZE) {
                    mCV.wait(ul);
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::cout << std::this_thread::get_id() << 
                    " [" <<  __func__ << "]:=> " << i << std::endl;
                mQueue.push(i);
                mCV.notify_one();
            }
        }
        void consumer() {
            for (int i = 0; i < 20; ++i) {
                std::unique_lock<std::mutex> ul(mMutex);
                if (mQueue.empty()) {
                    mCV.wait(ul);
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                std::cout << std::this_thread::get_id() << 
                    " [" << __func__ << "]:=> " << mQueue.front() << std::endl;
                mQueue.pop();
                mCV.notify_one();
            }
        }
    private:
        size_t const MAX_QUEUE_SIZE = 5;
        std::queue<int> mQueue;
        std::mutex mMutex;
        std::condition_variable mCV;
};

int main(int argc, char const *argv[])
{
    Application pcApp;
    std::thread pTh(&Application::producer, &pcApp);
    std::thread cTh(&Application::consumer, &pcApp);
    pTh.join();
    cTh.join();
    return 0;
}

