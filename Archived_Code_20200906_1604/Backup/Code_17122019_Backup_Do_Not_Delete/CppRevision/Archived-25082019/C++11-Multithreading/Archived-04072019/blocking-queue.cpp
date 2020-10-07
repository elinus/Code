#include <iostream>
#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include <chrono>

const int gQueueSize = 5;

int randomIntegerGenerator(int range) {

    return rand() % range;
}

class BlockingQueue {
    public:
        BlockingQueue() {}
        void producer() {
            for (int i = 0; i < 20; i++) {
                std::this_thread::sleep_for(std::chrono::milliseconds(randomIntegerGenerator(1000)));
                std::unique_lock<std::mutex> ulock(mMutex);
                while (mQueue.size() == gQueueSize) {
                    mCondVar.wait(ulock);
                }
                int value = randomIntegerGenerator(100);
                std::cout << "Pushing in queue, value = " << value << std::endl;
                mQueue.push(value);
                mCondVar.notify_one();
            }
        }
        void consumer() {
            for (int i = 0; i < 20; i++) {
                std::this_thread::sleep_for(std::chrono::milliseconds(randomIntegerGenerator(1000)));
                std::unique_lock<std::mutex> ulock(mMutex);
                if (mQueue.empty()) {
                    mCondVar.wait(ulock);
                }
                std::cout << "Poped value = " << mQueue.front() << std::endl;
                mQueue.pop();
                mCondVar.notify_one();
            }
        }
    private:
        std::queue<int> mQueue;
        std::mutex mMutex;
        std::condition_variable mCondVar;
};

int main (int argc, char const *argv[])
{
    srand(time(nullptr));
    BlockingQueue bq;
    std::thread cons_th(&BlockingQueue::consumer, &bq);
    std::thread prod_th(&BlockingQueue::producer, &bq);
    cons_th.join();
    prod_th.join();
    return 0;
}

