#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <functional>

class Application {
private:
    bool m_DataLoaded;
    std::mutex m_Mutex;
    std::condition_variable m_CV;
public:
    Application() : m_DataLoaded(false) {}
    ~Application() {}
    void loadData() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Loading data from XML" << std::endl;
        std::lock_guard<std::mutex> lock(m_Mutex);
        m_DataLoaded = true;
        m_CV.notify_one();
    }

    bool isDataLoaded() {
        return m_DataLoaded;
    }

    void mainTask() {
        std::cout << "Do some handshaking!" << std::endl;
        // m_Mutex.lock();
        // while (!m_DataLoaded) {
        //     m_Mutex.unlock();
        //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //     m_Mutex.lock();
        // }
        // m_Mutex.unlock();
        std::unique_lock<std::mutex> lock(m_Mutex);
        m_CV.wait(lock, std::bind(&Application::isDataLoaded, this));
        std::cout << "Do processing on loaded data" << std::endl;
    }
};

int main(int argc, char const *argv[]) {
    Application app;
    std::thread t1_ { &Application::loadData, &app };
    std::thread t2_ { &Application::mainTask, &app };
    t1_.join();
    t2_.join();
    return 0;
}
