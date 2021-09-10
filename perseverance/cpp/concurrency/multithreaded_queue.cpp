#include <iostream>
#include <future>
#include <chrono>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> g_queue;
std::mutex g_queue_mutex;
std::condition_variable g_cond_var;

void producer(int value) {
    for (int i = 0; i < 10; i++) {
        {
            std::lock_guard<std::mutex> lg(g_queue_mutex);
            g_queue.push(value + i);
        }
        g_cond_var.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(value));
    }
}

void consumer(int value) {
    while (true) {
        int num;
        {
            std::unique_lock<std::mutex> ul(g_queue_mutex);
            g_cond_var.wait(ul, []{ return !g_queue.empty(); });
            num = g_queue.front();
            g_queue.pop();
        }
        std::cout << "consume " << value << ": " << num << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    //start three providers for values 100+, 300+, 500+
    auto p1 = std::async(std::launch::async, producer, 100);
    auto p2 = std::async(std::launch::async, producer, 300);
    auto p3 = std::async(std::launch::async, producer, 500);

    //start two consumers printing the vals
    auto c1 = std::async(std::launch::async, consumer, 1);
    auto c2 = std::async(std::launch::async, consumer, 2);
    return 0;
}
