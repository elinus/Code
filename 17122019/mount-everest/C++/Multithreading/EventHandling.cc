#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

class Application {
    private:
        std::mutex m_Mutex;
        bool m_DataLoaded;
        std::condition_variable m_ConVar;
    public:
        Application() 
            : m_DataLoaded(false)
        {}

        void MainTask() {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "Loading data\n";
            std::lock_guard<std::mutex> lg(m_Mutex);
            m_DataLoaded = true;
            m_ConVar.notify_one();
        }

        void LoadData() {
            std::cout << "Do some handshaking...\n";
            std::unique_lock<std::mutex> ul(m_Mutex);
            m_ConVar.wait(ul);
            /*
            m_Mutex.lock();
            while (!m_DataLoaded)
            {
                m_Mutex.unlock();
                std::cout << std::this_thread::get_id() << " :: waiting..\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                m_Mutex.lock();
            }
            m_Mutex.unlock();
            */
            std::cout << "Do processing on loaded data\n";
        }
};

int main (int argc, char *argv[]) 
{
    Application app;
    std::thread t1(&Application::MainTask, &app);
    std::thread t2(&Application::LoadData, &app);
    t1.join();
    t2.join();
    return 0;
}

