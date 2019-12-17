#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>

using namespace std::chrono;

class Application {
    public:
        Application(): mMovieLoaded(false) {}
        void drawWindow() {
            std::cout << "Launching media player.." << std::endl;
            std::unique_lock<std::mutex> ulock(mutex);
            while (!mMovieLoaded) {
                condVar.wait(ulock);
            }
            std::cout << "Movie loaded successfully. Playing movie now!!" << std::endl;
        }
        void loadData() {
            std::this_thread::sleep_for(milliseconds(1000));
            std::cout << "Loading movie into RAM.." << std::endl;
            std::lock_guard<std::mutex> lockg(mutex);
            mMovieLoaded = true;
            condVar.notify_one();
        }
    private:
        std::mutex mutex;
        std::condition_variable condVar;
        bool mMovieLoaded;
};

int main (int argc, char const *argv[])
{
    Application app;
    std::thread t1(&Application::drawWindow, &app);
    std::thread t2(&Application::loadData, &app);
    t1.join();
    t2.join();
    return 0;
}

